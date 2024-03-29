#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "shell_sort.hpp"
#include "merge_sort.hpp"
#include "radix_sort.hpp"
#include "heap_sort.hpp"

using namespace std;

bool verif_sortare(int n, int v[])
{
    for (int i = 1; i < n; ++i)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}

int main()
{
    const int nr_teste = 8;
    const string test_names[] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt",
                                 "test5.txt", "test6.txt", "test7.txt", "test8.txt"};
    ofstream fout("rezultate.out");
    for (int i = 5 ;i <= 8; i++)
    {
        string filename = test_names[i];
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
        int v[n + 1];
        for (int i = 1; i <= n; i++)
            fin >> v[i];

        fout<< "Radix Sort baza 10: ";
        auto start = chrono::high_resolution_clock::now();
        radixSort(n, v, 10);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

        fout<< "Merge Sort: ";
        start = chrono::high_resolution_clock::now();
        merge_sort(1, n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

        fout<< "Shell Sort: ";
        start = chrono::high_resolution_clock::now();
        shellSort(n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';


        fout<< "Heap Sort: ";
        start = chrono::high_resolution_clock::now();
        heapSort(n, v);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';

        fout<< "STL Sort: ";
        start = chrono::high_resolution_clock::now();
        sort(v + 1, v + n + 1);
        end = chrono::high_resolution_clock::now();
        elapsed_seconds = end - start;

        if (!verif_sortare(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';
    }
    return 0;
}

