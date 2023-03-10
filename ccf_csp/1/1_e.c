#include <math.h>
#include <stdio.h>

int array[100];

void sort(int len) {
    for (int i = 0; i < len - 1; i++) {
        int m_index = i, temp;
        for (int j = i; j < len; j++) {
            if (array[j] > array[m_index]) {
                m_index = j;
            }
        }
        temp = array[m_index];
        array[m_index] = array[i];
        array[i] = temp;
    }
}

int main() {
    double ans;
    int times;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &array[i]);
    }
    sort(times);
    ans = array[0];
    for (int i = 1; i < times; i++) {
        ans = 2 * sqrt(ans * array[i]);
    }
    printf("%.3f", ans);
}
