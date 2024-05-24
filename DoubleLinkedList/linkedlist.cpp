#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* currNode = head;
            while (currNode->next != nullptr) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
            newNode->prev = currNode;
        }
    }

    void deleteNode(int data) {
        Node* currNode = head;
        while (currNode != nullptr) {
            if (currNode->data == data) {
                if (currNode->prev != nullptr) {
                    currNode->prev->next = currNode->next;
                } else {
                    head = currNode->next;
                }
                if (currNode->next != nullptr) {
                    currNode->next->prev = currNode->prev;
                }
                delete currNode;
                return;
            }
            currNode = currNode->next;
        }
    }

    void displayList() {
        Node* currNode = head;
        while (currNode != nullptr) {
            std::cout << currNode->data << " ";
            currNode = currNode->next;
        }
        std::cout << std::endl;
    }

    void displayReverseList() {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        while (currNode != nullptr) {
            std::cout << currNode->data << " ";
            currNode = currNode->prev;
        }
        std::cout << std::endl;
    }

    void editNode(int oldData, int newData) {
        Node* currNode = head;
        while (currNode != nullptr) {
            if (currNode->data == oldData) {
                currNode->data = newData;
                return;
            }
            currNode = currNode->next;
        }
    }
};