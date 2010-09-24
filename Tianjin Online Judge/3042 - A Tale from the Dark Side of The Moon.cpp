#include <iostream>
#include <string>

using namespace std;

int main(){
    bool end=false;
    int L;
    
    while(getline(cin,s)){
        L=s.size();
        for(int i=0;i<L;){
            if(i+2<L && s[i]=='E' && s[i+1]=='O' && s[i+2]=='F'){
                end=true;
                break;
            }
            
            if(!(s[i]>='a' && s[i]<='z') && s[i]!=' '){
                i++;
                continue;
            }
            
            if(s[i]==' '){
                printf(" ");
                i++;
            }else{
                if(i+1<L && s[i]=='d' && s[i+1]=='d'){
                    printf("p");
                    i+=2;
                }else if(i+1<L && s[i]=='e' && s[i+1]=='i'){
                    if(i>0 && s[i-1]=='c') printf("ei");
                    else printf("ie");
                    i+=2;
                }else if(i+3<L && s[i]=='p' && s[i+1]=='i' && s[i+2]=='n' && s[i+3]=='k'){
                    printf("floyd");
                    i+=4;
                }else{
                    printf("%c",s[i]);
                    i++;
                }
            }
        }
        if(end) break;
        printf("\n");
    }
    
    return 0;
}
