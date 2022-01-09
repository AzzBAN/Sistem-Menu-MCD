#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_child C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(info(P)).nama<< " | "<< info(info(P)).harga <<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, address_child C) {
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(info(P)).nama == C->info.nama) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteAfter(List_relasi &L, address_relasi &p){
    if(first(L) == NULL){
        cout<< "List relasi Kosong"<<endl;
    } else if (first(L) == p && next(p) == NULL){
        first(L) = NULL;
        info(p) = NULL;
        next(p) = NULL;
    } else if (first(L) == p){
        first(L) = next(p);
        info(p) = NULL;
        next(p) = NULL;
    } else if (next(p) == NULL){
        address_relasi q = first(L);
        while (next(q) != p){
            q = next(q);
        }
        next(q) = NULL;
        info(p) = NULL;
        next(p) = NULL;
    } else {
        address_relasi q = first(L);
        while (next(q) != p){
            q = next(q);
        }
        info(p) = NULL;
        next(q) = next(p);
        next(p) = NULL;
    }
}
