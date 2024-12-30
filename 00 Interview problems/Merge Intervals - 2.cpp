// https://www.scaler.com/academy/mentee-dashboard/class/236112/assignment/problems/94299?navref=cl_tt_nv

// Problem Description

// You have a set of non-overlapping intervals. You are given a new interval [start, end], insert this new interval into the set of intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.



// Problem Constraints

// 0 <= |intervals| <= 105



// Input Format

// First argument is the vector of intervals

// second argument is the new interval to be merged



// Output Format

// Return the vector of intervals after merging



// Example Input

// Input 1:

// Given intervals [1, 3], [6, 9] insert and merge [2, 5] .
// Input 2:

// Given intervals [1, 3], [6, 9] insert and merge [2, 6] .


// Example Output

// Output 1:

//  [ [1, 5], [6, 9] ]
// Output 2:

//  [ [1, 9] ]


// Example Explanation

// Explanation 1:

// (2,5) does not completely merge the given intervals
// Explanation 2:

// (2,6) completely merges the given intervals

vector<vector<int> > Solution::insert(vector<vector<int> > &A, vector<int> &B) {
    vector<vector<int> >ans;
    int l=B[0], r=B[1];

    for(int i=0; i<A.size(); i++){
        if(l>A[i][1]){
            ans.push_back({A[i][0],A[i][1]});
        }
        else if (A[i][0]>r){
            ans.push_back({l,r});
            for(int j=i; j<A.size(); j++){
                ans.push_back({A[j][0],A[j][1]});
            }
            return ans;
        }
        else{
            l=min(A[i][0], l);
            r=max(A[i][1], r);
        }
    }
    ans.push_back({l,r});
    return ans;
}
