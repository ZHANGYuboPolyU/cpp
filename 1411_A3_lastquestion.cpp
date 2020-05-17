#include<iostream>
#include<chrono>
using namespace std;
void test(int *A,int N) {
  if(N>3)
  {
    for(int i=0;i<N;i++)
    {
      sum+=A[i/3];
      if(i/3>0)
      {
        sum+=A[j/3];
        j++;
        countj++;
      }
      if(i/3>1)
      {
        sum+=A[k/3];
        k++;
        countk++;
      }
    }
    for(countj;countj<N;countj++)
    {
      sum+=A[j/3];
      sum+=A[k/3];
      j++;
      k++;
      countk++;
    }
    for(countk;countk<N;countk++)
    {
      sum+=A[k/3];
      k++;
    }
  }

  else
  {
    for(int i=0;i<N;i++)
      sum+=A[i/3];
    for(int i=0;i<N;i++)
      sum+=A[i/3+2];
    for(int i=0;i<N;i++)
      sum+=A[i/3+1];
  }
}
