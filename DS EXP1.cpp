#include<iostream>
using namespace std;

 struct Student 

{
	 int studentrollNo;
	char studentName[50];
	float studentMarks;
	 
};

void addStudent(Student s[100], int n)
{

	for(int i=0;i<n;i++)
	
	{
		cout<<"\n Enter details  of student"<<i+1<<endl;
		
		cout<<"Enter Student roll no :";
		cin>>s[i].studentrollNo;

		cout<<"Enter Student name :";
		cin>>s[i].studentName;
		
		cout<<"Enter Student marks:";
		cin>>s[i].studentMarks;
	}

}
void displayStudent(Student *s,int n)
{
cout<<"\n Student record";	
	 for(int i=0;i<n;i++)
	 {
	 	cout<<"Student:"<<i+1<<endl;
	 	cout<<"Student id :"<<(s+i)->studentrollNo <<endl;
	
	 	cout<<"Studentname :"<<(s+i)->studentName<<endl; 
	 	cout<<"Student marks :"<<(s+i)->studentMarks<<endl;
	 }
}
 int main()
 {
 	int n;
 	cout<<"Enter no of Student:";
 	cin>>n;
 	Student s[n];
 	addStudent(s,n);
 	displayStudent(s,n);
 	
 }
