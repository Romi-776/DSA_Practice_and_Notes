/*
OPTIMIZED SOLUTION:

Intuition:
Maintain an upper_bound for all the nodes and check that each node follows the upper bound criteria or not
and build the tree recursively.

T.C = O(N)
S.C = O(N)
*/
class Solution {
    // node that need to be processed
    int curr_pos = 0;
    TreeNode *construct(vector<int> &preorder, int upper_bound = INT_MAX) {
        // we processed all nodes or the curr_node doesn't fit upper_bound criteria
        if (curr_pos == preorder.size() or preorder[curr_pos] > upper_bound)
            return NULL;
        // creating new root for curr subtree
        TreeNode *root = new TreeNode(preorder[curr_pos++]);
        // left side should have upper_bound of curr_node's val
        root->left = construct(preorder, root->val);
        // right side have same bound as that of curr node
        root->right = construct(preorder, upper_bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // constructing bst recursively using upper bound logic for each node
        return construct(preorder);
    }
};


/*
MY NAIVE SOLUTION:
Recursively build the BST using below logic-
1. First node in preorder is root
2. All nodes smaller than root come in left subtree
3. All nodes larger than root come in right subtree
4. return the root of current subtree otherwise NULL.

Runtime: O(n * n) worst case, O(n log n) average case. For each node (n), we search for the split point (log n average, n worst case).
Memory: O(n) worst case, O(h) average case for the stack, where h is the height of the tree.

T.C = O(N^2)
S.C = O(N)
*/
class Solution {
    TreeNode* construct(vector<int>& preorder, int start, int end) {
        if (start <= end) {
            // first node in preorder is root
            TreeNode *root = new TreeNode(preorder[start]);

            // gathering all the nodes that are smaller than root
            int lend = start + 1;
            for (; lend <= end; lend++)
                if (preorder[lend] > preorder[start])
                    break;

            // all the nodes smaller than root come in left subtree
            root->left = construct(preorder, start + 1, lend - 1);

            // all the nodes larger than root come in right subtree
            root->right = construct(preorder, lend, end);

            return root;
        }
        return NULL;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size() - 1);
    }
};
