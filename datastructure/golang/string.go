package main

import "fmt"

func main() {
	uniqStrSeqMain()

}

func uniqStrSeqMain() {
	data := []rune("acqacqcc")

	left := 0
	right := 0
	maxLen := 0

	uniqMap := make(map[rune]bool)

	for {
		if right >= len(data) {
			break
		}

		if uniqMap[data[right]] {
			delete(uniqMap, data[left])

			if (right - left) > maxLen {
				maxLen = right - left
			}

			left++

		} else {
			uniqMap[data[right]] = true

			right++
		}

	}

	fmt.Println(maxLen)
}
