#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// level order traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // separator

    while (!q.empty()){
        Node *temp = q.front();
        q.pop();

        if (temp == NULL){ // purana level complete ho chuka hai
            cout << endl;
            if (!q.empty()){
                // queue still has some child
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " "; // isko yahan print issliye kiya kyuki agr hm q.pop() ke phele krnege to chances hai woh temp value NULL hoskta hai
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

// inorder traversal
void inOrderTraversal(Node *root){
    // base cond.
    if (root == NULL)    {
        return;
    }
    // recursive cond.
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// preorder traversal
void preOrderTraversal(Node *root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// post order traversal
void postOrderTraversal(Node *root){
    if (root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// get min val from BST
Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp -> left;
    }
    return temp;
}

// get max val from BST
Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp -> right;
    }
    return temp;
}

int successor(Node *root, int key){
    if(root == NULL) return -1;
    int succ = -1;
    while(root != NULL){
        if( key >= root->data){
            root = root->right;
        }
        else {
            succ = root->data;
            root = root->left;
        }
    }
    return succ;
}

int pred(Node *root, int key){
    if(root == NULL) return -1;
    int preds = -1;
    while(root != NULL){
        if(key > root->data){
            preds = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return preds;
}
pair<int, int> predecessorSuccessor(Node *root, int key){
    if(root == NULL)return {-1,-1};
    return make_pair(pred(root,key),successor(root,key));
}

Node* insertIntoBST(Node* root, int data){
    // base case
    if(root == NULL){
        // jab pheli bari uss node ko create krne ke liye hai base case
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        // right part mein insert karna hai
        root->right = insertIntoBST(root->right, data);
    }
    if(data < root->data){
        // left part mein insert karna hai
        root->left = insertIntoBST(root->left, data);
    }

    return root;

}

Node* deleteNodeFromBST(Node* root, int val){
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right != NULL){
            // ya to left subtree se maximum node lao ya rightsubtree se minimum aur usse replace krdo node se
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteNodeFromBST(root->right, mini);
            return root;
        }
    
    }
    else if(root->data < val){
        // right mein jao
        root->right = deleteNodeFromBST(root->right, val);
        return root;
    }
    else{
        // left mein jao
        root->left = deleteNodeFromBST(root->left, val);
        return root;
    }
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main(){
    Node* root = NULL;

    // 10 7 15 5 9 16 17 19 -1

    cout << "Enter data to create BST : (Use -1 to end the input string)" << endl;
    takeInput(root); 

    // cout << "Printing BST in Level Order Traversal" << endl;
    // levelOrderTraversal(root);
    
    cout << "Printing BST in In Order Traversal" << endl;
    inOrderTraversal(root);
    
    // cout << endl << "Printing BST in Pre Order Traversal" << endl;
    // preOrderTraversal(root);
    
    // cout << endl << "Printing BST in Post Order Traversal" << endl;
    // postOrderTraversal(root);

    // cout << "Min value of BST : " << minVal(root) -> data << " & Max value of BST : " << maxVal(root) -> data << endl;
    // pair<int, int> ans = predecessorSuccessor(root, 9);
    // cout << "Inorder Predecessor : " << ans.first << endl;
    // cout << "Inorder Successor : " << ans.second << endl;

    cout << endl << "Delete the node = " << endl;
    int x;
    cin >> x;
    root = deleteNodeFromBST(root, x);

    cout << endl << "Printing BST in In Order Traversal" << endl;
    inOrderTraversal(root);
    return 0;
}