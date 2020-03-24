/*********************************************************
*
*To Calculate the size of the array and array passing
*Author: Akash Kumar Gupta
*Date: 14/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;
class L
{
    public:
    struct Node {
        int data;
        Node *next;
    };
    
    private:
    Node* head{NULL};

public:
    L() : head(NULL) {}
   void insert(int new_data) {
      Node* new_node = (struct Node*) malloc(sizeof(struct Node));
      new_node->data = new_data;
      new_node->next = head;
      head = new_node;
   }
   void remove(int rem_data) {
       if (head == NULL) {
          cout << "Linked list is empty" << endl;
          return;
        }
        Node* curr = head;
        Node* prev = head;
        while (curr != NULL && curr->data != rem_data) {
            prev = curr;
            curr = curr->next;
            /*
            if (curr->next == NULL) {
                cout << "Node is not present" << endl;
                break;
            }
            */
        }
        if (curr == NULL) {
            cout<< "Node is not present" << endl;
        } else {
            if (curr == head) {
                head = head->next;
            } else
                prev->next=curr->next;
            delete curr;
        }
   }
   // Return the Node pointer which has find_data. If not, return NULL
   Node* find(int find_data) {
        Node* curr = head;
        while (curr != NULL && curr->data != find_data)
            curr = curr->next;
        return curr;
   }
   void display() {
     Node* ptr;
     ptr = head;
     while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
     }
     cout << endl;
   }
};

int main() {
   L obj;
   obj.insert(3);
   obj.insert(1);
   obj.insert(7);
   obj.insert(2);
   obj.insert(9);
   cout<<"The linked list is: ";
   obj.display();
   obj.remove(2);
   obj.display();
   int f = 3;
   L::Node nd = obj.find(f);
   // L::NodeIterator nd = obj.begin();
   // if (nd != obj.end())
    // cout << *nd << endl;
   // for(L::NodeIterator nd1 = obj.begin(); nd! != obj.end(); ++nd1) {
       // cout << *nd1;
   // }
   if (nd != NULL)
    cout << "Found node for " << f << endl;
   return 0;
   
   list<int> l;
   l.push_back(5);
   list<int>::iterator li = l.begin();
   if (li != l.end())
    cout << *li << endl;
}
