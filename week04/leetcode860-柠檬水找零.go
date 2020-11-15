/*
 贪心解法
*/

func lemonadeChange(bills []int) bool {
    five := 0
    ten := 0

    for _, bill := range bills {
        if bill == 5 {
            five++
        } else if bill == 10 {
            if five >= 1 {
                ten++
                five--
            } else {
                return false
            }

        } else if bill == 20 {
            if ten > 0 && five > 0 {
                ten--
                five--
            } else if ten <= 0 && five >= 3 {
                five -= 3
            } else {
                return false
            }
        }

    }
    return true
}