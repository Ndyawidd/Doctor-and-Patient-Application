#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include <iostream>
#include "Pasien.h"
using namespace std;

#define Nil NULL
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define pRelasi(P) P->pRelasi
#define pPasien(R) R->pPasien

struct dokter {
    string kodeDokter;
    string namaDokter;
    string spesialis;
    int jumPasien;
};

typedef dokter infotypeD;
typedef struct elmD *adrD;
typedef struct elmR *adrR;

struct elmD {
    infotypeD info;
    adrD next;
    adrD prev;
    adrR pRelasi;
};

struct listD {
    adrD first;
    adrD last;
};

struct elmR {
    infotypeP info;
    adrR next;
    adrP pPasien;
};

/**Dokter - Double Linked List*/
void createListDokter(listD &L);
bool isEmptyDokter(listD L);
adrD alokasiDokter(infotypeD dx);
void dealokasiDokter(adrD &P);

/**Relasi - Single Linked List*/
adrR alokasiRel(adrP P);
void insertRelasi(adrD D, adrR R);

//Case 1 : Menambah data Dokter
void insertDokter(listD &L, adrD P);

//Case 3 : Menambah pasien pada dokter tertentu
void connect(listD LD, listP LP);
bool isRedundant(listD L, adrD D, adrP P);

//Case 4 : Menghapus data Dokter
void deleteFirst_p(listD &L, adrD &P);
void deleteLast_p(listD &L, adrD &P);
void deleteAfter_p(listD &L, adrD &P, adrD prec);
void deleteElementDokter(listD &L, adrD &P);

//Case 6 : Menghapus data Pasien dari dokter tertentu
void deleteRelasi(listD &L, adrD &D, adrP P, adrR &R);

//Case 7 : Mencari Data Dokter berdasarkan Kode Dokter
adrD findElmDokter(listD L, infotypeD x);

//Case 9 : Mencari Dokter yang menangani pasien tertentu
adrR findElmRelasi(listD L, adrD D, adrP P);
void showDokterRel(listD LD, adrP P);

//Case 10 : Menampilkan Dokter
void printInfoDokter(listD L);

//Case 11 : Menampilkan Pasien
void printInfoPasien(listP LP, listD LD);

//Case 12 : Menampilkan data Dokter dan data Pasien yang dirawatnya
void showDokterRelPasien(listD LD);

//Case 13 : Menampilkan data Pasien dan data Dokter yang merawatnya
void showPasienRelDokter(listD LD, listP LP);

//Case 14 : Menampilkan penyakit dari pasien yang ditangani oleh dokter tertentu
void showPasienByDokterID(listD LD, adrD D);

//Case 15 : Menampilkan Data Dokter dan Penyakit Pasien yang dirawatnya
void showPasienByDokter(listD LD);

//Case 16 : Menampilkan Data Pasien dan Spesialis dari Dokter yang merawatnya
void showDokterByPasien(listD LD, listP LP);

//Case 17 : Menampilkan Spesialis dari Dokter yang merawat pasien tertentu
void showDokterByPasienID(listD LD, adrP P);

//Case 18 : Menghitung Pasien dari setiap Dokter tertentu
int countPasienByDokterID(listD LD, adrD D);

//Case 19 : Menghitung Dokter dari Pasien tertentu
int countDokterByPasienID(listD LD, adrP P);

//Case 20 : Menghitung Pasien yang tidak memiliki relasi
int countPasienNotRelasi(listD LD, listP LP);

//Case 21 : Mengubah pasien dari Dokter tertentu
void changePasienByDokter(listD LD, listP LP, adrD D, adrP P, adrP newP);

//Tambahan
int jumDokter(listD L);
int jumPasienfDokter(listD L, infotypeD x);





#endif // DOKTER_H_INCLUDED
