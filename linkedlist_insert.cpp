#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data =d;
        next=NULL;
    }

};

int sizeOfLL(node* head){
    int ct=0;
    while(head){
        ct++;
        head=head->next;
    }
    return ct;

}

void insertAtBeginning(node* head,node* tail,int data){
    node*n = new node(data);
    if(head==NULL){
        head=n;
        tail=n;
    }
    else{
        n->next=head;
        head=n;
    }

}

void insertAtend(node*head, node* tail,int data){
    node* n=new node(data);
    if(head==NULL){
        head=n;
        tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }

}

void insert(node* &head,node* &tail,int data,int index){
    node* n=new node(data);
    if(index==NULL){
        insertAtBeginning(head,tail,data);

    }
    else if(index==sizeOfLL(head)){
        insertAtend(head,tail,data);
    }
    else{
        node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;

        }
        n->next=temp->next;
        temp->next=n;

    }

}

void print(node*head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;

}
    
    

int main(){

}