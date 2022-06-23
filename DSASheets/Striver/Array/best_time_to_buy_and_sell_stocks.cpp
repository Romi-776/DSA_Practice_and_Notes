// Best Time to Buy and Sell Stock - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Sol2 (Optimized) - T.C = O(N), S.C = O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int left = 0, right = 1, max_profit = 0;

        // traversing all the prices using two pointers
        while (right < n)
        {
            // we have a pair where a previous prices is smaller than a later price which is profitable
            // so we're storing the max_profit that we can possibly get till now
            if (prices[left] < prices[right])
                max_profit = max(max_profit, prices[right] - prices[left]);
            
            // otherwise we have a pair where previous price is less than or equal to later price (not profitable)
            // so we need to go to a pair where previous prices is as small as possible so shifting our previous price
            // to the  
            else 
                left = right;
            right++;
        }
        return max_profit;
    }
};



// Sol1 (Naive Solution) - T.C = O(NlogN), S.C = O(M), where M = no. of unique elements in prices vector
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        map<int, int> mp;

        // storing the frequency of each price for later use
        for (int price : prices)
            mp[price]++;

        int max_profit = 0, n = prices.size();
    
        // now we're traversing from right to left in order to check that for the current price
        // do we have a smaller price such that the difference between them can be maximized
        for (int i = n - 1; i > 0; i--)
        {
            mp[prices[i]]--;
            if (!mp[prices[i]])
                mp.erase(prices[i]);
            int num = mp.begin()->first;
            max_profit = max(max_profit, prices[i] - num);
        }

        return max_profit;
    }
};
