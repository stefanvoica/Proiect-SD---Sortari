#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP


void heapify(int v[], int n, int i)
{
    int largest = i, l = 2 * i, r = 2 * i + 1;
    if (l <= n && v[l] > v[largest])
        largest = l;
    if (r <= n && v[r] > v[largest])
        largest = r;
    if (largest != i)
    {
        //interschimba (v[i], v[largest]);
        int aux = v[i];
        v[i] = v[largest];
        v[largest] = aux;
        heapify(v, n, largest);
    }
}

void heapSort(int n, int v[])
{
    for (int i = n / 2; i >= 1; i--)
        heapify(v, n, i);
    for (int i = n; i >= 1; i--)
    {
        //interschimba(v[1], v[i]);
        int aux = v[1];
        v[1] = v[i];
        v[i] = aux;
        heapify(v, i - 1, 1);
    }
}

#endif

