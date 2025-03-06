#include <stdio.h>
#include "int_list.h"

void IntList_print(ListHead* head){
  ListItem* aux=head->first;
  printf("[");
  while(aux){
    IntListItem* element = (IntListItem*) aux;
    printf("%d ", element->info);
    aux=aux->next;
  }
  printf("]\n");
}
