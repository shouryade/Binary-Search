#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool canEat(vector<int> &piles, int h, int k)
{
    int time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] % k)
            time++;
        time += (piles[i] / k);
        if (time > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int hi = *max_element(piles.begin(), piles.end());
    int lo = 1;
    int mid = (hi - lo) / 2 + lo;
    int ans = 0;
    while (lo <= hi)
    {
        if (canEat(piles, h, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
        mid = (hi - lo) / 2 + lo;
    }
    return ans;
}
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}