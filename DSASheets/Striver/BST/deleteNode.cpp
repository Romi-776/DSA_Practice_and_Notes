/*
MY SOLUTION INTUITION:
1. find the node to be deleted while tracking its parent pointer
2. Go to the biggest node in its left subtree
3. Connect that node's right with the node_to_be_deleted's right subtree
4. Delete the node

NOTE: LONG CODE TO MAINTAIN SMALL EDGE CASES
*/
// T.C = O(H), S.C = O(1) for iterative
// S.C = O(1) for recursive
class Solution
{
    pair<TreeNode *, TreeNode *> find_node_to_be_deleted(TreeNode *root, int key)
    {
        TreeNode *ptr = root, *prev = NULL;
        while (ptr and ptr->val != key)
        {
            prev = ptr;
            if (ptr->val > key)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        return {ptr, prev};
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // finding the pos of node to be deleted
        pair<TreeNode *, TreeNode *> node = find_node_to_be_deleted(root, key);

        // ptr = node, prev = node's parent
        TreeNode *ptr = node.first, *prev = node.second;

        // we found the node
        if (ptr and ptr->val == key)
        {
            // node to be deleted is a leaf node
            if (!(ptr->left) and !(ptr->right))
            {
                // and not a root node
                if (prev)
                {
                    // then parent should point NULL
                    if (prev->val > ptr->val)
                        prev->left = NULL;
                    else
                        prev->right = NULL;
                }
                else
                    root = NULL;
            }
            else
            {
                TreeNode *r = ptr->right, *l = ptr->left;
                // when the root needs to be deleted which don't have any left or right subtree
                if (!l and !prev)
                    root = r;
                else if (!r and !prev)
                    root = l;
                // node have left or right subtree
                else
                {
                    // going to the biggest node in left subtree
                    TreeNode *temp = l;
                    while (l and l->right)
                        l = l->right;

                    // at least we have left subtree
                    if (l)
                    {
                        // then biggest node's right can be connected to the right subtree of
                        // the node to be deleted
                        l->right = r;

                        // not a root node that's going to be deleted
                        if (prev)
                        {
                            // set its parent pointers, accordingly with the left subtree of node
                            // to be deleted
                            if (prev->val > ptr->val)
                                prev->left = temp;
                            else
                                prev->right = temp;
                        }
                        else
                            root = temp; // otherwise root is now left subtree of node
                    }
                    // we don't have left subtree
                    else
                    {
                        // not a root node that's going to be deleted
                        if (prev)
                        {
                            // set its parent pointers, accordingly with the left subtree of node
                            // to be deleted
                            if (prev->val > ptr->val)
                                prev->left = r;
                            else
                                prev->right = r;
                        }
                    }
                }
            }
            // deleting the required node
            delete ptr;
        }

        // root of the modified tree
        return root;
    }
};

/*
ANOTHER SIMILAR SOLUTION (MINOR DIFFERENCE)
INTUITION:

*/

TreeNode* deleteRootNode(TreeNode* root)
{
    if (root == NULL) return root;
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;

    TreeNode* next = root->right, * pre = NULL;
    // trying to get the minimum val node in right subtree
    for (; next->left != NULL; pre = next, next = next->left)
        ;
    // then connecting that node's left with the node to be deleted's left subtree
    next->left = root->left;

    // and we have more than one node in the right of the node to be deleted
    if (root->right != next)
    {
        // ??????
        pre->left = next->right;
        next->right = root->right;
    }
    return next;
}


TreeNode* deleteNode(TreeNode* root, int key)
{
    // finding the pos of node to be deleted
    // and maintaining its parent node
    TreeNode* cur = root, *pre = NULL;
    while (cur != NULL && cur->val != key)
    {
        pre = cur;
        if (key < cur->val) cur = cur->left;
        else if (key > cur->val) cur = cur->right;
    }

    // node to be deleted is the root
    if (pre == NULL) return deleteRootNode(cur);
    
    // node is not root but have either left or right subtree
    // so connecting parent's (left or right) pointer to the 
    // (left or right) pointer of the node
    if (pre->left == cur) pre->left = deleteRootNode(cur);
    else pre->right = deleteRootNode(cur);

    return root;
}

/*
SOME THINGS TO CONSIDER IN MIND
1. There are many solutions that got high votes using recursive approach, including the ones from the Princeton's Algorithm and Data Structure book. 
Don't you notice that recursive approach always takes extra space? Why not consider the iterative approach first?

2. Some solutions swap the values instead of swapping the nodes. In reality, the value of a node could be more complicated than just a single 
integer, so copying the contents might take much more time than just copying the reference.

3. As for the case when both children of the node to be deleted are not null, I transplant the successor to replace the node to be deleted, 
which is a bit harder to implement than just transplant the left subtree of the node to the left child of its successor. The former way is used 
in many text books too. Why? My guess is that transplanting the successor can keep the height of the tree almost unchanged, while transplanting 
the whole left subtree could increase the height and thus making the tree more unbalanced.
*/