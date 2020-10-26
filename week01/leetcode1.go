/*
 func: 两数之和
 users: wangzhen
 time: 2020-10-21
*/

func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums) - 1; i++ {
        for j := i + 1; j < len(nums); j++ {
            if target - nums[i] == nums[j] {
                return []int{i, j}
            }
        }
    }
    return []int{}
}