#include <iostream>

class Node{
private:
        Node* ptr;
        int num;
        char name[10];
        int prg;
        int cmp;
public:
        Node(int num, char name[10], int prg, int cmp, Node* ptr = NULL){
            this->num = num;
            for (int i = 0; i < 10; i++){
                this->name[i] = name[i];
            }
            this->prg = prg;
            this->cmp = cmp;
	    this->ptr = ptr;
        }
        int getNum(){
            return this->num;
        }
        char* getName(){
            return this->name;
        }
        int getPrg(){
            return this->prg;
        }
        int getCmp(){
            return this->cmp;
        }
        Node* getPtr(){
            return this->ptr;
        }
        Node setNum(int num){
            this->num = num;
            return *this;
        }
        Node setName(char name[10]){
            for (int i = 0; i < 10; i++){
                this->name[i] = name[i];
            }
            return *this;
        }
        Node setPrg(int prg){
            this->prg = prg;
            return *this;
        }
        Node setCmp(int cmp){
            this->cmp = cmp;
            return *this;
        }
        Node setPtr(Node* ptr){
            this->ptr = ptr;
            return *this;
        }
};

class LinkedList{
private:
        Node* head = NULL;
        Node* endPtr = NULL;
public:
        LinkedList addNodeEndfPtr(Node* nodePtr){
            if (this->head == NULL){
                this->head = nodePtr;
            } else {
                endPtr->setPtr(nodePtr);
            }
            endPtr = nodePtr;
            return *this;
        }
        LinkedList addNodeHeadfPtr(Node* nodePtr){
            if (this->head == NULL){
                endPtr = nodePtr;
            } else {
                nodePtr->setPtr(this->head);
            }
            this->head = nodePtr;
            return *this;
        }
        LinkedList addNodeNumfPtr(Node* nodePtr){
            if (this->head == NULL){
                this->head = nodePtr;
                endPtr = nodePtr;
            } else if (this->head->getNum() > nodePtr->getNum()){
                nodePtr->setPtr(this->head);
                this->head = nodePtr;
            } else {
                Node* ptr = this->head;
                while (ptr->getPtr() != NULL && ptr->getPtr()->getNum() < nodePtr->getNum()){
                    ptr = ptr->getPtr();
                }
                nodePtr->setPtr(ptr->getPtr());
                ptr->setPtr(nodePtr);
            }
            return *this;
        }
        bool isFound(int num){
            Node* ptr = this->head;
            while (ptr != NULL){
                if (ptr->getNum() == num){
                    return true;
                }
                ptr = ptr->getPtr();
            }
            return false;
        }
        void print(){
            Node* ptr = this->head;
            std::cout << "head -> ";
            while (ptr){
                std::cout << ptr->getNum();
                /*
                for (int i = 0; i < 10; i++){
                    std::cout << ptr->getName()[i];
                }
                std::cout << ptr->getPrg() << ptr->getCmp();
                */
                std::cout << " -> ";
                ptr = ptr->getPtr();
            }
            std::cout << "||" << std::endl;
        }
        /*
	LinkedList copy(){
		LinkedList* newList = new LinkedList();
		Node* ptr = this->head;
		while (ptr != NULL){
			Node* newNodePtr = new Node(ptr->getNum(), ptr->getName(), ptr->getPrg(), ptr->getCmp());
			newList->addNodeEndfPtr(newNodePtr);
			ptr = ptr->getPtr();
		}	
		return *newList; 
	}
        */
};

/*
LinkedList operator+(LinkedList linkedList, Node* nodePtr){
    return linkedList.copy().addNodeEndfPtr(nodePtr);
}

LinkedList operator+(Node* nodePtr, LinkedList linkedList){
    return linkedList.copy().addNodeHeadfPtr(nodePtr);
}

LinkedList operator+(LinkedList linkedList, Node node){
    return linkedList.copy().addNodeEndfPtr(&node);
}

LinkedList operator+(Node node, LinkedList linkedList){
    return linkedList.copy().addNodeHeadfPtr(&node);
}
*/

int main() {
    LinkedList list = LinkedList();
    while (true){
        int num;
        char name[10];
        int prg;
        int cmp;
        std::cout << "number(<=0 for quit): ";
        std::cin >> num;
        if (num <= 0){
            break;
        } else if (list.isFound(num)){
            std::cout << "number existing." << std::endl;
        } else {
            std::cout << "name: ";
            std::cin >> name;
            std::cout << "Programming score: ";
            std::cin >> prg;
            std::cout << "Computer science score: ";
            std::cin >> cmp;
            Node* newNodePtr = new Node(num, name, prg, cmp);
            list.addNodeNumfPtr(newNodePtr);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Result:" << std::endl;
    list.print();
    system("pause");
}
