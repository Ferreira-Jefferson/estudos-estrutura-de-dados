#include "linked_list.h"

int main() {
  LinkedList *list = LinkedList_create();
  LinkedList_add_first(list, 10);
  LinkedList_add_last(list, 2);
  LinkedList_add_last(list, 4);
  LinkedList_print(list);
  return 0;
}