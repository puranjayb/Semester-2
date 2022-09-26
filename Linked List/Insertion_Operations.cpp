/*C++ program to create a singly linked list and insert element at Beginning, End, At any point
@Puranjay Bhargava*/

#include <iostream>
using namespace std;

void InsertBeginning();
void InsertEnd();
void InsertAny();
void Print();

struct node{
    int data;
    node* next;
};
node* head=NULL;

int main(){

    int choice,x;
    cout<<"Enter first element: ";
    cin>>x;
    node* temp;
    temp=new node;
    temp->data=x;
    temp->next=NULL;
    head=temp;

    do{
    cout<<endl<<"*************************"<<endl;
    cout<<"1- Insert at begining"<<endl;
    cout<<"2- Insert at end"<<endl;
    cout<<"3- Insert at any location"<<endl;
    cout<<"4- Print"<<endl;
    cout<<"5- Exit"<<endl;
    cout<<"*************************"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
            InsertBeginning();
            break;
        case 2:
            InsertEnd();
            break;
        case 3:
            InsertAny();
            break;
        case 4:
            Print();
            break;
        default:
            break;

    }
    }while(choice<5);

    return 0;
}

void InsertBeginning(){
    int x;
    cout<<"Enter a number to insert at beginning: ";
    cin>>x;

    node* temp;
    temp= new node;
    temp->data=x;
    temp->next=NULL;

    if(head->next==NULL){
        head->next=temp;
    }

    else if(head->next!=NULL){
        temp->next=head->next;
        head->next=temp;
    }
}

void InsertEnd(){
    int x;
    cout<<"Enter a number to insert at end: ";
    cin>>x;

    node* temp,* temp1;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp1=new node;
    temp1->data=x;
    temp1->next=NULL;
    temp->next=temp1;
}

void InsertAny(){
    int pos,x;
    cout<<"What position do you want to insert: ";
    cin>>pos;
    cout<<"Enter element to insert at "<<pos<<": ";
    cin>>x;

    node* temp,* temp1;
    temp=head;
    for(int i=1;i<=pos-2;i++){ //pos-2 to get to the previous node at which we have to insert.
        temp=temp->next;
    }
    temp1=new node;
    temp1->data=x;
    temp1->next=temp->next;
    temp->next=temp1;
}

void Print(){
    node* temp;
    temp=head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data<<", ";
        temp=temp->next;
    }
    cout<<endl;
}
