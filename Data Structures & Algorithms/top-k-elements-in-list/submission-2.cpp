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

            if (seen.contains(x)) {
                int top = pq.top();

                int copy = top;
                pq.pop();
                pq.push(copy);
                continue;
            }

            if (pq.size() == k) {
                int current_min = pq.top();
                if (freq[current_min] < freq[x]) {
                    pq.pop();
                    seen.erase(current_min);
                } else {
                    continue;
                }
            }

            seen.insert(x);
            pq.push(x);
        }

        vector<int> res = {};

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
