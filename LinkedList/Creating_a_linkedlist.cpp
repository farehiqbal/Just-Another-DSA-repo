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

// NOTE: I have used Node** (double pointer) instead of Node* because we cannot change the value of a
// passed argument within the function. But in most cases we needed to change the value of *head-ref. 
// Thats why we passed the address of head-ref pointer, so we can change what is at that address. 

void reverse(Node** head_ref){

    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;

    while(current != NULL){
        
        next = current -> next;
        current -> next = prev;

        prev = current;
        current = next;

    }

    *head_ref = prev;



}

void deleteCompleteList(Node** head_ref){

    Node* current = *head_ref;
    

    while (current != NULL){

        
        free(current);
        current = current -> next;

    }

    
    *head_ref = NULL;


}

void printList(Node * node){

    while (node != NULL)
    {
    cout << node->data << "->";

    node = node->next;
    }
    cout << endl;
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
    new_node -> next = NULL;

    // 4. Locate the current last node


    // in case there are no nodes in the current list
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

    // 1. Check if the given node is null
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

void deleteSpecificNode(Node** head_ref, int position){

    // Check if list is empty
    if(*head_ref == NULL){
        return;

    }

    Node* temp = *head_ref;

    // if head needs to be removed

    if (position == 0){
        *head_ref = temp -> next;

        free(temp);
        return;

    }

    // lets find the previous node of the node to be deleted

    for (int i = 0; temp != NULL && i < position - 2 ; i++){
        temp = temp -> next;
    }

    // if position > no of nodes 

    if (temp == NULL || temp -> next == NULL){
        return;
    }

    Node* next = temp -> next -> next;

    free(temp -> next);

    temp ->next = next;

}



// Deleting from start means simply pointing the head to second node

void deleteFromStart(Node** head){

    Node* temp;

    // If linked list is empty

    if(head == NULL || *head == NULL) return;

    temp = *head;

    *head = (*head) -> next;

    free(temp);
    

}

void deleteFromEnd2(Node* head){

    if (head == NULL){
        cout << "No node to dlete";
        return;
    }

    if (head -> next == NULL){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp -> next -> next != NULL){

        temp = temp -> next;


    }

    free (temp -> next);
    temp -> next = NULL;

}

void deleteFromEnd(Node *head){

    // Case 1 when there are no nodes in list
    if (head == nullptr){
        cout << "No nodes to be deleted" << endl;

    }

    // Case 2 when there is a single node
    if (head -> next == nullptr){
        delete head;
        head = nullptr;

    }
    // case 3: 

    // if there are two or more than two nodes than you need to the second last node to break the link,
    // and assign the second last node as the last node i.e. make its next point to null.

    // current pointer goes to the last node while the prev pointer points to the second last node
    // and does the work.
    else {
        Node* curr = head, *prev = nullptr;

        while (curr -> next != nullptr)
        {
            prev = curr;            // shifts the prev pointer one step
            // cout << curr->data << " ";
            curr = curr -> next;    // curr goes to the next node.

        }
        
        prev -> next = nullptr;


        delete curr;
    }
}



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

void insertAfterSpecifc(Node* head, int nodeValue, int new_data){}
void insertBeforeSpecific(){}
void deleteAfterSpecific(){}
void deleteBeforeSpecific(){}
Node* getNode(Node*head, int value){}
void reverseWithRecursion(){
    
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
    
    
// string dialog = "1. Insert at end.\n
//                 2. Insert at start.\n
//                 3. Display.\n
//                 4. Delete at Start.\n
//                 5. Delete at End.\n
//                 0. Exit.\n";
// while(true)
//     {
//         cout << dialog;
//         cin >> opt;
//         switch (opt)
//         {
//         case 1:
//             insert_end();
//             break;
//         case 2:
//             insert_start();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             delete_start();
//             break;
//         case 5:
//             delete_end();
//             break;
//         case 0:
//             exit(3);
//         }
//     }

    printList(head);
    // deleteFromEnd(head);
    // printList(head);
    // insertAtEnd(&head, 4);
    deleteFromEnd2(head);
    printList(head);

}

