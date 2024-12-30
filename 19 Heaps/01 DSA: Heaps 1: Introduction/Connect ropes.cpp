// https://www.scaler.com/academy/mentee-dashboard/class/297841/assignment/problems/4385?navref=cl_tt_crd_nm

// Problem Description

// You are given an array A of integers that represent the lengths of ropes.




// You need to connect these ropes into one rope. The cost of joining two ropes equals the sum of their lengths.

// Find and return the minimum cost to connect these ropes into one rope.






// Problem Constraints

// 1 <= length of the array <= 100000
// 1 <= A[i] <= 1000



// Input Format

// The only argument given is the integer array A.



// Output Format

// Return an integer denoting the minimum cost to connect these ropes into one rope.



// Example Input

// Input 1:

//  A = [1, 2, 3, 4, 5]
// Input 2:

//  A = [5, 17, 100, 11]


// Example Output

// Output 1:

//  33
// Output 2:

//  182


// Example Explanation

// Explanation 1:

//  Given array A = [1, 2, 3, 4, 5].
//  Connect the ropes in the following manner:
//  1 + 2 = 3
//  3 + 3 = 6
//  4 + 5 = 9
//  6 + 9 = 15

//  So, total cost  to connect the ropes into one is 3 + 6 + 9 + 15 = 33.
// Explanation 2:

//  Given array A = [5, 17, 100, 11].
//  Connect the ropes in the following manner:
//  5 + 11 = 16
//  16 + 17 = 33
//  33 + 100 = 133

//  So, total cost  to connect the ropes into one is 16 + 33 + 133 = 182.

#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &A, int i) {
    int n = A.size();
    while (i < n) {
        int min_i = i;
        int lci = 2 * i + 1;
        int rci = 2 * i + 2;
        
        if (lci < n && A[lci] < A[min_i]) min_i = lci;
        if (rci < n && A[rci] < A[min_i]) min_i = rci;
        
        if (i == min_i) break;
        else {
            swap(A[i], A[min_i]);
            i = min_i;
        }
    }
}

void insert(vector<int> &minheap, int x) {
    minheap.push_back(x);
    int i = minheap.size() - 1;
    while (i > 0) {
        int pi = (i - 1) / 2;  //parent index
        if (minheap[pi] > minheap[i]) {
            swap(minheap[pi], minheap[i]);
            i = pi;
        } else {
            break;
        }
    }
}

int extractMin(vector<int> &minheap) {
    int minVal = minheap[0];
    minheap[0] = minheap.back();
    minheap.pop_back();
    heapify(minheap, 0);
    return minVal;
}

int solve(vector<int> &A) {
    vector<int> minheap;
    
    for (int num : A) {
        insert(minheap, num);
    }
    
    int totalCost = 0;
    
    while (minheap.size() > 1) {
        int first = extractMin(minheap);
        int second = extractMin(minheap);
        
        int cost = first + second;
        totalCost += cost;
        
        insert(minheap, cost);
    }
    
    return totalCost;
}
