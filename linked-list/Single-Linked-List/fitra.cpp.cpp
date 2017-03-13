#include "pasien.h"

using namespace std;

int main()
{
    int pilihan;
    char ulang;
    mulaiLinkedlist(); //memanggil fungsi input data pertama

    do{
        cout << endl;
        cout << "Selamat Datang Di Memasukan Data Pasien" << endl; //tampilan menu
        cout << "Menu : " << endl;
        cout << "1. Tambah Data di Depan" << endl;
        cout << "2. Tambah Data di Belakang" << endl;
        cout << "3. Tambah Data di Tengah" << endl;
        cout << "4. Tampilkan Data" << endl;
        cout << "5. Hapus Data" << endl;
        cout << endl;
        cout << "Masukan Pilihan Anda = ";
        cin >> pilihan;
        cin.ignore();

        switch(pilihan){ //proses memasukan pilihan yang dimenu
            case 1 :
                tambahData(); //memanggil fungsi untuk operasi tambah data didepan
                tambahDepan();
                break;
            case 2:
                tambahData(); //memanggil fungsi untuk operasi tambah data dibelakang
                tambahBelakang();
                break;
            case 3:
                tambahData(); //memanggil fungsi untuk operasi tambah data ditengah
                tambahTengah();
                break;
            case 4:
                tampil(); //fungsi menampilkan data pasien
                break;
            case 5:
                hapus(); //fungsi untuk menghapus data pasien, penghapusan data dengan urutan
                break;
        }

        cout << endl;
        cout<<"Anda Ingin Menambah Data atau menampilkan isi data [y/n]= ";
        cin>>ulang;

        system("CLS");

    }while(ulang == 'y'); //proses pengulangan untuk kembali ke menu utama atau tidak
}

