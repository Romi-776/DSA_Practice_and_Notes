/*
OPTIMIZATION OF BELOW WRITTEN APPROACH:
We can't Optimize the t.c further as we have to traverse to all the nodes in order to find the nth
smallest node from our tree in worst case. But we can save space by not storing the nodes and only storing the
answer. We can use a counter variable so the we can keep track of the position of the node when they'll
be sorted.
*/
class Solution
{
    int ans;
    int counter = 0;
    void inorder(TreeNode *root, int k)
    {
        if (root and counter != k)
        {
            inorder(root->left, k);
            // it will tell us that we're on what position
            // when nodes are sorted  
            counter++;

            // so when we're at kth smallest node then we'll add
            // it to our answer
            if (counter == k) ans = root->val;

            inorder(root->right, k);
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }
};

/*
INTUITION:
Since, Inorder Traversal of BST will give us nodes in ascending order. So, we can first traverse tree
and collect all the nodes using inorder traversal and then return the kth node from our collection of
nodes.
*/
// T.C = O(N), S.C = O(N) + O(N)
// One for recursive stack and other for nodes vector
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

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return nodes[k - 1];
    }
};