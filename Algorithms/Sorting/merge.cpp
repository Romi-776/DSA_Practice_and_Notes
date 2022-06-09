#include <bits/stdc++.h>

using namespace std;
/*
Merges two arrays l and r in sorted manner
*/
void merge(int left[], int right[], int arr[], int nl, int nr)
{
  int i, j, k;
  i = j = k = 0;

  // unless one of the two arrays is exhausted
  while (i < nl and j < nr)
  {
    // checking which array have smaller element
    // to add first in the array arr
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    // going to the next element
    k++;
  }

  // there are some elements left
  // then add it to the array arr
  while (i < nl)
  {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < nr)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
}

/*
DIVIDE THE ARRAY INTO TWO HALVES UNTIL THERE'S ONLY ONE ELEMENT 
IN THE SUBARRAY THEN START MERGING THE LEFT AND RIGHT HALF IN 
SORTED MANNER UNTIL THE WHOLE ARRAY IS SORTED
*/
void merge_sort(int arr[], int n)
{
  if (n < 2)
    return;
  int mid = n / 2;

  int left[mid], right[n - mid];

  for (int i = 0; i < mid; i++)
    left[i] = arr[i];

  for (int i = mid, j = 0; i < n; j++, i++)
    right[j] = arr[i];

  merge_sort(left, mid);
  merge_sort(right, n - mid);
  merge(left, right, arr, mid, n - mid);
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  int arr[n];
  for (auto &i : arr)
    cin >> i;

  merge_sort(arr, n);

  for (int i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}