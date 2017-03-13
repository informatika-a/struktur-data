#include <iostream>
#include <cstdlib>

using namespace std;

    int pilihan;
    int hasil1,hasil2,hasil3,hasil4;
    int angka=0, angka1=0,angka2=0;
    int data1=100,data2=200;
    int *angkanya, *angkanya1;
    int *banya_mhs[1];
    int banyak[1];
    char nama[20][20];
    string ulang;
    int var_x=300;
    int *ptr1;
    int **ptr2;


void testA (int &a, int &b); //a,b alias untuk variabel int
void testB (int *p , int*q);  //p,q adalah alamat variabel int
void testC (int a, int b);    //a,b adalah varibel-variabel baru


void menu(){
    cout<<"Menu : \n";
    cout<<"1. Operator Reference (&)\n";
    cout<<"2. Operator Dereference (*)\n";
    cout<<"3. Implementasi Aritmatika (+, -, /, %)\n";
    cout<<"4. Reference sebagai parameter fungsi\n";
    cout<<"5. Pointer of Array\n";
    cout<<"6. Pointer to Pointer\n";
    cout<<"7. Pengaksesan Isi Struct dengan Pointer\n";
}

int prosesAritmatika(int *angkanya, int *angkanya1){
     hasil1 = (*angkanya) + (*angkanya1);
     hasil2 = (*angkanya)  - (*angkanya1);
     hasil3 = (*angkanya) / (*angkanya1);
     hasil4 = (*angkanya) % (*angkanya1);
}

void testA (int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void testB (int *p, int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

struct data{
    int nilai1;
    int nilai2;
};

void menuPilihan(){
    data *induk_data;
    induk_data = new data;
    cout<<"Pilihan anda = ";cin>>pilihan;
    switch (pilihan)
    {
        case 1:
        cout<<"Masukan Angka = ";cin>>angka;
        angkanya = &angka;
        cout<<"Nilai (isi) dari variabel angka : "<<angka;
        cout<<"\nAlamat variabel angka (&angka) : "<<&angka;
        break;
        case 2:
        cout<<"Masukan Angka = ";cin>>angka;
        angkanya = &angka;
        cout<<"Nilai (isi) dari variabel angka : "<<angka;
        cout<<"\nNilai yang ditunjuk pointer *angkax : "<<*angkanya;
        break;
        case 3:
        cout <<"Masukan angka 1 = ";cin>>angka1;
        cout <<"Masukan angka 2 = ";cin>>angka2;

        angkanya = &angka1;
        angkanya1 = &angka2;

        cout<<prosesAritmatika(angkanya, angkanya1);

        cout<<"Hasil Penjumlahannya adalah = "<<hasil1;
        cout<<endl;
        cout<<"Hasil Pengurangannya adalah = "<<hasil2;
        cout<<endl;
        cout<<"Hasil Pembagiannya adalah = "<<hasil3;
        cout<<endl;
        cout<<"Hasil Modulusnya adalah = "<<hasil4;
        break;
        case 4 :
            cout<<endl;
            cout<<"1. Menggunakan Referensi untuk menukar data\n";
            cout<<"2. Menggunakan Pointer untuk menukar data kembali\n";
            int opsi;
            cout<<"Pilihan anda = ";cin>>opsi;
            if(opsi==1){
                cout<<endl;
                cout<<"data 1 = "<<data1<<endl;
                cout<<"data 2 = "<<data2<<endl;
                cout<<endl;
                cout<<"Menggunakan refrensi untuk menukar isi "<<endl;
                testA(data1 ,data2);  //melwetkan variabel-variabel
                cout<<"Test A data 1 = "<<data1<<endl;
                cout<<"TesT A data 2 = "<<data2<<endl;
            }
            else if(opsi==2){
                cout<<endl;
                cout<<"data 1 = "<<data1<<endl;
                cout<<"data 2 = "<<data2<<endl;
                cout<<endl;
                cout<<"Menggunakan pointer untuk menukar isi kembali "<<endl;
                testB(&data1 ,&data2);  //melewatkan alamat variabel
                cout<<"Test B data 1 = "<<data1<<endl;
                cout<<"Test B data 2 = "<<data2<<endl;
                cout<<endl;
            }
        break;
        case 5:
            banya_mhs[1] = &banyak[1];

            cout<<"Masukan banyak mahasiswa = ";
            cin>>banyak[1];
            cin.ignore();
            for(int kounter=0; kounter<banyak[1];kounter++){
                cout<<"Mahasiswa nama mahasiswa ke "<<kounter+1<<"= ";
                cin.getline(nama[kounter], 20);
                cout<<endl;
            }

            for(int kounter=0; kounter<banyak[1];kounter++){
                cout<<"Nama Mhs "<<nama[kounter];
                cout<<endl;
            }

        break;
        case 6:
        ptr1 = &var_x;
        ptr2 = &ptr1;

        cout<<"Nilai dari variabel = "<<*ptr1;
        cout<<endl;
        cout<<"Nilai dari variabel = "<<**ptr2;
        cout<<endl;
        break;
        case 7:
            cout<<endl;
            cout<<"Masukan Nilai 1 = ";cin>>induk_data -> nilai1;
            cout<<"Masukan Nilai 2 = ";cin>>induk_data -> nilai2;
            cout<<endl;
            cout<<"isi dari Nilai 1 = "<<induk_data -> nilai1;
            cout<<endl;
            cout<<"isi dari Nilai 2 = "<<induk_data -> nilai2;
    }
}

int main(){
    do{
      menu();
      menuPilihan();
    cout<<endl;
    cout<<"Ulang ? (ya/tidak) ";cin>>ulang;
    system("cls");
    }while(ulang=="ya");
     cout<<endl;

     return 0;
}

