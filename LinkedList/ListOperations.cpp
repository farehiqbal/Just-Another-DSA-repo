#include <iostream>
using namespace std;

class ListOperations{

    class Node{
        public:
        int data;
        Node *next;
    };

    
    // Add new node at front

    void insertAtStart (Node** head_ref, int new_data){

        // 1. Create a new node

        Node* new_node = new Node();

        // 2. Add data

        new_node -> data = new_data;

        // 3. Make the next of new node as the head

        new_node -> next = (*head_ref);

        // 4. Move head to point to the new node

        (*head_ref) = new_node;
        

    }


    // Also called append
    void insertAtEnd(Node** head_ref, int new_data){
        // 1. Creating a new node

        Node* new_node = new Node();

        // Will use this last pointer to get to the end of list
        Node* last  = *head_ref;

        // 2. Enter data.
        new_node -> data = new_data;

        // 3. Since the next of last node is always null
        new_node -> data = NULL;

        // 4. Locate the current last node

        if(*head_ref == NULL){
            *head_ref = new_node;
            return;
        }

        while ( last -> next != NULL){
            last = last -> next;


        }
        
        // 5. Change the last node to the newly added node.
        last -> next = new_node;



    }


    void insertAfter(Node* prev_node, int new_data){

        // 1. Check
        if (prev_node == NULL){
            cout << "The given previous node cannot be null";
            return;

        }
        // 2. Create new node
        Node* new_node = new Node();

        // 3. Add data

        new_node -> data = new_data;

        // 4. Make next of new node as next of prevnode
        new_node -> next = prev_node -> next;

        // 5. next of prev node as new_node

        prev_node -> next = new_node;


    }


    bool SearchInList(Node** head_ref, int key){

        Node* curr = *head_ref;

        while (curr != NULL) {
            if (curr -> data == key) return true;
                curr = curr -> next;

        }

        return false;

    }

};
