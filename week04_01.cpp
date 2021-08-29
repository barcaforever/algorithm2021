// 860 柠檬水找零
// [5,5,10,10,20] false 

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            // 如果收到了5块钱，则 5元 钞票的数量+1
            if (bill == 5) {
                five++;
            }
            // 如果收到了10块，需要找 一张5块，如果5元的数量<=0，则 false
            // 否则 10元+1 5元-1 ；
            if (bill == 10) {
                if (five <= 0) return false;
                five--;
                ten++;
            }
            // 如果收到了20元，需要找 1张10和1张5，或者3张5；优先找1张10和1张5；其次找3张5；
            // 如果10元和5元的数量都不符合，就返回false
            if (bill == 20) { 
                if (five > 0 && ten > 0) {
                    ten--;
                    five--;
                }else if (five >= 3) {
                    five -= 3;
                }else {
                    return false;
                }
            }
        }
        return true;

    }
};