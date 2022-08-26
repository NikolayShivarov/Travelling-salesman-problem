#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int main ()
{
  int n, t, c;
  ofstream fout;
  fout.open("tsp.txt",ios::app);

  cout << "Enter the number of cities" << endl;
  cin >> n;
  fout<<n;
  fout<<endl;

  for(int i=n-1;i>0;i--){
  for (c = 1; c <= i; c++)
  {
    t=0;
    while((t%100)==0) t = rand();
    fout << t%100 <<" ";
  }
  fout<<endl;
  }
  fout.close();
  return 0;
}
