package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 反转二叉树
func invertTree(root *TreeNode) *TreeNode {
	if root == nil ||
		(root.Left == nil && root.Right == nil) {
		return root
	}

	invertTree(root.Left)
	invertTree(root.Right)

	root.Left, root.Right = root.Right, root.Left

	return root
}
