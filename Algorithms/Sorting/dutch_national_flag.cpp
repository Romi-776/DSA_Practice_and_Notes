#include <bits/stdc++.h>

using namespace std;
/*
MOVE ELEMENTS LESS THAN 1 TOWARDS LEFT AND GREATER THAN 1 TOWARDS RIGHT
USING 3 POINTERS LOW, MID, AND HIGH
*/
void dutchNationalFlagSort(int arr[], int n)
{
    int mid = 0, low = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 1)
            mid++;
        else if (arr[mid] == 2)
            swap(arr[mid], arr[high]), high--;
        else if (arr[mid] == 0)
            swap(arr[mid], arr[low]), mid++, low++;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];
    for (auto &i : arr)
        cin >> i;

    dutchNationalFlagSort(arr, n);

    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}