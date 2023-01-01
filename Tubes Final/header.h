#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;
#define firstK(L) L.firstK
#define firstP(L) L.firstP
#define lastK(L) L.lastK
#define nextK(P) (P)->nextK
#define nextP(P) (P)->nextP
#define nextChild(P) (P)->nextChild
#define prevK(P) (P)->prevK
#define info(P) (P)->info

struct Kereta{
    string Jenis;
    string Tujuan;
    int gerbongK;
    int tempatdudukK;
};

struct Penumpang{
    string Nama;
    string idtiket;
    int gerbongP;
    int tempatdudukP;
};

typedef Kereta infotype_K;
typedef struct elm_K *address_K;

typedef Penumpang infotype_P;
typedef struct elm_P *address_P;

struct elm_K{
    infotype_K info;
    address_K nextK;
    address_K prevK;
    address_P nextChild;
};

struct elm_P{
    infotype_P info;
    address_P nextP;
};

struct List_K{
    address_K firstK;
    address_K lastK;
};

struct List_P{
    address_P firstP;
};

void createListPenumpang(List_P &L);
address_P newElementPenumpang(infotype_P X);

void insertFirstPenumpang(List_P &L, address_P P);
void deleteFirstPenumpang(List_P &L, address_P &P);
void deleteAfterPenumpang(List_P &L, address_P &P, address_P &Precp);
void printInfoPenumpang(List_P L);
address_P findElementPenumpang(List_P L, int gerbong);

void createListKereta(List_K &L);
void hubung(List_K &T, List_P &O);
address_K newElementKereta(infotype_K X);
void insertFirstKereta(List_K &L, address_K P);
void deleteFirstKereta(List_K &L, address_K &P);
void deleteAfterKereta(List_K &L, address_K &Preck, address_P &P);
void HapusKereta(List_K &L, address_K &P, address_K &Preck);
void hapusanak(List_P &L, List_K T, int tempatduduk);
int jumlah_penumpang(List_K &T, List_P &O, int n, int gerbong);
void printInfoKereta(List_K L);
address_K findElementKereta(List_K L, int gerbong);

void printAll(List_K K, List_P O);
int menu();


#endif // HEADER_H_INCLUDED
