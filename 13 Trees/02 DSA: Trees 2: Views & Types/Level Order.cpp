// https://www.scaler.com/academy/mentee-dashboard/class/236126/assignment/problems/206?navref=cl_tt_lst_nm

// Problem Description

// Given a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



// Problem Constraints

// 1 <= number of nodes <= 105



// Input Format

// First and only argument is root node of the binary tree, A.



// Output Format

// Return a 2D integer array denoting the level order traversal of the given binary tree.



// Example Input

// Input 1:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Input 2:

//    1
//   / \
//  6   2
//     /
//    3


// Example Output

// Output 1:

//  [
//    [3],
//    [9, 20],
//    [15, 7]
//  ]
// Output 2:

//  [ 
//    [1]
//    [6, 2]
//    [3]
//  ]


// Example Explanation

// Explanation 1:

//  Return the 2D array. Each row denotes the traversal of each level.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::solve(TreeNode* root) {
    vector<vector<int>> result;
    
    if (root == NULL) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            currentLevel.push_back(node->val);
            
            if (node->left != NULL) {
                q.push(node->left);
            }
            
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
        
        result.push_back(currentLevel);
    }
    
    return result;    
}
