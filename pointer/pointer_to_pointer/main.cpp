#include <iostream>

using namespace std;

int main()
{
    int var_x=300;
    int *ptr1;
    int **ptr2;

    ptr1 = &var_x;
    ptr2 = &ptr1;

    cout<<"Nilai dari variabel = "<<*ptr1;
    cout<<endl;
    cout<<"Nilai dari variabel = "<<**ptr2;
    cout<<endl;
    return 0;
}
