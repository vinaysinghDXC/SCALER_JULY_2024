// https://www.scaler.com/academy/mentee-dashboard/class/236126/assignment/problems/5714?navref=cl_tt_nv

// Problem Description

// Given a binary tree of integers denoted by root A. Return an array of integers representing the right view of the Binary tree.

// Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side.



// Problem Constraints

// 1 <= Number of nodes in binary tree <= 100000

// 0 <= node values <= 10^9



// Input Format

// First and only argument is head of the binary tree A.



// Output Format

// Return an array, representing the right view of the binary tree.



// Example Input

// Input 1:

 
//             1
//           /   \
//          2    3
//         / \  / \
//        4   5 6  7
//       /
//      8 
// Input 2:

 
//             1
//            /  \
//           2    3
//            \
//             4
//              \
//               5


// Example Output

// Output 1:

//  [1, 3, 7, 8]
// Output 2:

//  [1, 3, 4, 5]


// Example Explanation

// Explanation 1:

// Right view is described.
// Explanation 2:

// Right view is described.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> rightView;
    
    if (A == NULL) {
        return rightView;
    }

    queue<TreeNode*> q;
    q.push(A);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (i == levelSize - 1) {
                rightView.push_back(node->val);
            }
            
            if (node->left != NULL) {
                q.push(node->left);
            }

            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
    
    return rightView;     
}
