/*
We need to find the minimum (total) time needed to reach each and every node from a target node while 
traversing in breadth-wise manner in all directions.

1. Find pos of target node
2. Set parent pointer for each node 
3. Traverse all unvisited nodes in all directions and count the time
*/
class Solution
{
    // pointer to the target node
    Node *target = NULL;
    void find_target(Node *root, int targ)
    {
        if (root)
        {
            if (root->data == targ)
            {
                target = root;
                return;
            }

            find_target(root->left, targ);
            find_target(root->right, targ);
        }
    }

public:
    int minTime(Node *root, int targ)
    {
        int time = 0;
        if (root)
        {
            // finding the target node from where to start
            find_target(root, targ);

            // Using the BFS traversal trying to
            // create upward pointers that will help us to move in up and down dir
            unordered_map<Node *, Node *> up;
            queue<Node *> q;
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
            unordered_map<Node *, bool> vis;

            // Again, using BFS traversal, trying to go to all the nodes that are not
            // visited in all directions and counting the total time to visit all of them
            q.push(target);
            vis[target] = true;

            while (q.size())
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
                time++;
            }
        }
        return time - 1;
    }
};

/*
We can also try it by slightly different approach. After making parent map, instead of taking another bfs to find the time, You can find the 
height  of tree  using dfs considering target node as root node and also taking the help of visited map. The code of this part is similar to 
find the height or bt with slight modification.
*/
 
int height(Node* root ,   unordered_map<Node*,Node*>&par ,  unordered_map<Node*, int>&vis)
{
    if(!root)
    return 0;
    
    vis[root]=1;
    
    int lh= INT_MIN;
     int rh= INT_MIN;
      int ph= INT_MIN;
    
    if(!vis[root->left])
     lh= height(root->left, par, vis);
      if(!vis[root->right])
        rh= height(root->right, par, vis);
          if(!vis[par[root]])
        ph= height(par[root] , par, vis);
    
    return  max(ph, max(lh,rh)) +1;
}

The final ans will be height-1;