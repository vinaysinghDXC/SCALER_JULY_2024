// https://www.scaler.com/academy/mentee-dashboard/class/297917/homework/problems/334?navref=cl_tt_nv_dd

// Problem Description

// Given a binary tree A, invert the binary tree and return it.

// Inverting refers to making the left child the right child and vice versa.



// Problem Constraints

// 1 <= size of tree <= 100000



// Input Format

// First and only argument is the head of the tree A.



// Output Format

// Return the head of the inverted tree.



// Example Input

// Input 1:

 
//      1
//    /   \
//   2     3
// Input 2:

 
//      1
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7


// Example Output

// Output 1:

 
//      1
//    /   \
//   3     2
// Output 2:

 
//      1
//    /   \
//   3     2
//  / \   / \
// 7   6 5   4


// Example Explanation

// Explanation 1:

// Tree has been inverted.
// Explanation 2:

// Tree has been inverted.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void swaptree(TreeNode* &A){
    if (A==NULL) return;

    swap(A->left, A->right);
    swaptree(A->left);
    swaptree(A->right);
}

TreeNode* Solution::invertTree(TreeNode* A) {
    swaptree(A);
    return A;
}
