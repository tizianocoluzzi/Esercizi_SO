#include"linked_list.h"
typedef struct IntListItem{
    ListItem item;
    int value;
}IntListItem; 

typedef struct FloatListItem{
    ListItem item;
    float value;
}FloatListItem;

typedef struct PolListItem{
    ListItem item;
    ListHead* value;
}PolListItem;

