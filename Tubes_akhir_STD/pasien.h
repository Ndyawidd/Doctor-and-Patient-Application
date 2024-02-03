#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <iostream>

using namespace std;

#define Nil NULL;
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

struct pasien{
    string NoReg;
    string namaPasien;
    string diagnosa;
    int jumDokter;
};

typedef pasien infotypeP;
typedef struct elmP *adrP;

struct elmP {
    infotypeP info;
    adrP next;
    adrP prev;
};

struct listP{
    adrP first;
    adrP last;
};
/** CIRCULAR DOUBLE LINKED LIST*/
void createListPasien(listP &L);
adrP alokasiPasien(infotypeP px);
void dealokasiPasien(adrP &P);

//Case 2 : Menambah data Pasien
void insertPasien(listP &L, adrP P);

//Case 5 : Menghapus data Pasien
void deleteElementPasien(listP &L, adrP &P);

//Case 8 : Mencari Data Pasien berdasarkan No Registrasi Pasien
adrP findElmPasien(listP L, infotypeP px);

/**Tambahan*/
int jumPasien(listP L);
bool isEmptyPasien(listP L);


#endif // PASIEN_H_INCLUDED
