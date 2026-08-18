class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq = {};

        auto comp = [](int a, int b) {
            return freq[a] >= freq[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (int x : nums) {
            freq[x]++;
            pq.push(x);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res = {};

        while (!pq.isEmpty()) {
            res.push_back(pq.pop());
        }

        return res;
    }
};
