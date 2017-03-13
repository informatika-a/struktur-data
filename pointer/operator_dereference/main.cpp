#include <iostream>

using namespace std;

int angka=0;
int *angkanya;


int main()
{
    cout<<"Masukan Angka = ";cin>>angka;
    angkanya = &angka;
    cout<<"Nilai (isi) dari variabel angka : "<<angka;
    cout<<"\nNilai yang ditunjuk pointer *angkax : "<<*angkanya;
    return 0;
}
