#include <bits/stdc++.h>

using namespace std;

class KthLargest
{
    public:
        KthLargest(int k, vector<int> &nums)
        {
            K = k;
            for(int n : nums)
            {
                pq.push(n);
                if(pq.size() > K)
                    pq.pop();
            }
        }
        
        int add(int val)
        {
            pq.push(val);
            if(pq.size() > K)
                pq.pop();
            
            return pq.top();
        }
    private:
        priority_queue<int, vector<int>, greater<int>> pq;
        int K;
};