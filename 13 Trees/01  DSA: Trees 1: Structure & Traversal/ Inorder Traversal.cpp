// https://www.scaler.com/academy/mentee-dashboard/class/236128/assignment/problems/214?navref=cl_tt_lst_nm

// Problem Description

// Given a binary tree, return the inorder traversal of its nodes' values.



// Problem Constraints

// 1 <= number of nodes <= 105



// Input Format

// First and only argument is root node of the binary tree, A.



// Output Format

// Return an integer array denoting the inorder traversal of the given binary tree.



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

//  [1, 3, 2]
// Output 2:

//  [6, 1, 3, 2]


// Example Explanation

// Explanation 1:

//  The Inorder Traversal of the given tree is [1, 3, 2].
// Explanation 2:

//  The Inorder Traversal of the given tree is [6, 1, 3, 2].

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    TreeNode* curr = A;
    vector<int> ans;
    
    while (!st.empty() || curr != NULL) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left; 
        }
        
        curr = st.top();
        st.pop();
        
        ans.push_back(curr->val);
        
        curr = curr->right;
    }
    
    return ans;
}
