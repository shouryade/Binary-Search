#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int hi = n - 1;
    int lo = 0;
    int mid;

    while (lo <= hi)
    {
        mid = (hi - lo) / 2 + lo;
        if (arr[mid] - (mid + 1) >= k)

            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo + k;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 100;
    cout << findKthPositive(arr, k) << endl;
    return 0;
}