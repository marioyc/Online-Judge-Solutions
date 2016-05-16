#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,n,aux;
    char s[50];

    scanf("%d",&T);

    while(T--){
        scanf("%d %s",&n,s);

        int points = (s[0] == 'I'? 200 : 400);
        int total = 0;

        for(int i = 0;i < n;++i){
            scanf("%s",s);

            if(s[0] == 'C'){
                if(s[8] == 'W'){
                    total += 300;
                    scanf("%d",&aux);
                    total += max(0,20 - aux);
                }else if(s[8] == 'H'){
                    total += 50;
                }
            }else if(s[0] == 'T'){
                total += 300;
            }else if(s[0] == 'B'){
                scanf("%d",&aux);
                total += aux;
            }
        }

        printf("%d\n",total / points);
    }

    return 0;
}
