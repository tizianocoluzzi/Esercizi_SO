#include "linked_list.h"
#include "float_list.h"
#include "linked_list_exercise_1a.h"
#include <stdlib.h>
#include <assert.h>

#define NUM_ELEM 10

void ListFloatList_print(const ListHead* head){
    ListItem* item = head->first;
    while(item){
        ListHead* h =((ListFloatListItem*) item)-> info;
        FloatList_print(h);
        item = item->next;
    }
}
ListHead* random_float_list(int l){
    ListHead* h = malloc(sizeof(ListHead));
    List_init(h);
    for(int i = 0; i < l; i++){
        FloatListItem* new_item = malloc(sizeof(FloatListItem));
        new_item->list.prev = 0;
        new_item->list.next = 0;
        new_item->info = (float) (rand() % 1000) /100;//numero casuale random float tra 0 e 10
        ListItem* result = List_insert(h, 0, (ListItem*) new_item); //inserimento in testa
        assert(result); //controlla se il risultato esiste, altrimenti crash 
    }
    return h;
}
//TODO
void FL_free(ListHead* h){
    //funzione per liberare la lista innestata
    ListItem* item = h->first;
    while(item){
        ListItem* app =List_detach(h, item);
        item = h->first;
        free(app);
    }
    free(h);
}
void LFL_free(ListHead* h){
    //funzione per liberare la lista madre
    ListItem* item = h->first;
    for(int i = 0; i < NUM_ELEM; i++){
        ListItem* app = item;
        item = item->next;
        FL_free(((ListFloatListItem*)app)->info);
    }
}

void my_test(){
    ListHead h;
    int length = 10;
    List_init(&h);
    for(int i = 0; i < NUM_ELEM; i++){
        
        ListFloatListItem* item = malloc(sizeof(ListFloatListItem));
        item->list.prev = 0;
        item->list.next = 0;
        item->info = random_float_list(length);
        ListItem* result =List_insert(&h, 0, (ListItem*)item);
        assert(result);
    }
    ListFloatList_print(&h);
    LFL_free(&h);

}

void prof_exercise(){
    //creazione lista di liste di float random
    ListHead h;
    int length = 10;
    List_init(&h);
    for(int i = 0; i < NUM_ELEM; i++){
        ListFloatListItem* item = malloc(sizeof(ListFloatListItem));
        item->list.prev = 0;
        item->list.next = 0;
        item->info = random_float_list(length);
        ListItem* result =List_insert(&h, 0, (ListItem*)item);
        assert(result);
    }
    ListFloatList_print(&h);
    ListHead* h2 = (ListHead*) malloc(sizeof(ListHead));
    List_init(h2);
    ListFloatListItem* item =(ListFloatListItem*)  h.first;
    for(int i = 0; i < NUM_ELEM; i++){
        FloatListItem* new_item = malloc(sizeof(ListFloatListItem));
        new_item->list.prev = 0;
        new_item->list.next = 0;
        new_item->info = FloatList_sum(item->info);
        item = (ListFloatListItem*) ((ListItem*) item)->next;
        List_insert(h2, h2->last,(ListItem*) new_item);
    }
    printf("result:\n");
    FloatList_print(h2);
    LFL_free(&h);
    FL_free(h2);
    
}
int main(){
    prof_exercise();
}
