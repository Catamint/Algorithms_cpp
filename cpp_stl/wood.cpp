#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> vec[10];

int print(){
    for(int i=0;i<10;i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void lookfor(int &i, int &j, int a){
    for(i=0;i<10;i++){
        for(j=0;j<vec[i].size();j++){
            if(vec[i][j]==a) return;
        }
    }
}
void go_back(int i, int j_left){
    bool flag=false;
    for(int j=j_left;j<vec[i].size();j++){
        int temp=vec[i][j];
        if(temp!=i) vec[temp].push_back(temp);
        else flag=true;
    }
    vec[i].resize(j_left+1);
    if(flag==true) vec[i].push_back(i);
    print();
}
void move_(int i_a, int j_a, int n, int i_b){
    for(int j=j_a;n>0;n--,j++){
        vec[i_b].push_back(vec[i_a][j]);
    }
    vec[i_a].resize(j_a);
    print();
}

int main(){
    string v, p;
    int a,b;
    for(int i=0;i<10;i++){
        vec[i].push_back(i);
        // cout<<*vec[i].begin();
    }
    cin>>v;
    while(v!="quit"){
        cin>>a>>p>>b;
        int a_i, a_j, b_i, b_j;
        lookfor(a_i,a_j,a);
        lookfor(b_i,b_j,b);
        if(v=="move" && p=="onto"){
            go_back(a_i,a_j+1);
            go_back(b_i,b_j+1);
            move_(a_i,a_j,1,b_i);
        }

        // cout<<"1";
        cin>>v;
        // cout<<v<<a<<p<<b;
    }
    print();
}