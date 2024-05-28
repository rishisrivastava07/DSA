#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// recursive way
Node *builtTree(Node *root)
{
    cout << "Enter the data for node " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << root->data << endl;
    root->left = builtTree(root->left);

    cout << "Enter data for inserting in right of " << root->data << endl;
    root->right = builtTree(root->right);

    return root;
}

// level order traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // separator

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) // purana level complete ho chuka hai
        {
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // isko yahan print issliye kiya kyuki agr hm q.pop() ke phele krnege to chances hai woh temp value NULL hoskta hai
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// inorder traversal
void inOrderTraversal(Node *root)
{
    // Recursive Way
    /*
    // base cond.
    if (root == NULL)
    {
        return;
    }

    // recursive cond.
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
    */
    // Iterative way
    stack<Node *> st;
    Node *curr = root;

    st.push(curr);

    while (!st.empty())
    {
        if (curr->left)
        {
            curr = curr->left;
            st.push(curr);
        }
        else
        {
            Node *temp = st.top();
            st.pop();
            curr = temp;

            cout << curr->data << " ";

            if (curr->right)
            {
                curr = curr->right;
                st.push(curr);
            }
        }
    }
}

// preorder traversal
void preOrderTraversal(Node *root)
{
    /*
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    */

    // Iterative Way
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        cout << curr->data << " ";
        st.pop();

        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
}

// post order traversal
void postOrderTraversal(Node *root)
{
    /*
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
    */

    // Iterative Way
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();

        st2.push(curr);
        if (curr->left)
        {
            st1.push(curr->left);
        }
        if (curr->right)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty())
    {
        Node *curr = st2.top();
        st2.pop();
        cout << curr->data << " ";
    }
}

// built a tree from a given level order
void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// main
int main()
{
    Node *root = NULL;

    root = builtTree(root);

    // built tree from level order traversal
    // buildFromLevelOrder(root);
    // 1 3 5 7 11 -1 -1 -1 -1 -1 -1
    // levelOrderTraversal(root);
    // creating a tree

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order
    // cout << "Level Order Traversal for the Binary Tree " << endl;
    // levelOrderTraversal(root);

    // inorder traversal
    cout << "\nIn Order Traversal for the Binary Tree " << endl;
    inOrderTraversal(root);

    // preorder traversal
    cout << "\nPre Order Traversal for the Binary Tree " << endl;
    preOrderTraversal(root);

    // postorder traversal
    cout << "\nPost Order Traversal for the Binary Tree " << endl;
    postOrderTraversal(root);
    return 0;
}