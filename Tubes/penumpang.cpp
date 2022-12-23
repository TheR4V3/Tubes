#include "penumpang.h"

void createListPenumpang(List_P &L){
    first(L) = NULL;
}

address_P newElementPenumpang(infotype_P X){
    address_P P = new elm_P;
    info(P) = X;
    next(P) = NULL;
    return P;
}

void insertFirstPenumpang(List_P &L, address_P P){
    address_P Q;
    Q = first(L);
    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    }else{
        next(P) = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        first(L) = P;
    }
}
void deleteFirstPenumpang(List_P &L, address_P &P){
    P = first(L);
    if(P != NULL){
        first(L) = next(P);
        next(P) = NULL;
    }else{
        cout<<"List Kosong";
    }
}

void printInfoPenumpang(List_P L){
    address_P P = first(L);
    cout<<"List Penumpang: "<<endl;
    do {
        cout<<"Nama: "<<info(P).Nama<<endl;
        cout<<"ID: "<<info(P).idtiket<<endl;
        cout<<"Gerbong: "<<info(P).gerbong<<endl;
        cout<<"Tempat Duduk: "<<info(P).tempatduduk<<endl;
        P = next(P);
    } while(P != first(L));
    cout<<endl;
}


address_P findElementPenumpang(List_P L, int tempatduduk){
    address_P P = first(L);
    do{
        if(info(P).tempatduduk == tempatduduk){
            return P;
        }
        P = next(P);
    }while(P != first(L));
    return NULL;
}
