# https://www.scaler.com/academy/mentee-dashboard/class/236166/assignment/problems/4827?navref=cl_tt_nv

# Problem Description

# Given an array of integers A and an integer B.
# Find the total number of subarrays having sum equals to B.


# Problem Constraints

#  1 <= length of the array <= 50000
# -1000 <= A[i] <= 1000


# Input Format

# The first argument given is the integer array A.
# The second argument given is integer B.


# Output Format

# Return the total number of subarrays having sum equals to B.


# Example Input

# Input 1:
# A = [1, 0, 1]
# B = 1
# Input 2:
# A = [0, 0, 0]
# B = 0


# Example Output

# Output 1:
# 4
# Output 2:
# 6


# Example Explanation

# Explanation 1:
# [1], [1, 0], [0, 1] and [1] are four subarrays having sum 1.
# Explanation 1:
# All the possible subarrays having sum 0.

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        presum = 0
        count = 0
        presum_map = {0: 1}  
        for num in A:
            presum += num
            
            # Check if (presum - B) exists in the map
            if (presum - B) in presum_map:
                count += presum_map[presum - B]
            
            # Update the map with the current prefix sum
            if presum in presum_map:
                presum_map[presum] += 1
            else:
                presum_map[presum] = 1
        
        return count