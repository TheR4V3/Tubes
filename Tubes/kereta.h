#ifndef KERETA_H_INCLUDED
#define KERETA_H_INCLUDED
#include <iostream>
#include "penumpang.h"

using namespace std;
#define first(L) L.first
#define last(L) L.last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define child(P) (P)->child

struct Kereta{
    string Jenis;
    string Tujuan;
    int gerbong;
    int tempatduduk;
};

typedef Kereta infotype_K;
typedef struct elm_K *address_K;

struct elm_K{
    infotype_K info;
    address_K next;
    address_K prev;
    List_P penumpang;
};

struct List_K{
    address_K first;
    address_K last;
};

void createListKereta(List_K &L);
address_K newElementKereta(infotype_K X);
void insertFirstKereta(List_K &L, address_K P);
void deleteFirstKereta(List_K &L, address_K &P);
void printInfoKereta(List_K L);
address_K findElementKereta(List_K L, string jenis);
int menu();

#endif // KERETA_H_INCLUDED
