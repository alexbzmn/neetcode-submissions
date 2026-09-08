class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // [0, 1, 4, 7] -> [7, 4], [1], [0]
        unordered_map<int, int> ps = {};

        for (int i = 0; i < position.size(); i++) {
            ps[position[i]] = speed[i];
        }

        std::sort(position.begin(), position.end());

        stack<double> fleets = {};

        for (int i = position.size() - 1; i >= 0; i--) {
            int pos = position[i];
            int speed = ps[pos];
            double current_pace = double(target - pos) / speed;

            if (fleets.size() > 0) {
                int top = fleets.top();

                if (top < current_pace) {
                    fleets.push(current_pace);
                }
            } else {
                fleets.push(current_pace);
            }
        }

        return fleets.size();
    }
};
