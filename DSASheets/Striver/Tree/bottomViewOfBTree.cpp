// Similarly it can be done using BFS traversal by storing only col and changing the node in map
// at each col as new node will come for the same level 

// Using DFS Traversal
// T.C = O(NlogN), S.C = O(N)
map<int, pair<int, int>> mp;

void pre(Node *root, int col, int level)
{
    if (root)
    {
        // if this col have never been visited or this node at the current col
        // comes at a level below the node which was already visited in the same col
        // or is the rightmost at the same level
        if (mp.find(col) == mp.end() or mp[col].first <= level)
            mp[col] = {level, root->data}; // then get it into our data
        pre(root->left, col - 1, level + 1);
        pre(root->right, col + 1, level + 1);
    }
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root)
    {
        // preORder traversal
        pre(root, 0, 0);

        // getting the bottom view from the map sorted according to col value from left to right
        for (auto i : mp)
            ans.push_back(i.second.second);
    }
    return ans;
}