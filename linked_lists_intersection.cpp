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
	node* insert(node* nd) {
	    // node* temp = creatNode(data);
	    node* temp = nd;
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

node* find_intersect(linkedList& l1, linkedList& l2)
{
  
  return NULL;  
}



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
	linkedList l1, l2; // creating object 
	int data;
	int ino = 0;
	int choice;
	do
	{
		cout<<" enter 1 to add elements in the list"<<endl;
		cout<<" enter 2 to display the elements in the list"<<endl;
		cout<<" enter 3 to find intersecting node in both lists"<<endl;
		cout<<"OR enter 4  to exit"<<endl;
		// if (choice == 1) {
		for (int data = 1; data < 10; ++data) {
		    // cout<<"enter the value to enter into the list"<<endl;
		    // cin>>data;
		    node* nd = l.creatNode(data);
		    if (ino % 2) {
		        cout << "Inserting into List 1" << endl;
		        l1.insert(nd);
		    } else {
  		        cout << "Inserting into List 2" << endl;
		    	l2.insert(nd);
		    }

		    if (ino % 4 == 0)
		        l1.insert(nd);
		    ino++;
		}
		// }
		cin>>choice;
		if(choice == 2) {
		l1.display();
		l1.display();
		}
		else if (choice == 3) {
		    node* nd = find_intersect(l1, l2);
		    if (nd == NULL) {
		        cout << "No intersecting node" << endl;
		    } else {
		        cout << "Node intersects at value: " << nd->data << endl;
		    }
		}
		exit(0);
	}while(choice !=3);
	return 0;
} 
