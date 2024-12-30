// https://www.scaler.com/academy/mentee-dashboard/class/236078/homework/problems/66?navref=cl_tt_lst_sl

// Problem Description

// Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).






// The digits are stored such that the most significant digit is at the head of the list.

// NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: for this problem, the following are some good questions to ask :

// Q: Can the input have 0's before the most significant digit. Or, in other words, is 0 1 2 3 a valid input?
// A: For the purpose of this question, YES
// Q: Can the output have 0's before the most significant digit? Or, in other words, is 0 1 2 4 a valid output?
// A: For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.







// Problem Constraints

// 1 <= size of the array <= 1000000



// Input Format

// First argument is an array of digits.



// Output Format

// Return the array of digits after adding one.



// Example Input

// Input 1:

// [1, 2, 3]


// Example Output

// Output 1:

// [1, 2, 4]


// Example Explanation

// Explanation 1:

// Given vector is [1, 2, 3].
// The returned vector should be [1, 2, 4] as 123 + 1 = 124.

vector<int> Solution::plusOne(vector<int> &A) {

    vector<int> ans(A.size()+1, 0);

    for(int i=A.size(); i>=0; i--){
        ans[i]=A[i-1];
    }
    ans[A.size()]++;

    if((ans[A.size()]/10)>0){
        int e=A.size();
        int carry=0;
        while(e>=0 && carry>=0){
            int temp=ans[e];
            ans[e]=(ans[e]+carry)%10;
            carry=(temp+carry)/10;
            e--;
        }
    }

    int firstNonZeroIndex = 0;
    while (firstNonZeroIndex < ans.size() && ans[firstNonZeroIndex] == 0) {
        firstNonZeroIndex++;
    }

    // Remove leading zeros
    ans.erase(ans.begin(), ans.begin() + firstNonZeroIndex);

    return ans;
}
