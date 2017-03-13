#include <iostream>

using namespace std;

struct data{
    int nilai1;
    int nilai2;
};

int main()
{
    data *induk_data;
    induk_data = new data;

    cout<<"Masukan Nilai 1 = ";cin>>induk_data -> nilai1;
    cout<<"Masukan Nilai 2 = ";cin>>induk_data -> nilai2;
    cout<<endl;
    cout<<"isi dari Nilai 1 = "<<induk_data -> nilai1;
    cout<<endl;
    cout<<"isi dari Nilai 2 = "<<induk_data -> nilai2;
    return 0;
}
