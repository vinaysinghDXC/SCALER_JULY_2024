// https://www.scaler.com/academy/mentee-dashboard/class/236106/assignment/problems/159?navref=cl_tt_nv

// Problem Description

// You are given a linked list A
// Each node in the linked list contains two pointers: a next pointer and a random pointer
// The next pointer points to the next node in the list
// The random pointer can point to any node in the list, or it can be NULL
// Your task is to create a deep copy of the linked list A
// The copied list should be a completely separate linked list from the original list, but with the same node values and random pointer connections as the original list
// You should create a new linked list B, where each node in B has the same value as the corresponding node in A
// The next and random pointers of each node in B should point to the corresponding nodes in B (rather than A)


// Problem Constraints

// 0 <= |A| <= 106



// Input Format

// The first argument of input contains a pointer to the head of linked list A.



// Output Format

// Return a pointer to the head of the required linked list.



// Example Input

// Given list
//    1 -> 2 -> 3
// with random pointers going from
//   1 -> 3
//   2 -> 1
//   3 -> 1
  


// Example Output

//    1 -> 2 -> 3
// with random pointers going from
//   1 -> 3
//   2 -> 1
//   3 -> 1
  

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if (!A) return NULL;
    
    // copy each node and insert it right after the original noed
    RandomListNode* curr = A;
    while (curr) {
        RandomListNode* copy = new RandomListNode(curr->label);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    
    // et the random pointers for the copied noeds
    curr = A;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // restore the original list and extract the copied list
    curr = A;
    RandomListNode* copyHead = A->next;
    RandomListNode* copyCurr = copyHead;
    
    while (curr) {
        curr->next = curr->next->next; 
        if (copyCurr->next) {
            copyCurr->next = copyCurr->next->next;
        }
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    
    return copyHead;
}
