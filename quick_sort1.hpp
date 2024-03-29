#ifndef QUICK_SORT1_HPP
#define QUICK_SORT1_HPP

int numarMijloc(int a, int b, int c) {
    if ((a >= b && a <= c) || (a <= b && a >= c))
        return a;
    else if ((b >= a && b <= c) || (b <= a && b >= c))
        return b;
    else
        return c;
}

int partitie1(int st, int dr, int v[])
{
    int i, pivot = numarMijloc(v[st],v[(st+dr)/2],v[dr]), poz = st;
    for(i = st; i <= dr; i++)
        if(v[i] <= pivot)
        {
           int aux = v[poz];
           v[poz] = v[i];
           v[i] = aux;
           poz++;
        }
    return poz - 1;
}

void qs1(int st,int dr, int v[])
{
    if (st >= dr)
        return;
    int mij = partitie(st, dr, v);
    qs1(st, mij - 1, v);
    qs1(mij + 1, dr, v);
}

#endif

