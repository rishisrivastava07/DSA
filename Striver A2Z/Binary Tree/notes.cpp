/* Lect - 01

    Types of Binary Trees -
    1. Full Binary Trees = either has 0 or 2 children
    2. Complete Binary Tree =
        a. all levels are completely filled except the last level
        b. the last level has all nodes in left as possible
    3. Perfect Binary Tree = all leaf nodes are at the same level
    4. Balanced Binary Tree = height of tree at max of log(N) - where N is nodes
    5. Degenerate Tree = like skew trees (every nodes has its one child nodes)
*/

/* Lect - 02

    Struct Node{
        // Defining value of the node.
        int data;

        // Left reference ptr to the node.
        Struct Node* left;

        // Right reference ptr to the node.
        Struct Node* right;

        // Method to initialize the above values.
        Node (int val)
        {
        data = val;
        left = right = NULL;
        }
    };

    main()
    {
        // Creating a new node by using dynamic allocation.
        Struct Node* root = new Node(1);
        root -> left = new Node(2);
        root -> right = new Node(3);
        root -> left -> right = new Node(5);
    }
*/

/* Lect - 03
                1
              /   \
            2      3
          /  \   /  \
         4    5 6    7

    Traversal Techniques - (BFS / DFS)
    1. Inorder Traversal (left Root Right) = 4 2 5 1 6 3 7
    2. Pre-order Traversal (Root Left Right) = 1 2 4 5 3 6 7
      -> time complexity = O(N)
      -> space
    3. Post-order Traversal (Left Right Root) = 4 5 2 6 7 3 1
*/

/* Lect - 8
    Level Order Traversal

*/

/* Lect - 9
    A. Preorder Traversal
    Iterative Traversal - using stack data structure
    1. Take a stack (LIFO)
    2. whatever is the root of tree -> put into stack
    3. start traversal - take the top of the stack element -> take it out and print it
    4. then take its right and then its left and put it into the stack (for pre order reverse will be done for post order)
 */

/* Lect - 10
    B. Inorder Traversal
    Iterative Traversal - using stack data structure
    1. Take a stack datastructure and also a node initialised at root
    2. Every step of iteration take the whatever is at node  
    3. if(node != NULL) take it put into stack and move left
    4. else print stack top reassign to right of that node
    5. now move on right
*/

/* Lect - 11
    C. PostOrder Traversal
    Iterative Traversal - using 2 stack data structure
    1. Take 2 stacks st1 and st2
    2. Take the root of tree and put it in stack 1
    3. Take out from top of st1 -> put in st2
    4. Take its left and then right if empty don't put
    5. Time Complexity O(N)

    Iterative Traversal - using 1 stack data structure
    1. we try here always go left left left left .... till null then go right
    2. Again then go left left left left ... till encountered right and repeat same
    3. TC - O(2N) & SC - O(N)

    pseudo code -
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                post.add(temp->val);

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    post.add(temp->val);
                }
            }
            else{
                curr = temp;
            }
        }
    }
*/

/* Lect - 13
    Pre In Post order traversal in one Traversal

    1. We will use a stack data structure (LIFO).
    2. in this we will store {node,number} in it.
    3. Create 3 different list pre, in and post.
    4. Insert the root node and number as 1.
    5. Some Rules -
        if(num == 1){
            take in preOrder
            num++
            push(left) if exsist
        }
        if(num == 2){
            take in inOrder
            num++
            push(right) if exsist
        }
        if(num == 3){
            take in postOrder
            pop out the top element no need further
        }
    6. Every iteration take out the top most element from the stack
    7. TC - O(3N) SC - O(4N)
*/

/*  Lect - 14
    Maximum Depth in Binary Tree || Height of Binary Tree
    
    -> either use recursive {in which the auxillary space is O(height of tree)} or level-order traversal {which will take time complexity of O(N)}
    -> might take up same complexity in worst case

    Generally we use Recursive Traversal Techniques
    1. On standing on first node, we can say that 1 + max(left sub-tree, right sub-tree)
    2. At first we will move to the left and then right

    Lect - 15
    Similarly we can check that if it is a Balanced Binary Tree or Not

    -> two conditions extra we need to check 
    -> if(lh == -1 || rh == -1) return -1;
    -> if(abs(lh-rh) > 1) return -1;

    // this check will allow the search to be sort in O(N) 
    // and also not search further if it detects incomplete binary tree
*/

/**
 * Lect - 16 
 * Diameter of Binary Tree 
 * -> longest path between any two nodes
 * -> also this path doesnot need to pass via root (can pass or cannot pass both allowed)
 * 
 * Steps -
 * Knife Approach -
 *  1. Standing on every node just check left side of the tree and right side and add both and get max of the tree at that particular node
 *  2. Get the maximum of all those paths calculated at each node.
 * 
 * Brute-Force Approach -
 *  1. Standing on each, just traverse to its leaf node for left sub-tree and similarly for the right sub-tree
 *  2. now declare at the begining a maxi variable and pass it as reference
 *  3. at each recursive call just traverse and find the maxi = max(maxi,lh+rh)
 *  4. At the end after traversing we might ended up to get a TC - O(N*N)
 * 
 * Optimised Approach -
 * 
 * int findMax(node, maxi){
 *      if(node == null)
 *          return 0;
 *      
 *      lh = findMax(node->left, maxi);
 *      rh = findMax(node->right, maxi);
 *      maxi = max(maxi, lh+rh);
 * 
 *      return (1+max(lh,rh));
 * }
*/

/**
 * Lect - 17 - Maximum Path Sum in Binary Tree
 * 
 * Path means every node is appeared once during traversal
 * There can be multiple paths and we need to find out the maximum summation of paths
 * 
 * Brute Force -
 * Try to check the every possible combination paths between two nodes and check the maximum path in it.
 * But it result in much more complex if we have N nodes then we need to traverse N^2 times
 * 
 * To get better results we need to apply here -
 * i. Maximum height of Binary Tree
 * ii. Maximum width (or diameter) of Binary Tree
 * 
 * pseudo code -
 *  int maxPathDown(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int leftSumDown = max(0, maxPathDown(root->left, maxi));
        int rightSumDown = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, root->val + leftSumDown + rightSumDown);

        return (root->val + max(leftSumDown, rightSumDown));
    }
*/

/**
 * Lect - 18 - Check if two trees are identical or Not
 * 
 * We need to check tree 1 and tree 2 are identical or not
 * We just need to do traversal but must be equal traversal
 * 
 * bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return p == q;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
*/

/**
 * Lect - 19 - Zig-Zag traversal
 * 
 * Steps -
 * we need to take a queue 'q' data structure. and store root of the tree
 * also take a vector 'ds' and return this is an answer
 * We will use flag variable for moving left to right or right to left
 * flag initially value = 1
 * and check it flag value { if(1) - move left to right and if(0) - move right to left}
 * first time checkout the element check for left insert into queue if present
 * similarly for the right side
 * insert into the ds
 * Now, update the flag value after one level is completely inserted into the queue
 * 
*/

/**
 * Lect - 20 - Boundary traversal
 * traverse anticlockwise
 * 
 * steps -
 * first take the left boundary (since its an anticlockwise) excluding the leaf nodes
 * after that take leaf nodes
 * then take right boundary in reverse direction also exlude the leaf nodes k
 * 
 * first traverse the left side of the tree if not exist then traverse to the right and continue this
 * in case no left right sub tree is present then it is a leaf node ignore it
 * traverse the leaf nodes in INORDER traversal
 * Now take a temporary vector for storing the right sub tree
 * Traverse this first right right right until right is null and then left again first check right
 * if both right and then left is NULL it is leaf node ignore it. STOP here
 * now then push the temporary vector data to main vector where the boundary order traversal is stored.
 * return the result.
*/