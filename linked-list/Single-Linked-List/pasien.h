#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct data{ //data untuk pasien
    string nama;
    int umur;
    string penyakit;
    data *next;
};
    data *depan, *belakang, *mulai, *tambah, *posisi; //struct data pointer depan, belakang, mulai, tambah, posisi
    char nama[50];
    int umur;
    char penyakit[50];

void mulaiLinkedlist(){ //fungsi memasukan data pertama, tidak ada pengujian data itu masih kosong apa tidak
    cout << "Masukan Data Pertama Pasien : " << endl;
    cout << "Masukan Nama     = ";
    cin.getline(nama, 50);
    cout << "Masukan Umur     = ";
    cin >> umur;
    cin.ignore();
    cout << "Masukan Penyakit = ";
    cin.getline(penyakit, 50);

    mulai = new data; //menyiapkan ruang untuk pengisian data baru
    mulai->nama = nama; //data pertama untuk memasukan nama
    mulai->umur = umur; //data pertama untuk memasukan umur
    mulai->penyakit = penyakit; //data pertama untuk memasukan penyakit
    mulai->next = NULL; //mulai ini akan menuju ke null dengan penghubung pointer next setelah data pertama sudah terisi

    depan = mulai; //di proses ini inputan pertama otomatis menjadi depan dan belakang data
    belakang = mulai;
}

void tambahData(){
    tambah = new data; //menyiapkan ruang untuk pengisian data baru
    cout << "Masukan Nama     = ";
    cin.getline(nama, 50);
    cout << "Masukan Umur     = ";
    cin>>umur;
    cin.ignore();
    cout << "Masukan Penyakit = ";
    cin.getline(penyakit, 50);
    tambah->nama = nama; //menambahkan data nama pasien
    tambah->umur = umur; //menambahkan data umur pasien
    tambah->penyakit = penyakit; //menambahkan data penyakit pasien
    tambah->next = NULL; //operator tambah ini akan menuju ke null setelah data sudah dimasukan
}

void tambahDepan(){ //fungsi menambah data dari depan
    if(depan==NULL){ //tidak melakukan pengujian ini karena data pertama kali tidaklah kosong tapi sudah diisi atau terisi
        belakang = tambah;
    }
    else{
        tambah->next = depan; //memberikan akses variabel tambah ke variabel depan
    }
    depan = tambah; //jadi dari depan akan ditambah data baru
}

void tambahBelakang(){ //fungsi menambah data dari belakang
    if(belakang==NULL){ //tidak melakukan pengujian ini karena data pertama kali tidaklah kosong tapi sudah diisi atau terisi
        depan = tambah;
    }
    else{
        belakang->next = tambah; //memberikan akses variabel belakang ke variabel tambah
    }
    belakang = tambah; //jadi dari belakang akan ditambahkan data baru
}

void tambahTengah(){ //fungsi menambah data dari tengah
    int i, kounter, letak ;
    struct data *posisi, *backup;

    cout << "Posisi mana data ini akan ditaruh ";
    cin >> letak;

    posisi = depan;

    while (posisi != NULL){ //menghitung banyak linked list
        posisi = posisi->next;
        kounter++;
    }
    if (letak==1){ //linked awal
        if (depan==NULL){
            depan = tambah;
            depan->next = NULL;
        }
        else{
            backup = depan; //menyimpan data depan di variable backup
            depan = tambah; //meyimpan isi dari tambah ke depan
            depan->next = backup; //memberikan akses dari variable depan ke variable backup
        }
    }

    else if (letak>1 && letak<=kounter){ //cek apakah letak berada dalam jangkauan linked list
        //menset posisi ke link awal
        posisi = depan;
        for (i=1; i<letak; i++){
            backup = posisi; //menyimpan variable posisi ke variable backup
            posisi = posisi->next; //memberikan variable posisi ke link selanjutnya
        }
            backup->next = tambah; //memberikan akses variable backup ke variable tambah(baru)
            tambah->next = posisi; //memberikan akses variable (baru) ke variable
    }
    else{
        cout << "posisi tersebut keluar dari jangkuan" << endl;
    }
}

void hapus(){ //fungsi menghapus data sesuai posisi data yang ingin dihapus
        int i, kounter, letak ;
        struct data *posisi, *backup;

        if (depan==NULL){ //pengujian jika data depan sama dengan kosong
            cout << "List kosong" << endl;
            return;
        }

        cout << "Masukan Posisi yg Ingin dihapus : ";
        cin >> letak;

        posisi = depan;

        if (letak==1){  //linked awal
            depan = posisi->next;
        }
        else{
            while (posisi != NULL){ //menghitung banyak linked list
                posisi = posisi->next;
                kounter++;
            }
            if (letak>0 && letak<=kounter){ //jika letak lebih besar 0 dan letak tidak lebih besar daripada kounternya maka akan melakukan proses dibawah
                posisi = depan;
                for (i=1; i<letak; i++){
                    backup = posisi; //menyimpan variable posisi ke variable backup
                    posisi = posisi->next; //memberikan variable posisi ke link selanjutnya
                }
                backup->next = posisi->next; //memberikan akses dari variabel backup ke akses variabel posisi selanjutnya
            }
            else{
                cout << "posisi tersebut keluar dari jangkuan" << endl;
            }
            cout << "Data berhasil di hapus" << endl; //jika syarat memenuhi
        }
}

void tampil(){ //fungsi menpilkan data
    posisi = depan;
    char lihat;
    int lokasi=1;

    while(posisi!=NULL){ //jika posisi tidak sama dengan kosong

        system("CLS");

        cout << "Data ke- " << lokasi << " : \n";
        cout << "Nama     = " << posisi->nama << endl;
        cout << "Umur     = " << posisi->umur << endl;
        cout << "Penyakit = " << posisi->penyakit << endl;
        cout << endl;
        cout << "Ingin Lihat Data Selanjutnya [y/n] ? ";
        cin >> lihat;

        if(lihat == 'y'){
            posisi=posisi->next;//beralih ke data selanjutnya
            lokasi++;
        }
        else{
            break;
        }
    }
}

#endif // PASIEN_H_INCLUDED
