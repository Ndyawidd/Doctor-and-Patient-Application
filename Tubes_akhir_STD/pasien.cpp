#include "pasien.h"

/**PASIEN - CIRCULAR DOUBLE LINKED LIST*/
void createListPasien(listP &L)
{
    first(L) = Nil;
    last(L) = Nil;
}
adrP alokasiPasien(infotypeP px)
{
    adrP P = new elmP;
    info(P).NoReg = px.NoReg;
    info(P).namaPasien = px.namaPasien;
    info(P).diagnosa = px.diagnosa;
    info(P).jumDokter = px.jumDokter;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasiPasien(adrP &P)
{
    delete P;
}

//Case 2 : Menambah data Pasien
void insertPasien(listP &L, adrP P)
{
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
        next(P) = first(L);
        prev(first(L)) = P;
    }
}

//Case 5 : Menghapus data Pasien
void deleteElementPasien(listP &L, adrP &P)
{
    if (first(L) == NULL) {
      cout << "list Kosong" << endl;
    } else if (last(L) == first(L)) {
        first(L) = NULL;
        last(L) = NULL;
    } else {
        if(first(L)==P){
            first(L) = next(P);
            prev(first(L)) = last(L);
            next(last(L)) = first(L);
        } else if (last(L)==P) {
            last(L) = prev(P);
            next(last(L)) = first(L);
            prev(first(L)) = last(L);
        } else {
            adrP c = first(L);
            while(next(c) != P) {
                c = next(c);
            }
            next(c) = next(P);
            prev(next(c)) = c;
        }
    }
    next(P) = NULL;
    prev(P) = NULL;
    dealokasiPasien(P);
}

//Case 8 : Mencari Data Pasien berdasarkan No Registrasi Pasien
adrP findElmPasien(listP L, infotypeP px)
{
     adrP P = first(L);
    if (isEmptyPasien(L)) {
        return NULL;
    }
    do {
        if(info(P).NoReg == px.NoReg) {
            return P;
        }
        P = next(P);
    } while (P!=first(L));
    return NULL;
}


/**Tambahan*/
int jumPasien(listP L)
{
    int i = 0;
    adrP P = first(L);
    do {
        i++;
        P = next(P);
    } while (P!=first(L));
    return i;
}
bool isEmptyPasien(listP L)
{
    return (first(L) == NULL && last(L) == NULL);
}
