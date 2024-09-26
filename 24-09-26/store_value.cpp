#include <iostream>

template <class T>
class Stack {
private:
	T* stack;
	size_t max_stack_size;
	int top;
public:
	Stack(size_t max_stack_size) {
		this->max_stack_size = max_stack_size;
		this->stack = new T[max_stack_size];
		this->top = 0;
	}
	~Stack() {
		delete[] this->stack;
	}
	void push(const T& elem) {
		if (this->top >= this->max_stack_size) {
			throw std::runtime_error("the stack is full");
		}

		this->stack[this->top] = elem;
		this->top++;
	}
	T pop() {
		if (this->top <= 0) {
			throw std::runtime_error("the stack is empty");
		}

		this->top--;
		return this->stack[top];
	}
};

class Node {
private:
	int value;
public:
	Node() {
		this->value = 0;
	}
	Node(int value) {
		this->value = value;
	}
	void set_value(int i) {
		this->value = i;
	}
	int get_value() {
		return this->value;
	}
};

int main() {
	// test 1
	std::cout << "# test 1:" << std::endl;
	{
		Stack<int> stack(10);

		int a = 1;
		stack.push(a);

		int out_1 = stack.pop();

		int b = 2;
		stack.push(b);

		int out_2 = stack.pop();


		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		// std::cout << "out_1: " << out_1 << std::endl;
		// std::cout << "out_2: " << out_2 << std::endl;
		std::cout << "out_1: " << out_1 << std::endl;
		std::cout << "out_2: " << out_2 << std::endl;
	}
	std::cout << std::endl;

	// test 2
	std::cout << "# test 2:" << std::endl;
	{
		Stack<int> stack(10);

		int a = 1;
		stack.push(a);

		a = 10000;

		int out = stack.pop();

		std::cout << "a: " << a << std::endl;
		// std::cout << "out: " << out << std::endl;
		std::cout << "out: " << out << std::endl;
	}
	std::cout << std::endl;

	// test 3
	std::cout << "# test 3:" << std::endl;
	{
		Stack<Node> stack(10);

		Node a(1);
		stack.push(a);

		Node out_1 = stack.pop();

		Node b(2);
		stack.push(b);

		Node out_2 = stack.pop();


		std::cout << "a value: " << a.get_value() << std::endl;
		std::cout << "b value: " << b.get_value() << std::endl;
		// std::cout << "out_1: " << out_1 << std::endl;
		// std::cout << "out_2: " << out_2 << std::endl;
		std::cout << "out_1 value: " << out_1.get_value() << std::endl;
		std::cout << "out_2 value: " << out_2.get_value() << std::endl;
	}
	std::cout << std::endl;

	// test 4
	std::cout << "# test 4:" << std::endl;
	{
		Stack<Node> stack(10);

		Node a(1);
		stack.push(a);

		a.set_value(10000);

		Node out = stack.pop();

		std::cout << "a value: "<< a.get_value() << std::endl;
		// std::cout << "out: "<< out << std::endl;
		std::cout << "out value: "<< out.get_value() << std::endl;
	}
	std::cout << std::endl;

	// test 5
	std::cout << "# test 5:" << std::endl;
	{
		Stack<int> stack(10);

		int a = 1;
		stack.push(a);

		int out_1 = stack.pop();

		int b = 2;
		stack.push(b);

		out_1 = 10000;

		int out_2 = stack.pop();


		std::cout << "out_1: "<< out_1 << std::endl;
		std::cout << "out_2: "<< out_2 << std::endl;
	}

	return 0;
}
