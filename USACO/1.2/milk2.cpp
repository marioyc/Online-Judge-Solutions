/*
ID: zion_ba1
LANG: C++
TASK: milk2
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    
    int N;
    scanf("%d",&N);
    
    int S[N],E[N];
    for(int i=0;i<N;i++) scanf("%d %d",&S[i],&E[i]);
    
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            if(S[i]>S[j] || (S[i]==S[j] && E[i]>E[j])){
                swap(S[i],S[j]);
                swap(E[i],E[j]);
            }
    
    int s=S[0],e=E[0];
    int t1=E[0]-S[0],t2=0;
    
    for(int i=1;i<N;i++){
        if(S[i]<=e){
            if(E[i]>e){
                e=E[i];
                t1=max(t1,e-s);
            }
        }else{
            t2=max(t2,S[i]-e);
            s=S[i];
            e=E[i];
        }
    }
    
    printf("%d %d\n",t1,t2);
    
    return 0;
}
