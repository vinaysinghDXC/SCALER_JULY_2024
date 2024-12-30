// https://www.scaler.com/academy/mentee-dashboard/class/297849/assignment/problems/168773?navref=cl_tt_nv_dd

// Problem Description

// You are given an array B of meeting time intervals where each interval is represented as [start, end] (with start < end). You need to find the minimum number of conference rooms required to host all the meetings.


// Problem Constraints

// 1 <= B.length <= 104
// 0 <= start < end <= 106


// Input Format

// The first line contains an integer n, the number of meetings.
// The next n lines each contain two space-separated integers start and end representing the start and end times of the meetings.


// Output Format

// Output a single integer representing the minimum number of conference rooms required.


// Example Input

// Input 1:
// A = 3
// B = [ [0, 30],
//       [5, 10],
//       [15, 20] ]
// Input 2:
// A = 1
// B = [ [0, 1] ]


// Example Output

// Output 1:
// 2
// Output 2:
// 1


// Example Explanation

// Explanation 1:
// We need two rooms: 

// Room 1: [0, 30] 

// Room 2: [5, 10], [15, 20]
// Explanation 2:
// Since there is only one meeting, we need one room


int Solution::solve(int A, vector<vector<int> > &B) {
    int maxmeetingduration=B[0][0];

    for (int i = 0; i<B.size(); i++){
        for (int j = 0; j<B[0].size(); j++){
            maxmeetingduration=max(maxmeetingduration, B[i][j]);
        }
    }

    vector<int> delta(maxmeetingduration+1, 0);

    for (int i = 0; i< B.size(); i++){
        int start_time=B[i][0];
        int end_time=B[i][1];
        delta[start_time] += 1;
        delta[end_time] -= 1;
    }
    int ans=delta[0];
    for (int i = 1; i<delta.size(); i++){
        delta[i]=delta[i-1]+delta[i];
        ans = max(ans, delta[i]);
    }

    return ans;
}
