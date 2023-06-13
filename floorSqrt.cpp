#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

long long int floorSqrt(long long int x)
{
    long long lo = 1;
    long long hi = x;
    long long mid = (hi + lo) / 2;

    while (lo <= hi)
    {
        if (mid * mid <= x)
            lo = mid + 1;
        else
            hi = mid - 1;

        mid = (hi + lo) / 2;
    }
    return mid;
}

int main()
{
    long long x = 0;
    cout << floorSqrt(x) << endl;

    return 0;
}