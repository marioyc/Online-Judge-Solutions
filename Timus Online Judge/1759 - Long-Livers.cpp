#include <cstdio>

using namespace std;

int days[] = {31,30,31,30,31,30,31,31,30,31,30,31};

int calc(int dd, int mm, int yy){
    int ret = 0;
    
    for(int i = 0;i < yy;++i){
        ret += 365;
        if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) ++ret;
    }
    
    for(int i = 1;i < mm;++i){
        if(i == 2){
            if(yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) ret += 29;
            else ret += 28;
        }else ret += days[i - 1];
    }
    
    ret += dd;
    
    return ret;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    int ans = 0,best = 0,dd,mm,yy;
    
    for(int i = 0;i < n;++i){
        scanf("%d.%d.%d",&dd,&mm,&yy);
        int s = calc(dd,mm,yy);
        
        scanf("%d.%d.%d",&dd,&mm,&yy);
        
        scanf("%d.%d.%d",&dd,&mm,&yy);
        int e = calc(dd,mm,yy);
        
        if(e - s > best){
            best = e - s;
            ans = i;
        }
    }
    
    printf("%d\n",ans + 1);
    
    return 0;
}
