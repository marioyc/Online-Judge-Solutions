#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    vector<bool> p(1000000,true);
    
    p[0]=p[1]=false;
    
    for(int i=2;i<1000000;i++)
        if(p[i])
            for(int j=2;j*i<1000000;j++) p[i*j]=false;
    
    vector<int> cont1(1000000);
    vector<int> cont2(1000000);
    
    cont1[0]=cont1[1]=0;
    
    for(int i=2;i<1000000;i++){
        cont1[i]=cont1[i-1];
        if(p[i]) cont1[i]++;
    }
    
    cont2[0]=cont2[1]=0;
    cont2[2]=1;
    
    for(int i=3;i<1000000;i++){
        cont2[i]=cont2[i-1];
        if(p[i] && i%4==1) cont2[i]++;
    }
    
    int L,U;
    
    while(1){
        scanf("%d %d",&L,&U);
        if(L==-1 && U==-1) break;
        
        if(U<1) printf("%d %d 0 0\n",L,U);
        else printf("%d %d %d %d\n",L,U,cont1[U]-cont1[max(0,L-1)],cont2[U]-cont2[max(0,L-1)]);
    }
    
    return 0;
}
