#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;

     Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {   
        // this(data,NULL);
        this->data = data;
        this->next = NULL;
    }

};

void printList(Node* head){

    Node* temp = head;

    while (temp != NULL){
        cout << temp -> data << "-> ";
        temp = temp -> next;
    }
    cout <<"NULL";
}   
// Starting from 1 index from start as well 1 from end. No concept of '0' indexed.

Node* mthNodeReturner(Node* head, int m){

    Node* fast = head;
    Node* slow = head;

    if(head == nullptr){
        return slow = nullptr;

    }

    for(int i = 1; i < m; i++){
        fast = fast -> next;

    }

    if (fast == nullptr){
        return slow = nullptr;

    }

    while(fast && fast->next){


        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

Node* swapTwoNodes(Node* head, int n, int m){

    // firstly lets get both of the nodes.

    Node* currN = head; // currN is node from start
    Node* prevN = NULL; // prevN is 1 step behind currN

    for (int i = 1; i < n; i++)
    {
        prevN = currN;
        currN = currN -> next;
    }

    // currM is node from end
    Node* currM = mthNodeReturner(head, m);
    Node* prevM = nullptr;
    Node* temp = head;
    while(temp != currM){
        prevM = temp;
        temp = temp -> next;
    }
    
    // Case1 : if either of them does not exist
    if(!currM || !currN) {
        cout << endl <<"NullPointerException" << endl;
        throw 0;

    }

    // Case2: nth and mth nodes are same
    if(currN == currM){
        cout << endl<< "SwapException" << endl;
        throw 0;
    }


    // first change the next of prev pointers.

    // if n is not the head of list

    if(prevN){
        prevN -> next = currM;
    }
    else{
        head = currM;
    }

    // if m is not the head of list

    if(prevM){
        prevM -> next = currN;
    }
    else{
        head = currN;
    }


    // now swap

    temp = currN ->next;
    currN->next = currM -> next;
    currM ->next = temp;

    return head;

}




int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();

    head -> data = 1;
    second -> data = 2;
    third -> data = 3;
    fourth -> data = 4;
    fifth -> data = 5;
    sixth -> data = 6;

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;

    
    // swapTwoNodes(head, 2, 2);
    printList(swapTwoNodes(head, 7, 7));

}