#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int getSecondLargest(vector<int>& arr) {
            int size = arr.size();
            if(size < 2) return -1; // If there are less than 2 elements, return -1
            
            int max = arr[0];
            int secondMax = -1; // Initialize secondMax as -1, assuming all values are non-negative
            
            for(int i = 1; i < size; i++) {
                if(arr[i] > max) {
                    secondMax = max;
                    max = arr[i];
                }
                else if(arr[i] < max && arr[i] > secondMax) {
                    secondMax = arr[i];
                }
            }

            return secondMax; // Return the second largest element
        }
};

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    Solution s1;
    cout << s1.getSecondLargest(arr);  // Output should be 34
    return 0;
}
