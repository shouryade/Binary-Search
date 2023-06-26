#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int search(vector<int> &arr, int target)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    if (n == 1)
        return arr[0] == target ? 0 : -1;

    int hi = n - 1;
    int lo = 0;
    int mid = lo + (hi - lo) / 2;

    while (lo <= hi)
    {
        if (arr[mid] == target)
            return mid;
        if (arr[lo] <= arr[mid])
        {
            if (arr[lo] <= target && target <= arr[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && target <= arr[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        mid = lo + (hi - lo) / 2;
    }
    return -1;
}

int main()
{
    return 0;
}