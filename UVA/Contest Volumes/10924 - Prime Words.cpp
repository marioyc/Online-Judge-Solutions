#include <cstdio>
#include <cstring>

using namespace std;

bool is_prime(int n){
    if(n <= 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n/ i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

int main(){
    char s[21];
    
    while(scanf("%s",s) == 1){
        int L = strlen(s),n = 0;
        
        for(int i = 0;i < L;++i)
            n += s[i] >= 'a' && s[i] <= 'z'? s[i] - 'a' + 1 : s[i] - 'A' + 27;
        
        puts(is_prime(n)? "It is a prime word." : "It is not a prime word.");
    }
    
    return 0;
}
