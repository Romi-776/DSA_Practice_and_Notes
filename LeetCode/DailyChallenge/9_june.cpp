// Two Sum II - Input Array Is Sorted - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    // T.C = O(N), S.C = O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        
        // since the input array is sorted we can use two pointers
        // to find the index of two numbers whose sum equals target
        int lo = 0, hi = numbers.size()-1;
        
        // until we are at different indices
        while (lo < hi) {
            int sum = numbers[lo]+numbers[hi];
            // if we found the sum or target then we are done
            if (sum == target) {
                ans.push_back(lo+1), ans.push_back(hi+1);
                break;
            } 
            // otherwise sum is greater than target then we have to go towards smaller sum
            else if (sum > target) hi--; 
            // otherwise we have to go towards larger sum
            else lo++;
        }
        
        return ans;
    }
};