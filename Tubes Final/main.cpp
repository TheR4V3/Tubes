#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    List_K T;
    List_P O;
    int gerbong;
    int pilihan = 0, N;
    infotype_K x;
    infotype_P y;
    address_K P;
    address_P Q;
    address_K Preck;
    createListKereta(T);
    createListPenumpang(O);
    pilihan = menu();
    while(pilihan != 0){
        switch(pilihan){
        case 1:
            cout<<"berapa data yang mau ditambah: ";
            cin>>N;
            for (int i = 0; i<N; i++){
                cout<<"Masukkan data: "<<endl;
                cout<<"Jenis: ";
                cin>>x.Jenis;
                cout<<"Tujuan: ";
                cin>>x.Tujuan;
                cout<<"gerbong: ";
                cin>>x.gerbongK;
                cout<<"tempat duduk: ";
                cin>>x.tempatdudukK;
                P = newElementKereta(x);
                insertFirstKereta(T, P);
            }
            break;
        case 2:
            cout<<"berapa data yang mau ditambah: ";
            cin>>N;
            for (int i = 0; i<N; i++){
                cout<<"Masukkan data: "<<endl;
                cout<<"Nama: ";
                cin>>y.Nama;
                cout<<"ID tiket: ";
                cin>>y.idtiket;
                cout<<"gerbong: ";
                cin>>y.gerbongP;
                cout<<"tempat duduk: ";
                cin>>y.tempatdudukP;
                Q = newElementPenumpang(y);
                insertFirstPenumpang(O, Q);
            }
            break;
        case 3:
            cout<<"Data Kereta: "<<endl;
            printInfoKereta(T);
            cout<<findElementKereta(T, 2);
            break;
        case 4:
            cout<<"Data Penumpang: "<<endl;
            printInfoPenumpang(O);
            break;
        case 5:
            cout<<"Jumlah Gerbong: "<<endl;
//            jumlah_penumpang(T, O, N, gerbong);
            break;
        case 6:
            hubung(T,O);
            break;
        case 7:
            cout << "Hapus data: "<<endl;
//            HapusKereta(T, P, Preck);
            break;
        case 8:
            cout << "Hapus Gerbong:"<<endl;
//            hapusanak(O, T, N);
            break;
        case 9:
            cout<<"print All: "<<endl;
            printAll(T, O);
        }
        pilihan = menu();
    }
    cout<<"BYE BYE"<<endl;
    return 0;
}
