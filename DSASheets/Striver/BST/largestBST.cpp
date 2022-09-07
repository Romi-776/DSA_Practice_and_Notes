/*
INTUITION:
Recursively checking that does the maximum node in left subtree is smaller and the minimum
node in right subtree is greater than the current node then it will create a BST. So, we just
need to return each time the max number of nodes that have occurred in a BST till now, the max_value that have
occurred till now and the min_value.
*/

class Solution{
    // returns the max_possible_bst, max_val in left subtree,
    // min_val in right subtree.
    vector<int> postOrder(Node* root) {
        if (root) {
            vector<int> v1 = postOrder(root->left), v2 = postOrder(root->right);
            // left's max should be smaller than curr and right's min should be
            // greater than the curr
            if (v1[1] < root->data and root->data < v2[2])
                return {1 + v1[0] + v2[0], max(v2[1], root->data), min(v1[2], root->data)};
            return {max(v1[0], v2[0]), INT_MAX, INT_MIN};
        }
        return {0, INT_MIN, INT_MAX};
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return postOrder(root)[0];
    }
};