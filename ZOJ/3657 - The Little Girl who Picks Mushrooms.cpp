#include <cstdio>
#include <algorithm>

using namespace std;

int a[5];

int solve4(){
    int ret = 0,total = a[0] + a[1] + a[2] + a[3];
    
    for(int i = 0;i < 2;++i)
        for(int j = i + 1;j < 3;++j)
            for(int k = j + 1;k < 4;++k)
                if((a[i] + a[j] + a[k]) % 1024 == 0)
                    return 1024;
    
    for(int i = 0;i < 3;++i){
        for(int j = i + 1;j < 4;++j){
            int sum = total - a[i] - a[j];
            
            if(sum > 0){
                sum %= 1024;
                if(sum == 0) sum = 1024;
                ret = max(ret,sum);
            }
        }
    }
    
    return ret;
}

int solve5(){
    int ret = 0,total = a[0] + a[1] + a[2] + a[3] + a[4];
    
    for(int i = 0;i < 3;++i){
        for(int j = i + 1;j < 4;++j){
            for(int k = j + 1;k < 5;++k){
                int sum = a[i] + a[j] + a[k];
                
                if(sum % 1024 == 0){
                    sum = total - sum;
                    
                    if(sum > 0){
                        sum %= 1024;
                        if(sum == 0) sum = 1024;
                        ret = max(ret,sum);
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    int n;
    
    while(scanf("%d",&n) == 1){
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        
        if(n <= 3) printf("1024\n");
        else if(n == 4) printf("%d\n",solve4());
        else printf("%d\n",solve5());
    }
    
    return 0;
}
