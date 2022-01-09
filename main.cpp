#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main()
{
    List_parent LP;
    List_child LC;
    address_child C;
    address_parent P;
    address_relasi R;

    createList(LP);
    createList(LC);

    int menu;
    while(true){
        system("CLS");
        cout<< "===SELAMAT DATANG DI MENU UTAMA==="<<endl;
        cout<< "1. Tambah menu"<<endl;
        cout<< "2. Hapus menu"<<endl;
        cout<< "3. Menambahkan submenu"<<endl;
        cout<< "4. Menambahkan submenu ke menu"<<endl;
        cout<< "5. Mencari dan melihat menu"<<endl;
        cout<< "6. Menghapus submenu"<<endl;
        cout<< "7. Melihat semua menu dan submenu"<<endl;
        cout<< "8. Max parent"<<endl;
        cout<< "9. Min parent"<<endl;
        cout<< "0. KELUAR MENU"<<endl;
        cout<< "MASUKKAN PILIHAN MENU : ";
        cin>>menu;
        if(cin.fail()){
            cout<<"Menu berupa integer tekan ENTER untuk keluar"<<endl;
            cin.sync();
            cin.get();
            system("CLS");
            break;
        } else {
            switch (menu) {
                case 1:{
                    system("CLS");
                    infotype_parent x;
                    cout<< "««««« TAMBAH MENU ««««"<<endl;
                    cout<< "Masukkan nama menu : ";
                    cin.ignore();
                    getline(cin, x);
                    insertFirst(LP, alokasi(x));
                    break;
                }
                case 2:{
                    system("CLS");
                    infotype_parent menu;
                    cout<< "«««« HAPUS MENU ««««"<<endl;
                    cout<< "Masukkan menu yang ingin dihapus : ";
                    cin.ignore();
                    getline(cin, menu);
                    P = findElm(LP, menu);
                    deleteAfter(LP, P);
                    break;
                }
                case 3:{
                    system("CLS");
                    cout<< "«««« TAMBAH SUBMENU ««««"<<endl;
                    infotype_child x;
                    cout<< "Masukkan nama submenu : ";
                    cin.ignore();
                    getline(cin, x.nama);
                    cout<< "Masukkan harga : ";
                    cin>>x.harga;
                    insertFirst(LC, alokasi(x));
                    break;
                }
                case 4:{
                    system("CLS");
                    infotype_child x;
                    int y;
                    cout<< "«««« MEMASUKKAN SUBMENU KE MENU ««««"<<endl;
                    cout<< "Masukkan submenu : ";
                    cin.ignore();
                    getline(cin, x.nama);
                    C = findElm(LC, x.nama);
                    if (C == NULL){
                        cout<< "=== SUB MENU TIDAK TERSEDIA ==="<<endl;
                        break;
                    }
                    cout<< "«««« LIST MENU YANG ADA ««««"<<endl;
                    printInfo(LP);
                    cout<< "Masukkan Indeks Menu : ";
                    cin>>y;
                    P = findElmIdx(LP, y);
                    if (P == NULL){
                        break;
                    }
                    R = alokasi(C);
                    insertFirst(child(P), R);
                    break;
                }
                case 5:{
                    system("CLS");
                    infotype_parent menu;
                    cout<< "Pilih menu"<<endl;
                    cout<< "Masukkan nama menu : ";
                    cin.ignore();
                    getline(cin, menu);
                    P = findElm(LP, menu);
                    if (P == NULL){
                        cout<< "=== MENU TIDAK ADA ==="<<endl;
                        break;
                    }
                    printInfoMenu(P);
                    break;
                }
                case 6:{
                    system("CLS");
                    infotype_child x;
                    cout<< "«««« MENGHAPUS SUBMENU ««««"<<endl;
                    cout<< "Masukkan nama sub menu : ";
                    cin.ignore();
                    getline(cin, x.nama);
                    cout<<"tst"<<endl;
                    C = findElm(LC, x.nama);
                    if (C == NULL){
                        cout<< "SUBMENU TIDAK DITEMUKAN"<<endl;
                        break;
                    }
                    deleteRelasi(LP, C);
                    deleteAfter(LC, C);
                    break;
                }
                case 7:{
                    system("CLS");
                    cout<< "«««« MELIHAT SEMUA MENU & SUBMENU ««««"<<endl;
                    printInfo(LP);
                    break;
                }
                case 8:
                    system("CLS");
                    cout<< "«««« MAX PARENT ««««"<<endl;
                    maxParent(LP);
                    break;
                case 9:
                    system("CLS");
                    cout<< "«««« MIN PARENT ««««"<<endl;
                    minParent(LP);
                    break;
                case 0:
                    return false;
                default:
                    system("CLS");
                    cout<< "MENU TERSEBUT TIDAK ADA"<<endl;
                    cin.sync();
                    cin.get();
                    break;
            }
        }
    }


//    /** insert parent */
//    P = alokasi(3);
//    insertFirst(LP, P);
//    P = alokasi(7);
//    insertFirst(LP, P);
//    P = alokasi(2);
//    insertFirst(LP, P);
//    P = alokasi(4);
//    insertFirst(LP, P);
//
//    cout<<"list parent"<<endl;
//    printInfo(LP);
//
//    /** insert child */
//    C = alokasi("A");
//    insertFirst(LC, C);
//    C = alokasi("D");
//    insertFirst(LC, C);
//    C = alokasi("E");
//    insertFirst(LC, C);
//    C = alokasi("O");
//    insertFirst(LC, C);
//
//    cout<<"list child"<<endl;
//    printInfo(LC);
//
//    /** RELASIKAN PARENT DENGAN CHILD **/
//    P = findElm(LP, 4);
//    C = findElm(LC, "E");
//    R = alokasi(C);
//    insertFirst(child(P),R );
//    C = findElm(LC, "D");
//    R = alokasi(C);
//    insertFirst(child(P),R );
//
//
//    P = findElm(LP, 2);
//    C = findElm(LC, "E");
//    R = alokasi(C);
//    insertFirst(child(P),R );
//
//    P = findElm(LP, 3);
//    C = findElm(LC, "A");
//    R = alokasi(C);
//    insertFirst(child(P),R );
//
//    cout<<endl<<"Setelah Direlasikan"<<endl;
//    cout<<"list parent"<<endl;
//    printInfo(LP);
//
//    cout<<endl<<"list child"<<endl;
//    printInfo(LC);
//
//
//    /** KELEBIHAN DARI BENTUK IIIB: jika salah satu child diedit **/
//    C = findElm(LC, "E");
//    info(C) = "X";
//
//    cout<<endl<<"Setelah Child Diedit"<<endl;
//    cout<<"list parent"<<endl;
//    printInfo(LP);
//
//    cout<<endl<<"list child"<<endl;
//    printInfo(LC);

    return 0;
}
