#include <iostream> 
using namespace std;

//class define
class Node {
    public:
    int data ;
    Node *next;

    Node(int data);
};

class Queue{
    private: 
        Node *head;
        Node *tail;
        int size;
    public:
        Queue();
        ~Queue();
        int getsize();    
        //insertion
        void push(int data);
        //displayfunction
        void display();
        //deletion
        void pop();
        //findFunstion
        void finddata(int data); 
};

//------------------------------------------------------ member functions -------------------------------------

//------------------------------------------------------   constructors   -------------------------------------

Node::Node(int data)
{
    this->data = data;
    next = NULL;
}

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    size = 0;
    cout<<"list initailised"<<endl;
}

//------------------------------------------------------   constructors   -------------------------------------
Queue::~Queue()
{
    Node *temp = head;
    while(temp)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
    cout<<"list deleted";
}

//------------------------------------------------------ get size function -------------------------------------
int Queue::getsize()
{
    return size;
}

//------------------------------------------------------ insertion functions -------------------------------------

void Queue::push(int data)
{
    Node *n = new Node(data);
    //if list is empty
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else 
    {
        tail->next = n;
        tail = n; 
    }
    size++;
}

//------------------------------------------------------ display functions -------------------------------------

void Queue::display()
{
    Node *temp = head;
    if(!temp)
    cout<<"List is empty"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" --> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//------------------------------------------------------ delete data -------------------------------------

 void Queue::pop()
 {
    //no list
    if(tail == NULL)
        cout<<"list is empty --> not possible to delete";
    //list exist
    else
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        size--;
    }
 }

//------------------------------------------------------   find function   -------------------------------------

void Queue::finddata(int data)
{
    int pos = 1;
    bool found = false;
    Node *temp = head;
    while(temp)
    {   
        if(data == temp->data)
            {
                found = true;
                cout<<"data --> "<<data<<" is found at "<<pos<<"th postition of list"<<endl;
            }
        pos++;
        temp=temp->next;
    }

    if(!found)
        cout<<"DATA NOT FOUND"<<endl;
}
