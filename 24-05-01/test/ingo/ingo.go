package main

import "fmt"

type A struct {
	value int
}

func (A A) printit() {
	fmt.Printf("A: %v", A.value)
}

type B struct {
	A
	name string
}

func (B B) printit() {
	fmt.Printf("B: %v, %v", B.name, B.value)
}

func printA(a A) {
	a.printit()
}

func main() {
	var b B = B{A: A{value: 23}, name: "cool name"}
	b.printit()
	printA(b)

}
