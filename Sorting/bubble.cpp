#include <bits/stdc++.h>

using namespace std;
/*
MOVE HIGHER VALUE ELEMENTS GENERALLY TO THE RIGHT AND LOWER
VALUE ELEMENTS GENERALLY TO THE LEFT
*/
void bubble_sort(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    bool swapped = false;
    for (int j = 1; j + i < n; j++)
    {
      if (arr[j] < arr[j - 1])
      {
        swap(arr[j], arr[j - 1]);
        swapped = true;
      }
    }
    if (!swapped)
    {
      break;
    }
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  int arr[n];
  for (auto &i : arr)
    cin >> i;

  bubble_sort(arr, n);

  for (int i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}