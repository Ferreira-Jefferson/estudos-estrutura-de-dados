#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

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

void LinkedList_add_first(LinkedList* L, int val) {
  SNode *N = SNode_create(val);
  N->next = L->begin;
  L->begin = N;
}

void LinkedList_add_last(LinkedList* L, int val) {
  SNode *last = SNode_create(val);
  SNode *N = L->begin;
  if(N == NULL)
    N = last;
  else {
    while(N->next != NULL)
      N = N->next;
    N->next = last;
  }
}

void LinkedList_print(const LinkedList* L) {
  SNode *N = L->begin;

  while(N != NULL){
    printf("%d \n", N->val);
    N = N->next;
  }
}