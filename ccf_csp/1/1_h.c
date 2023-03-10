#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
    int cup[3];
    struct NODE *next;
} node;
int cup_max[3];
int visited[101][101][101]={0};

int bfs() {
    node *head = (node *)calloc(1, sizeof(node));
    node *present = (node *)calloc(1, sizeof(node));
    node *last = head;
    node *just = head;
    int total = 0 ,half=cup_max[0]/2;
    present->cup[0]=cup_max[0];
    head->next=present;
    
    visited[cup_max[0]][0][0]=1;
    if(cup_max[0]%2!=0) return 0;

    while (1) {
        if(present == NULL) {
            last = head;
            just = head;
            present = head->next;
            if(present == NULL) return 0;
            total++;
        }
        for (int f = 0; f < 3; f++) {
            for (int t = 0; t < 3; t++) {
                int c1 = present->cup[f], c2 = cup_max[t] - present->cup[t];
                int n[3];
                if (f == t || c1 * c2 == 0) {
                    continue;
                }
                if(c1 - c2 == half){
                    if (present->cup[3-f-t]==0) return total+1;
                    else return total+2;
                }
                if(c1 - c2 > 0){
                    n[f] = c1 - c2;
                    n[t] = cup_max[t];
                    n[3-f-t] = present->cup[3-f-t];
                }else{
                    n[f] = 0;
                    n[t] = present->cup[t] + c1;
                    n[3-f-t] = present->cup[3-f-t];
                }
                if(!visited[n[0]][n[1]][n[2]]){
                    visited[n[0]][n[1]][n[2]]=1;
                    node *temp = (node *)calloc(1, sizeof(node));
                    for(int i=0;i<3;i++){
                        temp->cup[i] = n[i];
                    }
                    printf("%d %d %d\n",temp->cup[0],temp->cup[1],temp->cup[2]);
                    just->next=temp;
                    temp->next=present;
                    just=temp;
                }
            }
        }
        just->next = present->next;
        last = present;
        present = present->next;
        free(last);
    }
    memset(visited,0,sizeof(visited));
}

int main() {
    int answers[100], inps, times=0;
    scanf("%d%d%d",&cup_max[0],&cup_max[1],&cup_max[2]);
    while (cup_max[0]!=0 || cup_max[1]!=0 || cup_max[2]!=0) {
        answers[times]=bfs();
        times++;
        scanf("%d%d%d",&cup_max[0],&cup_max[1],&cup_max[2]);
    }
    for(int i=0;i<times;i++){
        if(answers[i]){
            printf("%d\n",answers[i]);
        }else{
            printf("NO\n");
        }
    }
    getchar();getchar();
}
