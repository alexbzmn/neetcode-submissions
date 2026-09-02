class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> vals = {};
        
        for (string val : tokens) {
            if (val == "+") {
                int a = vals.top();
                vals.pop();

                int b = vals.top();
                vals.pop();

                vals.push(b + a);
            } else if (val == "-") {
                int a = vals.top();
                vals.pop();

                int b = vals.top();
                vals.pop();

                vals.push(b - a);
                
            } else if (val == "*") {
                int a = vals.top();
                vals.pop();

                int b = vals.top();
                vals.pop();

                vals.push(b * a);
            } else if (val == "/") {
                int a = vals.top();
                vals.pop();

                int b = vals.top();
                vals.pop();

                vals.push(b / a);
            } else {
                int val_int = stoi(val);
                vals.push(val_int);
            }
        }
        
        return vals.top();
    }
};
