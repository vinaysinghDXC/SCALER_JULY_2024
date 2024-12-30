// https://www.scaler.com/academy/mentee-dashboard/class/236112/assignment/problems/158403?navref=cl_tt_nv

// Problem Description

// Scaler Academy, a leading ed-tech platform known for its comprehensive learning programs, is planning to conduct maintenance on its website to enhance user experience and introduce new features.To ensure the maintenance work does not disrupt the scheduled meets of various batches, Scaler Academy aims to schedule this maintenance during the period of no user activity.

// Given sorted intervals A on the active hours of multiple learners on the platform and the scheduled meeting by [start, end], where time is denoted by numbers.

// Your task is to analyze this data and identify the longest continuous period when no meetings are scheduled before the end time B.

// This identified time slot is crucial as it represents the best opportunity to perform website maintenance with the least disruption to the scheduled meets of various batches.

// Refer the Example Explanation for better understanding!



// Problem Constraints

// 1 <= A.length <= 105
// A[i].length == 2
// 0 <= A[i][0] < A[i][1] <= 105
// A is sorted in non-decreasing order



// Input Format

// First Argument is a 2-D Integer Array A, of size Nx2.
// Second Argument is an Integer B.


// Output Format

// Return an Integer, denoting the longest continuous period.


// Example Input

// Input 1:
// A = [ [1, 3], [5, 8], [6, 7], [7, 9] ]
// B = 12
// Input 2:
// A = [ [0, 5], [2, 7] ]
// B = 7


// Example Output

// Output 1:
// 3
// Output 2:
// 0


// Example Explanation

// Explanation 1:
// Explanation
// The longest continuous period when no meetings are scheduled is [9, 12].

// Thus the answer is 3.
// Explanation 2:
// Explanation

// There is No free hours.  Thus the answer is 0.

int Solution::findLongestTime(vector<vector<int> > &A, int B) {
    
    int l=A[0][0], r=A[0][1];
    int ans=A[0][0];

    for(int i=1; i<A.size(); i++){
        if(A[i][0]<=r){
            r=max(A[i][1], r);
        }
        else{
            ans=max(A[i][0]-r, ans);
            l=A[i][0];
            r=A[i][1];
        }
    }
    ans=max(B-r, ans);
    return ans;
}
