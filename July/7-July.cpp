class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int maxDrink = numBottles;
        int emptyBottles = numBottles;
        while (emptyBottles>=numExchange) {
            maxDrink+=emptyBottles/numExchange;
            emptyBottles=(emptyBottles/numExchange)+(emptyBottles%numExchange);

        }
        return maxDrink;
    }
};