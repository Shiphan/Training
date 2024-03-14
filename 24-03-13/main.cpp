#include <iostream>
using namespace std;

class Node{
    private:
        Node* ptr = NULL;
        int num;
    public:
        Node(int num){
            this->num = num;
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
        void addNodeEnd(Node node){
            if (startPtr == NULL){
                startPtr = &node;
            }
            endPtr = &node;
        }
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
            cout << "head -> ";
            while (ptr){
                cout << ptr->getNum() << " -> ";
                ptr = ptr->getPtr();
            }
            cout << "||" << endl;
        }
};

int name(int i, double d, Node n){
    return d*i;
}

int main(){
    LinkedList list = LinkedList();
    Node* nodePtr = NULL;
    int inNum;
    cout << "any number for add it to the list" << endl << "<=0 for quit" << endl;
    while (true){
        cout << "No. ";
        cin >> inNum;

        if (inNum > 0){
            nodePtr = new Node(inNum);
            list.addNodeNumfPtr(inNum, nodePtr);
        } else {
            break;
        }
    }

    list.printList();
    system("pause");
}