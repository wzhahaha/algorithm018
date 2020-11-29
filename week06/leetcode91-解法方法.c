/** 解法：动态规划（分情况）
    一. 0要做特殊处理:
    1、如果第一个是0, 返回0.
    2、1到26之间只允许有"10"和"20", 所以如果包含0且不是"10"和"20"的, 也直接返回0

    二. dp[i]表示长度为i的字符串的numDecooding数
    1、如果最后1位为0, 由于0不在1到26之间, 最后2位必然是解码成一个数, 故dp[i] = dp[i-2]
    2、如果最后2位形成的数字在1到26之间, 那么, 最后2位可以选择拼接, 也可以选择不拼接, 故dp[i] = dp[i-1]+dp[i-2]
    否则, 即最后2位形成的数字不在1到26之间, 那么最后1位不能和前面进行拼接, 故dp[i] = dp[i-1]
*/
int numDecodings(char * s){
    int length = strlen(s);
    int pre = 1;
    int cur = 1;

    if (s[0] == '0') {
        return 0;
    }
    for(int i = 1; i < length; i++) {
        int temp = cur;
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') {
                cur = pre; // dp[i] = dp[i-2]
            } else {
                return 0;
            }
        } else if (s[i - 1] == '1' || s[i - 1] == '2' && (s[i] - '0' < 7)) {
            cur = cur + pre; // dp[i] = dp[i-1] + dp[i-2]
        }
        pre = temp;
    }
    return cur;
}