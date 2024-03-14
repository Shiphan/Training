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
        void setPtr(Node* ptr){
            this->ptr = ptr;
        }
};

class LinkedList{
    private:
        Node* startPtr = NULL;
        Node* endPtr = NULL;
    public:
        void addNode(Node node){
            if (startPtr == NULL){
                startPtr = &node;
            } else {
                endPtr->setPtr(&node);
            }
            endPtr = &node;
        }
        void addNodefPtr(Node* ptr){
            if (startPtr == NULL){
                startPtr = ptr;
            } else {
                endPtr->setPtr(ptr);
            }
            endPtr = ptr;
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

int main(){
    LinkedList list = LinkedList();
    Node* nodePtr = NULL;
    int inNum;
    cout << "any number for add it to the list" << endl << "0 for quit" << endl;
    while (true){
        cout << "No. ";
        cin >> inNum;

        if (inNum){
            nodePtr = new Node(inNum);
            list.addNodefPtr(nodePtr);
        } else {
            break;
        }
    }
    list.printList();
}