/**
 两数之和：map，哈希表方法。
 wangzhen
 2020-10-26
*/

func twoSum(nums []int, target int) []int {
    hashTable := map[int]int{}
    for i, x := range nums {
        if j, ok := hashTable[target - x]; ok {
            return []int {j, i}
        }
        hashTable[x] = i
    }
    return nil
}

