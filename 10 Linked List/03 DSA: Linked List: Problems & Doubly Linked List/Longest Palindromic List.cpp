// https://www.scaler.com/academy/mentee-dashboard/class/297893/homework/problems/4386?navref=cl_tt_nv_dd

// Problem Description

// Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list.

// A palindrome list is a list that reads the same backward and forward.

// Expected memory complexity : O(1)



// Problem Constraints

// 1 <= length of the linked list <= 2000

// 1 <= Node value <= 100



// Input Format

// The only argument given is head pointer of the linked list.



// Output Format

// Return the length of the longest palindrome list.



// Example Input

// Input 1:

//  2 -> 3 -> 3 -> 3
// Input 2:

//  2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2


// Example Output

// Output 1:

//  3
// Output 2:

//  5


// Example Explanation

// Explanation 1:

//  3 -> 3 -> 3 is largest palindromic sublist
// Explanation 2:

//  2 -> 1 -> 2 -> 1 -> 2 is largest palindromic sublist.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int countMatching(ListNode* a, ListNode* b) {
    int count = 0;
    while (a != NULL && b != NULL && a->val == b->val) {
        count++;
        a = a->next;
        b = b->next;
    }
    return count;
}

int Solution::solve(ListNode* A) {
    ListNode* prev = NULL;
    ListNode* curr = A;
    int maxLen = 0;
    
    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        
        int oddLen = 2 * countMatching(prev, next) + 1;
        maxLen = max(maxLen, oddLen);
        
        int evenLen = 2 * countMatching(curr, next);
        maxLen = max(maxLen, evenLen);
        
        prev = curr;
        curr = next;
    }
    
    return maxLen;
}
