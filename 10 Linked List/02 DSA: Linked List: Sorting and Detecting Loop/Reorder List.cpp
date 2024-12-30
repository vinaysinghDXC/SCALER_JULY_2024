// https://www.scaler.com/academy/mentee-dashboard/class/297869/homework/problems/33?navref=cl_tt_nv_dd

// Problem Description

// Given a singly linked list A

//  A: A0 → A1 → … → An-1 → An 
// reorder it to:

//  A0 → An → A1 → An-1 → A2 → An-2 → … 
// You must do this in-place without altering the nodes' values.



// Problem Constraints

// 1 <= |A| <= 106



// Input Format

// The first and the only argument of input contains a pointer to the head of the linked list A.



// Output Format

// Return a pointer to the head of the modified linked list.



// Example Input

// Input 1:

//  A = [1, 2, 3, 4, 5] 
// Input 2:

//  A = [1, 2, 3, 4] 


// Example Output

// Output 1:

//  [1, 5, 2, 4, 3] 
// Output 2:

//  [1, 4, 2, 3] 


// Example Explanation

// Explanation 1:

//  The array will be arranged to [A0, An, A1, An-1, A2].
// Explanation 2:

//  The array will be arranged to [A0, An, A1, An-1, A2].

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* A){
    ListNode* prev = NULL;
    ListNode* curr = A;
    while (curr != NULL) {
        ListNode* nn = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nn;
    }
    return prev;
}

ListNode* Solution::reorderList(ListNode* A) {
    if (A == NULL || A->next == NULL) return A;

    ListNode* slow = A;
    ListNode* fast = A;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *head1 = A;
    ListNode *head2 = slow->next;
    slow->next = NULL;
    head2 = reverse(head2);

    ListNode dummy(NULL);
    ListNode* curr = &dummy;

    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    return dummy.next;
}
