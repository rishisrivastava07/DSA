#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

// printing inorder binary tree
void inorderBTT(struct Node* root){
    struct Node* ptr = root;

    if(ptr == NULL){
        return;
    }

    inorderBTT(ptr->left);
    cout << (ptr->data) << " ";
    inorderBTT(ptr->right);
}
// printing preorder binary tree
void preorderBTT(struct Node* root){
    struct Node* ptr = root;

    if(ptr == NULL){
        return;
    }

    cout << (ptr->data) << " ";
    preorderBTT(ptr->left);
    preorderBTT(ptr->right);
}
// printing postorder binary tree
void postorderBTT(struct Node* root){
    struct Node* ptr = root;

    if(ptr == NULL){
        return;
    }

    postorderBTT(ptr->left);
    postorderBTT(ptr->right);
    cout << (ptr->data) << " ";
}

int main(){
    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal " << endl;
    inorderBTT(root);
    cout << endl;
    cout << "Pre-Order Traversal " << endl;
    preorderBTT(root);
    cout << endl;
    cout << "Post-Order Traversal " << endl;
    postorderBTT(root);
    cout << endl;
    return 0;    
}