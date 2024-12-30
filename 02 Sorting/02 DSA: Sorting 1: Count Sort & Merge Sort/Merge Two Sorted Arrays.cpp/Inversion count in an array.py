# // https://www.scaler.com/academy/mentee-dashboard/class/236086/homework/problems/4190?navref=cl_tt_nv

# // Problem Description

# // Given an array of integers A. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A. Find the total number of inversions of A modulo (109 + 7).



# // Problem Constraints

# // 1 <= length of the array <= 105

# // 1 <= A[i] <= 109



# // Input Format

# // The only argument given is the integer array A.



# // Output Format

# // Return the number of inversions of A modulo (109 + 7).



# // Example Input

# // Input 1:

# // A = [1, 3, 2]
# // Input 2:

# // A = [3, 4, 1, 2]


# // Example Output

# // Output 1:

# // 1
# // Output 2:

# // 4


# // Example Explanation

# // Explanation 1:

# // The pair (1, 2) is an inversion as 1 < 2 and A[1] > A[2]
# // Explanation 2:

# // The pair (0, 2) is an inversion as 0 < 2 and A[0] > A[2]
# // The pair (0, 3) is an inversion as 0 < 3 and A[0] > A[3]
# // The pair (1, 2) is an inversion as 1 < 2 and A[1] > A[2]
# // The pair (1, 3) is an inversion as 1 < 3 and A[1] > A[3]

class Solution:
    # @param A : list of integers
    # @return an integer
    def merge_count_split_inv(self, arr, temp_arr, left, mid, right):
        i = left    # Starting index for left subarray
        j = mid + 1 # Starting index for right subarray
        k = left    # Starting index to be sorted
        inv_count = 0
  
        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp_arr[k] = arr[i]
                i += 1
            else:
                temp_arr[k] = arr[j]
                inv_count += (mid-i + 1)
                j += 1
            k += 1
  
        while i <= mid:
            temp_arr[k] = arr[i]
            i += 1
            k += 1
  
        while j <= right:
            temp_arr[k] = arr[j]
            j += 1
            k += 1
  
        for i in range(left, right + 1):
            arr[i] = temp_arr[i]
              
        return inv_count
  
    def merge_sort_and_count(self, arr, temp_arr, left, right):
        MOD = 10**9 + 7
        inv_count = 0
        if left < right:
            mid = (left + right)//2
  
            inv_count += self.merge_sort_and_count(arr, temp_arr, left, mid)
            inv_count += self.merge_sort_and_count(arr, temp_arr, mid + 1, right)
            inv_count += self.merge_count_split_inv(arr, temp_arr, left, mid, right)
  
        return inv_count % MOD

    def solve(self, A):
        temp_arr = [0]*len(A)
        return self.merge_sort_and_count(A, temp_arr, 0, len(A) - 1)
