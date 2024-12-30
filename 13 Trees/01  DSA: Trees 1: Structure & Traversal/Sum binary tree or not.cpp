// https://www.scaler.com/academy/mentee-dashboard/class/236128/homework/problems/4401?navref=cl_tt_nv

// Problem Description

// Given a binary tree. Check whether the given tree is a Sum-binary Tree or not.

// Sum-binary Tree is a Binary Tree where the value of a every node is equal to sum of the nodes present in its left subtree and right subtree.

// An empty tree is Sum-binary Tree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

// Return 1 if it sum-binary tree else return 0.



// Problem Constraints

// 1 <= length of the array <= 100000

// 0 <= node values <= 50



// Input Format

// The only argument given is the root node of tree A.



// Output Format

// Return 1 if it is sum-binary tree else return 0.



// Example Input

// Input 1:

//        26
//      /    \
//     10     3
//    /  \     \
//   4   6      3
// Input 2:

//        26
//      /    \
//     10     3
//    /  \     \
//   4   6      4


// Example Output

// Output 1:

//  1
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  All leaf nodes are considered as SumTree. 
//  Value of Node 10 = 4 + 6.
//  Value of Node 3 = 0 + 3 
//  Value of Node 26 = (10 + 4 + 6) + 6 
// Explanation 2:

//  Sum of left subtree and right subtree is 27 which is not equal to the value of root node which is 26.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isSumTree(TreeNode* A, int &sum) {
    // Base case: If the node is NULL, it's a sum tree
    if (!A) {
        sum = 0;
        return true;
    }

    // Base case: If it's a leaf node, ie, the left and right are NULL, it's also a sum tree
    if (!A->left && !A->right) {
        sum = A->val;
        return true;
    }

    int leftSum = 0, rightSum = 0;

    bool isLeftSumTree = isSumTree(A->left, leftSum);
    bool isRightSumTree = isSumTree(A->right, rightSum);

    sum = A->val + leftSum + rightSum;

    return isLeftSumTree && isRightSumTree && (A->val == leftSum + rightSum);
}

int Solution::solve(TreeNode* A) {
    int sum = 0;
    if (isSumTree(A, sum)) {
        return 1;
    } 
    else {
        return 0;
    }
}
