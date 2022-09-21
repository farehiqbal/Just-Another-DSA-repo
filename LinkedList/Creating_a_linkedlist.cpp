#include <iostream>

using namespace std;

// Creating a node.
class Node
{
public:
    int value;
    Node *next; // pointer to the class.
};

// struct node {
//     int data;
//     struct node *next;

// };

int main()
{

    // Intialization.
    Node *head;
    Node *one = NULL;
    Node *two = NULL;
    Node *three = NULL;

    // Allocate nodes in heap.
    one = new Node();
    two = new Node();
    three = new Node();

    // Assign values.
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes.

    one->next = two;
    two->next = three;
    three->next = NULL;

    // Lets print the values now.

    head = one;

    while (head != NULL)
    {
        cout << head->value << endl;

        head = head->next;
    }
}