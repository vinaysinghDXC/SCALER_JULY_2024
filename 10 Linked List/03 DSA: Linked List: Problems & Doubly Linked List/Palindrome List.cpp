// https://www.scaler.com/academy/mentee-dashboard/class/297893/assignment/problems/331?navref=cl_tt_nv_dd

// Problem Description

// Given a singly linked list A, determine if it's a palindrome. Return 1 or 0, denoting if it's a palindrome or not, respectively.



// Problem Constraints

// 1 <= |A| <= 105



// Input Format

// The first and the only argument of input contains a pointer to the head of the given linked list.



// Output Format

// Return 0, if the linked list is not a palindrome.

// Return 1, if the linked list is a palindrome.



// Example Input

// Input 1:

// A = [1, 2, 2, 1]
// Input 2:

// A = [1, 3, 2]


// Example Output

// Output 1:

//  1 
// Output 2:

//  0 


// Example Explanation

// Explanation 1:

//  The first linked list is a palindrome as [1, 2, 2, 1] is equal to its reversed form.
// Explanation 2:

//  The second linked list is not a palindrom as [1, 3, 2] is not equal to [2, 3, 1].

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* getmiddle(ListNode* A){
    ListNode* slow=A;
    ListNode* fast=A;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

int Solution::lPalin(ListNode* A) {
    if (A == NULL || A->next == NULL) {
        return 1;
    }

    ListNode* mid=getmiddle(A);
    ListNode* A2 = reverse(mid);
    ListNode* A1 = A;
    
    while(A1!=NULL && A2!=NULL){
        if (A1->val != A2->val) return 0;
        A1=A1->next;
        A2=A2->next;
    }
    return 1;
}
