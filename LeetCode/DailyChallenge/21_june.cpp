// Furthest Building You Can Reach - https://leetcode.com/problems/furthest-building-you-can-reach/

// Using maxHeap
// T.C = O(N*log(N)) S.C = O(N)
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {

        // stores the no. of bricks used for the largest jump
        priority_queue<int> largest_jump;

        // trying to go from the 1st to last building
        int i = 0, n = heights.size() - 1;
        while (i < n)
        {
            // we need to do a jump
            if (heights[i] < heights[i + 1])
            {
                // how much bricks we need
                int diff = heights[i + 1] - heights[i];

                // do we have req. bricks, if yes then subtract it from total and record this jump in largest_jumps
                if (diff <= bricks)
                    bricks -= diff, largest_jump.push(diff);
                else if (ladders > 0) // do we have a ladder if not req. bricks
                {
                    // but before that we're checking that do we have taken a jump that required more bricks than now
                    // if yes then we can take that jump using a ladder and the current one using bricks by saving bricks
                    // for further use
                    if (largest_jump.size())
                    {
                        int lj = largest_jump.top();
                        if (lj > diff)
                        {
                            bricks += lj - diff;
                            largest_jump.pop();
                            largest_jump.push(diff);
                        }
                    }
                    ladders--; // ladder will be used for either current or prev greatest jump
                }
                else
                    break; // we don't have a brick or a ladder so stopping now
            }
            i++; // going to the next building
        }
        return i;
    }
};