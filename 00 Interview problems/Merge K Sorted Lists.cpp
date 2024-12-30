// https://www.scaler.com/academy/mentee-dashboard/class/297849/assignment/problems/238?navref=cl_tt_nv_dd

// Problem Description

// Given a list containing head pointers of N sorted linked lists.
// Merge these given sorted linked lists and return them as one sorted list.



// Problem Constraints

// 1 <= total number of elements in given linked lists <= 100000



// Input Format

// The first and only argument is a list containing N head pointers.



// Output Format

// Return a pointer to the head of the sorted linked list after merging all the given linked lists.



// Example Input

// Input 1:

//  1 -> 10 -> 20
//  4 -> 11 -> 13
//  3 -> 8 -> 9
// Input 2:

//  10 -> 12
//  13
//  5 -> 6


// Example Output

// Output 1:

//  1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
// Output 2:

//  5 -> 6 -> 10 -> 12 ->13


// Example Explanation

// Explanation 1:

//  The resulting sorted Linked List formed after merging is 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20.
// Explanation 2:

//  The resulting sorted Linked List formed after merging is 5 -> 6 -> 10 -> 12 ->13.



/**
 * Definition for singly-linked list node.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

// Comparator to use in the priority queue to make it a min-heap
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*>& A) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for (ListNode* list : A) {
        if (list != nullptr) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();

        current->next = node;
        current = current->next;

        if (node->next != nullptr) {
            minHeap.push(node->next);
        }
    }

    return dummy->next;
}
