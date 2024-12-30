// https://www.scaler.com/academy/mentee-dashboard/class/236106/homework/problems/37?navref=cl_tt_lst_nm

// Problem Description

// Given a sorted linked list, delete all duplicates such that each element appears only once.



// Problem Constraints

// 0 <= length of linked list <= 106



// Input Format

// First argument is the head pointer of the linked list.



// Output Format

// Return the head pointer of the linked list after removing all duplicates.



// Example Input

// Input 1:

//  1->1->2
// Input 2:

//  1->1->2->3->3


// Example Output

// Output 1:

//  1->2
// Output 2:

//  1->2->3


// Example Explanation

// Explanation 1:

//  Each element appear only once in 1->2.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (A == nullptr) return nullptr;
    
    ListNode* current = A;
    
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = current->next->next;  // Skip the duplicate node
            delete temp;  // Free memory of the duplicate node
        } else {
            current = current->next;
        }
    }
    
    return A;    
}
