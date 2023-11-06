#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class student {
	
	public:
	string name;
	string rollno;
	string course;
	string level;
	string contact;
	
	
	void input()
	{
		cout<<"Enter name:"<<endl;
		cin>>name;
		cout<<"Enter rollno:"<<endl;
		cin>>rollno;
		cout<<"Enter course:"<<endl;
		cin>>course;
		cout<<"Enter level:"<<endl;
		cin>>course;
		cout<<"Enter contact:"<<endl;
		cin>>contact;
	}
	void display()
	{
		cout<<"Name = "<<name<<endl;
		cout<<"Rollno = "<<rollno<<endl;
		cout<<"Course ="<<course<<endl;
		cout<<"level="<<level<<endl;
		cout<<"contact="<<contact<<endl;
	}
	bool matchrollno(const string& targetrollno)
	{
		return rollno==targetrollno;
	}
	
};
class studentmanagementsystem{
	
	  private:
	  	
	  	static const int maxstudent = 50;
	  	student student1[maxstudent];
	    int totalstudent =0;
	    
	    public:
	    	
	    	
	    void enter()
	    {
	    	
	    	if(totalstudent < maxstudent)
	    	{
	    		student1[totalstudent].input();
	    		totalstudent++;
	    	    savedatatofile();
			}
			else{
				
				cout<<"Maximum student limit reached:::::"<<endl;
			}
	    	
		}
		
		void show()
		{
			
			for (int i=0; i<totalstudent; i++)
			{
				cout<<"Data of student is:"<<i+1<<endl<<endl;
				student1[i].display();
			}
		}
		
		void search(){
			
			  string rollno;
			  
			  cout<<"Enter rollno to search "<<endl;
			  cin>>rollno;
			  
			  for (int i=0; i<totalstudent;i++)
			  {
			  	if(student1[i].matchrollno(rollno)){
			  		
			  		student1[i].display();
			  		return;
				  }
			  	
			  }
		}
		
		void update()
		{
			
			string rollno;
			cout<<"Enter rollno to update"<<endl;
			cin>>rollno;
			
			for(int i=0; i<totalstudent; i++)
			{
				if(student1[i].matchrollno(rollno))
				{
					student1[i].input();
					savedatatofile();
				}
				
			}
			
		}
		
		void deleterecord()
		{
			string rollno;
			cout<<"Enter rollno whose data you wanna delete:"<<endl;
			cin>>rollno;
			
			for (int i=0; i<totalstudent; i++)
			{
				if(student1[i].matchrollno(rollno)){
				
				   for (int j=i; j<totalstudent-1; j++)
				   {
				   	student1[j] = student1[j+1];
					   }	
					   totalstudent--;
					   
					   cout<<"Rollno of deleted record:"<<rollno<<endl;
					   savedatatofile();
					   return;
				}
			}
		    cout<<"Record not deleted:"<<rollno<<endl;
		  	
		}
		
		
		void deleterecordfile()
		{
			
			ofstream outfile("studentdata.txt", ios::trunc);
			if(outfile.is_open())
			{
				outfile.close();
			}
			else{
				cout<<"Error!while deleting"<<endl;
			}
			
		}
		
		void savedatatofile()
		{
			ofstream outfile("studentdata.txt", ios::app);
			if(outfile.is_open())
			{
				for(int i=0; i<totalstudent; i++)
				{
					
					outfile<< student1[i].name<<","<<student1[i].rollno<<","<<student1[i].course<<","<<student1[i].level<<","<<student1[i].contact<<endl;
				}
				outfile.close();
				
			}
			else{
				cout<<"File not opened"<<endl;
			}
			
		}
		
		
		void enter(int numstudents)
		{
			
			for (int i=0; i<numstudents; i++)
			{
				
				if (totalstudent<maxstudent)
				{
					
					cout<<"Enter student data"<<i+1<<endl<<endl;
					student1[i].input();
					totalstudent++;
					savedatatofile();
				}
				else{
					cout<<"Maximum student limit reached"<<endl;
					break;
				}
			}
		}
	studentmanagementsystem ()
		{
			ifstream infile("studentdata.txt");
			
			if (infile.is_open())
			{
				
				
				totalstudent = 0;
				
				string line;
				
				while(getline (infile, line))
				{
					
					istringstream iss(line);
					
					string name, rollno, course, level, contact;
					
					if (getline(iss, name, ',')&&
					    getline(iss, rollno, ',')&&
					    getline(iss, course, ',')&&
					    getline(iss, level, ',')&&
					    getline(iss,contact, ',')){
					    	
					    	if (totalstudent < maxstudent)
					    	{
					    		
					    		student1[totalstudent].name = name;
					            student1[totalstudent].rollno = rollno;
								student1[totalstudent].course = course;
                                student1[totalstudent].level = level;
                                student1[totalstudent].contact = contact;
                                totalstudent++;    		 
							}
							else{
								cout<<"Maxim limit reached"<<endl;
								break;
							}
						}
					    
					    
				}
				
				infile.close();
			}
			else{
				cout<<"error opening file"<<endl;
			}
			
			
		}
	
};

 int main()
 { 
 
  
 
    studentmanagementsystem sms;
    
 	int value;
	while(1)
	{
	cout<<"________________________________STUDENT MANAGEMENT SYSTEM__________________________________"<<endl;
	cout<<"                                Press 1 to enter data"<<endl;
	cout<<"                                Press 2 to show data"<<endl;
	cout<<"                                Press 3 to search data"<<endl;
	cout<<"                                Press 4 to update data"<<endl;
	cout<<"                                Press 5 to delete data"<<endl;
	cout<<"                                Press 6 to exit data"<<endl;
	cout<<"                                Press 7 to delete all records file"<<endl;
	cout<<"                                press 8 to add how many data of student to input                   "<<endl;
	cin>>value;
	
	switch(value)
	{
		case 1:
			sms.enter();
		    break;
		    
		    case 2:
			sms.show();
		    break;
		    
		    case 3:
		    sms.search();
		    break;
		    
		    case 4:
			sms.update();
		    break;
		    
		    case 5:
			sms.deleterecord();
		    break;
		    
		    case 6:
			exit(0);
		    break;
		    
		    case 7:
		    sms.deleterecordfile();
		    break;
		    
		    case 8:
		    	int data;
		    	cout<<"Enter how many data of student you wanna input"<<endl;
		    	cin>>data;
		    	sms.enter(data);
		    	break;
		    
		    case 9:
		    default:
		    cout<<"Invalid"<<endl;
		    break;
	}
	}
}
 




