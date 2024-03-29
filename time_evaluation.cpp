#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "shell_sort.hpp"
#include "merge_sort.hpp"
#include "radix_sort.hpp"
#include "quick_sort.hpp"
#include "heap_sort.hpp"
#include "quick_sort1.hpp"

using namespace std;
#define n_max 100000000
int v[n_max + 1], w[n_max + 1];

bool verif_sortare(int n, int v[])
{
    for (int i = 1; i < n; ++i)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}

void copiere (int w[],int v[],int n)
{
    for (int i=1;i<=n;i++)
        v[i]=w[i];
}

int main()
{
    ofstream fout("rezultate.out");
    for (int i = 1 ;i <= 1; i++)
    {
        string filename = "test"+to_string(i)+".txt";
        ifstream fin (filename);
        if (!fin)
        {
            fout << "Nu se poate deschide: " << filename << '\n';
            break;
        }
        fout << "Test " << filename << '\n';

        ///citirea vectorului
        int n, maxim;
        fin >> n >> maxim;
        fout << "n = " << n << " max = " << maxim <<'\n';

        for (int i = 1; i <= n; i++)
        {
            fin >> v[i];
            w[i] = v[i];
        }

        fout<< "Radix Sort baza 10: ";
        auto start = chrono::high_resolution_clock::now();
        radixSort(n, v, 10);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

         copiere(w,v,n);

        fout<< "Radix Sort baza 2^16: ";
        start = chrono::high_resolution_clock::now();
        radixSort(n, v, 1<<16);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';


        copiere(w,v,n);
        fout<< "Merge Sort: ";
        start = chrono::high_resolution_clock::now();
        merge_sort(1, n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';
        copiere(w,v,n);
        fout<< "Shell Sort: ";
        start = chrono::high_resolution_clock::now();
        shellSort(n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

        copiere(w,v,n);
        fout<< "Heap Sort: ";
        start = chrono::high_resolution_clock::now();
        heapSort(n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';
        copiere(w,v,n);
        fout<< "Quick Sort (Alegere 1): ";
        start = chrono::high_resolution_clock::now();
        qs(1, n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';


        copiere(w,v,n);
        fout<< "Quick Sort (Alegere 2): ";
        start = chrono::high_resolution_clock::now();
        qs1(1, n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

        copiere(w,v,n);
        fout<< "STL Sort: ";
        start = chrono::high_resolution_clock::now();
        sort(v + 1, v + n + 1);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

        fout<<'\n';
    }
    return 0;
}

