// https://www.scaler.com/academy/mentee-dashboard/class/236106/homework/problems/380?navref=cl_tt_nv

// Problem Description

// Given a singly linked list A and an integer B, reverse the nodes of the list B at a time and return the modified linked list.



// Problem Constraints

// 1 <= |A| <= 103

// B always divides A



// Input Format

// The first argument of input contains a pointer to the head of the linked list.

// The second arugment of input contains the integer, B.



// Output Format

// Return a pointer to the head of the modified linked list.



// Example Input

// Input 1:

//  A = [1, 2, 3, 4, 5, 6]
//  B = 2
// Input 2:

//  A = [1, 2, 3, 4, 5, 6]
//  B = 3


// Example Output

// Output 1:

//  [2, 1, 4, 3, 6, 5]
// Output 2:

//  [3, 2, 1, 6, 5, 4]


// Example Explanation

// Explanation 1:

//  For the first example, the list can be reversed in groups of 2.
//     [[1, 2], [3, 4], [5, 6]]
//  After reversing the K-linked list
//     [[2, 1], [4, 3], [6, 5]]
// Explanation 2:

//  For the second example, the list can be reversed in groups of 3.
//     [[1, 2, 3], [4, 5, 6]]
//  After reversing the K-linked list
//     [[3, 2, 1], [6, 5, 4]]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* start, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = start;
    ListNode* next = nullptr;
    int count = 0;

    // Reverse the first 'k' nodes
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    if (A == nullptr || B == 1) {
        return A;
    }

    ListNode* temp = A;
    int len = 0;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* prevGroupEnd = dummy;

    while (len >= B) {
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* groupEnd = groupStart;

        for (int i = 1; i < B; i++) {
            groupEnd = groupEnd->next;
        }

        ListNode* nextGroupStart = groupEnd->next;

        prevGroupEnd->next = reverse(groupStart, B);
        groupStart->next = nextGroupStart;

        prevGroupEnd = groupStart;
        len -= B;
    }

    return dummy->next;
}
