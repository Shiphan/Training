#include <iostream>
#include <String>

class Node{
    private:
        Node* ptr;
        int num;
        std::string name;
        int prg;
        int cmp;
    public:
        Node(int num, std::string name, int prg, int cmp, Node* ptr = NULL){
            this->num = num;
            // strcpy(this->name, name);
            this->name = name;
            this->prg = prg;
            this->cmp = cmp;
	    this->ptr = ptr;
        }
        int getNum(){
            return this->num;
        }
        std::string getName(){
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
        Node setName(std::string name){
            // strcpy(this->name, name);
            this->name = name;
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
        Node* find(int num){
            Node* ptr = this->head;
            while (ptr != NULL){
                if (ptr->getNum() == num){
                    return ptr;
                }
                ptr = ptr->getPtr();
            }
            return NULL;
        }
        void print(){
            Node* ptr = this->head;
            std::cout << "head -> ";
            while (ptr){
                std::cout << std::endl;
                std::cout << "[" << ptr->getNum() << ", " << ptr->getName() << ", " << ptr->getCmp() << ", " << ptr->getPrg() << "]";
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

class Menu{
    private:
        int select;
        // char content[];
    public:
        Menu() {
            // strcpy(this->content, content);
        }
        void show(){
            std::cout << "# Menu:\n1. add new data\n2. search by number\n0. get final result and exit\nyour select: ";
            std::cin >> this->select;
        }
        int getSelect(){
            return this->select;
        }
};

void addNodeMenu(LinkedList& list){
    int num;
    std::cout << "## Add data:\nnumber(<=0 for cancel): ";
    std::cin >> num;
    if (num <= 0){
        std::cout << "add canceled.\n";
    } else if (list.find(num)){
        std::cout << "number existing.\nadd canceled.\n";
    } else {
        std::string name;
        int prg;
        int cmp;
        std::cout << "name: ";
        std::cin.ignore('\n');
        std::getline(std::cin, name);
        // std::cin >> name;
        std::cout << "Programming score: ";
        std::cin >> prg;
        std::cout << "Computer science score: ";
        std::cin >> cmp;
        Node* newNodePtr = new Node(num, name, prg, cmp);
        list.addNodeNumfPtr(newNodePtr);
    }
}

void searchMenu(LinkedList& list){
    int searchNum;
    std::cout << "## Search data by number:\nnumber: ";
    std::cin >> searchNum;
    Node* foundNode = list.find(searchNum);
    if (foundNode != NULL){
        std::cout << "name: " << foundNode->getName() << "\nProgramming score: " << foundNode->getPrg() << "\nComputer science score: " << foundNode->getCmp() << std::endl;
    } else {
        std::cout << "your search did not match any data, consider other number\n";
    }
}

int main(){
    Menu menu = Menu();
    LinkedList list = LinkedList();
    while (true){
        menu.show();
        int select = menu.getSelect();
        if (select == 0){
            // print result
            list.print();
            break;
        } else {
            if (select == 1){
                addNodeMenu(list);
            } else if (select == 2) {
                // search data
                searchMenu(list);
            } else {
                std::cout << "selection unfined, consider other option\n";
            }
            std::cout << std::endl;
        }
    }
    system("pause");
}
