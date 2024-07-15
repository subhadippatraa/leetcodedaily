class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> current;
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + formula[i] - '0';
                    i++;
                }
                num = max(num, 1);
                if (!stk.empty()) {
                    map<string, int> temp = current;
                    current = stk.top();
                    stk.pop();
                    for (auto &p : temp) {
                        current[p.first] += p.second * num;
                    }
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(start, i - start);
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + formula[i] - '0';
                    i++;
                }
                num = max(num, 1);
                current[atom] += num;
            }
        }
        string result;
        for (auto &p : current) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};

