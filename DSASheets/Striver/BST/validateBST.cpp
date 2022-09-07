/*
Optimized Approach
INTUITION:
Assuming that there's some range in which each node should have a value to lie between.
At the start, range [LONG_MIN, LONG_MAX]
And if go left, range[minVal, val]
and if go right, range[val, maxVal]
and if any node is not in between the range then its not a BST.
*/
class Solution
{
    bool helper(TreeNode *curr, long minVal, long maxVal)
    {
        bool isValid = true;
        if (curr)
        {
            long val = curr->val;
            if (val >= maxVal or val <= minVal) return false;
            return helper(curr->left, minVal, val) and helper(curr->right, val, maxVal);
        }
        return isValid;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

/*
My Naive solution
INTUITION:
Inorder traversal of a BST gives us nodes in sorted order. So, we'll traverse the
tree using inorder traversal and store its node and then we'll check does the nodes
get are in sorted manner or not.

T.C = O(N) + O(N) // for inorder traversal and checking data is sorted or not
S.C = O(N) + O(N) // for recursive call stack and storing the nodes
*/
class Solution
{
    vector<int> nodes;
    void inorder(TreeNode *root)
    {
        if (root)
        {
            inorder(root->left);
            nodes.emplace_back(root->val);
            inorder(root->right);
        }
    }

    bool isSorted()
    {
        for (int i = 1; i < nodes.size(); i++)
            if (nodes[i] <= nodes[i - 1])
                return false;
        return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        inorder(root);
        return isSorted();
    }
};