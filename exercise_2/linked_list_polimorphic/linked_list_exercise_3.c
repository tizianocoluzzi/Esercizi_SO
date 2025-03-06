#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linked_list_exercise_3.h"
#include"linked_list.h"
//TODO creare una elemento che possa contenere una lista polimorfica
//di conseguenza creare print e distruttore per l'elemento che contiene la lista polimofica

//funzioni print delle tre classi
void IntPrint(ListItem* item);
void FloatPrint(ListItem* item);
void PolPrint(ListItem* item);
//TODO implementare gestione della memoria, quindi distruttori e rendere tutto valgrind proof
//istanze delle VMT delle tre classi
ListItemOps ops_int;
ListItemOps ops_float;
ListItemOps ops_pol;

int main(){
    //le tre funzioni di stampa principale
    //non ho implementato i distruttori
    ops_int.print_fn = IntPrint;
    ops_int.dtor_fn = NULL;
    ops_float.print_fn = FloatPrint;
    ops_float.dtor_fn = NULL;
    ops_pol.print_fn = PolPrint;
    ops_pol.dtor_fn = NULL;
    //piccola prova per vedere se andava tutto
    //lista madre
    ListHead capoccia; 
    List_init(&capoccia);
    //sottolista polimorfica
    ListHead h;
    List_init(&h);
    IntListItem* item1 = (IntListItem*) malloc(sizeof(IntListItem));
    assert(item1);
    item1->item.prev = 0;
    item1->item.next = 0;
    item1->item.ops = &ops_int;
    item1->value = 1;
    List_insert(&h, 0, (ListItem*) item1);
    FloatListItem* item2 = (FloatListItem*) malloc(sizeof(IntListItem));
    assert(item2);
    item2->item.prev = 0;
    item2->item.next = 0;
    item2->item.ops = &ops_float;
    item2->value = 1.1;
    List_insert(&h, 0, (ListItem*) item2);
    PolListItem* itemp = (PolListItem*)malloc(sizeof(PolListItem));
    itemp->item.prev = 0;
    itemp->item.next = 0;
    itemp->item.ops = &ops_pol;
    itemp->value = &h;
    List_insert(&capoccia, 0,(ListItem*) itemp);
    List_print(&capoccia);
}
void IntPrint(ListItem* item){
    IntListItem* i = (IntListItem*) item;
    printf("%d ", i->value);
}
void FloatPrint(ListItem* item){
    FloatListItem* i = (FloatListItem*) item;
    printf("%.2f ", i->value);
}
void PolPrint(ListItem* item){
    PolListItem* i = (PolListItem*) item;
    List_print(i->value);
}
