# // Problem Description

# // On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

# // Given row number A and index B, return the Bth indexed symbol in row A. (The values of B are 0-indexed.).



# // Problem Constraints

# // 1 <= A <= 20

# // 0 <= B < 2A - 1



# // Input Format

# // First argument is an integer A.

# // Second argument is an integer B.



# // Output Format

# // Return an integer denoting the Bth indexed symbol in row A.



# // Example Input

# // Input 1:

# //  A = 3
# //  B = 0
# // Input 2:

# //  A = 4
# //  B = 4


# // Example Output

# // Output 1:

# //  0
# // Output 2:

# //  1


# // Example Explanation

# // Explanation 1:

# //  Row 1: 0
# //  Row 2: 01
# //  Row 3: 0110
# // Explanation 2:

# //  Row 1: 0
# //  Row 2: 01
# //  Row 3: 0110
# //  Row 4: 01101001

# //  https://www.scaler.com/academy/mentee-dashboard/class/236076/homework/problems/31810?navref=cl_tt_lst_nm



class Solution:
    # @param A : integer
    # @param B : integer
    # @return an integer
    def row(self, A):
        if A == 1:
            return [0]
        
        prev_row = self.row(A - 1)

        current_row = []
        
        for num in prev_row:
            if num == 0:
                current_row.append(0)
                current_row.append(1)  
            elif num == 1:
                current_row.append(1)
                current_row.append(0)  
        
        return current_row

    # Function to return the B-th element in the A-th row
    def solve(self, A, B):
        ans = self.row(A)
        return ans[B]
