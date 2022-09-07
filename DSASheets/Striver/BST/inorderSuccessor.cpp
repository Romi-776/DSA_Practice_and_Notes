/*
OPTIMIZED APPROACH:
As inorder successor is a node that comes after x in inorder traversal, that mean
that will be a node that have the smallest value among all the nodes that have value
greater than x. So using bst properties to find that node.

T.C = O(H) for finding the node, S.C = O(H) for recursive stack
*/
class Solution{
    Node* ans = NULL;
    void find(Node* curr, int x) {
        if (curr) {
            if (curr->data > x) ans = curr, find(curr->left, x);
            else find(curr->right, x);
        }
    }
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        find(root, x->data);
        return ans;
    }
};

/*
MY NAIVE SOLUTION:
Using inorder traversal to find the node whose successor we need to find.
After finding the node, storing the just next node into our answer.

T.C = O(N) for traversing, S.C = O(N) for recursive stack
*/
class Solution{
    bool found = false;
    Node* ans = NULL;
    void inorder(Node* curr, Node* x) {
        if (curr) {
            inorder(curr->left, x);
            if (!found and curr == x) found = true;
            else if (found) ans = curr, found = false;
            inorder(curr->right, x);
        }
    }
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        inorder(root, x);
        return ans;
    }
};