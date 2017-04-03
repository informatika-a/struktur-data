#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std ;

int pil;
void plh();
void bt_br();
void tbh_blk();
void tbh_dpn();
void hps_blk();
void hps_dpn();
void tmpl();

struct simpul
{
    char angka[10];
        struct simpul *next;
} mhs, *baru, *awal=NULL, *akhir=NULL,*hapus,*bantu;

void clrscr()
{
    system("cls");
}

int main()
{
    do
    {
        cout<<"\n\nPROGRAM LINKED LIST"<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan"<<endl;
        cout<<"6. Keluar\n"<<endl;
        cout<<"Masukan pilihan anda [1 s/d 6] : ";
        cin>>pil;
        plh();
    } while(pil!=6);
    return 0;
}

void plh()
{
    if(pil==1)
        tbh_dpn();
    else if(pil==2)
        tbh_blk();
    else if(pil==3)
        hps_dpn();
    else if(pil==4)
        hps_blk();
    else if(pil==5)
        tmpl();
    else
        cout<<"selesai";
}

void bt_br()
{
    cout<<"\nTambah Data\n";
    cout<<"===========\n\n";
    baru=(simpul*)malloc(sizeof(struct simpul));
    cout<<"Input Angka : ";cin>>baru->angka;
    baru->next=NULL;
}

void tbh_blk()
{
    bt_br();
    if(awal==NULL)
    {
        awal=baru;
    }
    else
    {
        akhir->next=baru;
    }
    akhir=baru;
    akhir->next=NULL;
    cout<<endl<<endl;
    tmpl();
}

void tbh_dpn()
{
    bt_br();
    if(awal==NULL)
    {
        awal=baru;
        akhir=baru;
        akhir->next=NULL;
    }
    else
    {
        baru->next=awal;
        awal=baru;
    }
    cout<<endl<<endl;
    tmpl();
}

void hps_dpn()
{
    if (awal==NULL)
        cout<<"Kosong";
    else
    {
        hapus=awal;
        awal=awal->next;
        free(hapus);
    }
   cout<<endl<<endl;
    tmpl();
}

void hps_blk()
{
    if (awal==NULL)
        cout<<"Kosong";
    else if(awal==akhir)
    {
         hapus=awal;
         awal=awal->next;
         free(hapus);
    }
    else
    {
        hapus=awal;
        while(hapus->next!=akhir)
             hapus=hapus->next;
        akhir=hapus;
        hapus=akhir->next;
        akhir->next=NULL;
        free(hapus);
    }
    cout<<endl<<endl;
    tmpl();
}

void tmpl()
{
     if (awal==NULL)
          cout<<"Kosong";
     else
     {
         bantu=awal;
         while(bantu!=NULL)
         {
            cout<<" "<<bantu->angka;
            bantu=bantu->next;
         }
     }
     getch();
}
