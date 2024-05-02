#include <iostream>
#include <string>

class Student {
protected:
	int num;
	std::string name;
	int sum;
public:
	Student(int num, std::string name) {
		this->num = num;
		this->name = name;
		this->sum = 0;
	}
	int getNum() {
		return this->num;
	}
	std::string getName() {
		return this->name;
	}
	int getSum() {
		return this->sum;
	}
	void printInfo(){
		std::cout << "---" << std::endl;
		std::cout << "No." << this->num << std::endl;
		std::cout << "Name: " << this->name << std::endl;
	}
};

class StudentNode1 :public Student {
protected:
	StudentNode1* ptr;
	int prg;
	int eng;
public:
	StudentNode1(int num, std::string name, int prg, int eng) :Student(num, name) {
		this->ptr = nullptr;
		this->prg = prg;
		this->eng = eng;
		this->sum = prg + eng;
	}
	void setPtr(StudentNode1* ptr) {
		this->ptr = ptr;
	}
	StudentNode1* getPtr() {
		return this->ptr;
	}
	int getPrg() {
		return this->prg;
	}
	int getEng() {
		return this->eng;
	}
	void printInfo() {
		std::cout << "---" << std::endl;
		std::cout << "No." << this->num << std::endl;
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Programming score: " << this->prg << std::endl;
		std::cout << "English score: " << this->eng << std::endl;
	}
};

class StudentNode2 :public Student {
protected:
	StudentNode2* ptr;
	int run;
public:
	StudentNode2(int num, std::string name, int run) :Student(num, name) {
		this->run = run;
		this->sum = run;
	}
	void setPtr(StudentNode2* ptr) {
		this->ptr = ptr;
	}
	StudentNode2* getPtr() {
		return this->ptr;
	}
	int getRun() {
		return this->run;
	}
	void printInfo() {
		std::cout << "---" << std::endl;
		std::cout << "No." << this->num << std::endl;
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Run score: " << this->run << std::endl;
	}
};

class Student1List {
protected:
	StudentNode1* head;
	StudentNode1* endPtr;
	int length;
public:
	Student1List() {
		this->head = nullptr;
		this->endPtr = nullptr;
		this->length = 0;
	}
	void addNodeEndfPtr(StudentNode1* nodePtr) {
		if (this->head == NULL){
			this->head = nodePtr;
		} else {
			endPtr->setPtr(nodePtr);
		}
		endPtr = nodePtr;
		this->length++;
	}
	bool removeNodefNum(int num){
		StudentNode1* ptr = this->head;
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
					StudentNode1* newPtr = ptr->getPtr()->getPtr();
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
	StudentNode1* findFirst(int num){
		StudentNode1* ptr = this->head;
		while (ptr != NULL){
			if (ptr->getNum() == num){
				return ptr;
			}
			ptr = ptr->getPtr();
		}
		return NULL;
	}
	bool findAndPrintAllfName(std::string name){
		StudentNode1* ptr = this->head;
		bool found = false;
		while (ptr != NULL){
			if (ptr->getName() == name){
				ptr->printInfo();
				found = true;
			}
			ptr = ptr->getPtr();
		}
		return found;
	}
	void printList() {
		StudentNode1* ptr = this->head;
		std::cout << "head -> ";
		while (ptr){
			std::cout << ptr->getNum();
			std::cout << " -> ";
			ptr = ptr->getPtr();
		}
		std::cout << "||" << std::endl;
	}
	void printTranscript() {
		//print transcript
		int realSort = 1;
		int sort = 1;
		bool isPrinted[this->length] = {};
		bool run = true;

		while (run){ // not ready

			//get max that print
			int sumMax;
			StudentNode1* ptr = this->head;
			int i = 0;
			while (ptr != NULL){
				if (!i[isPrinted]){
					sumMax = ptr->getSum();

					//std::cout << "1\n";
					break;
				} else if (ptr->getPtr() == NULL) {
					run = false;
					
					//std::cout << "2\n";
				}
				ptr = ptr->getPtr();
				i++;
			}
			i = 0;
			ptr = this->head;
			while (ptr != NULL){
				int sum = ptr->getSum();
				if (!i[isPrinted] && sum > sumMax){
					sumMax = sum;

					//std::cout << "3\n";
				}
				ptr = ptr->getPtr();
				i++;
				
				//std::cout << "4\n";
			}
			//got it
			
			//print node that match
			i = 0;
			ptr = this->head;
			while (ptr != NULL){
				int sum = ptr->getSum();
				if (sum == sumMax && !i[isPrinted]){
					std::cout << "[" << sort << "]";
					realSort++;
					isPrinted[i] = true;
					ptr->printInfo();
							
					//std::cout << "5\n";
				}
				ptr = ptr->getPtr();
				i++;
						
				//std::cout << "6\n";
			}
			sort = realSort;
		}
	}
};

class Student2List {
protected:
	StudentNode2* head;
	StudentNode2* endPtr;
	int length;
public:
	Student2List() {
		this->head = nullptr;
		this->endPtr = nullptr;
		this->length = 0;
	}
	void addNodeEndfPtr(StudentNode2* nodePtr) {
		if (this->head == NULL){
			this->head = nodePtr;
		} else {
			endPtr->setPtr(nodePtr);
		}
		endPtr = nodePtr;
		this->length++;
	}
	bool removeNodefNum(int num){
		StudentNode2* ptr = this->head;
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
					StudentNode2* newPtr = ptr->getPtr()->getPtr();
					delete ptr->getPtr();
					ptr->setPtr(newPtr);
					this->length--;
					return true;
				}
				ptr = ptr->getPtr();
			}class MENU{
	private:
		int select;
	public:
		MENU() {
			this->select = -1;
		}
		void show(){
			std::cout << "######################" << std::endl;
			std::cout << "	MENU" << std::endl;
			std::cout << "(1). Insertion" << std::endl;
			std::cout << "(2). Search" << std::endl;
			std::cout << "(3). Deletion" << std::endl;
			std::cout << "(4). Print List Data" << std::endl;
			std::cout << "(5). Print Transcript" << std::endl;
			std::cout << "(0). Exit" << std::endl;
			std::cout << "Please select one... ";
		}
		int readselect(){
			return this->select;
		}
		void writeselect(int select){
			this->select = select;
		}
}
			return false;
		}
	}
	StudentNode2* findFirst(int num){
		StudentNode2* ptr = this->head;
		while (ptr != NULL){
			if (ptr->getNum() == num){
				return ptr;
			}
			ptr = ptr->getPtr();
		}
		return NULL;
	}
	bool findAndPrintAllfName(std::string name){
		StudentNode2* ptr = this->head;
		bool found = false;
		while (ptr != NULL){
			if (ptr->getName() == name){
				ptr->printInfo();
				found = true;
			}
			ptr = ptr->getPtr();
		}
		return found;
	}
	void printList() {
		StudentNode2* ptr = this->head;
		std::cout << "head -> ";
		while (ptr){
			std::cout << ptr->getNum();
			std::cout << " -> ";
			ptr = ptr->getPtr();
		}
		std::cout << "||" << std::endl;
	}
	void printTranscript() {
		//print transcript
		int realSort = 1;
		int sort = 1;
		bool isPrinted[this->length] = {};
		bool run = true;

		while (run){ // not ready

			//get max that print
			int sumMax;
			StudentNode2* ptr = this->head;
			int i = 0;
			while (ptr != NULL){
				if (!i[isPrinted]){
					sumMax = ptr->getSum();

					//std::cout << "1\n";
					break;
				} else if (ptr->getPtr() == NULL) {
					run = false;
					
					//std::cout << "2\n";
				}
				ptr = ptr->getPtr();
				i++;
			}
			i = 0;
			ptr = this->head;
			while (ptr != NULL){
				int sum = ptr->getSum();
				if (!i[isPrinted] && sum > sumMax){
					sumMax = sum;

					//std::cout << "3\n";
				}
				ptr = ptr->getPtr();
				i++;
				
				//std::cout << "4\n";
			}
			//got it
			
			//print node that match
			i = 0;
			ptr = this->head;
			while (ptr != NULL){
				int sum = ptr->getSum();
				if (sum == sumMax && !i[isPrinted]){
					std::cout << "[" << sort << "]";
					realSort++;
					isPrinted[i] = true;
					ptr->printInfo();
							
					//std::cout << "5\n";
				}
				ptr = ptr->getPtr();
				i++;
						
				//std::cout << "6\n";
			}
			sort = realSort;
		}
	}
};
class MENU{
	private:
		int select;
	public:
		MENU() {
			this->select = -1;
		}
		void show(){
			std::cout << "######################" << std::endl;
			std::cout << "	MENU" << std::endl;
			std::cout << "(1). Insertion" << std::endl;
			std::cout << "(2). Search" << std::endl;
			std::cout << "(3). Deletion" << std::endl;
			std::cout << "(4). Print List Data" << std::endl;
			std::cout << "(5). Print Transcript" << std::endl;
			std::cout << "(0). Exit" << std::endl;
			std::cout << "Please select one... ";
		}
		int readselect(){
			return this->select;
		}
		void writeselect(int select){
			this->select = select;
		}
};

void insertion(Student1List& list){
	int num;
	std::cout << "## Add data:" << std::endl << "number(<=0 for cancel): ";
	std::cin.ignore();
	std::cin >> num;
	if (num <= 0){
		std::cout << "add canceled." << std::endl;
	} else if (list.findFirst(num)){
		std::cout << "number existing." << std::endl << "add canceled." << std::endl;
	} else {
		std::string name;
		int prg;
		int eng;
		std::cout << "name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cout << "Programming score: ";
		std::cin >> prg;
		std::cout << "English score: ";
		std::cin >> eng;
		StudentNode1* newNodePtr = new StudentNode1(num, name, prg, eng);
		list.addNodeEndfPtr(newNodePtr);
	}
}

void insertion(Student2List& list){
	int num;
	std::cout << "## Add data:" << std::endl << "number(<=0 for cancel): ";
	std::cin.ignore();
	std::cin >> num;
	if (num <= 0){
		std::cout << "add canceled." << std::endl;
	} else if (list.findFirst(num)){
		std::cout << "number existing." << std::endl << "add canceled." << std::endl;
	} else {
		std::string name;
		int run;
		std::cout << "name: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cout << "Run score: ";
		std::cin >> run;
		StudentNode2* newNodePtr = new StudentNode2(num, name, run);
		list.addNodeEndfPtr(newNodePtr);
	}
}

int main() {
	StudentNode1 stun1 = StudentNode1(1, "name", 80, 76);
	stun1.printInfo();
}
