#include <cstdio>
#include <string>

using namespace std;

int main(){
    char X[4][5],X2[4][5],M[4][5];
    string s;
    
    for(int i = 0;i < 4;++i)
        scanf("%s",X[i]);
    
    for(int i = 0;i < 4;++i)
        scanf("%s",M[i]);
    
    for(int it = 0;it < 4;++it){
        for(int i = 0;i < 4;++i)
            for(int j = 0;j < 4;++j)
                if(X[i][j] == 'X')
                    s += M[i][j];
        
        for(int i = 0;i < 4;++i)
            for(int j = 0;j < 4;++j)
                X2[j][3-i] = X[i][j];
        
        for(int i = 0;i < 4;++i)
            for(int j = 0;j < 4;++j)
                X[i][j] = X2[i][j];
    }
    
    printf("%s\n",s.c_str());
    
    return 0;
}
