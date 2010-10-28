#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    if(N==0) printf("10\n");
    else if(N==1) printf("1\n");
    else{
        bool valid = true;
        string ans;
        
        while(valid && N!=1){
            valid = false;
            
            for(int i = 9;i>1;--i){
                if(N%i==0){
                    valid = true;
                    ans += (char)('0'+i);
                    N /= i;
                    break;
                }
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        if(!valid) printf("-1\n");
        else printf("%s\n",ans.c_str());
    }
    
    return 0;
}
 
