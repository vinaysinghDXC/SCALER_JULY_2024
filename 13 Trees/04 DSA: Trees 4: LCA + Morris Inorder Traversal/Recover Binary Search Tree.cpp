// https://www.scaler.com/academy/mentee-dashboard/class/297837/homework/problems/216?navref=cl_tt_crd_nm

// Problem Description

// Two elements of a Binary Search Tree (BST), represented by root A are swapped by mistake. Tell us the 2 values, when swapped, will restore the Binary Search Tree (BST).

// A solution using O(n) space is pretty straightforward. Could you devise a constant space solution?

// Note: The 2 values must be returned in ascending order



// Problem Constraints

// 1 <= size of tree <= 100000



// Input Format

// First and only argument is the head of the tree,A



// Output Format

// Return the 2 elements which need to be swapped.



// Example Input

// Input 1:

//          1 
//         / \ 
//        2   3
// Input 2:

 
//          2
//         / \
//        3   1



// Example Output

// Output 1:

//  [2, 1]
// Output 2:

//  [3, 1]


// Example Explanation

// Explanation 1:

// Swapping 1 and 2 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST 
// Explanation 2:

// Swapping 1 and 3 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void traverse(TreeNode* A, TreeNode* &curr, TreeNode* &prev, TreeNode* &one, TreeNode* &two) {
    if (A == nullptr) return;

    // In-order traversal
    traverse(A->left, curr, prev, one, two);

    prev = curr;
    curr = A;

    if (prev && prev->val > curr->val) {
        if (!one) {
            one = prev;
            two = curr;
        } 
        else two = curr;
        
    }
    traverse(A->right, curr, prev, one, two);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode* curr = nullptr;
    TreeNode* prev = nullptr;
    TreeNode* one = nullptr;
    TreeNode* two = nullptr;

    traverse(A, curr, prev, one, two);
    if (one && two) {
        return {min(one->val, two->val), max(one->val, two->val)};
    }
    return {};
}
