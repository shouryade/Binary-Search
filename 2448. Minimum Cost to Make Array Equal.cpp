#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Read https://leetcode.com/problems/minimum-cost-to-make-array-equal/editorial/
// Read https://leetcode.com/problems/minimum-cost-to-make-array-equal/solutions/2734728/pure-math-based-explanation-of-why-cost-function-is-convex/

// this is same Binary Search on Answer, but the implication of convex
// function requires that we can use the same search technique to find out 2 points and infer which will lead to minima
// unimodal search technique <- see

long long calculateMinCost(int val, vector<int> &cost, vector<int> &nums)
{
    long long costx = 0;
    for (int i = 0; i < nums.size(); i++)
        costx += ((long long)abs(val - nums[i]) * cost[i]);
    return costx;
}

long long minCost(vector<int> &nums, vector<int> &cost)
{
    int lo = *min_element(nums.begin(), nums.end());
    int hi = *max_element(nums.begin(), nums.end());

    long long answer = calculateMinCost(hi, cost, nums);
    int mid = (hi - lo) / 2 + lo;
    while (lo <= hi)
    {
        long long val = calculateMinCost(mid, cost, nums);
        long long val1 = calculateMinCost(mid + 1, cost, nums);
        if (val < val1)
        {
            answer = val;
            hi = mid - 1;
        }
        else
            lo = mid + 1;

        mid = (hi - lo) / 2 + lo;
    }
    return answer;
}

int main()
{
    vector<int> nums = {735103, 366367, 132236, 133334, 808160, 113001, 49051, 735598, 686615, 665317, 999793, 426087, 587000, 649989, 509946, 743518}, cost = {724182, 447415, 723725, 902336, 600863, 287644, 13836, 665183, 448859, 917248, 397790, 898215, 790754, 320604, 468575, 825614};
    cout << minCost(nums, cost) << endl;
    return 0;
}