#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, v[maxn], aux[maxn];

void interclasare(int st, int dr, int mij, int v[], int aux[]) {
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
void merge_sort(int st,int dr)
{
    if (st == dr)
        return;
    int mij = (st + dr) / 2;
    merge_sort(st, mij);
    merge_sort(mij + 1, dr);
    interclasare(st, dr, mij, v, aux);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    merge_sort(1,n);
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    return 0;
}
