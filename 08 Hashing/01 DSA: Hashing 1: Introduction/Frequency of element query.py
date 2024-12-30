# https://www.scaler.com/academy/mentee-dashboard/class/236104/assignment/problems/31492?navref=cl_tt_lst_nm

# Problem Description

# SCALER organizes a series of contests aimed at helping learners enhance their coding skills. Each learner can participate in multiple contests, and their participation is represented by integers in an array. The goal is to identify how frequently each learner has participated in these contests. This information will help SCALER determine which learners are participating the least, allowing them to provide targeted support and encouragement.


# Given an array A that represents the participants of various contests, where each integer corresponds to a specific learner, and an array B containing the learners for whom you want to check participation frequency, your task is to find the frequency of each learner from array B in the array A and return a list containing all these frequencies


# Problem Constraints

# 1 <= |A| <= 105
# 1 <= |B| <= 105
# 1 <= A[i] <= 105
# 1 <= B[i] <= 105


# Input Format

# First argument A is an array of integers.
# Second argument B is an array of integers denoting the queries.


# Output Format

# Return an array of integers containing the frequency of each learner in B as found in array A.


# Example Input

# Input 1:
# A = [1, 2, 1, 1]
# B = [1, 2]
# Input 2:
# A = [2, 5, 9, 2, 8]
# B = [3, 2]


# Example Output

# Output 1:
# [3, 1]
# Output 2:
# [0, 2]


# Example Explanation

# For Input 1:

# The frequency of learner 1 in the array A is 3 (they participated in three contests).
# The frequency of learner 2 in the array A is 1 (they participated in one contest).

# For Input 2:

# The frequency of learner 3 in the array A is 0 (they did not participate in any contest).
# The frequency of learner 2 in the array A is 2 (they participated in two contests).

class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return a list of integers
    def solve(self, A, B):
        frequency_map = {}
        
        for num in A:
            if num not in frequency_map:
                frequency_map[num] = 1
            else:
                frequency_map[num] += 1
        
        result = []
        for num in B:
            result.append(frequency_map.get(num, 0))
        
        return result
