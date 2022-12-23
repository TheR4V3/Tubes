#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED
#include <iostream>

using namespace std;
#define first(L) L.first
#define next(P) (P)->next
#define info(P) (P)->info

struct Penumpang{
    string Nama;
    string idtiket;
    int gerbong;
    int tempatduduk;
};

typedef Penumpang infotype_P;
typedef struct elm_P *address_P;

struct elm_P{
    infotype_P info;
    address_P next;
};

struct List_P{
    address_P first;
};

void createListPenumpang(List_P &L);
address_P newElementPenumpang(infotype_P X);
void insertFirstPenumpang(List_P &L, address_P P);
void deleteFirstPenumpang(List_P &L, address_P &P);
void printInfoPenumpang(List_P L);
address_P findElementPenumpang(List_P L, int gerbong);

#endif // PENUMPANG_H_INCLUDED
