// https://www.scaler.com/academy/mentee-dashboard/class/236106/assignment/problems/30667?navref=cl_tt_nv

// Problem Description

// You are given the head of a linked list A and an integer B. Delete the B-th node from the linked list.

// Note : Follow 0-based indexing for the node numbering.



// Problem Constraints

// 1 <= size of linked list <= 105
// 1 <= value of nodes <= 109
// 0 <= B < size of linked list




// Input Format

// The first argument A is the head of a linked list.

// The second arguement B is an integer.



// Output Format

// Return the head of the linked list after deletion



// Example Input

// Input 1:
// A = 1 -> 2 -> 3
// B = 1
// Input 2:
// A = 4 -> 3 -> 2 -> 1
// B = 0


// Example Output

// Output 1:
// 1 -> 3
// Output 2:
// 3 -> 2 -> 1


// Example Explanation

// For Input 1:
// The linked list after deletion is 1 -> 3.
// For Input 2:
// The linked list after deletion is 3 -> 2 -> 1.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    if (A == NULL) {
        return A;
    }
    
    if (B == 0) {
        ListNode* temp = A; 
        A = A->next;           
        delete temp;           
        return A;              
    }

    ListNode* current = A;
    int count = 0;
    
    while (current != NULL && count < B - 1) {
        current = current->next;
        count++;
    }
    
    if (current == NULL || current->next == NULL) {
        return A;
    }
    
    ListNode* node_to_delete = current->next;  
    current->next = current->next->next;       
    delete node_to_delete;                     
    
    return A;  
}
