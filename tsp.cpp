#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
#include<string>
using namespace std;
using namespace std::chrono;

string extractNumber(std::string line, int wordNumber)
{
    std::string tempString;
    int currentWordNumber=0;
    for(size_t i=0;i<line.length();i++)
    {
        if(line[i]==' ' || i==line.length()-1)
        {
            if(i==line.length()-1) tempString+=line[i];
            currentWordNumber++;
            if (wordNumber==currentWordNumber)
            {
                return tempString;
            }
            tempString="";
        }
        else
        {
            tempString+=line[i];
        }
    }
    return "";
}



int FindNearest(const vector<int>& city,vector<bool>& marked){
int min1=0,ind;
for(int i=1;i<city.size();i++){
    if(!marked[i]){
      if(min1==0){
        min1=city[i];
        ind=i;
      }
      if(min1>city[i]){
        min1=city[i];
        ind=i;
      }

    }
}

marked[ind]=1;
return ind;

}



int NearestNeighbourHelper(const vector<vector<int> >& graph, const int start){

vector<bool> marked;
marked.resize(graph.size());
marked[start]=1;
int curr=start;
int sum=0;
int old;
for(int i=2;i<graph.size();i++){
    old=curr;
    curr=FindNearest(graph[old],marked);
    sum+= graph[old][curr];

 }
sum+=graph[curr][start];
return sum;
}

int NearestNeighbour(const vector<vector<int> >& graph){
 return  NearestNeighbourHelper(graph,1);



}


int RepetitiveNearestNeighbour(const vector<vector<int> >& graph){
    int minroad=NearestNeighbourHelper(graph,1);
    for(int i=2;i<graph.size();i++) if(minroad> NearestNeighbourHelper(graph,i)) minroad= NearestNeighbourHelper(graph,i);
    return minroad;


}

int main(){
ifstream file;
file.open ("tsp.txt");
ofstream fout;
fout.open("results.txt");
string line;
int k;
while (getline(file, line))
{
    string strNum=extractNumber (line, 1);
     k= stoi(strNum);
              break;
}

for(int y=0;y<k;y++){
        cout<<"Example "<<y+1<<":"<<endl;
        fout<<"Example "<<y+1<<":"<<endl;
        int n;
        while (getline(file, line))
        {
                string nNum=extractNumber(line, 1);
                n=stoi(nNum);
                break;
        }
        cout<<n<<"cities"<<endl;
        fout<<n<<"cities"<<endl;
vector<vector<int> > a;
a.resize(n+1);
for(int i=1;i<=n;i++) a[i].resize(n+1);
for(int i=1;i<=n;i++) a[i][i]=0;
for(int i=1;i<n;i++){

        while(getline(file, line))
        {

    for(int j=i+1;j<=n;j++){
        string num=extractNumber(line, j-i);
        int number=stoi(num);
        a[i][j]=number;
        //cin>>a[i][j];
        a[j][i]=a[i][j];
    }
    break;
}
}
auto start = high_resolution_clock::now();
cout<<"NearestNeighbour:"<<NearestNeighbour(a)<<"   ";
fout<<"NearestNeighbour:"<<NearestNeighbour(a)<<"   ";
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout <<"Time:"<< duration.count()<< endl;
fout <<"Time:"<< duration.count()<< endl;
auto start1 = high_resolution_clock::now();
cout<<"RepetitiveNearestNeighbour:"<<RepetitiveNearestNeighbour(a)<<"   ";
fout<<"RepetitiveNearestNeighbour:"<<RepetitiveNearestNeighbour(a)<<"   ";
auto stop1 = high_resolution_clock::now();
auto duration1 = duration_cast<microseconds>(stop1 - start1);
cout <<"Time:"<< duration1.count() << endl;
fout <<"Time:"<< duration1.count() << endl;
}
file.close();
fout.close();

return 0;
}
