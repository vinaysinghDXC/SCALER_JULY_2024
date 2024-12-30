// https://www.scaler.com/academy/mentee-dashboard/class/236098/assignment/problems/27473?navref=cl_tt_nv

// Problem Description

// You are given an array A of N elements. Sort the given array in increasing order of number of distinct factors of each element, i.e., element having the least number of factors should be the first to be displayed and the number having highest number of factors should be the last one. If 2 elements have same number of factors, then number with less value should come first.

// Note: You cannot use any extra space


// Problem Constraints

// 1 <= N <= 104
// 1 <= A[i] <= 104


// Input Format

// First argument A is an array of integers.


// Output Format

// Return an array of integers.


// Example Input

// Input 1:
// A = [6, 8, 9]
// Input 2:
// A = [2, 4, 7]


// Example Output

// Output 1:
// [9, 6, 8]
// Output 2:
// [2, 7, 4]


// Example Explanation

// For Input 1:
// The number 9 has 3 factors, 6 has 4 factors and 8 has 4 factors.
// For Input 2:
// The number 2 has 2 factors, 7 has 2 factors and 4 has 3 factors.

int countFactors(int num) {
    int count = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i == num) 
                count++;  // Perfect square
            else 
                count += 2;  // Pair of factors
        }
    }
    return count;
}

int partition(vector<int> &arr, int s, int e){
    int pivot=arr[s];
    int l=s+1, r=e;
    while (l <= r) {
        int countL = countFactors(arr[l]);
        int countR = countFactors(arr[r]);
        int countPivot = countFactors(pivot);

        // Compare the number of factors
        if (countL < countPivot || (countL == countPivot && arr[l] < pivot)) {
            l++;
        } else if (countR > countPivot || (countR == countPivot && arr[r] > pivot)) {
            r--;
        } else {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    swap(arr[s], arr[r]);
    return r;
}

void quicksort(vector<int> &A, int s, int e){
    if(s>=e) return;
    int pi=partition(A, s, e);
    quicksort(A, s, pi-1);
    quicksort(A, pi+1, e);
}

vector<int> Solution::solve(vector<int> &A) {
    quicksort(A, 0, A.size() - 1);
    return A;
}
