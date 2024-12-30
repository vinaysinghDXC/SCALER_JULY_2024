// https://www.scaler.com/academy/mentee-dashboard/class/297853/homework/problems/365?navref=cl_tt_crd_nm

// Problem Description

// Max Heap is a special kind of complete binary tree in which, for every node, the value present in that node is greater than the value present in its children nodes.




// Find the number of distinct Max Heap that can be made from A distinct integers.

// In short, you have to ensure the following properties for the max heap :

// Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
// Every node is greater than all its children.
// NOTE: If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.






// Problem Constraints

// 1 <= A <= 100



// Input Format

// The first and only argument is an integer A.



// Output Format

// Return an integer denoting the number of distinct Max Heap.



// Example Input

// Input 1:

//  A = 4
// Input 2:

//  A = 10


// Example Output

// Output 1:

//  3
// Output 2:

//  3360


// Example Explanation

// Explanation 1:

//  Let us take 1, 2, 3, 4 as our 4 distinct integers
//  Following are the 3 possible max heaps from these 4 numbers :
//       4           4                     4
//     /  \         / \                   / \ 
//    3    2   ,   2   3      and        3   1
//   /            /                     /    
//  1            1                     2
// Explanation 2:

//  Number of distinct heaps possible with 10 distinct integers = 3360.


vector<vector<long long>> combination(int n, int k, int MOD) {
    vector<vector<long long>> result(n + 1, vector<long long>(k + 1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) {
            if(j == 0 || j == i) {
                result[i][j] = 1;
            }
            else {
                result[i][j] = (result[i - 1][j - 1] % MOD + result[i - 1][j] % MOD) % MOD;
            }
        }
    }
    
    return result;
}

int lst_ele(int total_elements) {
    if(total_elements == 1) return 0;
    
    int height = log2(total_elements);
    int max_elements_last = (1 << height);
    int actual_elements_last = total_elements - ((1 << height) - 1);

    if(actual_elements_last >= (max_elements_last / 2)) return (1 << height) - 1; //last level is more than half filled 
    
    return (1 << height) - 1 - (max_elements_last / 2) + actual_elements_last; //ast level is less than half filled
}

int Solution::solve(int A) {
    int MOD = 1e9+7;
    vector<vector<long long>> ncr = combination(A, A, MOD);
    
    vector<long long> dp(A + 1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= A; i++) {
        int left = lst_ele(i);
        dp[i] = ((ncr[i - 1][left] * dp[left]) % MOD * dp[i - 1 - left]) % MOD;
    }

    return dp[A];
}