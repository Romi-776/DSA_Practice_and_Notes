/*
1. For each node, find its parent node and contain the pointer to that node's parent in a hashmap
2. From target, traverse each unvisited node in a bfs manner (in all directions) for k iterations
3. After the kth iteration, the q will store all the nodes that are at k distance from target and
that will be our answer

// T.C = O(N), S.C = O(N)
*/
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (root)
        {
            // Using the BFS traversal trying to
            // create upward pointers that will help us to move in up and down dir
            unordered_map<TreeNode *, TreeNode *> up;
            queue<TreeNode *> q;
            q.push(root);

            while (q.size())
            {
                int sz = q.size();
                while (sz--)
                {
                    root = q.front();
                    q.pop();

                    if (root->left)
                        up[root->left] = root, q.push(root->left);
                    if (root->right)
                        up[root->right] = root, q.push(root->right);
                }
            }

            // helps us to check that which nodes are already visited so that while
            // traversing we're not going up, down, up, down, ...
            unordered_map<TreeNode *, bool> vis;

            // Again, using BFS traversal, trying to get those nodes that are k
            // distance away from the target node into the q
            q.push(target);
            vis[target] = true;
            while (k--)
            {
                int sz = q.size();
                while (sz--)
                {
                    root = q.front();
                    q.pop();

                    // trying all possible ways to go that are not visited
                    if (root->left and !vis[root->left])
                        vis[root->left] = true, q.push(root->left);
                    if (root->right and !vis[root->right])
                        vis[root->right] = true, q.push(root->right);
                    if (up[root] and !vis[up[root]])
                        vis[up[root]] = true, q.push(up[root]);
                }
            }

            // now, q have required nodes so filling our ans vector
            while (q.size())
            {
                ans.push_back(q.front()->val);
                q.pop();
            }
        }

        return ans;
    }
};