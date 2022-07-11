#include <bits/stdc++.h>
using namespace std;
int lastOcc(int arr[], int n, int k)
{
    
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > k)
            high = mid - 1;
        else if (arr[mid] < k)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int firstOcc(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > k)
            high = mid - 1;
        else if (arr[mid] < k)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}



int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << ((lastOcc(arr, n, 1)) - (firstOcc(arr, n, 1)) + 1);
    return 0;
}
