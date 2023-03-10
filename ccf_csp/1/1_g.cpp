#include <stdio.h>
int array[1000];
void sort(int len) {
    for (int i = 0; i < len - 1; i++) {
        int m_index = i, temp;
        for (int j = i; j < len; j++) {
            if (array[j] < array[m_index]) {
                m_index = j;
            }
        }
        temp = array[m_index];
        array[m_index] = array[i];
        array[i] = temp;
    }
    for (int i = 0; i < len-1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[len-1]);
}
int main() {
    int times, len;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &array[j]);
        }
        sort(len);
    }
}
