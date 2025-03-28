#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int left = 0, sum = 0, n = arr.size();

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink window from left if sum exceeds target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            // Check if current window sum matches target
            if (sum == target) {
                return {left + 1, right + 1};  // 1-based index
            }
        }

        return {-1};  // If no subarray found
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 4, 20, 3, 10, 5}; // Sample input
    int target = 33;

    vector<int> result = sol.subarraySum(arr, target);

    if (result.size() == 1 && result[0] == -1) {
        cout << "No subarray with given sum found" << endl;
    } else {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    }

    return 0;
}


//  Time complexity of this code is O(n) and space complexity is : = O(1)