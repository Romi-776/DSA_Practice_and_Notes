#include <bits/stdc++.h>

using namespace std;
/*
Partitions array in such manner that the elements
less than the pivot are left of the pivot and the
elements greater than the pivot are right of the pivot.
*/
int partition(int arr[], int start, int end)
{
  int pivot = arr[end];
  int partitionIndex = start;
  for (int i = start; i < end; i++)
  {
    if (arr[i] <= pivot)
    {
      swap(arr[i], arr[partitionIndex++]);
    }
  }
  swap(arr[partitionIndex], arr[end]);
  return partitionIndex;
}

/*
DIVIDE THE ARRAY USING SOME PARTITION WHICH CREATES TWO SUBARRAYS
THAT HAVE ELEMENTS EITHER LESS OR GREATER THAN THE PIVOT THEN SORT 
THOSE SUBARRAYS INDIVIDUALLY USING RECURSION.
*/
void quick_sort(int arr[], int start, int end)
{
  if (start < end)
  {
    int pIndex = partition(arr, start, end);
    quick_sort(arr, start, pIndex - 1);
    quick_sort(arr, pIndex + 1, end);
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  int arr[n];
  for (auto &i : arr)
    cin >> i;

  quick_sort(arr, 0, n - 1);

  for (int i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}