// Next Greater Element I - https://leetcode.com/problems/next-greater-element-i/

// T.C = O(N), S.C = O(N)
// Firstly, start traversing from right to left while maintaining a stack which will store the elements
// until the curr_ele >= stack.top and stack is not empty then keep on popping
// and for answer if there's an element in stack then that will be next greater otherwise -1
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // for storing the answer for each element which will be needed for nums1
    unordered_map<int, int> mp;
    int n = nums2.size();

    // stack to contain all greater elements than the curr_element
    stack<int> st;

    // traversing from right
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() and st.top() <= nums2[i])
            st.pop();

        if (st.size())
            mp[nums2[i]] = st.top();
        else
            mp[nums2[i]] = -1;

        st.push(nums2[i]);
    }
    // storing the answers of queries asked in nums1
    vector<int> ans;
    for (int i : nums1)
        ans.push_back(mp[i]);

    // Here, i'm directly returning the answer becuase values of each no. is stored in map
    // but in generall when we don't store the answer in map then we have to return the reverse
    // of answer which stored the values of each no. by push_back method
    return ans;
}