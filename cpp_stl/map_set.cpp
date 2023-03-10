#include<iostream>
#include<map>
#include<set>

using namespace std;
int main(){
    map<string, int> a;
    set<int> b;
    b.insert(4);
    b.insert(2);
    b.insert(2);
    cout<<*b.find(2)<<endl;
    cout<<b.count(2)<<endl;
    cout<<b.count(1)<<endl;
    for(set<int>::iterator a=b.begin(); a!=b.end(); a++){
        cout<<*a<<" ";
    }
    cout<<endl;
    a["a"]=0;
    a["5"]=4;
    a["5"]+=2;
    cout<<a["5"]<<endl;

}