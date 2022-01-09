#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#include "list_relasi.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child

typedef string infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    List_relasi child;
    address_parent next;
};

struct List_parent {
    address_parent first;
    address_parent last;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent &p);
void deleteRelasi(List_parent &L, address_child C);


/** PERLU MODIFIKASI */
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
address_parent findElmIdx(List_parent L, int i);
void printInfo(List_parent L);
void printInfoMenu(address_parent P);
int howmanymenu(List_parent L);
void maxParent(List_parent L);
void minParent(List_parent L);


#endif // LIST_PARENT_H_INCLUDED
