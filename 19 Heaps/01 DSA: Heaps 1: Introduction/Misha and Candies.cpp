// https://www.scaler.com/academy/mentee-dashboard/class/297841/homework/problems/1192?navref=cl_tt_nv_dd

// Problem Description

// Misha loves eating candies. She has been given N boxes of Candies.


// She decides that every time she will choose a box having the minimum number of candies, eat half of the candies and put the remaining candies in the other box that has the minimum number of candies.
// Misha does not like a box if it has the number of candies greater than B so she won't eat from that box. Can you find how many candies she will eat?

// NOTE 1: If a box has an odd number of candies then Misha will eat the floor(odd / 2).

// NOTE 2: The same box will not be chosen again.




// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= 105

// 1 <= B <= 106



// Input Format

// The first argument is A an Array of Integers, where A[i] is the number of candies in the ith box.
// The second argument is B, the maximum number of candies Misha like in a box.



// Output Format

// Return an integer denoting the number of candies Misha will eat.



// Example Input

// Input 1:


//  A = [3, 2, 3]
//  B = 4
// Input 2:

//  A = [1, 2, 1]
//  B = 2



// Example Output

// Output 1:

//  2
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  1st time Misha will eat from 2nd box, i.e 1 candy she'll eat and will put the remaining 1 candy in the 1st box.
//  2nd time she will eat from the 3rd box, i.e 1 candy she'll eat and will put the remaining 2 candies in the 1st box.
//  She will not eat from the 3rd box as now it has candies greater than B.
//  So the number of candies Misha eat is 2.
// Explanation 2:

//  1st time Misha will eat from 1st box, i.e she can't eat any and will put the remaining 1 candy in the 3rd box.
//  2nd time she will eat from the 3rd box, i.e 1 candy she'll eat and will put the remaining 1 candies in the 2nd box.
//  She will not eat from the 2nd box as now it has candies greater than B.
//  So the number of candies Misha eat is 1.

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
        int pi = (i - 1) / 2;  // parent index
        if (minheap[pi] > minheap[i]) {
            swap(minheap[pi], minheap[i]);
            i = pi;
        } else {
            break;
        }
    }
}

int extractMin(vector<int> &minheap) {
    if (minheap.empty()) return 0; // Check for empty heap
    int minVal = minheap[0];
    minheap[0] = minheap.back();
    minheap.pop_back();
    if (!minheap.empty()) {
        heapify(minheap, 0);
    }
    return minVal;
}

int solve(vector<int> &A, int B) {
    vector<int> minheap;

    for (int candies : A) {
        if (candies <= B) {
            insert(minheap, candies);
        }
    }

    int totalCandiesEaten = 0;

    while (minheap.size()>1) {
        int minCandies1 = extractMin(minheap);
        // cout<<"minCandies1 "<<minCandies1<<endl;
        int minCandies2 = extractMin(minheap);
        // cout<<"remainingCandies "<<minCandies2<<endl;

        int eatenCandies = minCandies1 / 2;
        totalCandiesEaten += eatenCandies;

        int remainingCandies = minCandies1 - eatenCandies + minCandies2;

        if (remainingCandies > 0 && remainingCandies <= B) {
            insert(minheap, remainingCandies);
            // cout<<"remainingCandies "<<remainingCandies<<endl;
        }
    }

    int minCandies1 = extractMin(minheap);
    if (minCandies1<=B) totalCandiesEaten += minCandies1 / 2;

    return totalCandiesEaten;
}
