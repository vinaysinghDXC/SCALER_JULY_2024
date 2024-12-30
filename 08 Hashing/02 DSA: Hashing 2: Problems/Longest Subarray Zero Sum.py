# https://www.scaler.com/academy/mentee-dashboard/class/236166/assignment/problems/27742?navref=cl_tt_nv

# Problem Description

# Given an array A of N integers.
# Find the length of the longest subarray in the array which sums to zero.

# If there is no subarray which sums to zero then return 0.



# Problem Constraints

# 1 <= N <= 105
# -109 <= A[i] <= 109


# Input Format

# Single argument which is an integer array A.


# Output Format

# Return an integer.


# Example Input

# Input 1:

#  A = [1, -2, 1, 2]
# Input 2:

#  A = [3, 2, -1]


# Example Output

# Output 1:

# 3
# Output 2:

# 0


# Example Explanation

# Explanation 1:

#  [1, -2, 1] is the largest subarray which sums up to 0.
# Explanation 2:

#  No subarray sums up to 0.

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        sub_len=0
        presum=0
        freq_map={0:-1}

        for i in range(len(A)):
            presum+=A[i]

            if presum in freq_map:
                sub_len=max(sub_len, (i-freq_map[presum]))
            else:
                freq_map[presum]=i

        return sub_len
