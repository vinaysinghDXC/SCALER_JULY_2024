// https://www.scaler.com/academy/mentee-dashboard/class/297837/homework/problems/6562?navref=cl_tt_nv_dd

// Problem Description

// Given a binary search tree.
// Return the distance between two nodes with given two keys B and C. It may be assumed that both keys exist in BST.

// NOTE: Distance between two nodes is number of edges between them.



// Problem Constraints

// 1 <= Number of nodes in binary tree <= 1000000

// 0 <= node values <= 109



// Input Format

// First argument is a root node of the binary tree, A.

// Second argument is an integer B.

// Third argument is an integer C.



// Output Format

// Return an integer denoting the distance between two nodes with given two keys B and C



// Example Input

// Input 1:

    
//          5
//        /   \
//       2     8
//      / \   / \
//     1   4 6   11
//  B = 2
//  C = 11
// Input 2:

    
//          6
//        /   \
//       2     9
//      / \   / \
//     1   4 7   10
//  B = 2
//  C = 6


// Example Output

// Output 1:

//  3
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  Path between 2 and 11 is: 2 -> 5 -> 8 -> 11. Distance will be 3.
// Explanation 2:

//  Path between 2 and 6 is: 2 -> 6. Distance will be 1


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

pair<bool, int> calculateDistance(TreeNode* root, int B, int C, int& distance) {
    if (!root) return {false, 0};

    pair<bool, int> lh = calculateDistance(root->left, B, C, distance);
    pair<bool, int> rh = calculateDistance(root->right, B, C, distance);
    
    bool current = (root->val == B || root->val == C);

    if (current && (lh.first || rh.first)) {
        distance = max(lh.second, rh.second);
        return {false, 0};
    }

    if (lh.first && rh.first) {
        distance = lh.second + rh.second;
        return {false, 0};
    }

    if (lh.first || rh.first || current) {
        return {true, max(lh.second, rh.second) + 1};
    }

    return {false, 0};
}

int Solution::solve(TreeNode* A, int B, int C) {
    int distance = 0;
    calculateDistance(A, B, C, distance);
    return distance;
}
