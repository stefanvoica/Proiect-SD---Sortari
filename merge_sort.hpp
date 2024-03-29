#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HP

void interclasare(int st, int dr, int mij, int v[]) {
    int aux[dr-st+2];
    int i = st, j = mij + 1, nr = 0;
    while (i<=mij && j<=dr) {
        if (v[i]<v[j]) {
            aux[++nr]=v[i], i++;
        }
        else    aux[++nr]=v[j], j++;
    }
    for (;i<=mij;i++)
        aux[++nr]=v[i];
    for (;j<=dr;j++)
        aux[++nr]=v[j];
    for (i=st;i<=dr;i++)
        v[i]=aux[i-st+1];
}
void merge_sort(int st,int dr,int v[])
{
    if (st == dr)
        return;
    int mij = (st + dr) / 2;
    merge_sort(st, mij,v);
    merge_sort(mij + 1, dr, v);
    interclasare(st, dr, mij, v);
}

#endif
