// Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved.


// Input Format

// The only argument given is string A.
// Output Format

// Return the length of the longest consecutive 1’s that can be achieved.
// Constraints

// 1 <= length of string <= 1000000
// A contains only characters 0 and 1.
// For Example

// Input 1:
//     A = "111000"
// Output 1:
//     3

// Input 2:
//     A = "111011101"
// Output 2:
//     7

int Solution::solve(string A) {
    int to=0;
    for (int i=0; i<A.length(); i++){
        if (A[i]=='1') to++;
    }
    if (to==0) return 0;
    if (to==A.length()) return A.length();

    int maxone=0;
    for (int i=0; i<A.length(); i++){
        if(A[i]=='0'){
            int l=0;
            for (int j=i-1; j>=0; j--){
                if (A[j]=='1') l++;
                else break;
            }
            int r=0;
            for (int j=i+1; j<A.length(); j++){
                if (A[j]=='1') r++;
                else break;
            }
            int fac=l+r;
            if (fac<to) fac=fac+1;
            maxone=max(maxone, fac);
        }
    }
    return maxone;
}
