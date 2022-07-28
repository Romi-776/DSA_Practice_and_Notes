// Similarly we can do it using BFS traversal by storing only the col values

// SOL-1 (Using DFS Traversal)
//| T.C = O(NlogN), S.C = O(N)

// to store the col, level, and node for top view nodes retrieval
map<int, pair<int, int>> mp;

void pre(Node *root, int col, int level)
{
    if (root)
    {
        // if this col have never been visited or this node at the current col
        // comes at a level above the node which was already visited in the same col
        if (mp.find(col) == mp.end() or mp[col].first > level)
            mp[col] = {level, root->data}; // then get it into our data
        pre(root->left, col - 1, level + 1);
        pre(root->right, col + 1, level + 1);
    }
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root)
    {
        // preORder traversal
        pre(root, 0, 0);

        // getting the top view from the map sorted according to col value from left to right
        for (auto i : mp)
            ans.push_back(i.second.second);
    }
    return ans;
}