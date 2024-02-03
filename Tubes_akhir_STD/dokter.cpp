#include "dokter.h"


/**Dokter - Double Linked List*/

void createListDokter(listD &L)
{
    first(L) = Nil;
    last(L) = Nil;
}
bool isEmptyDokter(listD L)
{
    return (first(L) == Nil && last(L) == Nil);
}
adrD alokasiDokter(infotypeD dx)
{
    adrD P = new elmD;
    info(P).namaDokter = dx.namaDokter;
    info(P).kodeDokter = dx.kodeDokter;
    info(P).spesialis = dx.spesialis;
    info(P).jumPasien = dx.jumPasien;
    next(P) = Nil;
    prev(P) = Nil;
    pRelasi(P) = Nil;
    return P;
}
void dealokasiDokter(adrD &P)
{
    delete P;
}

/**Relasi*/
adrR alokasiRel(adrP P)
{
    adrR R = new elmR;
    next(R) = Nil;
    pPasien(R) = P;
    return R;
}

//Case 1 : Menambah data Dokter
void insertDokter(listD &L, adrD P)
{
    if (first(L) == Nil) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

//Case 3 : Menambah pasien pada dokter tertentu
bool isRedundant(listD L, adrD D, adrP P)
{
    adrR R = pRelasi(D);
    bool sama = false;
    while (R != NULL && !sama) {
        if (pPasien(R) == P) {
            sama = true;
        }
        R = next(R);
    }
    return sama;
}
void connect(listD LD, listP LP)
{
     adrD D;
     adrP P;
     infotypeD dx;
     infotypeP px;
     string yes;
     printInfoDokter(LD);
     cout << endl;
     cout << "Masukkan kode dokter : ";
     cin >> dx.kodeDokter;
     D = findElmDokter(LD, dx);
     while(D == NULL) {
        cout << "Dokter tidak ditemukan, mohon coba lagi [Y/N] " << endl;
        cin >> yes;
        if (yes == "Y" || yes == "y") {
            cout << "Masukkan kode dokter : ";
            cin >> dx.kodeDokter;
        } else if (yes == "N" || yes == "n") {
            break;
        }
        D = findElmDokter(LD, dx);
     }

     if (D != NULL) {
        cout << endl;
        printInfoPasien(LP,LD);
        cout << "Masukkan No Registrasi Pasien : ";
        cin >> px.NoReg;
        P = findElmPasien(LP, px);

        while(P == NULL) {
            cout << "Pasien tidak ditemukan, mohon coba lagi [Y/N] " << endl;
            cin >> yes;
            if (yes == "Y" || yes == "y") {
                cout << "Masukkan No Registrasi Pasien : ";
                cin >> px.NoReg;
            } else if (yes == "N" || yes == "n") {
                break;
            }
            P = findElmPasien(LP, px);
        }

         if(!isRedundant(LD,D,P)) {
            if(D != NULL && P != NULL) {
                adrR R = alokasiRel(P);
                insertRelasi(D, R);
            cout << endl << "[Sukses Connect]" << endl;
            }
         } else {
            cout << "Mohon maaf, dokter " << dx.namaDokter << " sudah tercatat menangani pasien " << info(P).namaPasien << endl;
            cout << "Ingin mengganti ? [Y/N]" << endl;
            cout << "Jawab : ";
            cin >> yes;
            if (yes == "Y" || yes == "y") {
                connect(LD, LP);
            } else if (yes == "N" || yes == "n") {
                cout << "Terimakasih" << endl;
            }
         }
    }
}
void insertRelasi(adrD D, adrR R)
{
    if (pRelasi(D)==Nil) {
        pRelasi(D) = R;
    } else {
        adrR x = pRelasi(D);
        while(next(x)!=Nil) {
            x = next(x);
        }
        next(x) = R;
    }
}

//Case 4 : Menghapus data Dokter
void deleteFirst_p(listD &L, adrD &P)
{
    P = first(L);
    first(L) = next(P);
    next(P) = Nil;
    prev(first(L)) = Nil;
}
void deleteLast_p(listD &L, adrD &P)
{
    P = last(L);
    last(L) = prev(P);
    next(last(L)) = Nil;
    prev(P) = Nil;
}
void deleteAfter_p(listD &L, adrD &P, adrD prec)
{
    prec = first(L);
    while(next(prec)!=P){
        prec = next(prec);
    }
    next(prec) = next(P);
    prev(next(prec)) = prec;
    next(P) = NULL;
    prev(P) = NULL;
}
void deleteElementDokter(listD &L, adrD &P)
{
    if (first(L) == NULL){
        cout << "List Dokter kosong"<< endl;
    } else if (next(first(L))==NULL){
        P = first(L);
        first(L) = NULL;
        last(L)=NULL;
    } else {
        if (P == first(L)){
            deleteFirst_p(L, P);
        } else if (P == last(L)){
            deleteLast_p(L, P);
        } else {
            adrD prec;
            deleteAfter_p(L, P, prec);
        }
    }
}

//Case 6 : Menghapus data Pasien dari dokter tertentu
void deleteRelasi(listD &L, adrD &D, adrP P, adrR &R)
{
    if (pRelasi(D) == Nil) {
      cout << "list relasi Kosong" << endl;
    } else if (next(pRelasi(D)) == Nil) {
        R = pRelasi(D);
        pPasien(R) = Nil;
        pRelasi(D) = Nil;
    } else {
        if (R == pRelasi(D)){
            pRelasi(D) = next(R);
            next(R) = Nil;
            pPasien(R) = Nil;
        } else if (next(R) == Nil){
            adrR xr = pRelasi(D);
            while (next(xr) != R) {
                xr = next(xr);
            }
            next(xr) = Nil;
            pPasien(R) = Nil;
        } else {
            adrR prec = pRelasi(D);
            while (next(prec) != R) {
                prec = next(prec);
            }
            next(prec) = next(R);
            next(R) = Nil;
            pPasien(R) = Nil;
        }
    }
}

//Case 7 : Mencari Data Dokter berdasarkan Kode Dokter
adrD findElmDokter(listD L, infotypeD x)
{
    adrD P= first(L);
    while(P!=NULL) {
            if(info(P).kodeDokter == x.kodeDokter) {
                return P;
            }
            P = next(P);
        }
    return NULL;
}

//Case 9 : Mencari Dokter yang menangani pasien tertentu
adrR findElmRelasi(listD L, adrD D, adrP P)
{
    adrR R = pRelasi(D);

    if (R != Nil){
        while (R != Nil && pPasien(R)!=P){
            R = next(R);
        }
    }
    return R;
}
void showDokterRel(listD LD, adrP P)
{
    adrD D;
    adrR R;

    if (isEmptyDokter(LD)){
        cout << "Tidak ada Dokter" << endl;
    } else {
            D = first(LD);
            while (D != Nil){
                R = pRelasi(D);
                while (R != Nil){
                    if (pPasien(R) == P){
                        cout << "Kode Dokter : " << info(D).kodeDokter << endl;
                        cout << "Nama Dokter : " << info(D).namaDokter << endl;
                        cout << "Spesialisasi : " << info(D).spesialis << endl;
                        cout << "Jumlah Pasien: " << jumPasienfDokter(LD, info(D)) << endl;
                        cout << endl;
                    }
                    R = next(R);
                }
                D = next(D);
            }
            cout<< endl;
    }
    cout << endl;
}

//Case 10 : Menampilkan Dokter
void printInfoDokter(listD L)
{
    adrD P = first(L);
    int count = 1;

    cout << endl;
    cout << "[DATA DOKTER]" << endl;
    if (P == NULL) {
        cout << "Tidak ada Dokter yang ditemukan" << endl;
    } else {
        while(P!=NULL) {
            cout << "Data Dokter ke-" << count << endl;
            cout << "Kode Dokter : " << info(P).kodeDokter << endl;
            cout << "Nama Dokter : " << info(P).namaDokter << endl;
            cout << "Spesialisasi : " << info(P).spesialis << endl;
            cout << "Jumlah Pasien: " << jumPasienfDokter(L, info(P)) << endl;
            cout << endl;
            P = next(P);
            count++;
        }
    }
}

//Case 11 : Menampilkan Pasien
void printInfoPasien(listP LP, listD LD)
{
    adrP P = first(LP);
    cout << "[DATA PASIEN]" << endl;
    if (P == NULL) {
        cout << "Tidak ada Pasien yang ditemukan" << endl;
    } else {
        int count = 1;
        do {
            cout << "Data Pasien ke-" << count << endl;
            cout << "No Registrasi : " << info(P).NoReg << endl;
            cout << "Nama Pasien : " << info(P).namaPasien << endl;
            cout << "Diagnosa : " << info(P).diagnosa << endl;
            cout << "Jumlah Dokter : " << countDokterByPasienID(LD, P) << endl;
            cout << endl;
            P = next(P);
            count++;
        } while(P != first(LP));
    }
}

//Case 12 : Menampilkan data Dokter dan data Pasien yang dirawatnya
void showDokterRelPasien(listD LD)
{
    adrD D;
    adrR R;
    adrP P;
    int i = 1,j=1;
    cout << endl;
    cout << "[DATA RELASI DOKTER DAN PASIEN]" << endl << endl;
    if (isEmptyDokter(LD)){
        cout << "Tidak ada Dokter" << endl;
    } else {
            D = first(LD);
            while (D != Nil){
                cout << "Data Dokter Ke-" << i << endl; i++;
                cout << "Kode Dokter : " << info(D).kodeDokter << endl;
                cout << "Nama Dokter : " << info(D).namaDokter << endl;
                cout << "Spesialisasi : " << info(D).spesialis << endl;
                cout << "Jumlah Pasien: " << jumPasienfDokter(LD, info(D)) << endl;
                cout << endl;
                R = pRelasi(D);
                j = 1;
                cout << "----------" << endl;
                while (R != Nil){
                    P = pPasien(R);
                    cout << "Data Pasien ke-" << j << endl;j++;
                    cout << "No Registrasi : " << info(P).NoReg << endl;
                    cout << "Nama Pasien : " << info(P).namaPasien << endl;
                    cout << "Diagnosa : " << info(P).diagnosa << endl;
                    cout << "Jumlah Dokter : " << countDokterByPasienID(LD, P) << endl << endl;
                    R = next(R);
                }
                cout << "================================" << endl;
                D = next(D);
            }
            cout<< endl;
    }
    cout << endl;
}
//Case 13 : Menampilkan data Pasien dan data Dokter yang merawatnya
void showPasienRelDokter(listD LD, listP LP)
{
    adrP P;
    adrD D;
    adrR R;
    int i = 1, j=1;

    if (isEmptyDokter(LD)){
        cout << "Tidak ada Dokter yang Ditemukan" << endl;
    } else {
        P = first(LP);
        do{
            cout << "Data Pasien ke-" << j << endl;j++;
            cout << "No Registrasi : " << info(P).NoReg << endl;
            cout << "Nama Pasien : " << info(P).namaPasien << endl;
            cout << "Diagnosa : " << info(P).diagnosa << endl;
            cout << "Jumlah Dokter : " << countDokterByPasienID(LD, P) << endl << endl;
            cout << "-------" << endl;
            D = first(LD);
            i = 1;
            while (D != Nil){
                R = pRelasi(D);
                while (R != Nil){
                    if (pPasien(R) == P){
                        cout << "Data Dokter Ke-" << i << endl; i++;
                        cout << "Kode Dokter : " << info(D).kodeDokter << endl;
                        cout << "Nama Dokter : " << info(D).namaDokter << endl;
                        cout << "Spesialisasi : " << info(D).spesialis << endl;
                        cout << "Jumlah Pasien: " << jumPasienfDokter(LD, info(D)) << endl;
                        cout << endl;
                    }
                    R = next(R);
                }
                D = next(D);
            }
            cout<< endl;
            P = next(P);
            cout << "================================" << endl << endl;
        }while (P != first(LP));
    }
    cout << endl;
}

//Case 14 : Menampilkan penyakit dari pasien yang ditangani oleh dokter tertentu
void showPasienByDokterID(listD LD, adrD D)
{
    if(pRelasi(D)==NULL) {
        cout << "Dokter " << info(D).namaDokter << " tidak memiliki pasien";
    } else {
        adrR R = pRelasi(D);
        cout << "Dokter " << info(D).namaDokter << " merawat Pasien berdiagnosa : ";
        while(R!=NULL) {
            cout << info(pPasien(R)).diagnosa << ", ";
            R = next(R);
        }
    }
    cout << endl;
}

//Case 15 : Menampilkan Data Dokter dan Penyakit Pasien yang dirawatnya
void showPasienByDokter(listD LD)
{
    adrD D = first(LD);
    if (isEmptyDokter(LD)) {
        cout << "Tidak ada Dokter yang Ditemukan" << endl;
    } else {
        while(D!=NULL) {
            cout << "Dokter " << info(D).namaDokter << " merawat Pasien berdiagnosa : ";
            adrR R = pRelasi(D);
            while(R!=NULL) {
                cout << info(pPasien(R)).diagnosa << ", ";
                R = next(R);
            }
            D = next(D);
            cout << endl;
        }
    }
    cout << endl;
}

//Case 16 : Menampilkan Data Pasien dan Spesialis dari Dokter yang merawatnya
void showDokterByPasien(listD LD, listP LP)
{
    adrP P;
    adrD D;
    adrR R;

    if (isEmptyDokter(LD)){
        cout << "Tidak ada Dokter yang Ditemukan" << endl;
    } else {
        P = first(LP);
        do{
            cout <<"Pasien " <<info(P).namaPasien << " dirawat oleh dokter spesialis: ";
            D = first(LD);
            while (D != Nil){
                R = pRelasi(D);
                while (R != Nil){
                    if (pPasien(R) == P){
                        cout << info(D).spesialis<< ", ";
                    }
                    R = next(R);
                }
                D = next(D);
            }
            cout<< endl;
            P = next(P);
        }while (P != first(LP));
    }
    cout << endl;
}

//Case 17 : Menampilkan Spesialis dari Dokter yang merawat pasien tertentu
void showDokterByPasienID(listD LD, adrP P)
{
     if (isEmptyDokter(LD)) {
        cout << "Tidak ada Dokter yang Ditemukan" << endl;
    } else {
        cout <<"Pasien " <<info(P).namaPasien << " dirawat oleh Dokter Spesialis : ";
        adrD D = first(LD);
        while(D!=NULL) {
            adrR R = pRelasi(D);
            while(R!=NULL) {
                if (P == pPasien(R)) {
                    cout << info(D).spesialis << ", ";
                }
                R = next(R);
            }
            D = next(D);        }
    }
    cout << endl;
}

//Case 18 : Menghitung Pasien dari setiap Dokter tertentu
int countPasienByDokterID(listD LD, adrD D){
    adrR R = pRelasi(D);
    int i = 0;
    while(R!=NULL) {
        i++;
        R = next(R);
    }
    return i;
}

//Case 19 : Menghitung Dokter dari Pasien tertentu
int countDokterByPasienID(listD LD, adrP P){
    int i = 0;
    adrD D = first(LD);
    while(D!=NULL) {
        adrR R = pRelasi(D);
        while(R!=NULL) {
            if (P == pPasien(R)) {
                i++;
            }
            R = next(R);
        }
        D = next(D);
    }
    return i;
}

//Case 20 : Menghitung Pasien yang tidak memiliki relasi
int countPasienNotRelasi(listD LD, listP LP)
{
     int total = 0;
    adrP P = first(LP);
    if (P!=NULL) {
        do {
            bool found = false;
            adrD D = first(LD);
            while(D!=NULL) {
                adrR R = pRelasi(D);
                while(R!=NULL && !found) {
                    if(P == pPasien(R)) {
                        found = true;
                    }
                    R = next(R);
                }
                D = next(D);
            }
            if (!found) {
                total++;
            }
            P = next(P);
        } while(P!=first(LP));
    } else {
        total = 0;
    }
    return total;
}

//Case 21 : Mengubah pasien dari Dokter tertentu
void changePasienByDokter(listD LD, listP LP, adrD D, adrP P, adrP newP)
{
    adrR R;
    R = pRelasi(D);
    deleteRelasi(LD, D, P, R);
    insertRelasi(D, alokasiRel(newP));
    R = pRelasi(D);
    while(next(R)!=NULL) {
        R = next(R);
    }
}

/**Tambahan*/
int jumDokter(listD L)
{
    int i = 0;
    adrD P = first(L);
    while( P!= NULL) {
        i++;
        P = next(P);
    }
    return i;
}
int jumPasienfDokter(listD L, infotypeD x)
{
    int i=0;
    adrD D=findElmDokter(L, x);
    if (pRelasi(D) != Nil) {
        adrR R = pRelasi(D);
        while(R!=Nil) {
            R = next(R);
            i++;
        }
    }
    return i;
}
