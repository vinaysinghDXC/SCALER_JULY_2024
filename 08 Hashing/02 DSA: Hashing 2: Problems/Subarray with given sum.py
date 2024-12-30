# https://www.scaler.com/academy/mentee-dashboard/class/236166/homework/problems/4116?navref=cl_tt_nv

# Problem Description

# Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B.






# If the answer does not exist return an array with a single integer "-1".

# First sub-array means the sub-array for which starting index in minimum.








# Problem Constraints

# 1 <= length of the array <= 100000
# 1 <= A[i] <= 109
# 1 <= B <= 109



# Input Format

# The first argument given is the integer array A.

# The second argument given is integer B.



# Output Format

# Return the first continuous sub-array which adds to B and if the answer does not exist return an array with a single integer "-1".



# Example Input

# Input 1:

#  A = [1, 2, 3, 4, 5]
#  B = 5
# Input 2:

#  A = [5, 10, 20, 100, 105]
#  B = 110


# Example Output

# Output 1:





#  [2, 3]
# Output 2:

#  [-1]






# Example Explanation

# Explanation 1:

#  [2, 3] sums up to 5.
# Explanation 2:

#  No subarray sums up to required number.

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of integers
    def solve(self, A, B):

        presum=0
        presum_map = {0: -1} 
        ei=-1
        si=-1
        
        for i in range(len(A)):
            presum+=A[i]
            if(presum-B) in presum_map:
                si=presum_map[presum-B]+1
                ei=i+1
                break

            presum_map[presum] = i
        
        si=si if si>=0 else 0

        if ei>=0: 
            return A[si:ei]
        return [-1]