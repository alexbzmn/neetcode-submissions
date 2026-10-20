class Solution {
public:
    int spent_min = 0;

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles, piles.begin(), piles.end());
        return ;
    }

    int pile(vector<int>& piles, int left, int right, int h) {
        if (left == right) {


        }
        
        int m = (left + right) / 2;
        int rate = piles[m];

        int spent_hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (rate >= piles[i]) {
                spent_hours++;
            } else {
                int remainder = piles[i] % rate;
                if (remainder == 0) {
                    spent_hours+= piles[i] / rate;
                } else {
                    spent_hours+= ((piles[i] / rate) + 1);
                }
            }
        }

        if (spent_hours < h) {
            spent_min = min(spent_min, spent_hours);
            return pile(piles, left, m - 1, h);
        } else if (spent_hours > h) {
            return pile(piles, m + 1, right, h);
        }
    }
};
