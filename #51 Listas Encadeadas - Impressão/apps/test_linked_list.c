#include "linked_list.h"

int main() {
  LinkedList *list = LinkedList_create();
  LinkedList_add_first(list, 5);
  LinkedList_add_first(list, 4);
  LinkedList_add_first(list, 2);
  LinkedList_add_first(list, 10);
  LinkedList_print(list);
  return 0;
}