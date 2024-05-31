#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create();
LinkedList *LinkedList_create();
void LinkedList_add_first(LinkedList* L, int val);
void LinkedList_add_last_slow(LinkedList* L, int val);
void LinkedList_add_last_fast(LinkedList* L, int val);
void LinkedList_print(const LinkedList* L);
bool LinkedList_is_empty(const LinkedList* L);

#endif