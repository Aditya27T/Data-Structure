#include <iostream>
#include "AllFunction.hpp"

void deleteMenu( LinkedList &linkedList ) {
    int choice;
    do {
        printf("1. Delete by data\n");
        printf("2. Delete by position\n");
        printf("3. Enter Data\n" );
        printf("4. Display Data\n" );
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter data to delete: ");
                int data;
                scanf("%d", &data);
                linkedList.deleteData(data);
                break;
            }
            case 2: {
                printf("Enter position to delete: ");
                int position;
                scanf("%d", &position);
                linkedList.deleteDataByPosition(position);
                break;
            }
            case 3: {
                int data;
                while (1) {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    linkedList.addData(data);
                    printf("Do you want to enter more data? (1/0): ");
                    int more;
                    scanf("%d", &more);
                    if (more == 0) {
                        break;
                    }
                }
                break;
            }
            case 4: {
                linkedList.displayData();
                break;
            }
            case 0: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 0);
}

int main() {
    LinkedList linkedList;
   deleteMenu(linkedList);
}
