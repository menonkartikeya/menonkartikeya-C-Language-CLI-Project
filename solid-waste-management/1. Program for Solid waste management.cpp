#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<vector>
#include<sstream>
#include<string.h>
using namespace std;
class waste{       
	public:
		string name,type, category, refuse_type;
		struct amount
	    {
	    int amount_number;
		float amount_kg;
		float amount_l;
		float amount_m;
	    }a;
	    void category_value(int c)
	    {
	    	if(c==1)
	    	{
	    		category="Non-Hazardous waste";
			}
			else if(c==2)
			{
				category="Hazardous waste";
			}
			else
			{
				category="Not Entered";
			}
		}
	    void type_value(int c)
	    {
	    	if(c==1)
	    	{
	    		type="Solid";
			}
			else if(c==2)
			{
				type="Liquid";
			}
			else if(c==3)
			{
				type="Semi(sludge)";
			}
			else {
				type="Not Entered";
			}
		}
		void refusetype(int r)
	    {
	    	if(r==1)
	    	{
	    		refuse_type="Garbage";
			}
			else if(r==2)
			{
				refuse_type="Rubbish";
			}
			else if(r==3)
			{
				refuse_type="Trash";
			}
			else if(r==4)
			{
				refuse_type="E-waste";
			}
			else {
				refuse_type="Not Entered";
			}
		}
}w;
int x;
int c;
int r;       
int d=1;
string option;
void search_by_category();
void search_and_view(string choice)      //this function searches the data in file and shows it to the user
{
	if(choice=="c"||choice=="C")    //if user wants to search by category
	{
		search_by_category();
	}
	else if(choice=="a"||choice=="A")  //if user wants to view all the waste data
	{
		ifstream ob3("Waste_Data.csv",ios::in);   //FILE POINTERS is used to read from file
		string line, word, temp;
		getline(ob3,line); 
		cout<<setw(25)<<"NAME"<<setw(40)<<"Category"<<setw(25)<<"STATE"<<setw(30)<<"AMOUNT\n\n";
		
		vector<string> row;
        while (ob3){
        getline(ob3, line); 
        stringstream s(line); 
        while (getline(s, word, ',')) { 
            row.push_back(word); }
        if(!row.empty()){
		cout<<setw(25)<<row[0]<<setw(40)<<row[1]<<setw(25)<<row[2]<<setw(30)<<row[3]<<"\n";
	     }
	     row.clear();
        }
	}
	else
	{
		ifstream ob2("Waste_Data.csv",ios::in);  //if user entered the waste name to search
		                                         //FILE POINTERS is used to read from file
		vector<string> row; //Read the Data from the file as String Vector 
        string line, word, temp;
		while(ob2)
		{
		row.clear();
        getline(ob2, line); //read an entire row and store it in a string variable 'line' 
        stringstream s(line);   // used for breaking words 
        while (getline(s, word, ',')) {  //read every column data of a row and store it in a string variable, 'word'
            row.push_back(word); }// add all the column data of a row to a vector
		d = stricmp(row[0].c_str(),choice.c_str());//string::c_str() is used to get a pointer to the underlying C-string
		if(d==0)
		{
			cout << "Name: " << row[0] << "\t"; 
            cout << "Category: " << row[1] << "\t"; 
            cout << "Type/State: " << row[2] << "\t"; 
            cout << "Amount: " << row[3] << "\n\n";
			break;
		}
	    }
	    if(d!=0)
	      cout<<"Not Found\n\n";
		ob2.close();
	}
}
void search_by_category()
{
	cout<<"Enter category: \n\t1. Hazardous\n\t2. Non-Hazardous & others\n";
	cin>>r;
	ifstream ob4("Waste_Data.csv",ios::in);   //FILE POINTERS is used to read from file
	string line, word, temp; int e,f;
	vector<string> row;
	getline(ob4,line); 
	cout<<setw(25)<<"Name"<<setw(40)<<"Category"<<setw(25)<<"Type/State"<<setw(30)<<"Amount\n\n"; 
    while (ob4)
	{
    getline(ob4, line); 
    stringstream s(line); 
    while (getline(s, word, ',')) {row.push_back(word); }
    e = stricmp(row[1].c_str(),"Hazardous waste");//string::c_str() is used to get a pointer to the underlying C-string
	if((e!=0)&&(r==2)&&(!row.empty()))
		{
			cout << setw(25) << row[0]<<setw(40)<< row[1]<<setw(25)<< row[2] << setw(30)<<row[3] << "\n";
            f=0;
		}
	else if((e==0)&&(r==1)&&(!row.empty()))
		{
			cout << setw(25) << row[0]<<setw(40)<< row[1]<<setw(25)<< row[2] << setw(30)<<row[3] << "\n";
            f=0;
		}
	row.clear();
	}
	if(f!=0)
	    cout<<"Not Found\n\n";
	ob4.close();
}

void edit_details() //function to edit the details of waste already in the file
{
	fstream ob1, ob2;                   //FILE POINTERS is used to read and write data from file
	string wastename, opted, line, word; 
    vector<string> row; 
    ob1.open("Waste_Data.csv", ios::in);// Open an existing record 
    ob2.open("temporary.csv", ios::out); // Create a new file to store updated data 
    cout << "Enter the name of waste to be updated: "; 
    cin >> wastename; 
    search_and_view(wastename);
    if(d!=0)
    {
    	getche();
		system("cls");
		return;
	}
    cout << "Press 'D' to Delete from record\n"<<setw(75)<<"Press 'E' to edit\n"; 
    opted=getche(); 
    if(opted=="D"||opted=="d")  // If user wants to delete the waste data
    {
    	int d;
		while(ob1)
		{
		row.clear();
        getline(ob1, line); 
        stringstream s(line);   // used for breaking words 
        while (getline(s, word, ',')) {  //read every column data of a row and store it in a string variable, 'word'
            row.push_back(word); }// add all the column data of a row to a vector
		d = stricmp(row[0].c_str(),wastename.c_str());//string::c_str() is used to get a pointer to the underlying C-string
		if(ob1.eof()){ break;}
		if(d!=0)
	    {
	        ob2<<line<<endl;
		}
        }
        ob1.close();
		ob2.close();
		remove("Waste_Data.csv");                   //Old file is removed
		rename("temporary.csv","Waste_Data.csv");   //New file is updated
		system("cls");
	    cout<<"\n\n--------------------DELETED from record!------------------------\n\n";
	}
	else if(opted=="E"||opted=="e")      //If user wants to edit a waste data
	{
		int d;
		while(ob1)
		{
		row.clear();
        getline(ob1, line);     
        stringstream s(line);   // used for breaking words 
        while (getline(s, word, ',')) {  //read every column data of a row and store it in a string variable, 'word'
            row.push_back(word); }// add all the column data of a row to a vector
		d = stricmp(row[0].c_str(),wastename.c_str());//string::c_str() is used to get a pointer to the underlying C-string
		if(ob1.eof()){ break;}
		if(d==0)
		{
			K:
			cout<<"\nWaste name : ";
	        cin>>w.name; 
	        if(w.name=="a"||w.name=="A"||w.name=="c"||w.name=="C")
	        	{cout<<"----------Waste name can not be A or C------------\n";
	        	goto K;}
			cout<<"Give category: \n\t1. Non-Hazardous\n\t2. Hazardous\n";
			cin>>r;
			w.category_value(r);
            if(r==1)
	        {
	        int refuse;
		    cout<<"The waste is: \n\t1. Garbage\n\t2. Rubbish\n\t3. Trash\n\t4. E-waste\n";
		    cin>>refuse;
		    w.refusetype(refuse);
            }
	        cout<<"Type/State :\n\t1. Solid\n\t2. Liquid\n\t3. Semi(sludge)\n";
	        cin>>c;
	        w.type_value(c);
	        L:
	        cout<<"Enter amount: \n\t1. in number\n\t2. in Kg\n\t3. in L\n\t4. in M\n";
	        cin>>x;
	        switch(x)
	        {
	            case 1: cout<<"Enter amount in numbers ";
		                cin>>w.a.amount_number;
		                break;
                case 2: cout<<"Enter amount in Kilograms ";
		                cin>>w.a.amount_kg;
		                break;
	            case 3: cout<<"Enter amount in Litres ";
		                cin>>w.a.amount_l;
                        break;
                case 4: cout<<"Enter amount in metres ";
		                cin>>w.a.amount_m;
                        break;
	            default: cout<<"Invalid Input!\n";
	                    goto L;         
	        }
			ob2<<w.name<<","<<w.category;
	        if(r==1){ob2<<" ("<<w.refuse_type<<") ";}
	        ob2<<","<<w.type<<",";
	        if(x==1) ob2<<w.a.amount_number<<" Pcs."<<endl;
	        else if(x==2) ob2<<w.a.amount_kg<<" kg"<<endl;
	        else if(x==3) ob2<<w.a.amount_l<<" l"<<endl;
	        else if(x==4) ob2<<w.a.amount_m<<" m"<<endl;
	        system("cls");
	        cout<<"\n\n--------------------Waste details updated!------------------------\n\n";
		}
	    else
	    {
	        ob2<<line<<endl;
		}
        }
        ob1.close();
		ob2.close();
		remove("Waste_Data.csv");                  //Old file is deleted
		rename("temporary.csv","Waste_Data.csv");  //New file added
	}
	else
	{
		system("cls");
		cout<<"Invalid Input\n";
		ob1.close(); ob2.close();
		edit_details();
	}
}
int main()
{
	for(; ;)         //Infinite loop until the user enters 6  to exit
	{
		int op;
		cout<<"Press\n\t1: Enter details of waste\n\t2: View details of wastes\n\t";
		cout<<"3: Edit the details of a waste\n\t4: Waste Management\n\t";
		cout<<"5: About this program\n\t6: Exit\n";
		op=getche();
		system("cls");
		switch(op)
		{
			case '1':{
	                cout<<"Give category: \n\t1 : Non-Hazardous\n\t2 : Hazardous\n"
					    <<setw(75)<<"Or Press 5 to skip\n"
	                    <<setw(75)<<"Or Press 8 to go back\n";
	                cin>>r;
	                if(r!=8){
	                w.category_value(r);
                 	if(r==1)
	                {
	             	int refuse;
	             	X:
		            cout<<"The waste is: \n\t1 : Garbage\n\t2 : Rubbish\n\t3 : Trash\n\t4 : E-waste\n";
		            cout<<setw(75)<<"Or Press 5 to skip\n"<<setw(75)<<"Press 9 to know about these categories\n";
		            cin>>refuse;
		            if(refuse==9)
		            {
		         	ifstream ob3("ABOUT_REFUSE.txt",ios::in);
	                string result, line;
                    while (ob3){
			        (getline(ob3, line ));
			        result += line +'\n';}
                    cout<<result<<"\n\n"<<setw(75)<<"Press any key to go back\n";
                    getche();
                    goto X;
		            }
		            w.refusetype(refuse);
                   	}
	                cout<<"Type/State :\n\t1 : Solid\n\t2 : Liquid\n\t3 : Semi(sludge)\n"
					    <<setw(75)<<"Or Press 5 to skip\n";
	                cin>>c;
	                w.type_value(c);
	                K:
	                cout<<"Waste name : ";
	                cin>>w.name; 
	                if(w.name=="a"||w.name=="A"||w.name=="c"||w.name=="C")
	        	       {cout<<"----------Waste name can not be A or C------------\n";
	        	       goto K;}
	                L:
	                cout<<"Enter amount: \n\t1. in number\n\t2. in Kg\n\t3. in L\n\t4. in M\n";
	                cin>>x;
	                switch(x)
	                {
	                case 1: cout<<"Enter amount in numbers ";
		                    cin>>w.a.amount_number;
		                    break;
                    case 2: cout<<"Enter amount in Kilograms ";
		                    cin>>w.a.amount_kg;
		                    break;
	                case 3: cout<<"Enter amount in Litres ";
		                    cin>>w.a.amount_l;
                            break;
                    case 4: cout<<"Enter amount in metres ";
		                    cin>>w.a.amount_m;
                            break;
	                default: cout<<"Invalid Input!\n";
	                        goto L;         
	                }
	                //Entering in file using file pointer
					ofstream ob("Waste_Data.csv",ios::in|ios::out|ios::app);
	                ob.seekp(0,ios::end);
	                ob<<w.name<<","<<w.category;
	                if(r==1){ob<<" ("<<w.refuse_type<<") ";}
	                ob<<","<<w.type<<",";
	                if(x==1) ob<<w.a.amount_number<<" Pcs."<<endl;
	                else if(x==2) ob<<w.a.amount_kg<<" kg"<<endl;
	                else if(x==3) ob<<w.a.amount_l<<" l"<<endl;
	                else if(x==4) ob<<w.a.amount_m<<" m"<<endl;
	                ob.close();
	                
	                system("cls");
	                cout<<"\n\n--------------------Waste details stored!------------------------\n\n";
                    }
                    else system("cls");
			        break;
			        }
			case '2': {
	                cout<<"Enter waste name ";
	                cout<<setw(75)<<"Or, Press 'C' to search with category\n";
	                cout<<setw(94)<<"Or, Press 'A' to view all wastes' data\n\t";
	                cin>>option;
	                search_and_view(option);
				    break;
				}
			case '3':{edit_details();
			       break;}
			case '4': {P:     
			        cout<<"Enter the waste name(entered previously), to see how it should be managed:\n"
			            <<setw(75)<<"Or Press 8 to go back\n";
			        cin>>option;
			        if(option!="8"){
			        search_and_view(option);
			        if(d!=0)
                    {
    	            getche();
		            system("cls");
		            goto P;
	                }
	                ifstream ob2("Waste_Data.csv",ios::in);
		            vector<string> row; //Read the Data from the file as String Vector 
                    string line, word, temp;
	             	while(ob2)
		            {
		            row.clear();
                    getline(ob2, line); //read an entire row and store it in a string variable 'line' 
                    stringstream s(line);   // used for breaking words 
                    while (getline(s, word, ',')) {  //read every column data of a row and store it in a string variable, 'word'
                    row.push_back(word); }// add all the column data of a row to a vector
                    d = stricmp(row[0].c_str(),option.c_str());//string::c_str() is used to get a pointer to the underlying C-string
		            if(d==0)
		            {
		            int p[5];
					p[0] = stricmp(row[1].c_str(),"Hazardous waste");
					p[1] = stricmp(row[1].c_str(),"Non-Hazardous waste (Garbage) ");
					p[2] = stricmp(row[1].c_str(),"Non-Hazardous waste (Rubbish) ");
					p[3] = stricmp(row[1].c_str(),"Non-Hazardous waste (Trash) ");
					p[4] = stricmp(row[1].c_str(),"Non-Hazardous waste (E-waste) ");
					ifstream obj; 
					if(p[0]==0)
					{
						obj.open("Hazardous_waste.txt");
					}
					if(p[1]==0)
					{
						obj.open("Non_Hazardouswaste(Garbage).txt");
					}
					if(p[2]==0)
					{
						obj.open("Non_Hazardouswaste(Rubbish).txt");
					}
					if(p[3]==0)
					{
						obj.open("Non_Hazardouswaste(Trash).txt");
					}
					if(p[4]==0)
					{
						obj.open("Non-Hazardouswaste(E-waste).txt");
					}
					string  line;
                    while(!obj.eof())
                    {
                	getline(obj,line);
                	cout<<line<<endl;
				    }
				    obj.close();
				    getche();
				    system("cls");
				    break;
			        }
			        }
			        }
			        break;
			        }
			case '5': {
				     ifstream obj;
				     obj.open("About_program.txt");
				     string  line;
                    while(!obj.eof())
                    {
                	getline(obj,line);
                	cout<<line<<endl;
				    }
				    obj.close();
				    getche();
				    system("cls");
				    break;
			}
			case '6': return 0;//or use _Exit(any int); or exit(any int);
				    break;
			default: cout<<"Invalid Input\n\n";
		}
	}
	return 0;
}
