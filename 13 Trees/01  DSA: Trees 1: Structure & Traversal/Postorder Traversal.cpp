// https://www.scaler.com/academy/mentee-dashboard/class/236128/homework/problems/229?navref=cl_tt_lst_nm

// Problem Description

// Given a binary tree, return the Postorder traversal of its nodes values.



// Problem Constraints

// 1 <= number of nodes <= 105



// Input Format

// First and only argument is root node of the binary tree, A.



// Output Format

// Return an integer array denoting the Postorder traversal of the given binary tree.



// Example Input

// Input 1:

//    1
//     \
//      2
//     /
//    3
// Input 2:

//    1
//   / \
//  6   2
//     /
//    3


// Example Output

// Output 1:

//  [3, 2, 1]
// Output 2:

//  [6, 3, 2, 1]


// Example Explanation

// Explanation 1:

//  The Preoder Traversal of the given tree is [3, 2, 1].
// Explanation 2:

//  The Preoder Traversal of the given tree is [6, 3, 2, 1].

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void post(TreeNode* A, vector<int> &ans){
    if (A==NULL) return;
    post(A->left, ans);
    post(A->right, ans);
    ans.push_back(A->val);
}

vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    post(A, ans);
    return ans;
}
