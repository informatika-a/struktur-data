#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <conio.h>`
#include <windows.h>

using namespace std;

struct data{
    string nama;
    int umur;
    data *next;
};
    data *depan, *belakang, *mulai, *tambah, *posisi, *backup, *hapus;
    char nama[100];
    int umur;

void mulaiLinkedlist(){
    cout<<"Masukan Data Pertama Untuk Memulai Linked List : "<<endl;
    cout<<"Masukan Nama = ";
    cin.getline(nama, 100);
    cout<<"Masukan Umur = ";
    cin>>umur;
    cin.ignore();

    mulai = new data;
    mulai->nama = nama;
    mulai->umur = umur;
    mulai->next = NULL;

    depan = mulai;
    belakang = mulai;
}

void tambahData(){
    tambah = new data;
    cout<<"Masukan Nama = ";
    cin.getline(nama, 100);
    cout<<"Masukan Umur = ";
    cin>>umur;
    cin.ignore();
    tambah->nama = nama;
    tambah->umur = umur;
    tambah->next = NULL;
}

void tambahDepan(){
    if(depan==NULL){
        belakang = tambah;
    }
    else{
        tambah->next = depan;
    }
    depan = tambah;
}

void tambahBelakang(){
    if(belakang==NULL){
        depan = tambah;
    }
    else{
        belakang->next = tambah;
    }
    belakang = tambah;
}

void tambahTengah(){
    int i, kounter, letak ;
    cout<<"Posisi mana data ini akan ditaruh ";
    cin>>letak;

    posisi = depan;
    //menghitung banyak linked list
    while (posisi != NULL){
        posisi = posisi->next;
        kounter++;
    }
    //linked awal
    if (letak == 1){
        if (depan == NULL){
            depan = tambah;
            depan->next = NULL;
        }
        else{
            //menyimpan data depan di variable backup
            backup = depan;
            //meyimpan isi dari tambah ke depan
            depan = tambah;
            //memberikan akses dari variable depan ke variable backup
            depan->next = backup;
        }
    }
    //cek apakah letak berada dalam jangkauan linked list
    else if (letak > 1  && letak <= kounter){
        //menset posisi ke link awal
        posisi = depan;
        for (i = 1; i < letak; i++){
        //menyimpan variable posisi ke variable backup
            backup = posisi;
        //memberikan variable posisi ke link selanjutnya
            posisi = posisi->next;
        }
        //memberikan akses variable backup ke variable tambah(baru)
            backup->next = tambah;
        //memberikan akses variable (baru) ke variable
            tambah->next = posisi;
        }
    else{
        cout<<"Positon out of range"<<endl;
    }
}

void hapusTengah(){
        int i, kounter, letak ;
        cout<<"Masukan Posisi yg Ingin dihapus: ";
        cin>>letak;

        posisi = depan;
            while(posisi != NULL){
                posisi = posisi->next;
                kounter++;
            }
            if (letak> 0 && letak<= kounter){
                posisi = depan;
                for (i = 1;i < letak;i++){
                    backup = posisi;
                    posisi = posisi->next;
                }
                backup->next = posisi->next;
            }
            else{
                cout<<"Data yg ada hanya "<<kounter<<endl;
            }
            cout<<"Element Deleted"<<endl;
    }

void hapusDataTengah(){
    int umur;
    cout<<"Masukan Umur yg ingin di hapus = ";
    cin>>umur;

    posisi = depan;

    while(posisi->umur != umur){
        backup = posisi;
        posisi = posisi->next;
    }
    backup->next = posisi->next;
    posisi = NULL;
}

void hapusDepan(){
    hapus = depan;
    depan = hapus->next;
    hapus = NULL;
}

void hapusBelakang(){
    hapus = depan;
    while(hapus->next->next != NULL){
        hapus = hapus->next;
    }
    belakang = hapus;
    hapus->next = NULL;
}

void tampil(){
posisi = depan;
char lihat;
int lokasi=1;
          while(posisi!=NULL){
           system("CLS");
           cout<<"Data ke- "<<lokasi<<" : \n";
           cout<<"Nama = "<<posisi->nama<<endl;
           cout<<"Umur = "<<posisi->umur<<endl;
           if(posisi != belakang){
               cout<<"Ingin Lihat Data Selanjutnya [y/n] ? ";
               cin>>lihat;
           }
           else{
             cout<<"Data Habis"<<endl;
           }
           if(lihat == 'y'){
           posisi=posisi->next;//beralih ke data selanjutnya
           lokasi++;
           }
           else{
            break;
           }
        }
}
#endif // LINKEDLIST_H_INCLUDED
