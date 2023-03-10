#include <stdio.h>
#include <string.h>

int array[100000];

int main() {
    int from, to, total, set;
    scanf("%d", &total);
    while (total != 0) {
        memset(array, 0, sizeof(array));
        set = 0;
        for (int i = 0; i < total; i++) {
            scanf("%d%d", &from, &to);
            array[from]++;
            array[to + 1]--;
        }
        for (int i = 1; i < total; i++) {
            set += array[i];
            printf("%d ", set);
        }
        printf("%d\n", set + array[total]);
        scanf("%d", &total);
    }
}
