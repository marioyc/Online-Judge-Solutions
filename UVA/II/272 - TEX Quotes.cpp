#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    char c;
    bool ax=1;

    while(scanf("%c",&c)!=EOF){
        if(c=='"'){
            if(ax) printf("``");
            else printf("''");
            
            ax=(!ax);
        }else printf("%c",c);
    }

    return 0;
}
