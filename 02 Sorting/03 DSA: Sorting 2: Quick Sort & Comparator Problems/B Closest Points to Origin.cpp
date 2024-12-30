// https://www.scaler.com/academy/mentee-dashboard/class/236098/homework/problems/4194?navref=cl_tt_nv

// Problem Description

// You are developing a feature for Zomato that helps users find the nearest restaurants to their current location. It uses GPS to determine the user's location and has access to a database of restaurants, each with its own set of coordinates in a two-dimensional space representing their geographical location on a map. The goal is to identify the "B" closest restaurants to the user, providing a quick and convenient way to choose where to eat.

// Given a list of restaurant locations, denoted by A (each represented by its x and y coordinates on a map), and an integer B representing the number of closest restaurants to the user. The user's current location is assumed to be at the origin (0, 0).

// Here, the distance between two points on a plane is the Euclidean distance.

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

// NOTE: Euclidean distance between two points P1(x1, y1) and P2(x2, y2) is sqrt( (x1-x2)2 + (y1-y2)2).


// Problem Constraints

// 1 <= B <= length of the list A <= 105
// -105 <= A[i][0] <= 105
// -105 <= A[i][1] <= 105



// Input Format

// The argument given is list A and an integer B.



// Output Format

// Return the B closest points to the origin (0, 0) in any order.



// Example Input

// Input 1:

//  A = [ 
//        [1, 3],
//        [-2, 2] 
//      ]
//  B = 1
// Input 2:

//  A = [
//        [1, -1],
//        [2, -1]
//      ] 
//  B = 1


// Example Output

// Output 1:

//  [ [-2, 2] ]
// Output 2:

//  [ [1, -1] ]


// Example Explanation

// Explanation 1:

//  The Euclidean distance will be sqrt(10) for point [1,3] and sqrt(8) for point [-2,2].
//  So one closest point will be [-2,2].
// Explanation 2:

//  The Euclidean distance will be sqrt(2) for point [1,-1] and sqrt(5) for point [2,-1].
//  So one closest point will be [1,-1].

int getSquaredDistance(vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
}

void merge(vector<vector<int>>& A, vector<int>& distances, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> L(n1);
    vector<vector<int>> R(n2);
    vector<int> Ldist(n1), Rdist(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
        Ldist[i] = distances[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + 1 + i];
        Rdist[i] = distances[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Ldist[i] <= Rdist[j]) {
            A[k] = L[i];
            distances[k] = Ldist[i];
            i++;
        } else {
            A[k] = R[j];
            distances[k] = Rdist[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        distances[k] = Ldist[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        distances[k] = Rdist[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& A, vector<int>& distances, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, distances, left, mid);
        mergeSort(A, distances, mid + 1, right);

        merge(A, distances, left, mid, right);
    }
}

vector<vector<int>> Solution::solve(vector<vector<int>>& A, int B) {
    int n = A.size();
    vector<int> distances(n);
    
    for (int i = 0; i < n; i++) {   // Calculate the squared distance for each restaurant
        distances[i] = getSquaredDistance(A[i]);
    }

    mergeSort(A, distances, 0, n - 1);  // Sort the restaurants based on their distance using merge sort

    vector<vector<int>> result(A.begin(), A.begin() + B);   // Get the first B restaurants from the sorted list

    return result;
}
