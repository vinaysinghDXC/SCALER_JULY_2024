# // https://www.scaler.com/academy/mentee-dashboard/class/236104/assignment/problems/10203?navref=cl_tt_nv

# // Problem Description

# // Given two integer arrays, A and B of size N and M, respectively. Your task is to find all the common elements in both the array.


# // NOTE:


# // Each element in the result should appear as many times as it appears in both arrays.
# // The result can be in any order.


# // Problem Constraints

# // 1 <= N, M <= 105

# // 1 <= A[i] <= 109



# // Input Format

# // First argument is an integer array A of size N.

# // Second argument is an integer array B of size M.



# // Output Format

# // Return an integer array denoting the common elements.



# // Example Input

# // Input 1:

# //  A = [1, 2, 2, 1]
# //  B = [2, 3, 1, 2]
# // Input 2:

# //  A = [2, 1, 4, 10]
# //  B = [3, 6, 2, 10, 10]


# // Example Output

# // Output 1:

# //  [1, 2, 2]
# // Output 2:

# //  [2, 10]


# // Example Explanation

# // Explanation 1:

# //  Elements (1, 2, 2) appears in both the array. Note 2 appears twice in both the array.
# // Explantion 2:

# //  Elements (2, 10) appears in both the array.

# // # Do not write code to include libraries, main() function or accept any input from the console.
# // # Initialization code is already written and hidden from you. Do not write code for it again.
class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return a list of integers
    def solve(self, A, B):
        # Just write your code below to complete the function. Required input is available to you as the function arguments.
        # Do not print the result or any output. Just return the result via this function.

        freq_map={}
        for num in A:
            if num not in freq_map:
                freq_map[num]=1
            else:
                freq_map[num]+=1

        ans = []
        for num2 in B:
            if num2 in freq_map and freq_map[num2] > 0:
                ans.append(num2)
                freq_map[num2] -= 1
                if freq_map[num2] <= 0:
                    del freq_map[num2]

        return ans
