/*
BEST SOLUTION:
Using the logic of BSTIterator, we can implement the next and before methods to
get next and before nodes in sorted order (asc, desc). And by using these methods, we
can implement this problem using 2 sum logic.

T.C = O(N), S.C = O(H)
*/
class Solution {
    stack<TreeNode*> st1, st2;
    
    void goto_extreme_left(TreeNode* curr) {
        while (curr) st1.push(curr), curr = curr->left;
    }
    
    void goto_extreme_right(TreeNode* curr) {
        while (curr) st2.push(curr), curr = curr->right;
    }
    
    int next() {
        TreeNode* temp = st1.top(); st1.pop();
        goto_extreme_left(temp->right);
        return temp->val;
    }
    
    int before() {
        TreeNode* temp = st2.top(); st2.pop();
        goto_extreme_right(temp->left);
        return temp->val;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        goto_extreme_left(root);
        goto_extreme_right(root);
        
        int l = next(), r = before();
        while (l < r) {
            if (l+r == k) return true;
            else if (l+r < k) l = next();
            else r = before();
        }
        return false;
    }
};

/*
OPTIMIZED SOLUTION:
Traverse over every node and store its value, while traversing check that do we have found a node with
val = k - curr_node_val if yes then true otherwise in the end false;

T.C = O(N), S.C = O(N)
*/
class Solution
{
    unordered_set<int> s;
    public:
        bool findTarget(TreeNode *root, int k)
        {
            if (root)
            {
                if (s.count(k - root->val)) return true;
                s.insert(root->val);
                return findTarget(root->left, k) or findTarget(root->right, k);
            }
            return false;
        }
};

/*
NAIVE SOLUTION:
Traverse over every node and check that can we find another node with value k - curr_node_val
and if found then return true else false

T.C = O(Nlog(n)), S.C = O(N)
*/
class Solution
{
    bool find(TreeNode *root, int n)
    {
        while (root)
        {
            if (root->val == n) return true;
            else if (root->val < n) root = root->right;
            else root = root->left;
        }
        return false;
    }
    public:
        bool findTarget(TreeNode *root, int k)
        {
            if (root)
            {
                TreeNode* r = root;
                queue<TreeNode*> q;
                q.push(root);

                while (q.size())
                {
                    int sz = q.size();
                    while (sz--)
                    {
                        root = q.front();
                        q.pop();

                        int num = k - root->val;
                        if (num != root->val and find(r, num)) return true;
                        if (root->left) q.push(root->left);
                        if (root->right) q.push(root->right);
                    }
                }
            }
            return false;
        }
};

/*
SIMPLEST APPROACH:
Use inorder traversal to store the nodes in sorted order and then apply two sum on it.
T.C = O(N), S.C = O(N)
*/