#include<cstdio>

using namespace std;

int main(){    
    int T,k,cont;
    int n1[]={6,28,220,496,1184,2620,5020,6232,8128,10744,12285,17296,63020,66928,67095,69615,79759};
    int n2[]={6,28,284,496,1210,2924,5564,6368,8128,10856,14595,18416,76084,66992,71145,87633,88730};
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d",&k);
        
        cont=0;
        
        for(int i=0;i<17;i++) if(n1[i]<=k && n2[i]<=k) cont++;
        
        printf("%d\n",cont);
    }
    
    return 0;
}
