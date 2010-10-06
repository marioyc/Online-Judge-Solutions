#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std;
 
const int MAXV1 = 200;
const int MAXV2 = 200;
 
class PythTriplets
{
public:  
  vector<int> L[MAXV1];
  bool visited[MAXV2];
  int V1,V2,match[MAXV2];
  
  bool dfs(int u){
       for(int i=L[u].size()-1;i>=0;--i){
            int v = L[u][i];
            
            if(!visited[v]){
                  visited[v] = true;
                  if(match[v]==-1 || dfs(match[v])){
                        match[v] = u;
                        return true;
                  }
            }
       }
       return false;
  }
  
  int maximum_matching(){
       int ans = 0;
       memset(match,-1,sizeof(match));
       
       for(int i=0;i<V1;++i){
            memset(visited,false,sizeof(visited));
            ans += dfs(i);
       }
       
       return ans;
  }
  
  int findMax(vector <string> stick)
  {
    string s;
    for(int i=0;i<stick.size();++i) s += stick[i];
    
    int aux;
    vector<int> values;
    istringstream is(s);
    
    while(is>>aux) values.push_back(aux);
    
    V1 = V2 = 0; //even, odd
    vector<long long> A,B;
    
    for(int i=0;i<values.size();++i){
      if(values[i]%2==0){
        A.push_back(values[i]);
        ++V1;
      }else{
        B.push_back(values[i]);
        ++V2;
      }
    }
    
    for(int i=0;i<V1;++i){
      for(int j=0;j<V2;++j){
        long long c2 = A[i]*A[i]+B[j]*B[j];
        long long c = (long long)sqrt(c2);
        if(A[i]*A[i]+B[j]*B[j]==c*c && __gcd(A[i],B[j])==1) L[i].push_back(j);
      }
    }
    
    return maximum_matching();
  }
};
