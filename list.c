#include <stdio.h>
#include <stdlib.h>
#include "list.h"
// initialize the list
List *init(var initValue){
    node *head = malloc(sizeof(*head));
    List *list = malloc(sizeof(*list));
    if (list == NULL || head == NULL){
        exit(EXIT_FAILURE);
    }
    head->val = initValue;
    head->next = NULL;
    list->head = head;
    list->length = 1;
    return list;
}
// pushes node to the last of the list
int push(List *list,var val){
    return add(list, list->length, val);
}
// adds a node to the beginning of the list
int unshift(List *list, var val){
    return add(list, 0, val);
}
// add node in a certain index, returns 0 on failure and 1 on success
int add(List* list, int idx, var val){
    if (idx < 0 && idx > list->length) return 0;
    node *n = malloc(sizeof(*n));
    n->val = val;
    node *prec = getn(list, idx - 1);
    node *succ = getn(list, idx);
    if(prec  == NULL){
        list->head = n;
    } else {
        prec->next = n;
    }
    if (succ == NULL){
        n->next = NULL;
    } else {
        n->next = succ;
    }
    (list->length)++;
    return 1;
}
// removes a node in a certain index, returns 0 on failure and 1 on success
int removeNode(List* list, int idx){
    if (idx < 0 || idx >= list->length) return 0;
    node *n = getn(list, idx);
    node *prec = getn(list, idx - 1);
    node *succ = getn(list, idx + 1);
    if(prec == NULL){
        list->head = succ;
    } else {
        prec->next = succ;
    }
    (list->length)--;
    free(n);
    return 1;
}
// removes the last node of list (popping)
int pop(List* list){
    return removeNode(list, list->length - 1);
}
// removes the first node of list (shifting)
int shift(List* list){
    return removeNode(list, 0);
}
// returns pointer to the node of index idx, NULL if node doesn't exist
node *getn(List *list, int idx){
    if (idx < 0 || idx >= list->length) return NULL;
    node *n = list->head;
    int i;
    for(i = 0; i < idx; i++){
        n = n->next;
    }
    return n;
}
// print single node (used as a callback)
static void printNode(node *n, int idx){
    printf("node %d: "spec"\n", idx, n->val);
}
// print values of all nodes in the list
void printList(List* list) {
    forEach(list, &printNode);
}
// implementation of forEach
void forEach(List* list, void (*fun)(node*, int)){
    int i;
    node* n;
    for(n = list->head, i = 0; n != NULL; n=n->next, i++){
        (*fun)(n, i);
    }
}
// delete list!!!!
static void deleteNode(node* n, int i){
    free(n);
}
void destroyList(List *list){
    forEach(list, &deleteNode);
    printf("deleted all nodes\n");
    free(list);
    printf("deleted list\n");
}