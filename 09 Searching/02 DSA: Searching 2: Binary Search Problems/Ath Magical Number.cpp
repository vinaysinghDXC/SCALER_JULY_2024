// https://www.scaler.com/academy/mentee-dashboard/class/236114/homework/problems/5697?navref=cl_tt_nv

// Problem Description

// You are given three positive integers, A, B, and C.

// Any positive integer is magical if divisible by either B or C.

// Return the Ath smallest magical number. Since the answer may be very large, return modulo 109 + 7.

// Note: Ensure to prevent integer overflow while calculating.



// Problem Constraints

// 1 <= A <= 109

// 2 <= B, C <= 40000



// Input Format

// The first argument given is an integer A.

// The second argument given is an integer B.

// The third argument given is an integer C.



// Output Format

// Return the Ath smallest magical number. Since the answer may be very large, return modulo 109 + 7.



// Example Input

// Input 1:

//  A = 1
//  B = 2
//  C = 3
// Input 2:

//  A = 4
//  B = 2
//  C = 3


// Example Output

// Output 1:

//  2
// Output 2:

//  6


// Example Explanation

// Explanation 1:

//  1st magical number is 2.
// Explanation 2:

//  First four magical numbers are 2, 3, 4, 6 so the 4th magical number is 6.

long long gcd(long long a, long long b) { 
    // Using Euclid's algorithm for GCD
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Solution::solve(int A, int B, int C) {
    int mod = 1e9+7;

    long long l = min(B, C);
    long long r = (long long)A * min(B, C);
    
    long long lcm = ((long long)B * (long long)C) / gcd(B, C);
    long long ans = min(B, C);  
    
    while (l <= r) {
        long long m = l + (r - l) / 2;
        long long count = m / B + m / C - m / lcm;
        
        if (count == A) {
            ans = m; 
            r = m - 1; 
        } else if (count < A) {
            l = m + 1; 
        } else {
            r = m - 1;
        }
    }
    
    return ans % mod;
}
