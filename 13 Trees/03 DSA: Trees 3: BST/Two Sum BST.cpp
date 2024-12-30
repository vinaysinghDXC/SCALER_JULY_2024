// https://www.scaler.com/academy/mentee-dashboard/class/236130/homework/problems/336?navref=cl_tt_lst_nm

// Problem Description

// Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

// Return 1 to denote that two such nodes exist. Return 0, otherwise.



// Problem Constraints

// 1 <= size of tree <= 100000

// 1 <= B <= 109



// Input Format

// First argument is the head of the tree A.

// Second argument is the integer B.



// Output Format

// Return 1 if such a pair can be found, 0 otherwise.



// Example Input

// Input 1:

//          10
//          / \
//         9   20

// B = 19
// Input 2:

 
//           10
//          / \
//         9   20

// B = 40


// Example Output

// Output 1:

//  1
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  10 + 9 = 19. Hence 1 is returned.
// Explanation 2:

//  No such pair exists.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getNextInOrder(stack<TreeNode*>& stk, TreeNode*& node, bool forward) {
    while (node != NULL) {
        stk.push(node);
        node = forward ? node->left : node->right;//if forward true then go left else go right
    }

    node = stk.top();
    stk.pop();
    int value = node->val;
    node = forward ? node->right : node->left;//if forward true then go right else go left
    return value;
}

int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> leftStack, rightStack;
    TreeNode* left = A;
    TreeNode* right = A;

    int leftVal = getNextInOrder(leftStack, left, true);
    int rightVal = getNextInOrder(rightStack, right, false);

    while (leftVal < rightVal) {
        int currentSum = leftVal + rightVal;
        
        if (currentSum == B) return 1;
        else if (currentSum < B) leftVal = getNextInOrder(leftStack, left, true);
        else rightVal = getNextInOrder(rightStack, right, false);
    }

    return 0;
}