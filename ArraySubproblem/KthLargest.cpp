#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
        QuickSort(nums, low, high);
        return nums[nums.size() - k]; // Return Kth largest element
    }

    void QuickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int j = partition(nums, low, high);
            QuickSort(nums, low, j - 1);
            QuickSort(nums, j + 1, high);
        }
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high + 1;

        while (true) {
            do { i++; } while (i <= high && nums[i] < pivot);
            do { j--; } while (nums[j] > pivot);
            
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]); // Correct pivot placement
        return j; // Return pivot index
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution s1;
    int res = s1.findKthLargest(nums, k);
    cout << res;
    return 0;
}
