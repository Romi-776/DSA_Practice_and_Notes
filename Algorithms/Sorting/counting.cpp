#include <bits/stdc++.h>

using namespace std;
/*
COUNT THE FREQ OF EVERY ELEMENT IN ANOTHER ARRAY
THEN TRAVERSE THE FREQ ARRAY AND ADD EACH ELEMENT TO THE
OUTPUT ARRAY WHILE DECREASING FREQ OF EACH ELEMENT
*/
void counting_sort(int arr[], int n)
{
  int max_ele = INT_MIN;
  for (int i = 0; i < n; i++)
    if (arr[i] > max_ele)
      max_ele = arr[i];

  int count[max_ele + 1] = {0};
  for (int i = 0; i < n; i++)
    count[arr[i]]++;

  for (int i = 0, j = 0; i <= max_ele; i++)
  {
    while (count[i] > 0)
    {
      arr[j] = i;
      j++;
      count[i]--;
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

  counting_sort(arr, n);

  for (int i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}