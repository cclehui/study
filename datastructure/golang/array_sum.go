package main

// 两数之和
func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)

	for index, num := range nums {
		numMap[num] = index
	}

	for index, num := range nums {
		if otherIndex, ok := numMap[target-num]; ok && otherIndex != index {
			return []int{index, otherIndex}
		}
	}

	return nil
}
