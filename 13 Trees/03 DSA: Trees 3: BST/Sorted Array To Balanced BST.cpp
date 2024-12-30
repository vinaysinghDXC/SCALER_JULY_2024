// https://www.scaler.com/academy/mentee-dashboard/class/236130/assignment/problems/226?navref=cl_tt_nv

// Problem Description

// Given an array where elements are sorted in ascending order, convert it to a height Balanced Binary Search Tree (BBST).

// Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



// Problem Constraints

// 1 <= length of array <= 100000



// Input Format

// First argument is an integer array A.



// Output Format

// Return a root node of the Binary Search Tree.



// Example Input

// Input 1:

//  A : [1, 2, 3]
// Input 2:

//  A : [1, 2, 3, 5, 10]


// Example Output

// Output 1:

//       2
//     /   \
//    1     3
// Output 2:

//       3
//     /   \
//    2     5
//   /       \
//  1         10


// Example Explanation

// Explanation 1:

//  You need to return the root node of the Binary Tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* construct(const vector<int> &A, int l, int h) {
    if (l > h) return nullptr;

    int m = l + (h - l) / 2;

    TreeNode* root = new TreeNode(A[m]);

    root->left = construct(A, l, m - 1);
    root->right = construct(A, m + 1, h);

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if (A.empty()) return nullptr;
    
    int l = 0, h = A.size() - 1;
    return construct(A, l, h);
}
