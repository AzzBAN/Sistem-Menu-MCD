#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P).nama<<" | "<< info(P).harga <<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, string x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).nama==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteAfter(List_child &L, address_child &p){
    if(first(L) == NULL){
        cout<< "List child Kosong"<<endl;
    } else if (first(L) == p && next(p) == NULL){
        first(L) = NULL;
        next(p) = NULL;
    } else if (first(L) == p){
        first(L) = next(p);
        next(p) = NULL;
    } else if (next(p) == NULL){
        address_child q = first(L);
        while (next(q) != p){
            q = next(q);
        }
        next(q) = NULL;
        next(p) = NULL;
    } else {
        address_child q = first(L);
        while (next(q) != p){
            q = next(q);
        }
        next(q) = next(p);
        next(p) = NULL;
    }
}
