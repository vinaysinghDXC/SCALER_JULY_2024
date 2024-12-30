// https://www.scaler.com/academy/mentee-dashboard/class/297889/homework/problems/282?navref=cl_tt_nv_dd

// Problem Description

// There is a row of seats represented by string A. Assume that it contains N seats adjacent to each other.
// There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.





// An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

// Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

// In one jump a person can move to the adjacent seat (if available).

// NOTE: 1. Return your answer modulo 107 + 3.







// Problem Constraints

// 1 <= N <= 1000000
// A[i] = 'x' or '.'



// Input Format

// The first and only argument is a string A of size N.



// Output Format

// Return an integer denoting the minimum number of jumps required.



// Example Input

// Input 1:

//  A = "....x..xx...x.."
// Input 2:

//  A = "....xxx"


// Example Output

// Output 1:

//  5
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) 
//                  . . . . x . . x x . . . x . . 
//  Now to make them sit together one of approaches is -
//                  . . . . . . x x x x . . . . .
//  Steps To achieve this:
//  1) Move the person sitting at 4th index to 6th index: Number of jumps by him =   (6 - 4) = 2
//  2) Bring the person sitting at 12th index to 9th index: Number of jumps by him = (12 - 9) = 3
//  So, total number of jumps made: 2 + 3 = 5 which is the minimum possible.

//  If we other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.
 
// Explanation 2:

//  They are already together. So, the cost is zero.


//strategy to minimize the total number of moves is to position all 
//the people around the median of their current positions. because, 
//in a 1-dimensional space, median minimizes the sum of 
//absolute deviations. If we choose a position around the median, the number 
//of hops to move everyone will be minimized.

int Solution::seats(string A) {
    int MOD = 1e7 + 3;

    vector<int> positions;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 'x') {
            positions.push_back(i);
        }
    }
    
    if (positions.size() == 0) return 0;

    int median_index = positions.size() / 2;
    int median_pos = positions[median_index];

    long long total_hops = 0;

    int k = 1;
    for (int i = median_index -1 ; i>=0; i--) {
        total_hops = (total_hops + abs(median_pos-positions[i]-k)) % MOD;
        k++;
    }
    k=1;
    for (int i = median_index + 1; i < positions.size(); i++) {
        total_hops = (total_hops + abs(positions[i] - median_pos - k)) % MOD;
        k++;
    }

    return total_hops;
}

