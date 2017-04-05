#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct data{
    int nilai;
    data *next;
};

data *posisi, *depan, *baru, *belakang, *tambah, *backup, *bantu;
int input, input2;
int pilih;
char ulang;
int letak;

int main(){
    do{
    cout<<"Menu\n";
    cout<<"1. tambah depan\n";
    cout<<"2. tambah belakang\n";
    cout<<"3. tambah tengah\n";
    cout<<"4. hapus depan\n";
    cout<<"5. hapus belakang\n";
    cout<<"6. hapus tengah\n";
    cout<<endl;
    cout<<"masukan pilihan = ";
    cin>>pilih;

    switch(pilih){

    case 1 :
            cout<<"masukan nilai = ";
            cin>>input;
            cout<<endl;
            baru = new data;
            baru->nilai = input;
            if (depan == NULL){
            depan = baru ;
            belakang = baru;
            }
            else {
                baru->next = depan;
                depan = baru;
           }
           cout<<endl;
           posisi=depan;
           while(posisi!=NULL){
                cout<<posisi->nilai<<"\t\t";
                posisi=posisi->next;

    }
   break;

  case 2 :
  cout<<"masukan nilai = ";
  cin>>input;
  cout<<endl;
  baru = new data;
  baru->nilai = input;
  if (depan == NULL){
    depan = baru ;
    belakang = baru;
    }
    else {
        belakang->next = baru;
        belakang = baru;
   }
   cout<<endl;
   posisi=depan;
    while(posisi!=NULL){
        cout<<posisi->nilai<<"\t\t";
        posisi=posisi->next;

    }
   break;

  case 3:
    cout<<"masukan nilai = ";
    cin>>input;
    cout<<"masukan data ke posisi ke berapa = ";
    cin>>input2;
    baru = new data;
    baru->nilai = input;
    baru->next = NULL;

    letak=input;
    posisi=depan;
    for(int i = 1;i<letak; i++){
        backup = posisi;
        posisi=posisi->next;
    }
    backup->next=baru;
    baru->next=posisi;
    cout<<endl;
    posisi=depan;
    while(posisi!=NULL){
        cout<<posisi->nilai<<"\t\t";
        posisi=posisi->next;
    }
    break;

  case 4 :
    posisi=depan;
    depan=posisi->next;
    posisi = NULL;

    posisi = depan ;
    while(posisi!=NULL){
        cout<<posisi->nilai<<"\t\t";
        posisi=posisi->next;
    }

    break;

  case 5 :
      posisi = depan;
      while(posisi->next->next != NULL){
        posisi = posisi->next;
      }
      belakang = posisi ;
      posisi->next = NULL;

      posisi = depan ;
    while(posisi!=NULL){
        cout<<posisi->nilai<<"\t\t";
        posisi=posisi->next;
    }
    break ;

  case 6 :
    cout<<"masukan data ke posisi ke berapa = ";
    cin>>input2;
    letak = input2;
    posisi = depan;

    for(int i = 1;i<letak; i++){
        bantu = posisi;
        posisi=posisi->next;
    }
    bantu->next=posisi->next;
    posisi = NULL ;
    cout<<endl;
    posisi=depan;
    while(posisi!=NULL){
        cout<<posisi->nilai<<"\t\t";
        posisi=posisi->next;
    }

    break;

}

    cout<<endl;
    cout<<endl;
    cout<<"ulang ? [y/n] =  ";cin>>ulang;
    system("cls");
    }while(ulang=='y');

    return 0;
}
