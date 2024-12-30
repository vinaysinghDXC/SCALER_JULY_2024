// https://www.scaler.com/academy/mentee-dashboard/class/236126/assignment/problems/224?navref=cl_tt_nv

// Problem Description

// Given the inorder and postorder traversal of a tree, construct the binary tree.



// NOTE: You may assume that duplicates do not exist in the tree.





// Problem Constraints

// 1 <= number of nodes <= 105



// Input Format

// First argument is an integer array A denoting the inorder traversal of the tree.

// Second argument is an integer array B denoting the postorder traversal of the tree.



// Output Format

// Return the root node of the binary tree.



// Example Input

// Input 1:

//  A = [2, 1, 3]
//  B = [2, 3, 1]
// Input 2:

//  A = [6, 1, 3, 2]
//  B = [6, 3, 2, 1]


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
TreeNode* buildTreeHelper(int inStart, int inEnd, int postStart, int postEnd,
                          unordered_map<int, int>& inorderMap, vector<int>& inorder, 
                          vector<int>& postorder) {
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int inorderRootIndex = inorderMap[rootVal];//find the position of the root in the inorder array

    int leftSubtreeSize = inorderRootIndex - inStart;

    root->left = buildTreeHelper(inStart, inorderRootIndex - 1, postStart, postStart + leftSubtreeSize - 1, inorderMap, inorder, postorder);
    root->right = buildTreeHelper(inorderRootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1, inorderMap, inorder, postorder);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < A.size(); i++) {
        inorderMap[A[i]] = i;
    }
    return buildTreeHelper(0, A.size() - 1, 0, B.size() - 1, inorderMap, A, B);    
}
