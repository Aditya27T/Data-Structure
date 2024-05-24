#include <iostream>
#include "AllFunction.hpp"

void deleteMenu( LinkedList &linkedList ) {
    printf("1. Delete by data\n");
    printf("2. Delete by position\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter data to delete: ");
        int data;
        scanf("%d", &data);
        linkedList.deleteData(data);
    } else if (choice == 2) {
        printf("Enter position to delete: ");
        int position;
        scanf("%d", &position);
        linkedList.deleteDataByPosition(position);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int choice, data, searchData, newData;
    LinkedList linkedList;
    while (1) {
        printf("\nLinked List Menu\n");
        printf("1. Add Data\n");
        printf("2. Display Data\n");
        printf("3. Search Data (by Head)\n");
        printf("4. Search Data (by Head and Tail)\n");
        printf("5. Delete Data\n");
        printf("6. Insert Node After Data\n");
        printf("7. Insert Node Before Data\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                linkedList.addData(data);
                break;
            case 2:
                linkedList.displayData();
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                if (linkedList.searchDataByHead(searchData) != -1) {
                    printf("Data found at position %d (by Head).\n", linkedList.searchDataByHead(searchData));
                } else {
                    printf("Data not found in the linked list (by Head).\n");
                }
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                if (linkedList.searchDataByHeadAndTail(searchData) != -1) {
                    printf("Data found at position %d (by Head and Tail).\n", linkedList.searchDataByHeadAndTail(searchData));
                } else {
                    printf("Data not found in the linked list (by Head and Tail).\n");
                }
                break;
            case 5:
                deleteMenu(linkedList);
                break;
            case 6:
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                printf("Enter new data to insert: ");
                scanf("%d", &newData);
                linkedList.insertAfter(searchData, newData);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                printf("Enter new data to insert: ");
                scanf("%d", &newData);
                linkedList.insertBefore(searchData, newData);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
