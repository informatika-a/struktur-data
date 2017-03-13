#include <iostream>
#include <windows.h>

using namespace std;

void testA (int &a, int &b); //a,b alias untuk variabel int
void testB (int *p , int*q);  //p,q adalah alamat variabel int
void testC (int a, int b);    //a,b adalah varibel-variabel baru

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

int data1=100,data2=200;

int main()
{
char ulang;

    do{
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
            cout<<"Ulang ? (y/n) ";cin>>ulang;
            system("CLS");
        }while(ulang=='y');
    return 0;
}
