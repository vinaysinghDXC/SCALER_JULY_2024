#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::pair

// void sortVectors(std::vector<int>& A, std::vector<int>& B) {
//     int n = A.size();
//     std::vector<std::pair<int, int> > pairedVec;

//     // Combine A and B into a vector of pairs
//     for (int i = 0; i < n; ++i) {
//         pairedVec.push_back(std::make_pair(A[i], B[i]));
//     }

//     // Sort the paired vector based on the first element (A[i])
//     std::sort(pairedVec.begin(), pairedVec.end());

//     // Separate the sorted pairs back into A and B
//     for (int i = 0; i < n; ++i) {
//         A[i] = pairedVec[i].first;
//         B[i] = pairedVec[i].second;
//     }
// }

int main() {
    // std::vector<int> A(4);
    // A.push_back(4);
    // A.push_back(2);
    // A.push_back(9);
    // A.push_back(1);
    // std::vector<int> B(4);
    // B.push_back(40);
    // B.push_back(20);
    // B.push_back(90);
    // B.push_back(410);

    // sortVectors(A, B);

    // Print sorted A and rearranged B
    int A = 91;
    int B = sqrt(A);
    std::cout << "Sqrt of A: "<<B;
    // for (int a : A) std::cout << a << " ";
    // std::cout << "\nRearranged B: ";
    // for (int b : B) std::cout << b << " ";

    return 0;
}
