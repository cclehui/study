package main

import "fmt"

func main() {

	findInTwoDimSortedArrayMain()
}

// 给定一个m * n的矩阵，其中矩阵的每一行和每一列都是升序的，实现一个方法，查找一个数字在矩阵中是否存在。
func findInTwoDimSortedArrayMain() {
	data := [][]int{
		{1, 2, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 5, 6},
		{4, 5, 6, 8},
	}

	//fmt.Println(findInTwoDimSortedArrayOne(data, 10))
	fmt.Println(findInTwoDimSortedArrayTwo(data, 1))

}

func findInTwoDimSortedArrayTwo(data [][]int, value int) bool {
	if len(data) < 1 || len(data[0]) < 1 {
		return false
	}

	m := len(data)
	n := len(data[0])

	i, j := 0, n-1

	for {
		if i >= m || j < 0 {
			break
		}

		if data[i][j] == value {
			return true
		}

		if value > data[i][j] {
			i++
			continue
		}

		if value < data[i][j] {
			j--
			continue
		}
	}

	return false
}

func findInTwoDimSortedArrayOne(data [][]int, value int) bool {
	if len(data) < 1 || len(data[0]) < 1 {
		return false
	}

	m := len(data)
	n := len(data[0])

	for i := 0; i < m; i++ {
		left := 0
		right := n - 1

		for {
			fmt.Println(i, left, right)

			curIndex := left + (right-left)/2
			if curIndex == left {
				curIndex++
			}

			if left >= right || curIndex > right {
				break
			}

			if data[i][curIndex] == value {
				return true
			}

			if data[i][curIndex] > value {
				right = curIndex
			} else {
				left = curIndex
			}
		}
	}

	return false
}
