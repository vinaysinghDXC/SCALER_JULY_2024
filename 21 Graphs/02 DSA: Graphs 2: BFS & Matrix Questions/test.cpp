#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int A = 5;
    vector<int> components(A + 1), size(A + 1, 1);
    iota(components.begin(), components.end(), 0);

    for (int i = 0; i<=A; i++){
        cout<<components[i]<<" ";
    }

    cout<<endl;

    return 0;
}
