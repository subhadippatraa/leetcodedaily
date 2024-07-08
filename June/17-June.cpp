class Solution {
public:
    bool judgeSquareSum(int c) {

        int a = 0;
        int b = sqrt(c);
        while (a <= b) {
            long long int sum = long(a * a) + long(b * b);
            if (sum > c)
                b--;
            else if (sum < c)
                a++;
            if (sum == c)
                return true;
        }
        return false;
    }
};