GNU nano 6.2                                                                                       linked_list.h                                                                                                 
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void printList(struct Node* head);
void insertSorted(struct Node** head, int data);
void deleteOccurrences(struct Node** head, int key);
void deleteAtPosition(struct Node** head, int position);
void deleteOccurrencesUnsorted(struct Node** head, int key);
void deleteAtPositionUnsorted(struct Node** head, int position);

#endif