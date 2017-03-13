#include <iostream>

using namespace std;

int angka=0;
int *angkanya;

int main()
{
    cout<<"Masukan Angka = ";cin>>angka;
    angkanya = &angka;
    cout<<"Nilai (isi) dari variabel angka : "<<angka;
    cout<<"\nAlamat variabel angka (&angka) : "<<&angka;
    return 0;
}
