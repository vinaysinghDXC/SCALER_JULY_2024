// https://scaler.com/academy/mentee-dashboard/class/236130/assignment/problems/18384?navref=cl_tt_nv

// Problem Description

// Given a Binary Search Tree(BST) A. If there is a node with value B present in the tree delete it and return the tree.

// Note - If there are multiple options, always replace a node by its in-order predecessor


// Problem Constraints

// 2 <= No. of nodes in BST <= 105
// 1 <= value of nodes <= 109
// Each node has a unique value


// Input Format

// The first argument is the root node of a Binary Search Tree A.
// The second argument is the value B.


// Output Format

// Delete the given node if found and return the root of the BST.


// Example Input

// Input 1:

//             15
//           /    \
//         12      20
//         / \    /  \
//        10  14  16  27
//       /
//      8

//      B = 10

// Input 2:

//             8
//            / \
//           6  21
//          / \
//         1   7

//      B = 6



// Example Output

// Output 1:

//             15
//           /    \
//         12      20
//         / \    /  \
//        8  14  16  27

// Output 2:

//             8
//            / \
//           1  21
//            \
//             7



// Example Explanation

// Explanation 1:

// Node with value 10 is deleted 
// Explanation 2:

// Node with value 6 is deleted 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* findMax(TreeNode* A) {
    while (A->right != NULL) {
        A = A->right;
    }
    return A;
}

TreeNode* Solution::solve(TreeNode* A, int B) {
        if (A == NULL) return A;  // Base case: empty tree
        
        if (B < A->val) {   // Traverse to the left subtree if the value to delete is smaller
            A->left = solve(A->left, B);
        }
        else if (B > A->val) {  //else traverse right
            A->right = solve(A->right, B);
        }
        else {
            if (A->left == NULL) {  // Node is a leaf node or has only one child
                TreeNode* temp = A->right;
                delete A;
                return temp;
            }
            else if (A->right == NULL) {
                TreeNode* temp = A->left;
                delete A;
                return temp;
            }

            // Node has two children Find the in-order predecessor
            TreeNode* temp = findMax(A->left);

            // Replace the current node's value with the in-order predecessor's value
            A->val = temp->val;

            // Delete the in-order predecessor from the left subtree
            A->left = solve(A->left, temp->val);
        }

        return A;
}
