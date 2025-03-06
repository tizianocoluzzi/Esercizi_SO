#pragma once
#include "linked_list.h"
#include "float_list.h"

typedef struct ListListItem{
  ListItem list;
  ListHead head;
} ListListItem;

void ListList_print(const ListHead* head);

void ListList_marginalize(ListHead* dest, const ListHead* src);
