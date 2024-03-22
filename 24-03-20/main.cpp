#include <iostream>

class Node{
private:
        Node* ptr;
        int num;
public:
        Node(int num, Node* ptr = NULL){
            this->num = num;
	    this->ptr = ptr;
        }
        int getNum(){
            return num;
        }
        Node* getPtr(){
            return ptr;
        }
        void setNum(int num){
            this->num = num;
        }
        void setPtr(Node* ptr){
            this->ptr = ptr;
        }
};

class LinkedList{
private:
        Node* startPtr = NULL;
        Node* endPtr = NULL;
public:
        void addNodeEndfPtr(Node* nodePtr){
            if (startPtr == NULL){
                startPtr = nodePtr;
            } else {
                endPtr->setPtr(nodePtr);
            }
            endPtr = nodePtr;
        }
        void addNodeHeadfPtr(Node* nodePtr){
            if (startPtr == NULL){
                endPtr = nodePtr;
            } else {
                nodePtr->setPtr(startPtr);
            }
            startPtr = nodePtr;
        }
        void addNodeNumfPtr(int num, Node* nodePtr){
            if (startPtr == NULL){
                startPtr = nodePtr;
                endPtr = nodePtr;
            } else {
                if (startPtr->getNum() > num){
                    nodePtr->setPtr(startPtr);
                    startPtr = nodePtr;
                } else {
                    Node* ptr = startPtr;
                    while (ptr->getPtr() != NULL && ptr->getPtr()->getNum() < num){
                        ptr = ptr->getPtr();
                    }
                    nodePtr->setPtr(ptr->getPtr());
                    ptr->setPtr(nodePtr);
                }
            }
        }
        void printList(){
            Node* ptr = startPtr;
            std::cout << "head -> ";
            while (ptr){
                std::cout << ptr->getNum() << " -> ";
                ptr = ptr->getPtr();
            }
            std::cout << "||" << std::endl;
        }
};

LinkedList operator+(LinkedList linkedList, Node* nodePtr){
    linkedList.addNodeEndfPtr(nodePtr);
    return linkedList;
}

LinkedList operator+(Node* nodePtr, LinkedList linkedList){
    linkedList.addNodeHeadfPtr(nodePtr);
    return linkedList;
}

LinkedList operator+(LinkedList linkedList, Node node){
    linkedList.addNodeEndfPtr(&node);
    return linkedList;
}

LinkedList operator+(Node node, LinkedList linkedList){
    linkedList.addNodeHeadfPtr(&node);
    return linkedList;
}

int main() {
    
}
