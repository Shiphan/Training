class A {
	int value;

	A({required this.value});
	void printit() {
		print("A: $value");
	}

}

class B extends A {
	String name;

	B({required super.value, required this.name});

	@override
	void printit() {
		print("B: $name, $value");
	}
	String getName() {
		return this.name;	
	}

}

void printA(A a) {
	a.printit();
}

/*
void printName(A a) {
	print(a.getName());
}
*/

void main() {
	B b = B(value: 23, name: "cool name");
	b.printit();
	printA(b);

}
