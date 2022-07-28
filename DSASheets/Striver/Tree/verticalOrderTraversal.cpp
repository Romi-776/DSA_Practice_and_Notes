// SOL-1 | T.C = O(NlogN + M*NlogN) where M = no. of columns | S.C = O(N)
// My naive solution

// to store which node corresponds to which column and occurred at which level
map<int, vector<pair<int, int>>> mp;

void pre(TreeNode *node, int col, int level)
{
    if (node)
    {
        // adding the node into column with its value and level
        mp[col].push_back({level, node->val});
        if (node->left)
            pre(node->left, col - 1, level + 1);
        if (node->right)
            pre(node->right, col + 1, level + 1);
    }
}

public:
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root)
    {
        // performing preorder traversal
        pre(root, 0, 0);

        // getting all the nodes from each column in ascending order of col value
        for (auto nodes : mp)
        {
            // sorting the nodes according to their column first and then value
            auto start = nodes.second.begin(), end = nodes.second.end();
            sort(start, end);
            // getting all the nodes in correct order
            vector<int> v;
            for (auto node : nodes.second)
                v.push_back(node.second);
            ans.push_back(v);
        }
    }
    return ans;
}