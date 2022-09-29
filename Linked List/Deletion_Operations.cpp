#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head;

void Insert();
void DeleteBeginning();
void DeleteEnd();
void DeleteAny();
void Print();

int main() {
    
    int x,choice;
    cout<<"Enter first element: ";
    cin>>x;
    
    node* temp;
    temp= new node;
    temp->data=x;
    temp->next=NULL;
    head=temp;
    do{
    cout<<endl<<"*************************"<<endl;
    cout<<"1- Insert"<<endl;
    cout<<"2- Delete node at beginning"<<endl;
    cout<<"3- Delete node at end"<<endl;
    cout<<"4- Delete node at any point"<<endl;
    cout<<"5- Print the list"<<endl;
    cout<<"6- Exit"<<endl;
    cout<<"*************************"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    
    switch(choice){
        case 1:
            Insert();
            break;
            
        case 2:
            DeleteBeginning();
            break;
        
        case 3:
            DeleteEnd();
            break;
             
        case 4:
            DeleteAny();
            break;
        
        case 5:
            Print();
            break;
        
        default:
            break;
    }
    }while(choice<6);
    
	return 0;
}

void Insert(){
    int x;
    cout<<"Enter element to insert: ";
    cin>>x;
    
    node* temp,* temp1;
    temp=head;
    
    temp1= new node;
    temp1->data=x;
    temp1->next=NULL;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next=temp1;
}

void DeleteBeginning(){
    
    node* temp,* temp1;
    temp=head;
    temp1=head;
    temp=temp->next;
    delete temp1;
    head=temp;
    cout<<"Deleted node at beginning"<<endl;
}

void DeleteEnd(){
    
    node* temp,* temp1;
    temp=head;
    while(temp->next!=NULL){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    delete temp;
    cout<<"Deleted node at end"<<endl;
}

void DeleteAny(){
    int x;
    cout<<"Enter the position to delete: ";
    cin>>x;

    node* temp,* temp1;
    temp=head;
    for(int i=1;i<x;i++){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    delete temp;
    cout<<"Deleted node at "<<x<<endl;
}

void Print(){
    node* temp;
    temp=head;
    cout<<"The list is: ";
    while(temp!=NULL){
        cout<<temp->data<<",";
        temp=temp->next;
    }
    cout<<endl;
}