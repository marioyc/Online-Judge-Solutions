#include <cstdio>

using namespace std;

int val[27];

int to_num(char s[]){
    int cont1 = 0,cont2 = 0;
    
    for(int i = 0;i < 7;++i){
        if(s[i] >= 'A' && s[i] <= 'Z') ++cont1;
        else break;
    }
    
    for(int i = 6;i >= 0;--i){
        if(s[i] >= '0' && s[i] <= '9') ++cont2;
        else break;
    }
    
    int ret = 0;
    
    if(cont1 == 3 && cont2 == 4){
        for(int i = 0;i < 3;++i)
            ret = ret * 26 + s[i] - 'A';
        for(int i = 3;i < 7;++i)
            ret = ret * 10 + s[i] - '0';
        return ret;
    }else if(cont1 == 5 && cont2 == 2){
        for(int i = 0;i < 5;++i){
            if(val[ s[i] - 'A' ] == -1) return -1;
            ret = ret * 21 + val[ s[i] - 'A' ];
        }
        for(int i = 5;i < 7;++i)
            ret = ret * 10 + s[i] - '0';
        return 26 * 26 * 26 * 10000 + ret;
    }
    
    return -1;
}

int main(){
    val[0] = 0;
    int pos = 1;
    
    for(char c = 'A';c <= 'Z';++c){
        val[pos] = val[pos - 1];
        if(c != 'A' && c != 'C' && c != 'M' && c != 'I' && c != 'P')
            ++val[pos];
        ++pos;
    }
    
    val['A' - 'A'] = -1;
    val['C' - 'A'] = -1;
    val['M' - 'A'] = -1;
    val['I' - 'A'] = -1;
    val['P' - 'A'] = -1;
    
    char s1[8],s2[8];
    int C;
    
    while(true){
        scanf("%s %s %d",s1,s2,&C);
        if(C == 0) break;
        
        int x = to_num(s1),y = to_num(s2);
        
        if(y == -1 || y > x + C || y <= x) puts("N");
        else puts("Y");
    }
    
    return 0;
}
