#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;
};


void printReverse(Node* head) {
        if (head == NULL) {
            return;
        }
        
        if (head->next == NULL) {
            cout << head->next;
            return;
        }
        
        Node* last = head;
        
        while (last->next != NULL){
            last = last->next;
        }
        
        Node* temp;
        Node* temp2;
        
        while(last != head) {
            temp = head;
            temp2 = NULL;
            while (temp != last){
                temp2 = temp;
                temp = temp->next;
            }
            cout << temp->data << "->";
            last = temp2;
        }
        cout << head->data;

    }

 


void printList(Node* head){

    Node* temp = head;

    while (temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
}   

Node* Reverse(Node** head){

    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;

    while(curr != NULL){

        next = curr -> next;
        curr -> next = prev;


        prev = curr;
        curr = next;
        
    }
     
     
    *head = prev;
    return *head;
    
}

void removeDuplicatesV2(Node *head){

    if(head == nullptr){
        cout<<"List Empty!";
        return;
    }
    Node *ptr1 = nullptr;
    Node *temp = new Node();
    Node *ptr2;

    while(head != nullptr){
        ptr2 = head;
        ptr1 = head->next;
        while(ptr1 != nullptr){
            if(head->data == ptr1->data){
                temp = ptr1;
                ptr2->next = ptr1->next;
                ptr1 = ptr1->next;
                delete(temp);
            }
            else{
                ptr2 = ptr1;
                ptr1 = ptr1->next;
            }
        }
        head = head->next;
    }
}

Node* nthPositionReturner(Node* head, int n){

    Node* fast = head;
    Node* slow = head;

    if(head == nullptr){
        return slow = nullptr;

    }

    for(int i = 0; i < n; i++){
        fast = fast -> next;

    }

    if (fast == nullptr){
        return slow = nullptr;

    }

    while(fast -> next != nullptr){


        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}




void removeDuplicates(Node* head){

    Node* ptr1 = head;
    Node* ptr2 = NULL;
    Node* temp;
    while(ptr1 != NULL && ptr1 -> next != NULL){

        ptr1 = ptr2;

        while(ptr2 -> next != NULL){

            if (ptr1 -> data = ptr2 -> next -> data){

                temp = ptr2 -> next;

                ptr2 -> next = ptr2 -> next -> next;

                delete temp;
            }
            else{
                ptr2 = ptr2 -> next;

            }
 
        }

         ptr1 = ptr1 -> next;
    }

    printList(head);
    

}



Node* removeNthFromEnd(Node* head, int n){

    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast -> next;

    }

    while (fast -> next != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }
   
    Node* temp = slow -> next;
    slow -> next = slow -> next -> next;

    delete temp;

    return head;

    

}


 
// nth - 1 node.
Node* nthValueFromEnd(Node* head, int n){

    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast -> next;
    }
    
    while(fast -> next != NULL){

        fast = fast -> next;
        slow = slow -> next;
    
    }

    return slow;

}

void SplitEvenAndOdd(Node* head){

    Node* bufferOdd = new Node();
    Node* bufferEven = new Node();

    Node* tempOdd = bufferOdd;
    Node* tempEven = bufferEven;

    int addedLast = 0;

    while(head != NULL){
        if(head -> data & 1 == 1){
            tempOdd -> next = head;
            tempOdd = tempOdd ->next;
            addedLast = 0;
        }
        else{
            tempEven -> next = head;
            tempEven = tempEven -> next;
            addedLast = 1;

        }
        head = head -> next;
    }
    addedLast == 0 ? tempOdd -> next = NULL : tempEven -> next = NULL;
    printList(bufferEven -> next);
    cout << endl;
    printList(bufferOdd -> next);
}



Node* Intersection(Node* head1, Node* head2){

    Node* buffer = new Node();
    
    buffer -> data = 0;
    buffer -> next = NULL;
    Node* temp = buffer;
    Node* dummy = head2;

    while(head1 != NULL){
        head2 = dummy;
        while(head2 != NULL){

            if (head1 -> data == head2 -> data){
                temp -> next = head1;
                // printList (temp);
                temp = temp -> next;
            }

            head2 = head2 -> next;
        }

        head1 = head1 -> next;

    }
    temp -> next = NULL;

    return buffer -> next;
}

void menu(){
    cout 
    << "1. Display list" << endl
    << "2. Display in reverse" << endl
    << "3. Reverse linked list" <<endl
    << "4. Split even and odd from list" << endl
    << "5. Find intersection of lists" << endl
    << "6. Remove nth from end"<<endl;
    
}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;


    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head -> data = 1;
    second -> data = 2;
    third -> data = 2;
    fourth -> data = 4;

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = NULL;


    Node* head2 = NULL;
    Node* second2 = NULL;
    Node* third2 = NULL;

    head2 = new Node();
    second2 = new Node();
    third2 = new Node();


    head2 -> data = 2;
    second2 -> data = 3;
    third2 -> data = 4;

    head2 -> next = second2;
    second2 -> next = third2;
    third2 -> next = NULL;
    
    bool flag = true;
    
   do
   {
        menu();
        cout <<endl;

        cout << "Enter choice:"<< endl;
        int choice;
        cin >> choice;
        if (choice == 0) flag = false;

        switch (choice)
        {
        case 1:
            printList(head);
            cout <<endl << "\n";
            break;
        case 2:
            printReverse(head);
            cout << endl << "\n";
            break;
        case 3:
            printList(Reverse(&head));
            cout << endl << "\n";
            break;
        case 4:
            SplitEvenAndOdd(head);
            cout << endl << "\n";
            break;
        case 5:
            printList(Intersection(head, head2));
            cout << endl << "\n";
            break;
        case 6:
            cout << "Enter nth node from end: ";
            int n;
            cin >> n;
            printList(removeNthFromEnd(head, n));
            cout <<endl<< "\n";

        default:
            break;
        }
   } while (flag);
   
   

}