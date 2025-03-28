#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int max_sum = INT_MIN;  // Correctly initialized for negative numbers
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];  
            max_sum = max(max_sum, sum);  

            //  If sum is lesser than 0 then 
            if (sum < 0) {
                sum = 0;
            }
        }

        return max_sum;
    }
};

int main() {
    vector<int> arr = {-2, -4};  // Example with negative numbers
    Solution s;
    cout << "Maximum Subarray Sum: " << s.maxSubarraySum(arr) << endl;

    return 0;
}


//  Time complexity of this code is O(n) and space complexity is O(1) .

