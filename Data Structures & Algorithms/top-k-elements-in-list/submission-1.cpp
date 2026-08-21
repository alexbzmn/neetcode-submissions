class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq = {};
        unordered_set<int> seen = {};

        auto comp = [&freq](int a, int b) {
            return freq[a] > freq[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (int x : nums) {
            freq[x] = freq[x] + 1;
            if (!seen.contains(x)) {
                pq.push(x);
                seen.insert(x);
            }
            
            if (pq.size() > k) {
                seen.erase(pq.top());
                pq.pop();
            }
        }

        vector<int> res = {};

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
