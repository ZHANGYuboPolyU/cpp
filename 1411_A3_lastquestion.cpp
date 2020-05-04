#include<iostream>
#include<chrono>
using namespace std;
int main() {
  int sum = 0;
  int N;
  int A[101]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101};
  int j=3,k=6;
  int countj=0,countk=0;

  N=300;
  auto start = std::chrono::steady_clock::now();
  if(N<3)
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
      sum+=A[i/3+1
      ];
  }
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>(end-start);
  cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  cout<<sum<<endl;
}