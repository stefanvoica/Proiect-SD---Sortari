#ifndef RADIX_SORT_HPP
#define RADIX_SORT_HP


int getMaxValue(int n,int v[]) {
    int maxVal = v[1];
    for (int i = 2; i <= n; i++)
        if (v[i] > maxVal)
            maxVal = v[i];
    return maxVal;
}

void countingSort(int n, int ex, const int baza, int v[]) {
    int output[n+1];
    int i, numara[baza] = {0};
    for (i = 1; i <= n; i++)
        numara[(v[i] / ex) % baza]++;
    for (i = 1; i < baza; i++)
        numara[i] += numara[i - 1];
    for (i = n; i >= 1; i--)
        output[numara[(v[i] / ex) % baza]--] = v[i];
    for (i = 1; i <= n; i++)
        v[i] = output[i];
}

void radixSort(int n, int v[], const int baza) {
    int maxVal = getMaxValue(n,v);
    for (int ex = 1; maxVal / ex > 0; ex *= baza)
        countingSort(n, ex, baza, v);
}


#endif
