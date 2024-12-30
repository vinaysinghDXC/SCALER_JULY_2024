// https://www.scaler.com/academy/mentee-dashboard/class/297865/assignment/problems/297?navref=cl_tt_nv

// Problem Description

// Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.







// If there is more than one solution possible, return the lexicographically smaller solution.

// If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then 
// [a, b] < [c, d], If a < c OR a==c AND b < d. 
// NOTE: A solution will always exist. Read Goldbach's conjecture.








// Problem Constraints

// 4 <= A <= 2*107



// Input Format

// First and only argument of input is an even number A.



// Output Format

// Return a integer array of size 2 containing primes whose sum will be equal to given number.



// Example Input

//  4


// Example Output

//  [2, 2]


// Example Explanation

//  There is only 1 solution for A = 4.

 vector<int> Solution::primesum(int A) {
    vector<int> isprime(A+1, 1);
    isprime[0]=0;
    isprime[1]=0;

    for (int i =2; i*i<=A; i++){
        if (isprime[i]==1){
            for (int j=i*i; j<=A; j+=i){
                isprime[j]=0;
            }
        }
    }

    for (int i =2; i<=A/2; i++){
        if(isprime[i] && isprime[A-i]) return {i, A-i};
    }
}

