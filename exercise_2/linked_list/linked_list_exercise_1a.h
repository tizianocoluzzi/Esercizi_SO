#pragma once
#include "linked_list.h"
#include "float_list.h"

typedef struct ListFloatListItem{
    ListItem list;
    ListHead* info;
}ListFloatListItem;

void ListFloatList_print(const ListHead* head);
