#include <iostream>
using namespace std;

class ListOperations{

    class Node{
        public:
        int data;
        Node *next;
    };

    
    // Add new node at front

    void Push (Node** head_ref, int new_data){

        // 1. Create a new node

        Node* new_node = new Node();

        // 2. Add data

        new_node -> data = new_data;

        // 3. Make the next of new node as the head

        new_node -> next = (*head_ref);

        // 4. Move head to point to the new node

        (*head_ref) = new_node;
        

    }


};
