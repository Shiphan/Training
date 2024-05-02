#include <iostream>

class Bass{
protected:
	int num1;
};

class Son :public virtual Bass {
public:
	Son() {
	}
};

class Don :public virtual Bass {
public:
	Don() {
	}
};

class Gon :public Son, public Don {
public:
	Gon(int num) {
		num1 = num;
	}
	int getNum1() {
		return num1;
	}
};

int main(){
	Gon gon = Gon(2);
	std::cout << gon.getNum1() << std::endl;
}
