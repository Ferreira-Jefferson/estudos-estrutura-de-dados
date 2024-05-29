#include "linked_list.h"
#include "mytime.h"

int main() {
  LinkedList *list_slow = LinkedList_create();
  LinkedList *list_fast = LinkedList_create();
  timer t1, t2;

  t1 = tic();
  for(int i=0; i < 100000; i++)
    LinkedList_add_last_slow(list_slow, i);
  t2 = tac();
  printf("Performance (slow): %f ms\n", comptime(t1, t2));

  t1 = tic();
  for(int i=0; i < 100000; i++)
    LinkedList_add_last_fast(list_fast, i);
  t2 = tac();
  printf("Performance (fast): %f ms\n", comptime(t1, t2));

  return 0;
}