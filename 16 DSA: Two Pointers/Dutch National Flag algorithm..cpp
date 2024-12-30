// Dutch National Flag algorithm.

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    // Your solution logic will go here
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() { 
    vector<int> nums1 = {2, 0, 2, 1, 1, 0}; 
    sortColors(nums1); 
    cout <<   "Test Case 1:"   ; 
    for (int num : nums1) cout << num; 
    cout <<   "(Expected: 0 0 1 1 2 2) "  << endl; 
 
    vector<int> nums2 = {2, 0, 1}; 
    sortColors(nums2); 
    cout <<   "Test Case 2: "  ; 
    for (int num : nums2) cout << num; 
    cout <<   "(Expected: 0 1 2)"   << endl; 
 
    vector<int> nums3 = {0}; 
    sortColors(nums3); 
    cout <<   "Test Case 3:"   ; 
    for (int num : nums3) cout << num; 
    cout <<   "(Expected: 0)"   << endl; 
 
    vector<int> nums4 = {1, 2, 0}; 
    sortColors(nums4); 
    cout <<   "Test Case 4:"   ; 
    for (int num : nums4) cout << num; 
    cout <<   "(Expected: 0 1 2)"   << endl; 
 
    return 0; 
} 