#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node with given value for sorted data
void insertNodeSorted(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    if (*head_ref == NULL || (*head_ref)->data >= value) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to insert a new node with given value for unsorted data
void insertNodeUnsorted(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete all occurrences of a node with a given value
void deleteAllOccurrences(struct Node** head_ref, int key) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    int deleted = 0;

    while (current != NULL) {
        if (current->data == key) {
            deleted = 1;
            if (prev == NULL) {
                *head_ref = current->next;
                free(current);
                current = *head_ref;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    if (!deleted) {
        printf("Node with value %d not found in the linked list.\n", key);
    } else {
        printf("All occurrences of node with value %d deleted successfully.\n", key);
    }
}

// Function to delete a node at a particular position
void deleteNodeAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        printf("Node at position %d deleted successfully.\n", position);
        return;
    }

    int i;
    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* next_node = temp->next->next;
    free(temp->next);
    temp->next = next_node;
    printf("Node at position %d deleted successfully.\n", position);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int main() {
    struct Node* sortedHead = NULL;
    struct Node* unsortedHead = NULL;
    int choice, data, key, position, numNodes;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Sorted Data Mode\n");
        printf("2. Unsorted Data Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Sorted Data Mode Operations:\n");
                printf("1. Add a node\n");
                printf("2. Delete all occurrences of a node with a given value\n");
                printf("3. Delete a node at a particular position\n");
                printf("4. Print the linked list\n");
                printf("5. Back to Main Menu\n);
                            printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the number of nodes to add: ");
                        scanf("%d", &numNodes);
                        printf("Enter %d nodes: ", numNodes);
                        for (int i = 0; i < numNodes; ++i) {
                            scanf("%d", &data);
                            insertNodeSorted(&sortedHead, data);
                        }
                        break;
                    case 2:
                        printf("Enter the value of the node to delete: ");
                        scanf("%d", &key);
                        deleteAllOccurrences(&sortedHead, key);
                        break;
                    case 3:
                        printf("Enter the position of the node to delete: ");
                        scanf("%d", &position);
                        deleteNodeAtPosition(&sortedHead, position);
                        break;
                    case 4:
                        printf("Linked list: ");
                        printList(sortedHead);
                        break;
                    case 5:
                        printf("Returning to Main Menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Please enter a valid option.\n");
                }
                break;