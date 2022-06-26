// Maximum XOR After Operations

// T.C = O(Nlog(M)), S.C = O(M)
// Here, M = no. of bits in max number of array
/*
INTUITION
After some observation, I got to know that the max possible xor
of the whole array will be all possible set bits of the max number
(possible set bits are at positions of each set bit in any number of array)
*/
class Solution
{
    vector<int> decToBin(int n)
    {
        vector<int> v;
        while (n)
        {
            v.push_back(n % 2);
            n /= 2;
        }
        return v;
    }

public:
    int maximumXOR(vector<int> &nums)
    {
        int ma = INT_MIN;
        for (int i : nums)
            ma = max(ma, i);

        vector<int> v = decToBin(ma);
        for (int j : nums)
        {
            vector<int> vv = decToBin(j);
            for (int i = 0; i < vv.size(); i++)
                if (vv[i] == 1)
                    v[i] = 1;
        }
        reverse(v.begin(), v.end());
        int n = v.size() - 1;
        int num = 1;
        int ans = 0;
        for (int i = n; i >= 0; i--)
        {
            if (v[i])
                ans += num;
            num *= 2;
        }
        return ans;
    }
};