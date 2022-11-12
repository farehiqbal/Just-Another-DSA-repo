#include <iostream>

using namespace std;

class Node{
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

    
};

int main(){

    Node* root = NULL;

}