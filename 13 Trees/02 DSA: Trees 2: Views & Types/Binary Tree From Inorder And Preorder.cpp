// https://www.scaler.com/academy/mentee-dashboard/class/236126/homework/problems/219?navref=cl_tt_lst_nm

// Problem Description

// Given preorder and inorder traversal of a tree, construct the binary tree.

// NOTE: You may assume that duplicates do not exist in the tree.



// Problem Constraints

// 1 <= number of nodes <= 105



// Input Format

// First argument is an integer array A denoting the preorder traversal of the tree.

// Second argument is an integer array B denoting the inorder traversal of the tree.



// Output Format

// Return the root node of the binary tree.



// Example Input

// Input 1:

//  A = [1, 2, 3]
//  B = [2, 1, 3]
// Input 2:

//  A = [1, 6, 2, 3]
//  B = [6, 1, 3, 2]


// Example Output

// Output 1:

//    1
//   / \
//  2   3
// Output 2:

//    1  
//   / \
//  6   2
//     /
//    3


// Example Explanation

// Explanation 1:

//  Create the binary tree and return the root node of the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* buildTreeHelper(int inStart, int inEnd, int preStart, int preEnd,
                          unordered_map<int, int>& inorderMap, vector<int>& preorder, 
                          vector<int>& inorder) {
    if (inStart > inEnd || preStart > preEnd) {
        return nullptr;
    }

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inorderRootIndex = inorderMap[rootVal];

    int leftSubtreeSize = inorderRootIndex - inStart;

    root->left = buildTreeHelper(inStart, inorderRootIndex - 1, preStart + 1, preStart + leftSubtreeSize, inorderMap, preorder, inorder);
    root->right = buildTreeHelper(inorderRootIndex + 1, inEnd, preStart + leftSubtreeSize + 1, preEnd, inorderMap, preorder, inorder);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < B.size(); i++) {
        inorderMap[B[i]] = i;
    }

    return buildTreeHelper(0, B.size() - 1, 0, A.size() - 1, inorderMap, A, B);
}
