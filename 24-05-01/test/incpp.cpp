#include <iostream>
#include <string>

class A {
private:
	int value;

public:
	A(int value) {
        this->value = value;
    }
	virtual void printit() {
        std::cout << "A: " << this->value << std::endl;
	}
    int getValue() {
        return this->value;
    }

};

class B :public A {
private:
	std::string name;

public:
	B(int value, std::string name) :A(value) {
        this->name = name;
    };

	void printit() override {
        std::cout << "B: " << this->getValue() << ", " << this->name << std::endl;
	}
	std::string getName() {
		return this->name;	
	}

};

void printA(A a) {
	a.printit();
}

void printA(A* a) {
	a->printit();
}

/*
void printName(A a) {
    std::cout << a.getName() << std::endl;
}
*/

int main() {
	B* b = new B(23, "cool name");
	b->printit();
	printA(*b);
	printA(b);
}
