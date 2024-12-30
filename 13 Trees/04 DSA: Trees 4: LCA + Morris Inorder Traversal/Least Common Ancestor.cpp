// Problem Description

// Find the lowest common ancestor in an unordered binary tree A, given two values, B and C, in the tree.


// Lowest common ancestor: the lowest common ancestor (LCA) of two nodes and w in a tree or directed acyclic graph (DAG) is the lowest (i.e., deepest) node that has both v and w as descendants.




// Problem Constraints

// 1 <= size of tree <= 100000

// 1 <= B, C <= 109



// Input Format

// First argument is head of tree A.

// Second argument is integer B.

// Third argument is integer C.



// Output Format

// Return the LCA.



// Example Input

// Input 1:

 
//       1
//      /  \
//     2    3
// B = 2
// C = 3
// Input 2:

//       1
//      /  \
//     2    3
//    / \
//   4   5
// B = 4
// C = 5


// Example Output

// Output 1:

//  1
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  LCA is 1.
// Explanation 2:

//  LCA is 2.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool exists(TreeNode* root, int key) {
    if (root == NULL) return false;
    if (root->val == key) return true;
    
    return exists(root->left, key) || exists(root->right, key);
}

TreeNode* findlca(TreeNode* A, int B, int C){
    if (A==NULL) return NULL;
    if (A->val==B || A->val==C) return A;

    TreeNode* lans=findlca(A->left, B, C);
    TreeNode* rans=findlca(A->right, B, C);

    if (lans!=NULL && rans!=NULL) return A;

    else if (lans!=NULL) return lans;

    else return rans;
}

int Solution::lca(TreeNode* A, int B, int C) {
    if (!exists(A, B) || !exists(A, C)) return -1;

    TreeNode* lcaref=findlca(A, B, C);

    if (lcaref == NULL) return -1;

    return lcaref->val;
}
