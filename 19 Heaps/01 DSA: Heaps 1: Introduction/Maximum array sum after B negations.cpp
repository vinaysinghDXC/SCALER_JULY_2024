// https://www.scaler.com/academy/mentee-dashboard/class/297841/homework/problems/4395?navref=cl_tt_crd_nm

// Problem Description

// Given an array of integers A and an integer B. You must modify the array exactly B number of times. In a single modification, we can replace any one array element A[i] by -A[i].


// You need to perform these modifications in such a way that after exactly B modifications, sum of the array must be maximum.



// NOTE: You can perform the modification on the same element multiple times.



// Problem Constraints

// 1 <= length of the array <= 5*105
// 1 <= B <= 5 * 106
// -100 <= A[i] <= 100



// Input Format

// The first argument given is an integer array A.
// The second argument given is an integer B.



// Output Format

// Return an integer denoting the maximum array sum after B modifications.



// Example Input

// Input 1:

//  A = [24, -68, -29, -9, 84]
//  B = 4
// Input 2:

//  A = [57, 3, -14, -87, 42, 38, 31, -7, -28, -61]
//  B = 10


// Example Output

// Output 1:

//  196
// Output 2:

//  362


// Example Explanation

// Explanation 1:

 
// Operation 1: Make -29 to 29,
// Operation 2: Make -9 to 9,
// Operation 3: Make 9 to -9,
// Operation 4: Make -68 to 68.
// Thus, the final array after 4 modifications = [24, 68, 29, -9, 84]
// Explanation 2:

//  Final array after B modifications = [57, -3, 14, 87, 42, 38, 31, 7, 28, 61]


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
    if (minheap.empty()) return 0;
    int minVal = minheap[0];
    minheap[0] = minheap.back();
    minheap.pop_back();
    if (!minheap.empty()) {
        heapify(minheap, 0);
    }
    return minVal;
}

int Solution::solve(vector<int> &A, int B) {
    vector<int> minheap(A.begin(), A.end());

    for (int i = (minheap.size() - 2) / 2; i >= 0; i--) {
        heapify(minheap, i);
    }

    for (int i = 0; i < B; i++) {
        int smallest = extractMin(minheap);
        smallest = -smallest;
        insert(minheap, smallest);
    }

    int maxSum = 0;
    while (!minheap.empty()) {
        maxSum += extractMin(minheap);
    }

    return maxSum;
}
