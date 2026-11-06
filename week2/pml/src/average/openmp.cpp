#include "kernels.hpp"
#include <omp.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int moving_average_openmp(const Samples& x, const vector<int>& widths, Samples& y)
{
	int m = y.size();
	int num_workers = 1;	
	#pragma omp parallel
	
	#pragma omp_single
		num_workers = omp_get_num_threads();
	
	#pragma omp for schedule(runtime)//za menjanje tokom poziva i da 
		for (int i = 0; i < m; ++i)
		{
			double sum = 0;
			for (int j = 0; j < widths[i]; ++j)
			{
				sum += x[i + j];
			}
			y[i] = sum / widths[i];
		}
	return num_workers;
}
