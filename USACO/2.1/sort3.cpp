/*
ID:zion_ba1
LANG:C++
TASK:sort3
*/

#include <cstdio>
#include <algorithm>


using namespace std;

int main(){
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    
    int N; scanf("%d",&N);
    
    int a[N];
    
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    
    int count1=0,count2=0;
    
    for(int i=0;i<N;i++)
        if(a[i]==1) count1++;
        else if(a[i]==2) count2++;
    
    int ans=0;
    
    for(int i=count1,j=0;i<count1+count2;i++){
        if(a[i]==1){
            for(;j<count1;j++)
                if(a[j]==2){
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
        }
    }
    
    for(int i=count1+count2,j=0;i<N;i++){
        if(a[i]==1){
            for(;j<count1;j++)
                if(a[j]==3){
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
        }
    }
    
    
    for(int i=count1+count2,j=count1;i<N;i++){
        if(a[i]==2){
            for(;j<count1+count2;j++)
                if(a[j]==3){
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
        }
    }
    
    for(int i=count1,j=0;i<N;i++){
        if(a[i]==1){
            for(;j<count1;j++)
                if(a[j]!=1){
                    swap(a[i],a[j]);
                    ans++;
                    break;
                }
        }
    }
    
    for(int i=count1+count2;i<N;i++) if(a[i]==2) ans++;
    
    printf("%d\n",ans);
    
    return 0;
}
