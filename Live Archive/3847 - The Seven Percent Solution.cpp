#include<cstdio>

using namespace std;

void print(char &c){
    if(c==' ') printf("%c20",'%');
    else if(c=='!') printf("%c21",'%');
    else if(c=='$') printf("%c24",'%');
    else if(c=='%') printf("%c25",'%');
    else if(c=='(') printf("%c28",'%');
    else if(c==')') printf("%c29",'%');
    else if(c=='*') printf("%c2a",'%');
    else printf("%c",c);
}

int main(){
    char c;
    
    while(1){
        scanf("%c",&c);
        if(c=='#') break;
        
        print(c);
        
        while(1){
            scanf("%c",&c);
            print(c);
            
            if(c=='\n') break;
        }        
    }
    
    return 0;
}
