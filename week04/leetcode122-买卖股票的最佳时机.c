/* 
 贪心法：求解每次的正利润之和，即为最大利润 
*/
int maxProfit(int* prices, int pricesSize){
    int count = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            count += prices[i] - prices[i - 1];
        }
    }
    return count;
}

/* 利用c语言fmax库函数，发现时间上12ms->4ms */
int maxProfit(int* prices, int pricesSize){
    int ans = 0;
    for (int i = 1; i < pricesSize; ++i) {
        ans += fmax(0, prices[i] - prices[i - 1]);
    }
    return ans;
}