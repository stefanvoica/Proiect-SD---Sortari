///Pivotul este pe ultima pozitie
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

int partitie(int st, int dr, int v[])
{
    int i, pivot = v[dr], poz = st;
    for(i = st; i <= dr; i++)
        if(v[i] <= pivot)
        {
            swap(v[poz], v[i]);
            poz++;
        }
    return poz - 1;
}

void qs(int st,int dr, int v[])
{
    if (st >= dr)
        return;
    int mij = partitie(st, dr, v);
    qs(st, mij - 1, v);
    qs(mij + 1, dr, v);
}

void citire(int &n, int v[])
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
}

void afisare(int st, int dr, int v[])
{
    for(int i = st; i <= dr; ++i)
        cout << v[i] << " ";
}

int main()
{
    int n, v[N + 5];
    citire(n, v);
    qs(1, n, v);
    afisare(1, n, v);

    return 0;
}
