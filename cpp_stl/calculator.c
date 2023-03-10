#include<stdio.h>

int main(){
    char line[100];
    scanf("%s",line);
    while (1/*结束条件*/){
        float fig=0; //暂存当前数字
        float fig_lst[100]={0}; float *fig_idx=fig_lst; //计算过乘除后的多项式
        char ch='+'; //上一个符号
        int total=0; //多项式的项数
        float ans=0; //结果
        int dot_flag=0;

        for(char *p=line;; p++){    //逐位判断
            if(*p>='0' && *p<='9' && dot_flag==0)   //当前位p为数字,fig=p+fig*10
                fig = fig*10 + (*p-'0');
            else{                                   //当前位p为符号,计算前一项的结果保存到fig_idx
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
                    }
                    *fig_idx /= fig;
                }                   //乘除运算保存结果
                ch=*p;
                fig=0;              //更新数字和符号缓存
            }
            if(*p=='\0') break;
        }
        for(;total>-1;total--){
            ans += *fig_idx--;      //计算多项式的和
        }
        printf("answer: %f\n",ans);
        scanf("%s",line);
    }
}