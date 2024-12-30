// https://www.scaler.com/academy/mentee-dashboard/class/297869/assignment/problems/34?navref=cl_tt_crd_nm

// Problem Description

// Sort a linked list, A in O(n log n) time.



// Problem Constraints

// 0 <= |A| = 105



// Input Format

// The first and the only arugment of input contains a pointer to the head of the linked list, A.



// Output Format

// Return a pointer to the head of the sorted linked list.



// Example Input

// Input 1:

// A = [3, 4, 2, 8]
// Input 2:

// A = [1]


// Example Output

// Output 1:

// [2, 3, 4, 8]
// Output 2:

// [1]


// Example Explanation

// Explanation 1:

//  The sorted form of [3, 4, 2, 8] is [2, 3, 4, 8].
// Explanation 2:

//  The sorted form of [1] is [1].

ListNode* merge2sorted(ListNode* A, ListNode* B) {
    if (!A) return B;
    if (!B) return A;

    ListNode* head = NULL, *tail = NULL;

    if (A->val <= B->val) {
        head = tail = A;
        A = A->next;
    } else {
        head = tail = B;
        B = B->next;
    }

    while (A != NULL && B != NULL) {
        if (A->val <= B->val) {
            tail->next = A;
            A = A->next;
        } else {
            tail->next = B;
            B = B->next;
        }
        tail = tail->next;
    }

    if (A != NULL) {
        tail->next = A;
    } else {
        tail->next = B;
    }

    return head;
}

ListNode* getmiddlenode(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* mergesort(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* mid = getmiddlenode(head);
    ListNode* secondHalf = mid->next;
    mid->next = NULL;

    ListNode* left = mergesort(head);
    ListNode* right = mergesort(secondHalf);

    return merge2sorted(left, right);
}

ListNode* Solution::sortList(ListNode* A) {
    return mergesort(A);
}
