// https://www.scaler.com/academy/mentee-dashboard/class/236106/homework/problems/39?navref=cl_tt_nv

// Problem Description

// Given a linked list A, remove the B-th node from the end of the list and return its head.
// For example, given linked list: 1->2->3->4->5, and B = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

// NOTE: If B is greater than the size of the list, remove the first node of the list.

// Try doing it using constant additional space.



// Problem Constraints

// 1 <= |A| <= 106


// Input Format

// The first argument of input contains a pointer to the head of the linked list. The second argument of input contains the integer B.


// Output Format

// Return the head of the linked list after deleting the B-th element from the end.


// Example Input

// Input 1:
// A = 1->2->3->4->5
// B = 2
// Input 2:
// A = 1
// B = 1


// Example Output

// Output 1:
// 1->2->3->5
// Output 2:
  


// Example Explanation

// Explanation 1:
// In the first example, 4 is the second last element.
// Explanation 2:
// In the second example, 1 is the first and the last element.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
        ListNode* dummy = new ListNode(0);
        dummy->next = A;
        
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the 'first' pointer 'B' steps aA
        for (int i = 0; i < B; i++) {
            if (first->next == NULL) {
                // If B is greater than the length of the list, remove the first node
                return A->next;
            }
            first = first->next;
        }

        // Move both 'first' and 'second' until 'first' reaches the end
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy->next;    
}

