#pragma once
#include "linked_list.h"

typedef struct FloatListItem{
  ListItem list;
  float info;
} FloatListItem;

void FloatList_print(const ListHead* head);

float FloatList_sum(const ListHead* head);
