// MERGE SORTED ARRAY - https://leetcode.com/problems/merge-sorted-array/


// Optimized solution | T.C = O(n+m), S.C = O(1)
class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
           	// without using extra space and merging from backward direction
            int i = m - 1, j = n - 1, k = m + n - 1;

            while (i >= 0 and j >= 0)
            {
               	// adding the greater of the two elements from the back
               	// of two vectors into nums1 at kth position
                if (nums1[i] > nums2[j])
                    nums1[k--] = nums1[i--];
                else
                    nums1[k--] = nums2[j--];
            }

           	// remaining elements in nums2 
           	// then add it to nums1 otherwise
           	// it'll be sorted
            while (j >= 0)
                nums1[k--] = nums2[j--];
        }
};


// My naive solution | T.C = O(n+m), S.C = O(n+m)
class Solution 
{
  public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
      {
          int i = 0, j = 0, k = 0;
          // using extra space and merging from forward direction
          vector<int> extra(n + m);

          while (i < m and j < n) {
              if (nums1[i] <= nums2[j])
                  extra[k++] = nums1[i++];
              else 
                  extra[k++] = nums2[j++];
          }
          
          while (i < m)
              extra[k++] = nums1[i++];
          while (j < n)
              extra[k++] = nums2[j++];
          
              
          for (i = 0; i < n + m; i++)
              nums1[i] = extra[i];
      }
};