// https://www.scaler.com/academy/mentee-dashboard/class/297837/assignment/problems/335?navref=cl_tt_nv_dd

// Problem Description

// Given a binary search tree represented by root A, write a function to find the Bth smallest element in the tree.



// Problem Constraints

// 1 <= Number of nodes in binary tree <= 100000

// 0 <= node values <= 10^9



// Input Format

// First and only argument is head of the binary tree A.



// Output Format

// Return an integer, representing the Bth element.



// Example Input

// Input 1:

 
//             2
//           /   \
//          1    3
// B = 2
// Input 2:

 
//             3
//            /
//           2
//          /
//         1
// B = 1



// Example Output

// Output 1:

//  2
// Output 2:

//  1


// Example Explanation

// Explanation 1:

// 2nd element is 2.
// Explanation 2:

// 1st element is 1.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traversal(TreeNode* A, int B, int &ans, int &count){
    if (A==NULL) return;
    traversal(A->left, B, ans, count);
    count++;
    if (count==B){
        ans=A->val;
    }
    traversal(A->right, B, ans, count);

}

int Solution::kthsmallest(TreeNode* A, int B) {
    int ans=-1, count=0;
    traversal(A, B, ans, count);
    return ans;
}
