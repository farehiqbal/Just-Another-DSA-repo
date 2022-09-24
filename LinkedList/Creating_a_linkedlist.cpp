#include <iostream>
using namespace std;

// void pushAtStart (Node** head_ref, int new_data);
// void printList(Node *node);

// Creating a node.
class Node
{
public:
    int data;
    Node *next; // pointer to the class.

    // Node(int x){
    //     data = x;
    //     next = NULL;
    // }
};


void printList(Node * node){
    while (node != NULL)
    {
    cout << node->data << endl;

    node = node->next;
    }
}


void pushAtStart (Node** head_ref, int new_data){

    // 1. Create a new node

    Node* new_node = new Node();

    // 2. Add data

    new_node -> data = new_data;

    // 3. Make the next of new node as the head

    new_node -> next = (*head_ref);

    // 4. Move head to point to the new node

    (*head_ref) = new_node;
    

}



int main()
{

    // Intialization.
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // Allocate nodes in heap.
    head = new Node();
    second = new Node();
    third = new Node();

    // Assign values
    head->data = 1;
    second->data = 2;
    third->data = 3;

    // Connect nodes.

    head->next = second;
    second->next = third;
    third->next = NULL;

    // Lets print the values now.

   
}

