/**
 N叉树的前序遍历
 wangzhen
 2020-10-31
*/

/* 第一遍没啥思路，递归--参考网友写法 */
var res []int
func preorder(root *Node) []int {
    res = []int{}
    dfs(root)
    return res
}

func dfs(root *Node) []int {
    if root != nil {
        res = append(res, root.Val)
    
        for _, n := range root.Children {
            dfs(n) 
        }
    }
    return res
}
