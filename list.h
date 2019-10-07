#ifndef LIST

#define LIST
// defining the type of nodes' data
typedef double var;
// specifier of var type
#define spec "%0.3lf" 
// defining structures
typedef struct node node;
struct node{
    var val;
    node* next;
};

typedef struct List List;
struct List{
    node* head;
    int length;
};
// functions prototypes
List *init(var);
int add(List*, int,  var);
node *getn(List*, int);
int push(List *list,var val);
int unshift(List*, var);
int removeNode(List*, int);
int pop(List*);
int shift(List*);
void printList(List*);
void forEach(List* list, void (*fun)(node*, int));
void destroyList(List*);

#endif