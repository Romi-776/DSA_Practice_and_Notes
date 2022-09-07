/*
INTUITION:
Going to the leaf node position where this node should be located and then inserting the node at that
position in the tree.
*/

// if the tree is height balanced BST
// T.C = O(log(n)), S.C = O(1)
// otherwise T.C = O(N) as all the nodes are connected like linked list
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // node to be inserted
        TreeNode *node = new TreeNode(val);
        if (root)
        {
            // iterator to iterate over the tree
            TreeNode *ptr = root;

            // unless we're not at null
            while (ptr)
            {
                // we need to insert our node to the right
                if (ptr->val < val)
                {
                    // if there's another node already to the right then go further
                    if (ptr->right)
                        ptr = ptr->right;
                    else
                    {
                        // otherwise add the node and stop the process
                        ptr->right = node;
                        break;
                    }
                }
                // similarly for the left side of curr node
                else
                {
                    if (ptr->left)
                        ptr = ptr->left;
                    else
                    {
                        ptr->left = node;
                        break;
                    }
                }
            }
        }
        else
            root = node; // when root is null then node to be inserted will be root

        // root of the modified tree
        return root;
    }
};