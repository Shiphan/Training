package main

import (
	"fmt"
)

type Node struct {
	num  int
	name string
	prg  int
	eng  int
}

func (Node Node) printInfo() {
	fmt.Println("---")
	fmt.Printf("No. %v\n", Node.num)
	fmt.Printf("Name: %v\n", Node.name)
	fmt.Printf("Programming score: %v\n", Node.prg)
	fmt.Printf("English score: %v\n", Node.eng)
}

func main() {
	var list []Node

	list = append(list, Node{num: 34, name: "cool name", prg: 88, eng: 90})
	list = append(list, Node{num: 28, name: "cool name", prg: 8, eng: 9})

	for r := range list {
		list[r].printInfo()
	}
}
