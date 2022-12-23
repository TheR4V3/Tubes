#include <iostream>
#include "kereta.h"
#include "penumpang.h"

using namespace std;

int main()
{
    List_K T;
    List_P O;
    int pilihan = 0, N;
    infotype_K x;
    infotype_P y;
    address_K P;
    address_P Q;
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
                cin>>x.gerbong;
                cout<<"tempat duduk: ";
                cin>>x.tempatduduk;
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
                cin>>y.gerbong;
                cout<<"tempat duduk: ";
                cin>>y.tempatduduk;
                Q = newElementPenumpang(y);
                insertFirstPenumpang(O, Q);
            }
            break;
        case 3:
            cout<<"Data Kereta: "<<endl;
            printInfoKereta(T);
            break;
        case 4:
            cout<<"Data Kereta: "<<endl;
            printInfoPenumpang(O);
            break;
        }
        pilihan = menu();
    }
    cout<<"BYE BYE"<<endl;
    return 0;
}
