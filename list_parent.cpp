#include "list_parent.h"

void createList(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}


void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    int i = 1;
    if(first(L)!=NULL) {
        do {
            cout<< "MENU "<<i<<endl;
            cout<<info(P)<<endl;
            printInfo(child(P));
            cout<<endl;
            P = next(P);
            i++;
        } while((P)!=NULL);
    }
}

void printInfoMenu(address_parent P){
    cout<<endl;
    cout<< "MENU "<<info(P)<<" : "<<endl;
    printInfo(child(P));
    cout<<endl;
}

address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != NULL);
    return NULL;
}

int howmanymenu(List_parent L){
    address_parent P = first(L);
    int x = 1;
    while(P != last(L)){
        P = next(P);
        x++;
    }
    return x;
}

address_parent findElmIdx(List_parent L, int i){
    int x = 1;
    if (first(L) == NULL){
        cout<< "=== LIST KOSONG ==="<<endl;
    } else if (i < x || i > howmanymenu(L)){
        cout<< "!!!index tidak sesuai!!!"<<endl;
    } else {
        address_parent P = first(L);
        while(x != i){
            P = next(P);
            x++;
        }
        return P;
    }
    return NULL;
}

void deleteAfter(List_parent &L,  address_parent &p){
    if(first(L) == NULL){
        cout<< "List Kosong"<<endl;
    } else if (first(L) == p && next(p) == NULL){
        first(L) = NULL;
        next(p) = NULL;
    } else if (first(L) == p){
        first(L) = next(p);
        next(p) = NULL;
    } else if (next(p) == NULL){
        address_parent q;
        while (next(q) != p){
            q = next(q);
        }
        next(q) = NULL;
        next(p) = NULL;
    } else {
        address_parent q;
        while (next(q) != p){
            q = next(q);
        }
        next(q) = next(p);
        next(p) = NULL;
    }
}

void deleteRelasi(List_parent &L, address_child C){
    if (first(L) == NULL){
        cout<< "LIST PARENT KOSONG"<<endl;
    } else {
        address_parent P = first(L);
        address_relasi R;
        while (P != NULL){
            R = findElm(child(P), C);
            if (R != NULL){
                deleteAfter(child(P), R);
            }
            P = next(P);
        }
    }
}

void maxParent(List_parent L){
    int max = 0;
    int temp = 0;
    address_parent P = first(L);
    address_parent maxAdr = NULL;
    address_relasi R;
    while (P != NULL){
        R = first(child(P));
        while(R != NULL){
            temp = temp + info(info(R)).harga;
            R = next(R);
        }
        if (temp > max){
            maxAdr = P;
            max = temp;
        }
        temp = 0;
        P = next(P);
    }
    if (maxAdr == NULL){
        cout<< "SUBMENU MASIH KOSONG"<<endl;
    } else {
        cout<< "???????? TOTAL SUB MENU PALING MAHAL ????????"<<endl;
        printInfoMenu(maxAdr);
    }
}

void minParent(List_parent L){
    int max = 99999999999;
    int temp = 0;
    address_parent P = first(L);
    address_parent maxAdr = NULL;
    address_relasi R;
    while (P != NULL){
        R = first(child(P));
        while(R != NULL){
            temp = temp + info(info(R)).harga;
            R = next(R);
        }
        if (temp < max){
            maxAdr = P;
            max = temp;
        }
        temp = 0;
        P = next(P);
    }
    if (maxAdr == NULL){
        cout<< "SUBMENU MASIH KOSONG"<<endl;
    } else {
        cout<< "???????? TOTAL SUB MENU PALING MURAH ????????"<<endl;
        printInfoMenu(maxAdr);
    }
}