class Solution {
public:
    int passThePillow(int n, int time) {

        int round = time / (n - 1);
        int steps = time % (n - 1);
        if (round % 2 == 0) {
            return steps + 1;
        } else {
            return n - steps;
        }
    }
};