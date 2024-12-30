// https://www.scaler.com/academy/mentee-dashboard/class/297917/assignment/problems/378?navref=cl_tt_nv_dd

// Problem Description

// Given a binary tree, return a 2-D array with vertical order traversal of it. Go through the example and image for more details.


// NOTE: If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.



// Problem Constraints

// 0 <= number of nodes <= 105



// Input Format

// First and only arument is a pointer to the root node of binary tree, A.



// Output Format

// Return a 2D array denoting the vertical order traversal of tree as shown.



// Example Input

// Input 1:

//       6
//     /   \
//    3     7
//   / \     \
//  2   5     9
// Input 2:

//       1
//     /   \
//    3     7
//   /       \
//  2         9


// Example Output

// Output 1:

//  [
//     [2],
//     [3],
//     [6, 5],
//     [7],
//     [9]
//  ]
// Output 2:

//  [
//     [2],
//     [3],
//     [1],
//     [7],
//     [9]
//  ]


// Example Explanation

// Explanation 1:

//  First row represent the verical line 1 and so on.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* A) {
    if (A == NULL)
        return {};

    map<int, vector<int>> map;

    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;//front element from the queue
        int vl = q.front().second;
        q.pop();

        map[vl].push_back(node->val);//add node value to the corresponding vertical level in the map

        if (node->left) {
            q.push({node->left, vl - 1});
        }

        if (node->right) {
            q.push({node->right, vl + 1});
        }
    }

    vector<vector<int> > ans;

    for (auto& [vl, nodes] : map) {
        ans.push_back(nodes);
    }

    return ans;
}