class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // [0, 1, 4, 7] -> [7, 4], [1], [0]
        // [7, 8, 11, 12, 16]
        // [7, 6, 9, 9, 10]
        unordered_map<int, int> ps = {};

        for (int i = 0; i < position.size(); i++) {
            ps[position[i]] = speed[i];
        }

        std::sort(position.begin(), position.end());

        stack<double> fleets = {};

        for (int i = position.size() - 1; i >= 0; i--) {
            int pos = position[i];
            int speed = ps[pos];
            double time_to_reach_target = double(target - pos) / speed;

            if (fleets.size() > 0) {
                double top = fleets.top();

                if (top < time_to_reach_target) {
                    fleets.push(time_to_reach_target);
                }
            } else {
                fleets.push(time_to_reach_target);
            }
        }

        return fleets.size();
    }
};
