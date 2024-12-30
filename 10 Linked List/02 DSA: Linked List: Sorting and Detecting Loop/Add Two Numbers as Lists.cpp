// https://www.scaler.com/academy/mentee-dashboard/class/297869/homework/problems/38?navref=cl_tt_nv_dd

// Problem Description

// You are given two linked lists, A and B, representing two non-negative numbers.



// The digits are stored in reverse order, and each of their nodes contains a single digit.

// Add the two numbers and return it as a linked list.





// Problem Constraints

// 1 <= |A|, |B| <= 105



// Input Format

// The first argument of input contains a pointer to the head of linked list A.

// The second argument of input contains a pointer to the head of linked list B.



// Output Format

// Return a pointer to the head of the required linked list.



// Example Input

// Input 1:

 
//  A = [2, 4, 3]
//  B = [5, 6, 4]
// Input 2:

 
//  A = [9, 9]
//  B = [1]


// Example Output

// Output 1:

 
//  [7, 0, 8]
// Output 2:

 
//  [0, 0, 1]


// Example Explanation

// Explanation 1:

//  A = 342 and B = 465. A + B = 807. 
// Explanation 2:

//  A = 99 and B = 1. A + B = 100. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(NULL);
    ListNode* current = ans;
    int carry = 0;                          

    while (A != NULL || B != NULL || carry != 0) {
        int sum = carry;

        if (A != NULL) {
            sum += A->val;
            A = A->next;
        }

        if (B != NULL) {
            sum += B->val;
            B = B->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return ans->next;
}
