#include <bits/stdc++.h>
using namespace std;
const int ZERO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Overall this question is quite easy. But the I encountered upper_bound here today.
//  So I will use this problem to explain what it does.

// basically in this question I am updating some values, and then taking snapshots of the array at that time.
// Snapshots are implemented using a vector of maps, such that each map has a value of which index and what value it was last changed to.
// Now to get a snapshot, its a little tricky. We could iterate over all the snaps to find the latest snap that has a value, but it could be difficult to implement.
// Thus we use the logic here:
// Array[index] gives me a an array of snapshot maps => {1,3,5}
// Lets say I request a snapshot number 4. But as you see here in snapshot 4 there wasn't any updation. The last change in index that happened before snapshot 4 was 3.
// How do I get it?
// lets take an upper_bound of the array[index] with value as 4.
// this means find me the iterator of the number just greater than 4.
// if the iterator points to beginning of Array => Array[index].begin() then by the question rule I should return 0
// Otherwise, just do an iterator--;
// The iterator would be pointing to the number just smaller than 4 but greatest one before it.
// In this case it's 3.
// return it->second. [returns value at it].

class SnapshotArray
{
public:
    vector<map<int, int>> Array;
    int idx = 0;
    SnapshotArray(int length)
    {
        map<int, int> m;
        Array.resize(length, m);
    }

    void set(int index, int val)
    {
        Array[index][idx] = val;
    }

    int snap()
    {

        Array.push_back(Array[idx]);
        return idx++;
    }

    int get(int index, int snap_id)
    {
        auto ind = Array[index].upper_bound(snap_id);

        if (ind == Array[index].begin())
            return 0;
        ind--;
        return ind->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
int main()
{

    return 0;
}