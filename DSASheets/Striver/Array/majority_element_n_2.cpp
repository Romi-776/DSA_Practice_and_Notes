/*
OPTIMIZED SOLUTION:
Moore Voting Algo
Since the majority_ele occurs more than n/2 times then using this algo it will
always contain the extra count of the majority_ele and the remaining nums will be
cancelled with the remaining count of the majority_ele.
T.C = O(N), S.C = O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_ele = 0, count = 0;
        for (int i : nums) {
            if (!count) majority_ele = i;
            if (majority_ele == i) count++;
            else count--;
        }
        
        return majority_ele;
    }
};

/*
ANOTHER NAIVE SOLUTION:
Sorting the array and finding the max_freq_element
T.C = O(NLog(N)), S.C = O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max_freq = 1, ans = nums[0], curr = nums[0], freq = 1;
        for (int i = 1; i < int(nums.size()) ; i++) {
            if (nums[i] == curr) freq++;
            else freq = 1, curr = nums[i];
            if (freq > max_freq) max_freq = freq, ans = curr;
        }
        return ans;
    }
};

/*
MY NAIVE SOLUTION:
Using Freq map
T.C = O(N), S.C = O(N)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
            if (freq[i] > n/2) return i;
        }
        return -1;
    }
};