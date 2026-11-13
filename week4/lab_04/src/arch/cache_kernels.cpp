#include "cache_kernels.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Sum sum_rows(const Matrix& a, int n)
{
	Sum sum = 0;
	for(int i=0;i<n;++i)
	 for(int j=0;j<n;++j)
	  sum += a[i*n+j];
	  
	  return sum;
}

Sum sum_columns(const Matrix& a, int n)
{
	Sum sum = 0;
	for(int j=0;j<n;++j)
	 for(int i=0;i<n;++i)
	  sum += a[i*n+j];
	  
	  return sum;
}
