/*
 func: 删除有序数组中的重复项
 users: wangzhen
 time: 2020-10-25
*/

func removeDuplicates(nums []int) int {
    slow := 0
    
    for fast := 1; fast < len(nums); fast++ {
        if nums[fast] != nums[slow] {
            if fast - slow > 1 {
                nums[slow + 1] = nums[fast]
            }
            slow++
        }
    }
    return slow + 1
}