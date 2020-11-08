/**
 替换空格
 wangzhen
 2020-11-5
*/

func replaceSpace(s string) string {
    count := 0
    for _, i := range s {
        if i == ' ' {
            count++;
        }
    }
    res := make([]rune, len(s) + count * 2)
    i := 0

    for _, str := range s {
        if str != ' ' {
            res[i] = str
            i++
        } else {
            res[i] = '%'
            res[i + 1] = '2'
            res[i + 2] = '0'
            i += 3
        }
    }

    return string(res)
}