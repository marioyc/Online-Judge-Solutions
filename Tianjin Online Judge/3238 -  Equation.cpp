#include <cstdio>
#include <algorithm>

using namespace std;

int sq[1001];
int cont1[3000001];
int cont2[3000001];

void solve(int &r){
    if(cont2[r]!=-1) return;
    
    cont2[r]=0;
    
    for(int i=0;i<=1000 && sq[i]<=r;i++) cont2[r]+=cont1[r-sq[i]];
}

int main(){
    for(int i=0;i<=1000;i++) sq[i]=i*i;
    
    int r;
    
    fill(cont1,cont1+3000001,0);
    
    for(int i=0;i<=1000;i++)
        for(int j=i;j<=1000;j++){
                r=sq[i]+sq[j];
                if(i==j) cont1[r]+=1;
                else cont1[r]+=2;
            }
    
    fill(cont2,cont2+3000001,-1);
    
    int T;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&r);
        
        solve(r);
        printf("%d\n",cont2[r]);
    }
    
    return 0;
}
