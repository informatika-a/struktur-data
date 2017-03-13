#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int *banya_mhs[1];
    int banyak[1];
    char nama[20][20];

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

    return 0;
}
