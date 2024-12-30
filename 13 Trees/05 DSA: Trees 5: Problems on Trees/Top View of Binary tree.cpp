// https://www.scaler.com/academy/mentee-dashboard/class/297917/assignment/problems/5715?navref=cl_tt_nv_dd

// Problem Description

// Given a binary tree of integers denoted by root A. Return an array of integers representing the top view of the Binary tree.





// The top view of a Binary Tree is a set of nodes visible when the tree is visited from the top.

// Return the nodes in any order.




// Problem Constraints

// 1 <= Number of nodes in binary tree <= 100000

// 0 <= node values <= 10^9



// Input Format

// First and only argument is head of the binary tree A.



// Output Format

// Return an array, representing the top view of the binary tree.



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

//  [1, 2, 4, 8, 3, 7]
// Output 2:

//  [1, 2, 3]


// Example Explanation

// Explanation 1:

// Top view is described.
// Explanation 2:

// Top view is described.

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
    if (A == NULL)
        return {};

    map<int, int> map;

    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;//front element from the queue
        int vl = q.front().second;
        q.pop();

        if (map.find(vl) == map.end()) {
            map[vl] = node->val;
        }

        if (node->left) {
            q.push({node->left, vl - 1});
        }

        if (node->right) {
            q.push({node->right, vl + 1});
        }
    }

    vector<int> ans;

    for (auto& [vl, value] : map) {
        ans.push_back(value);
    }

    return ans;
}
