#include <cstdio>
#include <algorithm>

using namespace std;

bool fit(int a[3], int b[3]){
    do{
        if(a[0]<b[0] && a[1]<b[1] && a[2]<b[2]) return true;
        if(a[0]>b[0] && a[1]>b[1] && a[2]>b[2]) return true;
    }while(next_permutation(b,b+3));
    
    return false;
}

int main(){
    int d1,s1,v1,d2,s2,v2;
    
    scanf("%d %d %d %d %d %d",&d1,&s1,&v1,&d2,&s2,&v2);
    
    int a[]={d1,s1,v1};
    int b[]={d2,s2,v2};
    
    sort(b,b+3);
    
    if(fit(a,b)) printf("DA\n");
    else printf("NE\n");
    
    return 0;
}
