void countSort(int v[], int N) {
    int M = 0;
    for (int i = 1; i <= N; i++)
        M = std::max(M, v[i]);
    std::vector<int> countArray(M + 1, 0);
    for (int i = 1; i <= N; i++) {
        countArray[v[i]]++;
    }
    for (int i = 2; i <= M; i++) {
        countArray[i] += countArray[i - 1];
    }
    std::vector<int> outputArray(N + 1);
    for (int i = N; i >= 1; i--) {
        outputArray[countArray[v[i]]] = v[i];
        countArray[v[i]]--;
    }
    for (int i = 1; i <= N; i++)
        v[i] = outputArray[i];
}
