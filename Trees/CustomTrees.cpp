#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node* getNewNode(int data){
        
        Node* newNode = new Node();
        newNode -> data = data;
        newNode -> left = NULL;
        newNode -> right = NULL;

        return newNode;
    }

    Node* insertNode(Node* root, int data){

        if (root == NULL){
            return getNewNode(data);
        }

        else if (data <= root->data){
            root -> left = insertNode(root->left , data);
        }

        else {
            root -> right = insertNode(root -> right, data);
        }

        return root;
    }

    bool searchNode(Node* root, int key){
        
        if(root == NULL) return false;

        else if (root->data == key) return true;

        else if (root -> data <= key) return searchNode(root -> left, key);

        else return searchNode(root ->right, key);
    }

    void inOrder(Node* root){

        if (root != NULL){
            inOrder(root ->left);
            cout << root -> data << " ";
            inOrder(root -> right);
        }
    }

    void preOrder(Node* root){

        if (root != NULL) {
            cout << " " << root->data;
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node* root){

        if (root != NULL) {
            preOrder(root->left);
            preOrder(root->right);
            cout << " " << root->data;
        }
    }

    Node* FindMin(Node* root)
    {
	while(root->left != NULL) root = root->left;
	return root;
    }

    // Delete node with 2 children:
    /*
    1. find min in right subtree
    2. copy that value targeted node.
    3. delete duplicate from right subtree
    */

    Node* deleteNode(Node* root, int data){

        if(!root) return root;
        
        else if(data < root -> data) root ->left = deleteNode(root ->left, data);

        else if (data > root -> data) root -> right = deleteNode(root -> right, data);
        // node is found till here
        else{
            // case 1: Leaf node
            if(root ->left == NULL && root -> right == NULL){
                delete root;
                root = NULL;
                
            }
            // Case 2: node with one child
            else if(root -> left == NULL){
                Node* temp = root;
                root = root -> right;
                delete temp;
                
            }
            else if(root -> right == NULL){
                Node* temp = root;
                root = root -> left;
                delete temp;
                
            }

            // case 3: Node with two child
            else{
                Node* temp = FindMin(root -> right);
                root -> data = temp ->data;
                root -> right = deleteNode(root ->right, temp -> data);
            }
        }

        return root;
    }

    void printInRange(Node* root, int X, int Y){

        if(root == NULL) return;

        if(root->data >= X && root -> data <= Y){
            printInRange(root-> left, X, Y);
            cout << root -> data << " ";
            printInRange(root -> right, X ,Y); 
        }

        else if(root -> data >= Y){
            printInRange(root->left, X, Y);
        }

        else printInRange(root-> right, X, Y);
    }

    int countLeaves(Node* root){

        if (!root) return 0;

        if(!root->left && !root->right) return 1;

        return countLeaves(root ->left) + countLeaves(root-> right);
    }

    void printLeaves(Node* root){
        
        if(!root) return;

        if(!root ->left && !root-> right){
            cout<< root -> data<< " ";
            return;
        }

        // if left child exists, check for leaf
        if(root -> left){
            printLeaves(root ->left);
        }

        // similarly
        if(root -> right){
            printLeaves(root->right);
        }
    }
};

int main(){

    Node* root = NULL;

    Node tree;

    int values[] = {5,3,6,1,2,4};

    for (int i = 0; i < 6; i++)
    {   
        root = tree.insertNode(root, values[i]);
    }

    tree.inOrder(root);
    
}