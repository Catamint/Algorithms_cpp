#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main(){
    cout<<"hlw"<<endl;

    cout<<"1:"<<endl;
    int* a = new int[3];
    for(int i=0;i<3;i++)
        cin>>a[i];

    for(int i=0;i<3;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"2:"<<endl;
    int* c = new int[3];
    for(int i=0;i<3;i++)
        cin>>*(c+i);

    for(int i=0;i<3;i++)
        cout<<c[i]<<" ";
    cout<<endl;

    // delete[] a;

    // array<int, 3> b = {};
    // cout<<*b<<endl;


    return 0;
}