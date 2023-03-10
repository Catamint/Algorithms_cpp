#include<iostream>
using namespace std;

int main(){
    string line;
    cin>>line;
    while (1/*结束条件*/){
        float fig=0; //暂存当前数字
        float fig_lst[100]={0}; float *fig_idx=fig_lst; //计算过乘除后的多项式
        int total=0; //多项式的项数        
        char ch='+'; //上一个符号
        float ans=0; //结果

        for(string::iterator p=line.begin();; p++){    //逐位判断
            if(*p>='0' && *p<='9')          //当前位p为数字, fig=p+fig*10
                fig = fig*10 + (*p-'0');
            else if(*p=='.'){               //当前位p为'.', fig+=遍历小数
                string::iterator left = p, right = p;
                float extra = 0;
                while(*++right>='0' && *right<='9');
                p=--right;
                for(;right>left;right--)
                    extra=(extra + *right-'0')/10.0;
                fig+=extra;
            }

            else{                           //当前位p为符号,计算前一项的结果保存到fig_idx
                if(ch=='+'){
                    *++fig_idx = fig;
                    total++;
                }else if(ch=='-'){
                    *++fig_idx = -fig;
                    total++;
                                    //加减运算保存多项式
                }else if(ch=='*') {
                    *fig_idx *= fig;
                }else if(ch=='/') {
                    if(fig==0) {
                        printf("error");
                        return -1;
                    } *fig_idx /= fig;
                }                   //乘除运算保存结果
                ch=*p;
                fig=0;              //更新数字和符号缓存
            }
            if(*p=='\0') break;
        }
        for(;total>-1;total--){
            ans += *fig_idx--;      //计算多项式的和
        }
        cout<<"answer: "<<ans<<endl;
        cin>>line;
    }
}