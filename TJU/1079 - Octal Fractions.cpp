#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char num[1003];
    int ans[3001],temp[3001];
    
    while(scanf("%s",num)==1){
        printf("%s [8] = ",num);
        
        memset(ans,0,sizeof(ans));
        int d = strlen(num);
        
        for(int i = d-1,j = 0;i>=2;--i,j += 3){
            ans[0] = num[i]-'0';
            memset(temp,0,sizeof(temp));
            
            for(int k = j;k>=0;--k){
                int aux = ans[k]*125;
                
                for(int x = 3;x>=0;--x){
                    temp[k+x] += aux%10;
                    aux /= 10;
                    if(x>0) temp[k+x-1] += temp[k+x]/10;
                    temp[k+x] %= 10;
                }
            }
            
            for(int k = 0;k<=j+3;++k)
                ans[k] = temp[k];
        }
        
        printf("0.");
        
        d = (d-2)*3;
        while(d>1 && ans[d]==0) --d;
        for(int i = 1;i<=d;++i) putchar('0'+ans[i]);
        
        puts(" [10]");
    }
    
    return 0;
}
