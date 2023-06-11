#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
int maxValue(int n, int index, int maxSum)
{
    int left = index;
    int right = n - 1 - index;
    ll high = maxSum;
    ll low = 1;
    ll res = 0;
    while (low <= high)
    {
        ll mid = (high - low) / 2 + low;
        ll sum = mid;
        ll rem = mid - 1;
        ll rsum = 0;
        ll lsum = 0;
        if (right <= rem)
        {
            rsum += (rem) * (rem + 1) / 2 - (rem - right) * (rem - right + 1) / 2;
        }
        else
            rsum += (rem) * (rem + 1) / 2 + 1 * (right - rem);
        if (left <= rem)
        {
            lsum += (rem) * (rem + 1) / 2 - (rem - left) * (rem - left + 1) / 2;
        }
        else
        {
            lsum += (rem) * (rem + 1) / 2 + 1 * (left - rem);
        }
        sum += lsum + rsum;
        if (sum <= maxSum)
        {
            res = mid;
            low = mid + 1;
        }
        else
            high--;
    }
    return res;
}

int main()
{
    cout << maxValue(4, 2, 6) << endl;

    return 0;
}