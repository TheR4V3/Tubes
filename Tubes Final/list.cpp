#include "header.h"

void createListKereta(List_K &L){
    firstK(L) = NULL;
    lastK(L) = NULL;
}

address_K newElementKereta(infotype_K X){
    address_K P = new elm_K;
    info(P) = X;
    nextK(P) = NULL;
    prevK(P) = NULL;
    nextChild(P) = NULL;
    return P;
}

void insertFirstKereta(List_K &L, address_K P){
    if (firstK(L) == NULL && lastK(L) == NULL){
        firstK(L) = P;
        nextK(P) = P;
        prevK(P) = P;
    }else{
        prevK(P) = prevK(firstK(L));
        nextK(prevK(firstK(L))) = P;
        nextK(P) = firstK(L);
        prevK(firstK(L)) = P;
        firstK(L) = P;
    }
}

void deleteFirstKereta(List_K &L, address_K &P){
    P = firstK(L);
    nextK(prevK(firstK(L))) = nextK(firstK(L));
    prevK(nextK(firstK(L))) = prevK(firstK(L));
    firstK(L) = nextK(firstK(L));
    nextK(P) = NULL;
    prevK(P) = NULL;
}

void deleteAfterKereta(List_K &L, address_K &Preck, address_K &P){
    P = nextK(Preck);
    nextK(Preck) = nextK(P);
    nextK(P) = NULL;
}

address_K findElementKereta(List_K L, int gerbong){
    address_K P = firstK(L);
    do{
        if(info(P).gerbongK == gerbong){
            return P;
        }
        P = nextK(P);
    }while(P != firstK(L));
    return NULL;
}

void printInfoKereta(List_K L){
    address_K P = firstK(L);
    cout<<"List Kereta: "<<endl;
    do{
        cout<<"Jenis: "<<info(P).Jenis<<endl;
        cout<<"Tujuan: "<<info(P).Tujuan<<endl;
        cout<<"Gerbong: "<<info(P).gerbongK<<endl;
        cout<<endl;
        P = nextK(P);
    }while (P != firstK(L));
    cout<<endl;
}

void createListPenumpang(List_P &L){
    firstP(L) = NULL;
}

address_P newElementPenumpang(infotype_P X){
    address_P P = new elm_P;
    info(P) = X;
    nextP(P) = NULL;
    return P;
}

void insertFirstPenumpang(List_P &L, address_P P){
    if (firstP(L) == NULL){
        firstP(L) = P;
    }else{
        nextP(P) = firstP(L);
        firstP(L) = P;
    }
}


void deleteFirstPenumpang(List_P &L, address_P &P){
    P = firstP(L);
    if(P != NULL){
        firstP(L) = nextP(P);
        nextP(P) = NULL;
    }else{
        cout<<"List Kosong";
    }
}

void deleteAfterPenumpang(List_P &L, address_P &P, address_P &PrecP){
    P = nextP(PrecP);
    nextP(PrecP) = nextP(P);
    nextP(P) = NULL;
}

address_P findElementPenumpang(List_P L, int gerbong){
    address_P P = firstP(L);
    while(P != NULL){
        if(info(P).gerbongP == gerbong){
            return P;
        }
        P = nextP(P);
    }
    return NULL;
}

void printInfoPenumpang(List_P L){
    address_P P = firstP(L);
    cout<<"List Penumpang: "<<endl;
    while(P != NULL){
        cout<<"Nama: "<<info(P).Nama<<endl;
        cout<<"ID: "<<info(P).idtiket<<endl;
        cout<<"Gerbong: "<<info(P).gerbongP<<endl;
        cout<<"Tempat Duduk: "<<info(P).tempatdudukP<<endl;
        cout<<endl;
        P = nextP(P);
    }
    cout<<endl;
}

int jumlah_penumpang(List_K &T, List_P &O, int n, int gerbong){
    address_K K;
    address_P P;
    findElementKereta(T, gerbong);
    n = 0;
    if (K != NULL){
        while(nextP(P) != firstP(O)){
            P = nextP(P);
            n++;
        }
    }
    cout << "Gerbong Kosong" << endl;
    return n;
}

void hapusanak(List_P &L, List_K T, int tempatduduk){
    address_K H;
    address_P Precp;
    address_P P = firstP(L);
    address_P M = findElementPenumpang(L, tempatduduk);
    if(H != NULL){
      if (M == P){
        deleteFirstPenumpang(L, P);
      }else{
        while(nextP(P) != firstP(L)){
            if(M == P){
                deleteAfterPenumpang(L, P, Precp);
            }
        }
      }
    }
}

void hubung(List_K &T, List_P &O){
    address_K K = firstK(T);
    do{
        address_P P = firstP(O);
        while (P != NULL){
            if(info(K).gerbongK == info(P).gerbongP){
                nextChild(K) = P;
            }
            P = nextP(P);
        }
        K = nextK(K);
    }while(K != firstK(T));
}

void HapusKereta(List_K &L, address_K &P, address_K &Preck){
    int gerbong;
    address_K O = findElementKereta(L, gerbong);
    while (findElementKereta(L, gerbong) != NULL){
        if (O == firstK(L)){
            deleteFirstKereta(L, P);
        }else{
            deleteAfterKereta(L, Preck, P);
        }
    }

}

void printAll(List_K K, List_P O){
    address_K P = firstK(K);
    cout<<"==================List Kereta================"<<endl;
    do{
        cout<<"Jenis: "<<info(P).Jenis<<endl;
        cout<<"Tujuan: "<<info(P).Tujuan<<endl;
        cout<<"Gerbong: "<<info(P).gerbongK<<endl;
        address_P Q = nextChild(P);
        if(Q != NULL){
            cout<<"---->Nama: "<<info(Q).Nama<<endl;
            cout<<"---->ID: "<<info(Q).idtiket<<endl;
            cout<<"---->Gerbong: "<<info(Q).gerbongP<<endl;
            cout<<"---->Tempat Duduk: "<<info(Q).tempatdudukP<<endl;
            cout<<endl;
        }else{
            cout<<"-Gerbong Kosong-"<<endl;
        }
        cout<<endl;
        P = nextK(P);
    }while (P != firstK(K));
    cout<<endl;
}

int menu(){
    cout<<"======MENU======"<<endl;
    cout<<"1. Menambahkan N data baru Kereta"<<endl;
    cout<<"2. Menambahkan N data baru Penumpang"<<endl;
    cout<<"3. Menampilkan data Kereta"<<endl;
    cout<<"4. Menampilkan data penumpang"<<endl;
    cout<<"5. Jumlah Gerbong"<<endl;
    cout<<"6. Hubung"<<endl;
    cout<<"7. Menghapus Data Pilihan"<<endl;
    cout<<"8. Menghapus Data Gerbong"<<endl;
    cout<<"9. Show All"<<endl;
    cout<<"0. Exit"<<endl;

    int input = 0;
    cin>>input;
    return input;
}
