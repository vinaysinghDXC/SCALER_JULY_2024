// https://www.scaler.com/academy/mentee-dashboard/class/297869/assignment/problems/36?navref=cl_tt_nv_dd

// Problem Description

// Merge two sorted linked lists, A and B, and return it as a new list.




// The new list should be made by splicing together the nodes of the first two lists and should also be sorted.






// Problem Constraints

// 0 <= |A|, |B| <= 105



// Input Format

// The first argument of input contains a pointer to the head of linked list A.

// The second argument of input contains a pointer to the head of linked list B.



// Output Format

// Return a pointer to the head of the merged linked list.



// Example Input

// Input 1:

//  A = 5 -> 8 -> 20
//  B = 4 -> 11 -> 15
// Input 2:

//  A = 1 -> 2 -> 3
//  B = Null


// Example Output

// Output 1:

//  4 -> 5 -> 8 -> 11 -> 15 -> 20
// Output 2:

//  1 -> 2 -> 3


// Example Explanation

// Explanation 1:

//  Merging A and B will result in 4 -> 5 -> 8 -> 11 -> 15 -> 20 
// Explanation 2:

//  We don't need to merge as B is empty.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* p1=A;
    ListNode* p2=B;

    ListNode* head=NULL;
    ListNode* tail=NULL;

    if (p1->val<=p2->val){
        head=p1;
        tail=p1;
        p1=p1->next;
    }

    else{
        head=p2;
        tail=p2;
        p2=p2->next; 
    }

    while(p1!=NULL && p2!=NULL){
        if (p1->val<=p2->val){
            tail->next=p1;
            p1=p1->next;
            tail=tail->next;
        }

        else{
            tail->next=p2;
            p2=p2->next;
            tail=tail->next;
        }
    }

    if (p1!=NULL) tail->next=p1;
    else tail->next=p2;

    return head;
}
