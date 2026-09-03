class Solution {
public:

    class Node {
        public:
        Node() {

        }

        int val;
        int index;

        Node(int val, int index) : val(val), index(index) {}
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<Node> stack = {};
        
        for (int i = 0; i < temperatures.size(); i++) {
        
            while (!stack.empty()) {
                Node top = stack.top();

                if (top.val < temperatures[i]) {
                    res[top.index] = i - top.index;
                    stack.pop();
                } else {
                    break;
                }
            }

            stack.push(Node(temperatures[i], i));
        }

        return res;
    }
};
