#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    // Function to add data at the end of the linked list
    void addData(int data) {
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        printf("Data added successfully.\n");
    }

    // Function to display the linked list
    void displayData() {
        if (head == NULL) {
            printf("Linked list is empty.\n");
            return;
        }
        Node* temp = head;
        printf("Linked list: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    // Function to search for data in the linked list (by Head)
    int searchDataByHead(int data) {
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == data) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    // Function to search for data in the linked list (by Head and Tail)
    int searchDataByHeadAndTail(int data) {
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == data) {
                return position;
            }
            if (temp == tail) {
                break;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    // Function to delete a specific data from the linked list
    void deleteData(int data) {
        if (head == NULL) {
            printf("Linked list is empty.\n");
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->data == data) {
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                printf("Data deleted successfully.\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        printf("Data not found in the linked list.\n");
    }

    void deleteDataByPosition(int position) {
        if (head == NULL) {
            printf("Linked list is empty.\n");
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        int count = 1;
        while (temp != NULL) {
            if (count == position) {
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                printf("Data deleted successfully.\n");
                return;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
        printf("Position not found in the linked list.\n");
    }

    // Function to insert a node after a specific data
    void insertAfter(int searchData, int newData) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == searchData) {
                Node* newNode = createNode(newData);
                newNode->next = temp->next;
                temp->next = newNode;
                printf("Node inserted successfully.\n");
                return;
            }
            temp = temp->next;
        }
        printf("Data not found in the linked list.\n");
    }

    // Function to insert a node before a specific data
    void insertBefore(int searchData, int newData) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->data == searchData) {
                Node* newNode = createNode(newData);
                if (prev == NULL) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    newNode->next = temp;
                    prev->next = newNode;
                }
                printf("Node inserted successfully.\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        printf("Data not found in the linked list.\n");
    }
};
