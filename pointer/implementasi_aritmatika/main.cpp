#include <iostream>

using namespace std;

int hasil1,hasil2,hasil3,hasil4;
int angka1=0,angka2=0;
int *angkanya, *angkanya1;

void prosesAritmatika(int *angkanya, int *angkanya1){
     hasil1 = (*angkanya) + (*angkanya1);
     hasil2 = (*angkanya)  - (*angkanya1);
     hasil3 = (*angkanya) / (*angkanya1);
     hasil4 = (*angkanya) % (*angkanya1);
}

int main()
{
    cout <<"Masukan angka 1 = ";cin>>angka1;
        cout <<"Masukan angka 2 = ";cin>>angka2;

        angkanya = &angka1;
        angkanya1 = &angka2;

        prosesAritmatika(angkanya,angkanya1);

        cout<<"Hasil Penjumlahannya adalah = "<<hasil1;
        cout<<endl;
        cout<<"Hasil Pengurangannya adalah = "<<hasil2;
        cout<<endl;
        cout<<"Hasil Pembagiannya adalah = "<<hasil3;
        cout<<endl;
        cout<<"Hasil Modulusnya adalah = "<<hasil4;
    return 0;
}
