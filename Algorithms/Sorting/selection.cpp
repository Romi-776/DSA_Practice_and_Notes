#include <bits/stdc++.h>

using namespace std;
/*
FIND THE SMALLEST ELEMENT IN THE SORTED PART OF THE ARRAY
AND SWAP IT WITH THE FIRST ELEMENT OF THE UNSORTED PART Of ARRAY
*/
void selection_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min_index = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[min_index])
        min_index = j;
    swap(arr[i], arr[min_index]);
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  int arr[n];
  for (auto &i : arr)
    cin >> i;

  selection_sort(arr, n);

  for (int i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}