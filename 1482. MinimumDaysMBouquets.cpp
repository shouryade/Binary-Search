#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool checkBouquets(vector<int> &bloomDay, int pos, int m, int k)
{
    int b = 0;
    int flowers = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= pos)
            flowers++;
        else
            flowers = 0;
        if (flowers == k)
        {
            b++;
            flowers = 0;
        }
    }
    return b >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (m * k > n)
        return -1;
    int lo = 0;
    int hi = INT_MAX;
    int mid = lo + (hi - lo) / 2;
    while (lo <= hi)
    {
        if (checkBouquets(bloomDay, mid, m, k))
            hi = mid - 1;
        else
            lo = mid + 1;
        mid = (hi - lo) / 2 + lo;
    }
    return mid;
}
int main()
{
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 2;
    int k = 3;
    cout << minDays(bloomDay, m, k) << endl;
    return 0;
}