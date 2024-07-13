class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {

        int n = positions.size();
        vector<int> ind;

        for (int i = 0; i < n; i++) {
            ind.push_back(i);
        }
        auto compare = [&](int ind1, int ind2) {
            return positions[ind1] < positions[ind2];
        };

        sort(ind.begin(), ind.end(), compare);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            int idx = ind[i];
            if (directions[idx] == 'R') {

                st.push(idx);
            } else {                                            // if its a left dir it will not collide with anyone

                while (!st.empty() && healths[idx] > 0) {
                    int rightIdx = st.top();
                    if (healths[rightIdx] < healths[idx]) {

                        healths[idx]--;
                        healths[rightIdx] = 0;
                        st.pop();
                    } else if (healths[rightIdx] > healths[idx]) {

                        healths[idx] = 0;
                        healths[rightIdx]--;
                    } else {

                        healths[idx] = 0;
                        healths[rightIdx] = 0;
                        st.pop();
                    }
                }
            }
        }

        // Collect the remaining healths of robots that survived
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
