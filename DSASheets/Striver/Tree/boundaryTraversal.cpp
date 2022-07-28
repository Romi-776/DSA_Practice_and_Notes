// (Firstly, Traverse the left boundary, then find the leaves, then find the right boundary)
// 12. Boundary Traversal
class Solution
{
public:
    // preOrder Traversal
    void leftBoundary(Node *root, vector<int> &ans)
    {
        if (root and (root->left or root->right))
        {
            ans.push_back(root->data);
            if (root->left)
                leftBoundary(root->left, ans);
            else
                leftBoundary(root->right, ans);
        }
    }

    void rightBoundary(Node *root, stack<int> &st)
    {
        if (root and (root->left or root->right))
        {
            st.push(root->data);
            if (root->right)
                rightBoundary(root->right, st);
            else
                rightBoundary(root->left, st);
        }
    }

    // inOrder Traversal
    void findLeaves(Node *root, vector<int> &ans)
    {
        if (root)
        {
            findLeaves(root->left, ans);
            if (!root->left and !root->right)
                ans.push_back(root->data);
            findLeaves(root->right, ans);
        }
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root)
        {
            // starting from root
            ans.push_back(root->data);

            // getting left boundary
            leftBoundary(root->left, ans);

            // leaves can be possible if there's a left or right child of root node
            if (root->left or root->right)
                findLeaves(root, ans);

            // getting right boundary in stack in order to later reverse them for boundary
            stack<int> st;
            rightBoundary(root->right, st);
            while (st.size())
                ans.push_back(st.top()), st.pop();
        }
        return ans;
    }
};
