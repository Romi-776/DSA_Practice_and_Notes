// CONSTRUCTING BINARY TREE FROM PRE AND INORDER
/*
INTUITION
At the start of every pre, we have the root of the current subtree. We just need to find index of root
(same node) in inorder then the left nodes are in left subtree and the right nodes are in right subtree.
So, we can build the tree recursively.

// T.C = O(N^2), S.C = O(N)
*/
class Solution
{
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        if (pre.size() and in.size())
        {
            // new pre and in order traversals for left and right subtrees
            vector<int> pl, il, pr, ir;

            // indx of root node in pre
            int indx = 0;
            for (int i = 0; i < in.size(); i++)
                if (in[i] == pre[0])
                {
                    indx = i;
                    break;
                }

            // filling new pre and in
            int j = 1;
            for (int i = 0; i < indx; i++, j++)
                pl.push_back(pre[j]), il.push_back(in[i]);
            for (int i = indx + 1; i < in.size(); j++, i++)
                pr.push_back(pre[j]), ir.push_back(in[i]);

            // creating new root node
            TreeNode *root = new TreeNode(pre[0]);

            // pre for left and in for right subtrees
            root->left = buildTree(pl, il);
            root->right = buildTree(pr, ir);

            return root;
        }
        return NULL;
    }
};

// Sol2 : With hashmap for searching the pos of root node
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int rootIdx = 0;
        unordered_map<int, int> hmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            hmap[inorder[i]] = i;
            // value -> index mapping for inorder array
        }
        return build(preorder, inorder, rootIdx, 0, inorder.size() - 1, hmap);
    }

    //***Note*** that rootIdx is passed as reference
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int left, int right, unordered_map<int, int> &hmap)
    {
        if (left > right)
            return nullptr;

        int pivot = hmap[preorder[rootIdx]];
        TreeNode *node = new TreeNode(inorder[pivot]); // inorder[pivot] == prorder[rootIdx]
        rootIdx++;

        node->left = build(preorder, inorder, rootIdx, left, pivot - 1, hmap);
        // rootIdx value gets changed after successive calls to build the left subtree
        // Since it is passed as reference, updated value of rootIdx is passed to build
        // the right subtree
        node->right = build(preorder, inorder, rootIdx, pivot + 1, right, hmap);

        return node;
    }
};

// SOL3 : ITERATIVE
class Solution
{
public
    TreeNode buildTree(int[] preorder, int[] inorder)
    {
        // deal with edge case(s)
        if (preorder.length == 0)
        {
            return null;
        }

        // build a map of the indices of the values as they appear in the inorder array
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < inorder.length; i++)
        {
            map.put(inorder[i], i);
        }

        // initialize the stack of tree nodes
        Stack<TreeNode> stack = new Stack<>();
        int value = preorder[0];
        TreeNode root = new TreeNode(value);
        stack.push(root);

        // for all remaining values...
        for (int i = 1; i < preorder.length; i++)
        {
            // create a node
            value = preorder[i];
            TreeNode node = new TreeNode(value);

            if (map.get(value) < map.get(stack.peek().val))
            {
                // the new node is on the left of the last node,
                // so it must be its left child (that's the way preorder works)
                stack.peek().left = node;
            }
            else
            {
                // the new node is on the right of the last node,
                // so it must be the right child of either the last node
                // or one of the last node's ancestors.
                // pop the stack until we either run out of ancestors
                // or the node at the top of the stack is to the right of the new node
                TreeNode parent = null;
                while (!stack.isEmpty() && map.get(value) > map.get(stack.peek().val))
                {
                    parent = stack.pop();
                }
                parent.right = node;
            }
            stack.push(node);
        }

        return root;
    }
}