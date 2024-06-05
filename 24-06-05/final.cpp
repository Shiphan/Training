// Visual Studio

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

class Merch {
protected:
	int num;
	std::string name;
	int price;
	int stock;
	Merch* ptr;
public:
	Merch() {
		this->num = 0;
		this->price = 0;
		this->stock = 0;
		this->ptr = NULL;
	}
	Merch(int num, std::string name, int price, int stock) {
		this->num = num;
		this->name = name;
		this->price = price;
		this->stock = stock;
		this->ptr = NULL;
	}
	int getNum() {
		return this->num;
	}
	std::string getName() {
		return this->name;
	}
	int getPrice() {
		return this->price;
	}
	int getStock() {
		return this->stock;
	}
	void setStock(int stock) {
		this->stock = stock;
	}
	void setPtr(Merch* ptr) {
		this->ptr = ptr;
	}
	Merch* getPtr() {
		return this->ptr;
	}
	virtual void printInfo() {
		std::cout << "----------" << std::endl;
		std::cout << std::setw(12) << "編號: " << std::setw(6) << this->num << std::endl;
		std::cout << std::setw(12) << "名稱: " << std::setw(6) << this->name << std::endl;
		std::cout << std::setw(12) << "價格: " << std::setw(6) << this->price << std::endl;
		std::cout << std::setw(12) << "庫存: " << std::setw(6) << this->stock << std::endl;
	}
	virtual std::string getData() {
		return "{\n\tnum=" + std::to_string(this->getNum()) + "\n"
			+ "\tname=" + this->getName() + "\n" 
			+ "\tprice=" + std::to_string(this->getPrice()) + "\n"
			+ "\tstock=" + std::to_string(this->getStock()) + "\n"
			+ "\n}\n";
	}
};

class Food :public Merch {
protected:
	float lim;

public:
	Food() :Merch() {
		this->lim = 0;
	}
	Food(int num, std::string name, float lim, int price, int stock) :Merch(num, name, price, stock) {
		this->lim = lim;
	}
	float getLim() {
		return this->lim;
	}
	void printInfo() override {
		std::cout << "----------" << std::endl;
		std::cout << std::setw(12) << "編號: " << std::setw(6) << this->num << std::endl;
		std::cout << std::setw(12) << "名稱: " << std::setw(6) << this->name << std::endl;
		std::cout << std::setw(12) << "有效期限: " << std::setw(6) << this->lim << std::endl;
		std::cout << std::setw(12) << "價格: " << std::setw(6) << this->price << std::endl;
		std::cout << std::setw(12) << "庫存: " << std::setw(6) << this->stock << std::endl;
	}
	std::string getData() override {
		return "{\n\tnum=" + std::to_string(this->getNum()) + "\n"
			+ "\tname=" + this->getName() + "\n" 
			+ "\tprice=" + std::to_string(this->getPrice()) + "\n"
			+ "\tlim=" + std::to_string(this->getLim()) + "\n"
			+ "\tstock=" + std::to_string(this->getStock()) + "\n"
			+ "}\n";
	}


};

class List {
protected:
	Merch* head;
	Merch* endPtr;
	int length;
public:
	List() {
		this->head = NULL;
		this->endPtr = NULL;
		this->length = 0;
	}
	void addNode(Merch* nodePtr) {
		if (this->head == NULL){
			this->head = nodePtr;
		} else {
			endPtr->setPtr(nodePtr);
		}
		endPtr = nodePtr;
		this->length++;
	}
	Merch* findFirst(int num){
		Merch* ptr = this->head;
		while (ptr != NULL){
			if (ptr->getNum() == num){
				return ptr;
			}
			ptr = ptr->getPtr();
		}
		return NULL;
	}
	bool removeNodefNum(int num){
		Merch* ptr = this->head;
		if (head == NULL){
			return false;
		} else if (this->head->getNum() == num){
			this->head = this->head->getPtr();
			delete ptr;
			this->length--;
			return true;
		} else {
			while (ptr->getPtr() != NULL){
				if (ptr->getPtr()->getNum() == num){
					Merch* newPtr = ptr->getPtr()->getPtr();
					delete ptr->getPtr();
					ptr->setPtr(newPtr);
					this->length--;
					return true;
				}
				ptr = ptr->getPtr();
			}
			return false;
		}
	}
	bool findAndPrintAllfName(std::string name) {
		Merch* ptr = this->head;
		bool found = false;
		while (ptr != NULL) {
			if (ptr->getName() == name) {
				ptr->printInfo();
				found = true;
			}
			ptr = ptr->getPtr();
		}
		return found;
	}
	void printData() {
		if (this->head == NULL) {
			std::cout << "目前沒有產品" << std::endl;
			return;
		}

		Merch* ptr = this->head;
		while (ptr != NULL) {
			ptr->printInfo();
			ptr = ptr->getPtr();
		}
	}
	void printList() {
		Merch* ptr = this->head;
		std::cout << "head -> ";
		while (ptr) {
			std::cout << ptr->getNum();
			std::cout << " -> ";
			ptr = ptr->getPtr();
		}
		std::cout << "||" << std::endl;
	}
	std::string getDatas() {
		std::string datas = "";
		Merch* ptr = this->head;
		while (ptr != NULL) {
			datas.append(ptr->getData());
			ptr = ptr->getPtr();
		}
		return datas;
	}
};

void insertion(List& list) {
	int num;

	std::cout << "## Add new data:" << std::endl << "number(<=0 for cancel): ";
	std::cin.ignore();
	std::cin >> num;

	if (num <= 0){
		std::cout << "add canceled." << std::endl;
	} else if (list.findFirst(num)){
		std::cout << "number existing." << std::endl;
		std::cout << "add canceled." << std::endl;
	} else {
		std::string name;
		float lim;
		int price;
		int stock;

		std::cout << "名稱: ";
		std::cin.ignore();
		std::getline(std::cin, name);

		std::cout << "有效期限: ";
		std::cin >> lim;

		std::cout << "價格: ";
		std::cin >> price;

		std::cout << "庫存: ";
		std::cin >> stock;

		list.addNode(new Food(num, name, lim, price, stock));
	}
}

void search(List& list) {
	std::cout << "search by name... ";
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);
	if (!list.findAndPrintAllfName(name)) {
		std::cout << "No match result." << std::endl;
	}
}

void remove(List& list) {
	int rmNum;
	std::cout << "select the number you want to delete... ";
	std::cin >> rmNum;

	if (list.removeNodefNum(rmNum)){
		std::cout << "該筆資料已刪除" << std::endl;
	} else {
		std::cout << "該筆資料不存在，無法刪除" << std::endl;
	}
}

void purchase(List& list) {
	int num;
	std::cout << "輸入編號以進貨: ";
	std::cin >> num;
	
	Merch* merch = list.findFirst(num);
	if (merch == NULL) {
		std::cout << "該產品不存在，無法進貨" << std::endl;
		return;
	}

	int in;
	int stock = merch->getStock();
	std::cout << "進貨數量: ";
	std::cin >> in;

	merch->setStock(stock + in);
}

void ship(List& list) {
	int num;
	std::cout << "輸入編號以出貨: ";
	std::cin >> num;
	
	Merch* merch = list.findFirst(num);
	if (merch == NULL) {
		std::cout << "該產品不存在，無法出貨" << std::endl;
		return;
	}

	int out;
	int stock = merch->getStock();
	std::cout << "出貨數量: ";
	std::cin >> out;
	if (out > stock) {
		std::cout << "該產品存量不足，無法出貨" << std::endl;
		return;
	}

	merch->setStock(stock - out);
}

void exitMenu(List list) {
	std::cout << "saving..." << std::endl;
	std::ofstream file("product.txt");

	file << list.getDatas() << std::endl;  
	
	file.close();
	std::cout << "exit..." << std::endl;
}

class MENU{
private:
	int select;
public:
	MENU() {
		this->select = -1;
	}
	void show(){
		std::cout << "######################" << std::endl;
		std::cout << "	Final MENU" << std::endl;
		std::cout << "(1). Insertion" << std::endl;
		std::cout << "(2). Search" << std::endl;
		std::cout << "(3). Deletion" << std::endl;
		std::cout << "(4). Print Data" << std::endl;
		std::cout << "(5). Purchase" << std::endl;
		std::cout << "(6). Ship" << std::endl;
		std::cout << "(0). Exit" << std::endl;
		std::cout << "Please select one... ";
	}
	int readselect(){
		return this->select;
	}
	void writeselect(int select) {
		this->select = select;
	}
};

bool menuSelectHandler(int select, List& list) {
	switch (select) {
		case 0:
			exitMenu(list);
			return false;
		case 1:
			insertion(list);
			return true;
		case 2:
			search(list);
			return true;
		case 3:
			remove(list);
			return true;
		case 4:
			list.printData();
			return true;
		case 5:
			purchase(list);
			return true;
		case 6:
			ship(list);
			return true;
		/*
		case 7:
			list.printList();
			return true;
		*/
		default:
			std::cout << "selection unfined, consider other option" << std::endl;
			return true;
	}
}


void recoverList(List& list) {
	std::ifstream datafile("product.txt");

	std::string line;

	while (getline(datafile, line)) {
		if (line.find_first_of("{") == std::string::npos) {
			continue;
		}

		int num = 0;
		std::string name = "";
		float lim = 0;
		int price = 0;
		int stock = 0;

		getline(datafile, line);
		while (line.find_first_of("}") == std::string::npos) {
			size_t equalIndex = line.find_first_of("=");
			if (equalIndex == std::string::npos) {
				getline(datafile, line);
				continue;
			}

			size_t keyPos = line.find_first_not_of(" \t");
			std::string key = line.substr(keyPos, equalIndex - keyPos);
			std::string value = "";
			if (equalIndex < line.size() - 1) {
				value = line.substr(equalIndex + 1);
			}

			if (key == std::string("num")) {
				num = std::stoi(value);	
			} else if (key == std::string("name")) {
				name = value;
			} else if (key == std::string("lim")) {
				lim = std::stof(value);	
			} else if (key == std::string("price")) {
				price = std::stoi(value);	
			} else if (key == std::string("stock")) {
				stock = std::stoi(value);	
			}

			getline(datafile, line);
		}
		list.addNode(new Food(num, name, lim, price, stock));
	}
}

int main() {
	bool running = true;
	MENU menu;
	List list;

	recoverList(list);

	while (running) {
		menu.show();
		int select;
		std::cin >> select;
		menu.writeselect(select);

		running = menuSelectHandler(menu.readselect(), list);
	}
	return 0;
}


