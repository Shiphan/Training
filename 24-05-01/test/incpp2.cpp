#include <iostream>

class A {
public:
	virtual void printit() {
		std::cout << "A" << std::endl;
	}
};

class B :public A {
public:
	void printit() override {
		std::cout << "B" << std::endl;
	}
};

void printAbyValue(A a) {
	a.printit();
}

void printAbyPtr(A* a) {
	a->printit();
}

int main() {
	B* b1 = new B();
	B b2 = B();
	b1->printit();
	b2.printit();

	std::cout << "---" << std::endl;

	printAbyValue(*b1);
	printAbyPtr(b1);
	
	std::cout << "---" << std::endl;

	printAbyValue(b2);
	printAbyPtr(&b2);

	std::cout << "---" << std::endl;

	A* b3 = new B();
	b3->printit();
	A b4 = *b3;
	(*b3).printit();
	b4.printit();
}
