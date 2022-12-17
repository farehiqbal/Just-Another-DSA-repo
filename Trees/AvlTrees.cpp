#include <iostream>

using namespace std;

class Node{
    public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(){
        key = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }

    Node(int key){
        Node* node = new Node();
        node -> key = key;
        node -> height = 1;
        node -> left = NULL;
        node -> right = NULL;

    }                            

};


Node* getNewNode(int key){

    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    
    return node;

}

// get height of a specific node.
int getHeight(Node* node){
    
    if (!node) return 0;

    return node -> height;
}

// simple method max of two integers

int max(int a, int b){

    return (a > b)? a: b;
}

int getBalanceFactor(Node* node){

    if(node == NULL) return 0;

    return getHeight(node ->left) - getHeight(node ->right);

}

Node* rotateRight(Node* y){
    Node* x = y ->left;
    Node* T2 = x ->right;

    x ->right = y;
    y->left = T2;

    x->height = 1 + max(getHeight(x-> left), getHeight(x -> right));
    y->height = 1 + max(getHeight(y-> left), getHeight(y -> right));

    return x;
}

Node* rotateLeft(Node* x){
    Node* y = x ->right;
    Node* T2 = y -> left;

    y ->left = x;
    x -> right = T2;

    x->height = 1 + max(getHeight(x-> left), getHeight(x -> right));
    y->height = 1 + max(getHeight(y-> left), getHeight(y -> right));

    return y;
}


Node* insert(Node* root, int key){
    
    if(root == NULL){
        return getNewNode(key);
    }
    else if (key < root -> key){
        root -> left = insert(root ->left, key);
    }
    else if(key > root ->key){
        root -> right = insert(root -> right, key);
    }
    else return root; // no duplicates are allowed.

    // now we need to update to update the height of each node.

    root -> height = 1 + max (getHeight(root -> left), getHeight(root ->right));

    int bf = getBalanceFactor(root);

    if(bf > 1 && key < root -> left -> key) return rotateRight(root);

    if(bf <-1 && key > root-> right ->key) return rotateLeft(root);

    if(bf > 1 && key > root ->left -> key){
        root -> left = rotateLeft(root ->left);
        return rotateRight(root);
    }

    if(bf < -1 && key < root ->right -> key){
        root ->right = rotateRight(root ->right);
        return rotateLeft(root);
    }

    return root;

}

Node* FindMin(Node* root){

	while(root->left != NULL) root = root->left;
	return root;
}


Node* deleteNode(Node* root, int data){

    if(!root) return root;
    
    else if(data < root -> key) root ->left = deleteNode(root ->left, data);

    else if (data > root -> key) root -> right = deleteNode(root -> right, data);
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
            root -> key = temp ->key;
            root -> right = deleteNode(root ->right, temp -> key);
        }
    }

    if (!root) return root;

    // update the height of each node
    root -> height = 1 + max (getHeight(root -> left), getHeight(root ->right));

    int bf = getBalanceFactor(root);

    if(bf > 1){
        if(getBalanceFactor(root ->left ) >= 0){
            return rotateRight(root);
        }
        else{
            root ->left = rotateLeft(root ->left);
            return rotateRight(root);
        }
    }


     if (bf < -1) {
        if (getBalanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    } else {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
  }


    return root;

}


void printTree(Node *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}



void preOrder(Node* root){

    if (root != NULL) {
        cout << " " << root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){
    
    Node* root = NULL;
    

    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);

    printTree(root, "", true);
    // preOrder(root);
    deleteNode(root, 3);
    printTree(root, "", true);
}