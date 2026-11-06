#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> owner(12, -1);//-1 pocetna vrednost elementa od 12 ukupno
    int num_workers = 0;
    omp_set_dynamic(0);

#pragma omp parallel shared(owner, num_workers)//pravljenje paralelnog regiona, deljene promenljive opisane, ne mora ovde
    {
#pragma omp single//definisanje da samo jedna nit izvrsi ovu sekciju, nema potrebe da vise radi jer je deljena promenljiva pa jedna moze da pokupi i to je dovoljno
        num_workers = omp_get_num_threads();//niti u timu

#pragma omp for schedule(runtime)//za taj tim niti raspodeli informaciju, uzimanje iz okruzenja
        for (int i = 0; i < 12; ++i)
        {
            owner[i] = omp_get_thread_num();
        }
    }

    cout << "workers=" << num_workers << '\n';// ispis niti i vektor
    for (int i = 0; i < 12; ++i)
    {
        cout << i << ": " << owner[i] << '\n';
    }
}
