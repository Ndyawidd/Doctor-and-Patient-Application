#include <iostream>
#include "Dokter.h"
#include "Pasien.h"

using namespace std;

int menu() {
    int choose;
    cout << "===================== DATA PASIEN DAN DOKTER =====================" << endl;
    cout << "1.  Menambah data Dokter" << endl;
    cout << "2.  Menambah data Pasien" << endl;
    cout << "3.  Menambah pasien pada dokter tertentu" << endl;
    cout << "4.  Menghapus data Dokter" << endl;
    cout << "5.  Menghapus data Pasien" << endl;
    cout << "6.  Menghapus data Pasien dari dokter tertentu" << endl; //Delete Relasi
    cout << "7.  Mencari Data Dokter berdasarkan Kode Dokter" << endl;
    cout << "8.  Mencari Data Pasien berdasarkan No Registrasi Pasien" << endl;
    cout << "9.  Mencari Dokter yang menangani pasien tertentu" << endl; //Find Relasi
    cout << "10. Menampilkan Dokter" << endl;
    cout << "11. Menampilkan Pasien" << endl;
    cout << "12. Menampilkan Data Dokter dan data Pasien yang dirawatnya" << endl;
    cout << "13. Menampilkan Data Pasien dan data Dokter yang merawatnya" << endl;
    cout << "14. Menampilkan penyakit dari pasien yang ditangani oleh dokter tertentu" << endl;
    cout << "15. Menampilkan Dokter dan Penyakit Pasien yang dirawatnya" << endl;
    cout << "16. Menampilkan Pasien dan Spesialis dari Dokter yang merawatnya" << endl;
    cout << "17. Menampilkan Spesialis dari Dokter yang merawat pasien tertentu" << endl;
    cout << "18. Menghitung Pasien dari setiap Dokter tertentu" << endl;
    cout << "19. Menghitung Dokter dari Pasien tertentu" << endl;
    cout << "20. Menghitung Pasien yang tidak memiliki relasi" << endl;
    cout << "21. Mengubah pasien dari Dokter tertentu" << endl;
    cout << "[Masukkan angka selain menu diatas untuk keluar]" << endl;
    cout << "Pilih menu : ";
    cin >> choose;
    system("CLS");
    return choose;
}


int main() {
    int pil;
    string yes;

    listD LD;
    adrD D;
    infotypeD dx;

    listP LP;
    adrP P;
    infotypeP px;

    adrR R;

    createListDokter(LD);
    createListPasien(LP);

    pil = menu();
    while (pil <=21 && pil>=1) {
        switch((pil)) {
        case 1: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t TAMBAH DOKTER \t" << endl;
            cout << "Kode Dokter : ";
            cin >> dx.kodeDokter;
            D = findElmDokter(LD, dx);
            while(D != NULL){
                cout << "Kode Dokter sudah terdaftar, silahkan masukkan kode lain" << endl << "Kode Dokter : ";
                cin >> dx.kodeDokter;
                dx.namaDokter = "";
                dx.spesialis = "";
                D = findElmDokter(LD, dx);
                cout << D;
            }
            cout << "Nama Dokter : ";
            cin >> dx.namaDokter;

            cout << "Spesialis : ";
            cin >> dx.spesialis;

            D = alokasiDokter(dx);
            insertDokter(LD, D);

            cout << "\t[Input Berhasil]\t" << endl;
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 2: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t TAMBAH PASIEN \t" << endl;
            cout << "No Registrasi : ";
            cin >> px.NoReg;
            P = findElmPasien(LP, px);
            while(P != NULL){
                cout << "No Registrasi sudah terdaftar, silahkan masukkan No baru" << endl << "No Registrasi : ";
                cin >> px.NoReg;
                P = findElmPasien(LP, px);
            }
            cout << "Nama Pasien : ";
            cin >> px.namaPasien;

            cout << "Diagnosa : ";
            cin >> px.diagnosa;

            P = alokasiPasien(px);
            insertPasien(LP, P);

            cout << "\t[Input Berhasil]\t" << endl;
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 3: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENAMBAH PASIEN PADA DOKTER TERTENTU \t" << endl;
            if (first(LD)!=NULL) {
                connect(LD, LP);
            } else {
                cout << "Data Dokter Tidak Ditemukan" << endl;
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 4: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENGHAPUS DOKTER \t" << endl;
            printInfoDokter(LD);
            cout << endl;
            if (first(LD)!=NULL) {
                cout << "Kode Dokter : ";
                cin >> dx.kodeDokter;
                D = findElmDokter(LD, dx);
                if(D == NULL){
                    cout << "Kode Dokter TIDAK TERDAFTAR" << endl;
                } else {
                    deleteElementDokter(LD, D);
                    cout << "\t[Delete Berhasil]\t" << endl;
                }
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 5: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENGHAPUS PASIEN \t" << endl;
            printInfoPasien(LP, LD);
            cout << endl;
            if (first(LP)!=NULL) {
                cout << "No Registrasi : ";
                cin >> px.NoReg;
                P = findElmPasien(LP, px);
                if (P == NULL){
                    cout << "No Registrasi TIDAK TERDAFTAR" << endl;
                } else {
                    deleteElementPasien(LP, P);
                    D = first(LD);
                    while(D!=NULL) {
                        R = pRelasi(D);
                        while(R!=NULL) {
                            adrP p = pPasien(R);
                            if (p == P) {
                                deleteRelasi(LD, D, p, R);
                            }
                            R = next(R);
                        }
                        D = next(D);
                    }
                    cout << "\t[Delete Berhasil]\t" << endl;
                }
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 6: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENGHAPUS DATA PASIEN DARI DOKTER TERTENTU \t" << endl;
            if (first(LD)!=NULL && first(LP)!=NULL) {
                showDokterRelPasien(LD);
                cout << "Kode Dokter : ";
                cin >> dx.kodeDokter;
                D = findElmDokter(LD, dx);
                if (D!=NULL) {
                    cout << endl;
                    cout << "No Registrasi Pasien : ";
                    cin >> px.NoReg;
                    P = findElmPasien(LP, px);
                    if (P!=NULL) {
                        R = findElmRelasi(LD, D, P);
                        if (R!=NULL) {
                            deleteRelasi(LD, D, P, R);
                            cout << "\t[Delete Berhasil]\t" << endl;
                        } else {
                            cout << "Dokter " << info(D).namaDokter << " tidak merawat pasien " << info(P).namaPasien << endl;
                        }
                    } else {
                        cout << "Pasien Tidak Ditemukan" << endl;
                    }
                } else {
                    cout << "Dokter Tidak Ditemukan" << endl;
                }
            } else {
                cout << "Data Pasien atau Dokter Tidak Ditemukan" << endl;
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 7: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENCARI DOKTER \t" << endl;
            cout << "Kode Dokter : ";
            cin >> dx.kodeDokter;
            D = findElmDokter(LD, dx);
            if (D!=NULL) {
                cout << endl << "DOKTER DITEMUKAN" << endl;
                cout << "Kode Dokter : " << info(D).kodeDokter << endl;
                cout << "Nama Dokter : " << info(D).namaDokter << endl;
                cout << "Spesialisasi : " << info(D).spesialis << endl;
                cout << "Jumlah Pasien: " << jumPasienfDokter(LD, info(D)) << endl;
            } else {
                cout << "DOKTER TIDAK DITEMUKAN" << endl;
            }
            cout << "----------------------------" << endl;
            break;

        case 8: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENCARI PASIEN \t" << endl;
            cout << "No Registrasi : ";
            cin >> px.NoReg;
            P = findElmPasien(LP, px);
            if (P!=NULL) {
                cout << endl << "PASIEN DITEMUKAN" << endl;
                cout << "No Registrasi : " << info(P).NoReg << endl;
                cout << "Nama Pasien : " << info(P).namaPasien << endl;
                cout << "Diagnosa : " << info(P).diagnosa << endl;
                cout << "Jumlah Dokter : " << countDokterByPasienID(LD, P) << endl;
                cout << endl;
            } else {
                cout << "PASIEN TIDAK DITEMUKAN" << endl;
            }
            cout << "----------------------------" << endl;
            break;

        case 9: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENCARI DOKTER YANG MENANGANI PASIEN TERTENTU \t" << endl;

            printInfoPasien(LP, LD);
            cout << endl;
            if (first(LP)!=NULL) {
                cout << "No Registrasi : ";
                cin >> px.NoReg;
                P = findElmPasien(LP, px);

                if(P!=NULL) {
                    cout << endl << "Dokter Yang Menangani : " << endl << endl;
                    showDokterRel(LD, P);
                } else {
                    cout << "PASIEN TIDAK DITEMUKAN" << endl;
                }
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 10: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN DATA DOKTER \t" << endl;
            printInfoDokter(LD);
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 11: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN DATA PASIEN \t" << endl;
            printInfoPasien(LP, LD);
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 12 : //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN DATA DOKTER DAN DATA PASIEN YANG DIRAWATNYA \t" << endl;
            showDokterRelPasien(LD);
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 13: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN DATA PASIEN DAN DATA DOKTER YANG MERAWATNYA \t" << endl;
            showPasienRelDokter(LD, LP);
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 14: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN PENYAKIT DARI PASIEN YANG DIRAWAT DOKTER TERTENTU \t" << endl;
            printInfoDokter(LD);
            cout << endl;
            if (first(LD)!=NULL) {
                cout << "Kode Dokter : ";
                cin >> dx.kodeDokter;
                D = findElmDokter(LD, dx);
                if (D!=NULL) {
                    showPasienByDokterID(LD, D);
                } else {
                    cout << "Dokter Tidak Ditemukan" << endl;
                }
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 15: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN DOKTER DAN PENYAKIT PASIEN YANG DIRAWATNYA \t" << endl;
            showPasienByDokter(LD);
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 16: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN DATA PASIEN DAN SPESIALIS DARI DOKTER YANG MERAWATNYA \t" << endl;
            showDokterByPasien(LD, LP);
            cout << "----------------------------" << endl;
            cout << endl;
            break;
            break;

        case 17: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENAMPILKAN SPESIALIS DARI DOKTER YANG MERAWAT PASIEN TERTENTU \t" << endl;
            printInfoPasien(LP, LD);
            cout << endl;
            if (first(LP)!=NULL) {
                cout << "No Registrasi Pasien : ";
                cin >> px.NoReg;
                P = findElmPasien(LP, px);
                showDokterByPasienID(LD, P);
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 18: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENGHITUNG PASIEN YANG DIRAWAT DOKTER TERTENTU \t" << endl;
            printInfoDokter(LD);
            cout << endl;
            if (first(LD)!=NULL) {
                cout << "Kode Dokter : ";
                cin >> dx.kodeDokter;
                D = findElmDokter(LD, dx);
                if (D!=NULL) {
                    cout << "Terdapat " << countPasienByDokterID(LD, D) << " Pasien yang ditanganai oleh Dokter " << info(D).namaDokter << endl;
                } else {
                    cout << "Dokter Tidak Ditemukan" << endl;
                }
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 19: //ALIFYA CHAIRUNNISA (1303220130)
            cout << "----------------------------" << endl;
            cout << "\t MENGHITUNG DOKTER YANG MERAWAT PASIEN TERTENTU \t" << endl;
            printInfoPasien(LP, LD);
            cout << endl;
            if (first(LP)!=NULL) {
                cout << "No Registrasi : ";
                cin >> px.NoReg;
                P = findElmPasien(LP, px);
                cout << "Terdapat " << countDokterByPasienID(LD, P) << " Dokter yang menangani pasien " << info(P).namaPasien << endl;
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 20://NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENGHITUNG PASIEN YANG TIDAK DIRAWAT \t" << endl;
            cout << "Pasien yang tidak dirawat oleh dokter ada sebanyak : " << countPasienNotRelasi(LD, LP) << " Orang" << endl;
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        case 21: //NADYA WIDDY ASTUTI(1303223061)
            cout << "----------------------------" << endl;
            cout << "\t MENGUBAH PASIEN DARI DOKTER TERTENTU \t" << endl;
            string newPasien;

            if (first(LD)!=NULL && first(LP)!=NULL) {
                showDokterRelPasien(LD);
                cout << endl;
                cout << "Kode Dokter : ";
                cin >> dx.kodeDokter;
                D = findElmDokter(LD, dx);
                if(P == NULL){
                    cout << "Kode Dokter tidak ditemukan" << endl;
                    break;
                } else {
                    cout << "No Registrasi Pasien yang akan diubah : ";
                    cin >> px.NoReg;
                    P = findElmPasien(LP, px);
                }

                if(P == NULL){
                    cout << "No Registrasi tidak ditemukan" << endl;
                } else {
                    R = findElmRelasi(LD, D, P);
                    if (R!=NULL) {
                        infotypeP newpx;
                        cout << "No Registrasi Pasien yang baru : ";
                        cin >> newpx.NoReg;
                        P = findElmPasien(LP, newpx);
                        if (P!=NULL) {
                            adrP newP = findElmPasien(LP, newpx);
                            changePasienByDokter(LD, LP, D, P, newP);
                        } else {
                            cout << "Data Pasien tidak Ditemukan" << endl;
                        }

                    } else {
                        cout << "Dokter " << info(D).namaDokter << " tidak merawat pasien " << info(P).namaPasien << endl;
                    }
                }
            } else {
                cout << "Data Pasien atau Dokter Tidak Ditemukan" << endl;
            }
            cout << "----------------------------" << endl;
            cout << endl;
            break;

        }
        pil = menu();
    }

    return 0;
}
