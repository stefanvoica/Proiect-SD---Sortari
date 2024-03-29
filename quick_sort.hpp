#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

int partitie(int st, int dr, int v[])
{
    int i, pivot = v[dr], poz = st;
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

void qs(int st,int dr, int v[])
{
    if (st >= dr)
        return;
    int mij = partitie(st, dr, v);
    qs(st, mij - 1, v);
    qs(mij + 1, dr, v);
}

#endif
