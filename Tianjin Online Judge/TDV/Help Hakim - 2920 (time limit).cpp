#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    long long total;
    
    while(scanf("%d",&N)==1){
        total=N;
        total=total*(N+1)/2*(N+2)/3;
        
        //cout<<total<<endl;
        printf("%lld\n",total);
    }
    
    return 0;
}
