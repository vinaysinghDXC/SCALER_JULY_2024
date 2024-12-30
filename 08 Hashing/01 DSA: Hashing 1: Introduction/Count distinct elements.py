# https://www.scaler.com/academy/mentee-dashboard/class/236104/assignment/problems/27502?navref=cl_tt_nv

# Problem Description

# Given an array A of N integers, return the number of unique elements in the array.


# Problem Constraints

# 1 <= N <= 105
# 1 <= A[i] <= 109


# Input Format

# First argument A is an array of integers.


# Output Format

# Return an integer.


# Example Input

# Input 1:
# A = [3, 4, 3, 6, 6]
# Input 2:
# A = [3, 3, 3, 9, 0, 1, 0]


# Example Output

# Output 1:
# 3
# Output 2:
# 4


# Example Explanation

# For Input 1:
# The distinct elements of the array are 3, 4 and 6.
# For Input 2:
# The distinct elements of the array are 3, 9, 0 and 1.

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        unique_set = set()
        for num in A:
            if num not in unique_set:
                unique_set.add(num)
            else:
                unique_set.add(num)

        return len(unique_set)
