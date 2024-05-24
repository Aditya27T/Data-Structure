#include <iostream>
#include "linkedlist.cpp"

using namespace std;

int main() {
    LinkedList list;
    cout << "Adding 1, 2, 3, 4, 5 to the list" << endl;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    cout << "Displaying the list" << endl;
    list.displayList();

    cout << "Display Reverse List" << endl;
    list.displayReverseList();

    cout << "edit 3 to 666" << endl;
    list.editNode(3, 666);
    cout << "Displaying the edited list" << endl;
    list.displayList();

    cout << "Delete 5 from the list" << endl;
    list.deleteNode(5);
    list.displayList();
}