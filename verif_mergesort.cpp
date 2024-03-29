#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "shell_sort.hpp"

using namespace std;

bool isSorted(int n, int v[])
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
                                 "test5.txt", "test6.txt", "test7.txt", "test8.txt"
                                };
    ofstream fout("rezultate.out");
    for (int i = 0; i < nr_teste; i++)
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
        fout << "n = " << n << "max = " << maxim <<'\n';
        int v[n + 1];
        for (int i = 1; i <= n; i++)
            fin >> v[i];

        fout<< "Shell Sort: ";
        auto start = chrono::high_resolution_clock::now();
        shellSort(n, v);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        if (!isSorted(n, v))
            fout << "Vectorul nu a fost sortat corect" << '\n';
        else fout << elapsed_seconds.count() << " secunde" << '\n';
    }
    return 0;
}
