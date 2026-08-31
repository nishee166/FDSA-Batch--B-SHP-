#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insertatfront(Node *& head , int value)
{  
        Node* newnode = new Node();
               newnode->data = value;
               newnode->next=head;

               head=newnode;
}


void insertatend(Node*& head , int value )
{
       Node * newnode = new Node();
         newnode->data = value;

        
         if(head == NULL)
         {
            insertatfront( head,value);
            return;
         }

                Node* temp = head;

          while(temp->next != NULL)
          {
            temp = temp->next;
          }
           temp->next = newnode;
         
} 
void insertatspecific(Node*& head , int value , int position)
{
              if(position<1)
              {
                cout<<"invalid position";
                return;
              }
               if (position == 1)
               {
                insertatfront(head,value);
                return;
               }

                Node* temp = head;
  

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

     if(temp == NULL)
     {
        cout<<"position is grater than current length"<<endl;
        return;
     }

     Node * newnode  = new Node();
     newnode->data = value;
     newnode->next = temp->next;
       temp->next = newnode;
}
 void display(Node *& head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<<temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head = NULL;  
     int value;  int position ; 
    bool isright = true;  int choice;
    while(isright){

        cout<<"enter 1 for insert at front:"<<endl;
        cout<<"enter 2 for insert at end:"<<endl;
        cout<<"enter 3 to insert at specific position:"<<endl;
        cout<<"enter 4 for exit: "<<endl;

        cout<<"enter your choice ";
        cin>>choice;

       
        switch(choice)
        {
            case 1:
            cout<<"enter your token number";
             cin>>value;

             insertatfront(head,value);
             break;

             case 2:
              cout<<"enter your token number";
               cin>>value;

             insertatend(head , value );
             break;

             case 3:
 
             cout<<"enter the position";
             cin>>position;
             cout<<"enter your token number";
               cin>>value;

             insertatspecific(head , value , position);
             break;

             case 4:
             isright = false;
             break; 

             default :
              cout<<"invalid choice";
              break;
        }
         

    }
    display(head);
}