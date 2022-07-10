// Smallest Number in Infinite Set - https://leetcode.com/problems/smallest-number-in-infinite-set/

// T.C = O(nlog(n)), S.C = O(n)
/*
INTUITION
Simple implementation where we're using priority queue to get smallest element in our set
and map to check that which element is present or not while inserting or deleting.
*/
class SmallestInfiniteSet
{
    // smallest element at top priority_queue
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp; // to store the frequency or presence of the element

public:
    SmallestInfiniteSet()
    {
        // filling our set with all the possible values that can occur
        for (int i = 1; i <= 10000; i++)
            pq.push(i), mp[i]++;
    }

    int popSmallest()
    {
        // deleting the smallest element from our set
        int n = pq.top();
        pq.pop();
        mp[n] = 0;
        return n;
    }

    void addBack(int num)
    {
        // element not present so need to add back to our set
        if (mp[num] == 0)
            mp[num]++, pq.push(num);
    }
};