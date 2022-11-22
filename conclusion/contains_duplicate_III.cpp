#include <bits/stdc++.h>

using namespace std;

//hard不用太在意
//想不到
//網路上的解法
//https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/142/conclusion/1013/discuss/824578/C++-O(N)-time-complexity-or-Explained-or-Buckets-or-O(K)-space-complexity
bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    const int n = nums.size();

    if(n == 0 or indexDiff < 0 or valueDiff < 0)
        return false;

    unordered_map<int, int> buckets;

    for(int i = 0; i < n; i++)
    {
        int bucket = nums[i]/((long)valueDiff + 1);

        if(nums[i] < 0)
            bucket--;
        
        if(buckets.find(bucket) != buckets.end())
            return true;
        else
        {
            buckets[bucket] = nums[i];
            if(buckets.find(bucket-1) != buckets.end() and
               (long) nums[i] - buckets[bucket-1] <= valueDiff)
               return true;
            
            if(buckets.find(bucket+1) != buckets.end() and
               (long) buckets[bucket+1] - nums[i] <= valueDiff)
               return true;
            
            if(buckets.size() > indexDiff)
            {
                int key_to_remove = nums[i-indexDiff]/((long)valueDiff + 1);
                if(nums[i-indexDiff] < 0)
                    key_to_remove--;

                buckets.erase(key_to_remove);
            }
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {1,5,9,1,5,9};
    int idx = 2;
    int val = 3;
    bool ans = containsNearbyAlmostDuplicate(nums, idx, val);

    cout << ans << endl;

    return 0;
}