// https://www.scaler.com/academy/mentee-dashboard/class/297869/assignment/problems/4370?navref=cl_tt_nv_dd

// Problem Description

// Given a linked list of integers, find and return the middle element of the linked list.



// NOTE: If there are N nodes in the linked list and N is even then return the (N/2 + 1)th element.





// Problem Constraints

// 1 <= length of the linked list <= 100000

// 1 <= Node value <= 109



// Input Format

// The only argument given head pointer of linked list.



// Output Format

// Return the middle element of the linked list.



// Example Input

// Input 1:

//  1 -> 2 -> 3 -> 4 -> 5
// Input 2:

//  1 -> 5 -> 6 -> 2 -> 3 -> 4


// Example Output

// Output 1:

//  3
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  The middle element is 3.
// Explanation 2:

//  The middle element in even length linked list of length N is ((N/2) + 1)th element which is 2.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
    ListNode* slow=A;
    ListNode* fast=A;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->val;
}
