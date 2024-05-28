#include "linked_list.h"
#include <stdlib.h>

typedef struct _snode {
  int val;
  struct _snode *next;
} SNode;

typedef struct _linked_list {
  SNode *begin;
} LinkedList;

SNode *SNode_create(int val) {
  SNode *N = calloc(1, sizeof(SNode));
  N->val = val;
  N->next = NULL;
  return N;
}

LinkedList *LinkedList_create() {
  LinkedList *L = calloc(1, sizeof(LinkedList));
  L->begin = NULL;
  return L; 
}