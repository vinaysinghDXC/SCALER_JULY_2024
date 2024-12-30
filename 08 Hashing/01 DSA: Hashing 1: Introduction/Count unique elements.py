# https://www.scaler.com/academy/mentee-dashboard/class/236104/homework/problems/27543?navref=cl_tt_lst_nm

# Problem Description

# You are given an array A of N integers. Return the count of elements with frequncy 1 in the given array.


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
# 1
# Output 2:
# 2


# Example Explanation

# Explanation 1:
# Only the element 4 has a frequency 1.
# Explanation 2:
# The elements 9 and 1 has a frequncy 1.

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        freq_map={}
        for num in A:
            if num not in freq_map:
                freq_map[num]=1
            else:
                freq_map[num] += 1
        
        count=0
        for num in A:
            if freq_map[num]==1:
                count+=1
        
        return count

