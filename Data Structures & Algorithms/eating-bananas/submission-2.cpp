class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;

        int res = r;
        while (l <= r) {
            int rate = (l + r) / 2;

            long long total_hours = 0l;
            for (int i = 0; i < piles.size(); i++) {
                int pile = piles[i];
                if (pile > rate) {
                    total_hours += ceil(static_cast<double>(pile) / rate);
                } else {
                    total_hours += 1;
                }
            }

            if (total_hours <= h) {
                res = min(rate, res);
                r = rate - 1;
            } else {
                l = rate + 1;
            }
        }
        
        return res;
    }
};
