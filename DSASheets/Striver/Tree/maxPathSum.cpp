// 9. Binary Tree Maximum Path Sum

// T.C = O(N), S.C = O(N) for recursive stack

// finding the possible max_path_sum with the help of a function
// similar to finding height and width of binary tree

class Solution
{
    // initial possible max_path_sum
    int maxSum = INT_MIN;

    int pathSum(TreeNode *root)
    {
        if (root)
        {
            // checking the max possible left sum
            int l = pathSum(root->left);
            // checking the max possible right sum
            int r = pathSum(root->right);

            // checking that left + root + right sum is greater than max sum
            maxSum = max(maxSum, root->val + l + r);

            // now checking that do we need to consider left or right path along with the root
            // for max possible value of path sum
            int sum = root->val + max(l, r);
            if (sum > 0)
                return sum;
        }

        // there's a null so returning 0
        return 0;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        pathSum(root);
        return maxSum;
    }
};