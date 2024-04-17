#include <iostream>
#include <string>

class STNODE {
	private:
        STNODE* ptr;
        int num;
        std::string name;
        int prg;
        int eng;
    public:
        STNODE(){
            this->ptr = NULL;
            this->prg = 0;
            this->eng = 0;
        }
        STNODE(int num, std::string name, int prg, int eng, STNODE* ptr = NULL){
            this->num = num;
            this->name = name;
            this->prg = prg;
            this->eng = eng;
	    	this->ptr = ptr;
        }
        void printInfo(){
        	std::cout << "---" << std::endl;
        	std::cout << "No." << this->num << std::endl;
			std::cout << "Name: " << this->name << std::endl;
        	std::cout << "Programming score: " << this->prg << std::endl;
        	std::cout << "English score: " << this->eng << std::endl;
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
        int getEng(){
            return this->eng;
        }
        STNODE* getPtr(){
            return this->ptr;
        }
        void setNum(int num){
            this->num = num;
        }
        void setName(std::string name){
            this->name = name;
        }
        void setPrg(int prg){
            this->prg = prg;
        }
        void setEng(int eng){
            this->eng = eng;
        }
        void setPtr(STNODE* ptr){
            this->ptr = ptr;
    	}
};

class LinkedList{
    private:
        STNODE* head;
        STNODE* endPtr;
        int length;
    public:
    	LinkedList(){
    		this->head = NULL;
    		this->endPtr = NULL;
    		this->length = 0;
		}
        void addNodeEndfPtr(STNODE* nodePtr){
            if (this->head == NULL){
                this->head = nodePtr;
            } else {
                endPtr->setPtr(nodePtr);
            }
            endPtr = nodePtr;
            this->length++;
        }
        bool removeNodefNum(int num){
        	STNODE* ptr = this->head;
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
						STNODE* newPtr = ptr->getPtr()->getPtr();
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
        STNODE* findFirst(int num){
            STNODE* ptr = this->head;
            while (ptr != NULL){
                if (ptr->getNum() == num){
                    return ptr;
                }
                ptr = ptr->getPtr();
            }
            return NULL;
        }
        bool findAndPrintAllfName(std::string name){
        	STNODE* ptr = this->head;
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
        void printList(){
            STNODE* ptr = this->head;
            std::cout << "head -> ";
            while (ptr){
                std::cout << ptr->getNum();
                std::cout << " -> ";
                ptr = ptr->getPtr();
            }
            std::cout << "||" << std::endl;
        }
        void printTranscript(){
        	//print transcript
        	int realSort = 1;
        	int sort = 1;
        	bool isPrinted[this->length] = {};
        	bool run = true;

        	while (run){ // not ready

			//get max that print
			int sumMax;
        		STNODE* ptr = this->head;
        		int i = 0;
	                while (ptr != NULL){
	                	if (!i[isPrinted]){
	                		sumMax = ptr->getPrg() + ptr->getEng();

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
				int sum = ptr->getPrg() + ptr->getEng();
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
                            int sum = ptr->getPrg() + ptr->getEng();
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

class Menu{
    private:
        int select;
    public:
        Menu() {
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

void insertion(LinkedList& list){
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
        STNODE* newNodePtr = new STNODE(num, name, prg, eng);
        list.addNodeEndfPtr(newNodePtr);
    }
}

int main(){
	Menu menu = Menu();
	LinkedList list = LinkedList();
	int select;
	
	while (true){
		menu.show();
        std::cin >> select;
        menu.writeselect(select);
		
		if (menu.readselect() == 1){
			insertion(list);
		} else if (menu.readselect() == 2){
			std::cout << "search by name... ";
			std::string name;
			std::cin.ignore();
			std::getline(std::cin, name);
			if (list.findAndPrintAllfName(name)) {
				
			} else {
				std::cout << "No match result." << std::endl;
			}
		} else if (menu.readselect() == 3){
			int rmNum;
			std::cout << "select the number you want to delete... ";
			std::cin >> rmNum;
			if (list.removeNodefNum(rmNum)){
				std::cout << "No." << rmNum << " has been deleted." << std::endl;
			} else {
				std::cout << "No." << rmNum << " is not in the list." << std::endl;
			}
		} else if (menu.readselect() == 4){
			list.printList();
		} else if (menu.readselect() == 5){
			list.printTranscript();
		} else if (menu.readselect() == 0){
			std::cout << "exit..." << std::endl;
			break;
		} else {
			std::cout << "selection unfined, consider other option" << std::endl;
		}
		std::cout << std::endl;
	}
}
