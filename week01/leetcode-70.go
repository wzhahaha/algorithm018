/*
 func: 爬楼梯
 users: wangzhen
 time: 2020-10-19
*/

func climbStairs(n int) int {
    first := 1
    second := 2

    if n == 1 {
        return 1
    }
    if n == 2 {
        return 2
    }

    for i := 3; i <= n; i++ {
        first, second = second, second + first
    }
    return second
}

/*

*/