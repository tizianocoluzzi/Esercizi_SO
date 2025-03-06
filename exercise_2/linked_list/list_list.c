#include <stdio.h>
#include <stdlib.h>
#include "list_list.h"

void ListList_print(const ListHead* head){
  const ListItem* aux=head->first;
  printf("[");
  while(aux){
    const ListListItem* row = (const ListListItem*) aux;
    FloatList_print(&row->head);
    aux=aux->next;
  }
  printf("]\n");
}

void ListList_marginalize(ListHead* dest, const ListHead* src) {
  const ListItem* aux=src->first;
  List_init(dest);
  while(aux) {
    FloatListItem* dest_item  = (FloatListItem*) malloc(sizeof(FloatListItem));
    dest_item->list.prev=0;
    dest_item->list.next=0;
    const ListListItem* row = (const ListListItem*)(aux);
    dest_item->info=FloatList_sum(&(row->head));

    ListItem* result=
        List_insert(dest, dest->last, (ListItem*) dest_item);
    
    aux=aux->next;
  }
}
