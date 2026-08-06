#include<iostream>
#include<cstdlib>
using namespace std;
 struct Node
 {
 
 int Data;                 //insertion of liked list
 Node*Next;
 
};
 int main()                                       
 {
 
  Node*head = NULL ;
  Node*new_Node ,*temp ,*temp2 ,*temp3;
  
 //create first node
 new_Node=(Node*)malloc(sizeof( Node));
 new_Node->Data=10;
 new_Node->Next=NULL; 
 head = new_Node;
 
 //create second node
 temp=(Node*)malloc(sizeof(Node));
 temp->Data=20;
 head->Next=temp;
  //link first node to second node
 head->Next=temp;
 
 //create third node
 temp2=(Node*)malloc(sizeof(Node));
 temp2->Data=30;
 temp2->Next=NULL;
 
 //link second node to third node
 temp->Next=temp2;

 //create fourth node
 temp3=(Node*)malloc(sizeof(Node));
 temp3->Data=40;
 temp3->Next=NULL;
 
 //link third node to fouth node
 temp2->Next=temp3;
 
 //display linked list
 Node*ptr=head;
 
 while(ptr !=NULL){
 

cout<<ptr->Data<<"->";
ptr=ptr->Next;
}
cout<<"NULL"; 

 return 0;
}
