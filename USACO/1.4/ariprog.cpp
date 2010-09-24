/*
ID:zion_ba1
LANG:C++
TASK:ariprog
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    bool bisquare[2*M*M+1];
    vector<int> L;
    int s;
    
    fill(bisquare,bisquare+2*M*M+1,false);
    
    for(int i=0;i<=M;i++)
        for(int j=i;j<=M;j++){
            s=i*i+j*j;
            if(!bisquare[s]) L.push_back(s);
            bisquare[s]=true;
        }
    
    sort(L.begin(),L.end());
    
    int a,b_max=(L.back()-L.front())/(N-1),cont;
    bool found=false;
    
    for(int b=1;b<=b_max;b++){
        for(int i=0;L[i]+b*(N-1)<=L.back();i++){
            a=L[i];
            for(cont=1;cont<N && bisquare[a+b*cont];cont++) ;
            if(cont==N){
                printf("%d %d\n",a,b);
                found=true;
            }
        }
    }
    
    if(!found) printf("NONE\n");
        
    return 0;
}
