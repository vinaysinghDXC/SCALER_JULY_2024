// https://www.scaler.com/academy/mentee-dashboard/class/236098/homework/problems/267?navref=cl_tt_lst_nm

// Problem Description

// Given an array of integers A, sort the array into a wave-like array and return it.
// In other words, arrange the elements into a sequence such that

// a1 >= a2 <= a3 >= a4 <= a5..... 
// NOTE: If multiple answers are possible, return the lexicographically smallest one.



// Problem Constraints

// 1 <= len(A) <= 106
// 0 <= A[i] <= 106



// Input Format

// The first argument is an integer array A.



// Output Format

// Return an array arranged in the sequence as described.



// Example Input

// Input 1:

// A = [1, 2, 3, 4]
// Input 2:

// A = [1, 2]


// Example Output

// Output 1:

// [2, 1, 4, 3]
// Output 2:

// [2, 1]


// Example Explanation

// Explanation 1:

// One possible answer : [2, 1, 4, 3]
// Another possible answer : [4, 1, 3, 2]
// First answer is lexicographically smallest. So, return [2, 1, 4, 3].
// Explanation 1:

// Only possible answer is [2, 1].

void merge(vector<int> &A, int s, int e){
    int m = s+(e-s)/2;

    int n1=m-s+1;
    int n2=e-m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i =0; i<n1; i++){
        L[i]=A[s+i];
    }

    for (int i =0; i<n2; i++){
        R[i]=A[m+1+i];
    }

    int i =0, j=0, k=s;

    while(i<n1 && j<n2){
        if (L[i]<R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(vector<int> &A, int s, int e){
    if (s>=e) return;

    int m = s+(e-s)/2;

    mergeSort(A, s, m);
    mergeSort(A, m+1, e);

    merge(A, s, e);
}

void convertToWave(vector<int>& A) {
    for (int i = 0; i < A.size() - 1; i += 2) {
        swap(A[i], A[i + 1]);       // Swap adjacent elements
    }
}

vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();

    mergeSort(A, 0, n - 1);

    convertToWave(A);    

    return A; 
}
