// https://www.scaler.com/academy/mentee-dashboard/class/236080/homework/problems/122781?navref=cl_tt_nv

// Problem Description

// Print N numbers in Decreasing Order and then in Increasing Order.

// You are given a positive number N.
// You are required to print the numbers from N to 1.
// You are required to not use any loops. Don't change the signature of the function DecThenInc function.
// Note : Please print an new line after printing the output.


// Problem Constraints

// 1 <= N <= 100


// Input Format

// The first line contains a single integer N.


// Output Format

// A single line having number printed from N to 1 and then from 1 to N.


// Example Input

// Input 2:
// 1
// Input 1:
// 4


// Example Output

// Output 1:
// 1 1
// Output 2:
// 4 3 2 1 1 2 3 4


// Example Explanation

// Elements are First printer from N down to 1 and then 1 upto N.

void printNumbersDec(int A) {
    if (A == 0) {
        return;
    }
    cout << A << " ";
    printNumbersDec(A - 1);
}

void printNumbersInc(int A) {
    if (A == 0) {
        return;
    }
    printNumbersInc(A - 1);
    cout << A << " ";
    
}

void Solution::DecThenInc(int A) {
    printNumbersDec(A);
    printNumbersInc(A);
    cout<<endl;
}
