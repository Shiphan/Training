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
        void addNodeEndfPtr(Node* ptr){
            if (startPtr == NULL){
                startPtr = ptr;
            } else {
                endPtr->setPtr(ptr);
            }
            endPtr = ptr;
        }
        void addNodeHeadfPtr(Node* ptr){
            if (startPtr == NULL){
                endPtr = ptr;
            } else {
                ptr->setPtr(startPtr);
            }
            startPtr = ptr;
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
    char inLocation;
    int inNum;
    cout << "any number for add it to the list" << endl << "0 for quit" << endl;
    while (true){
        cout << "add at...(h/e): ";
        cin >> inLocation;
        if (inLocation != 'h' && inLocation != 'e'){
            if (inLocation == '0'){
                break;
            } else {
                cout << "*[h] for head or [e] for end" << endl;
            }
        } else {
            cout << "No. ";
            cin >> inNum;
            cout << endl;
            if (inNum){
                nodePtr = new Node(inNum);
                if (inLocation == 'h'){
                    list.addNodeHeadfPtr(nodePtr);
                } else {
                    list.addNodeEndfPtr(nodePtr);
                }
                
            } else {
                break;
            }
        }
    }
    list.printList();
    system("pause");
}