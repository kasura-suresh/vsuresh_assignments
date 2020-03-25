/****************************************
 c++ programe to implement linkedList 
 using structure and class 
 author :Md Shakil Ansari ;date- 5 mar,2020 
 ****************************************/

#include<iostream>
using namespace std;
struct node // making a node of structure type
{
    int data;
    node *next;
};	
class linkedList
{
	private :
	node *START;
	public :
	linkedList( ) //constructor to intialize the start pointer
	{
		START = NULL ;
	}
	node* creatNode(int data)
	{
		node *temp;
		temp = new node ; // allocating memory to the new node 
		temp->data = data ;
		temp->next = NULL ;
		return temp;
	}
	node* insert(int data) {
	    node* temp = creatNode(data);
		if(START == NULL)
	        START = temp ; //makes new node as the first node
	    else {
	    	node *ptr ;
	    	ptr = START ; //for not disturbing START pointer
	    	while(ptr->next != NULL) // checks the last node of the list
	    	  ptr = ptr->next ;
	    	ptr->next = temp ; // inserts the new node at end
		}
		return temp;
	}
		void display()
		{
			if (START == NULL) // checks whether the list is empty
			cout<<"sorry... the list is empty"<<endl;
			node *ptr;
			ptr = START ;
			while(ptr != NULL) // untill reaches the end of the list 
			{
			cout<<ptr->data<<" "; //prints the data of currently pointed node
			ptr = ptr->next ; // after printing , points to the next node
		        }
			
		}
	void remove(int rem_data) {
	    if (START == NULL)
	        return;
	    node* curr = START;
	    node* prev = NULL;
	    while (curr != NULL && curr->data != rem_data) {
	        prev = curr;
	        curr = curr->next;
	    }
	    if (curr != NULL) {
	        if (curr == START)
	            START = START->next;
	        else
	            prev->next = curr->next;
	        delete curr;
	    }
	}
	
}; 

class Stack : public linkedList {
    public:
        node* push(int dat) {
            node* temp = creatNode(dat);
            temp->next = START;
            START = temp;
        }
        void pop() {
            if (START != NULL)
                remove(START->data);
            if (START == NULL)
                rear = NULL;
        }
};

class Queue : public Stack {
    // START of list is the front of the Queue
    node* rear{NULL};
    public:
        void push(int dat) {
            rear = insert(dat); // called the list insertion
                // Set the rear??
        }
};


int main()
{
	linkedList l; // creating object 
	int data;
	int choice;
	do
	{
		cout<<" enter 1 to add elements in the list"<<endl;
		cout<<" enter 2 to display the elements in the list"<<endl;
		cout<<"OR enter 3  to exit"<<endl;
		cin>>choice;
		if (choice == 1) {
		    cout<<"enter the value to enter into the list"<<endl;
		    cin>>data;
		    l.creatNode(data);
		}
		else if(choice == 2)
		l.display();
		else
		exit(0);
	}while(choice !=3);
	return 0;
} 
