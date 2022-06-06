#include <bits/stdc++.h>

using namespace std;
/*
BUILD YOUR SORTED ARRAY IN PLACE, SHIFTING ELEMENTS OUT OF THE WAY IF
NECESSARY TO MAKE ROOM FOR THE UNSORTED ELEMENT IN THE SORTED ARRAY
*/
void insertion_sort(int arr[], int n)
{
  // traverse through the 2nd to the nth element
  for (int i = 1; i < n; i++)
  {
    // let the element be temp
    int temp = arr[i];
    // let the curr index be j
    int j = i;

    // unless we're not at the last element
    // and the prev element is greater than temp
    while (j > 0 and arr[j - 1] > temp)
    {
      // we'll shift the prev element to
      // the curr element in order to make space
      // for our unsorted element in the sorted array
      arr[j] = arr[j - 1];

      // move to the next element
      j--;
    }

    // we have made the required space for our temp
    // in the sorted array, so put it into the curr index
    arr[j] = temp;
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  int arr[n];
  for (auto &i : arr)
    cin >> i;

  insertion_sort(arr, n);

  for (int i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}