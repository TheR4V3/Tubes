#include "kereta.h"

void createListKereta(List_K &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_K newElementKereta(infotype_K X){
    address_K P = new elm_K;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstKereta(List_K &L, address_K P){
    if (first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void deleteFirstKereta(List_K &L, address_K &P){
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
    prev(first(L)) = NULL;
}

void printInfoKereta(List_K L){
    address_K P = first(L);
    cout<<"List Kereta: "<<endl;
    while (next(P) != NULL){
        cout<<"Jenis: "<<info(P).Jenis<<endl;
        cout<<"Tujuan: "<<info(P).Tujuan<<endl;
        cout<<"Gerbong: "<<info(P).gerbong<<endl;
        cout<<"Tampat duduk: "<<info(P).tempatduduk<<endl;
        P = next(P);
    }
    cout<<endl;
}

address_K findElementKereta(List_K L, int gerbong){
    address_K P = first(L);
    while(P != NULL){
        if (info(P).gerbong == gerbong){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

int menu(){
    cout<<"======MENU======"<<endl;
    cout<<"1. Menambahkan N data baru Kereta"<<endl;
    cout<<"2. Menambahkan N data baru Penumpang"<<endl;
    cout<<"3. Menampilkan data Kereta"<<endl;
    cout<<"4. Menampilkan data penumpang"<<endl;
    cout<<"5. Jumlah data penjualan rumah"<<endl;
    cout<<"0. Exit"<<endl;

    int input = 0;
    cin>>input;
    return input;
}
