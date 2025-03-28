  #include<iostream>
  #include<vector>
  using namespace std;
  // Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
  // Output: 8
  // Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.


  //  Logic :-

  //  we need to iterat 2 times the same arr , such that outer loop will told buying price and inner loop will told selling price.
  //  we will store the max profit in max_profit variable.
  //  we will return max_profit at the end of the function.


  class Solution {
    public:
      int maximumProfit(vector<int> &prices) {
          // code here
          // int max_profit = 0;
          int max =0;
          int size = prices.size();
          for(int i=0;i<size;i++)
          {
            for(int j=i+1;j<size;j++)
            {
            int max_profit = 0;
              
              max_profit = prices[j] - prices[i];
              if(max<max_profit)
              {
                max = max_profit ;
              }
            }
          
          }
          return max;
      }
  };



  int main()
  {
    Solution obj ;
    vector<int>prices = {1,3,6,9,11};
    cout<<"Maximum Profit is "<<obj.maximumProfit(prices);
    return 0 ;
  }

  //  Time Complexity: O(n^2) where n is the number of days.