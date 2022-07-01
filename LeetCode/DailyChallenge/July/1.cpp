// Maximum Units on a Truck - https://leetcode.com/problems/maximum-units-on-a-truck/

// T.C = O(Nlog(N)), S.C = O(1)
/*
INTUITION
Max units will be possible if the truck carries as much of those boxes
that have max number of units in each box
*/
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        // sorting the boxes having mostUnits at front and least at end
        sort(boxTypes.begin(), boxTypes.end(), comp);

        // counting possible max units that truck can carry
        int units = 0;
        for (auto i : boxTypes)
        {
            // truck have some space
            if (truckSize)
            {
                // possible boxes (of current type) that can be put on truck
                int currPossibleUnits = min(i[0], truckSize);
                // units of that type of boxes
                units += currPossibleUnits * i[1];
                // truck capacity decreased
                truckSize -= currPossibleUnits;
            }
            else
                break; // truck is full
        }

        return units;
    }
};