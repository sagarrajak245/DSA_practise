
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSumFixedWindow(vector<int> arr, int k)
{
    int n = arr.size();
    int maxsum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < k; i++)
    {
        currentSum += arr[i]; // Calculate the sum of the first 'k' elements
    }
    maxsum = currentSum; // Initialize maxsum with the first window sum

    for (int i = k; i < n; i++)
    {
        currentSum += arr[i] - arr[i - k]; // Slide the window by adding the next element and removing the first element of the previous windowmax
        maxsum = max(maxsum, currentSum);  // Update maxsum if the current window sum is greater
    }
    return maxsum; // Return the maximum sum found
}

int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Maximum sum of subarray of size " << k << " is: " << maxSumFixedWindow(arr, k) << endl;
    return 0;
}