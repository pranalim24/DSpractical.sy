#include<iostream>
#include<cstdlib>
using namespace std;
 struct Node
 {
 
 int Data;
 Node*Next;
 
};
 int main()
 {
 
  Node*head = NULL ;
  Node*new_Node;
 new_Node=(Node*)malloc(sizeof( Node));
 new_Node->Data=10;
 new_Node->Next=NULL; 
 head = new_Node;
 
 
 cout << head->Data <<" -> NEXT" ;
 return 0;
}
