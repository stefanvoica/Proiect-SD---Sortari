#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

void shellSort(int n, int v[]) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i <= n; ++i) {
            int temp = v[i], j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}


#endif

