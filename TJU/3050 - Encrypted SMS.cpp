#include<cstdio>

using namespace std;

int cont;
char x,pos;

char decode(char start, char &c, int L){
    pos=c-start;
    pos=((pos-cont)%L+L)%L;
    c=start+pos;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    char c;
    
    while(1){
        scanf("%c",&c);
        if(c=='#') break;
        
        cont=0;
        
        do{
            cont++;
            
            if(c>='A' && c<='C') decode('A',c,3);
            else if(c>='a' && c<='c') decode('a',c,3);
            else if(c>='D' && c<='F') decode('D',c,3);
            else if(c>='d' && c<='f') decode('d',c,3);
            else if(c>='G' && c<='I') decode('G',c,3);
            else if(c>='g' && c<='i') decode('g',c,3);
            else if(c>='J' && c<='L') decode('J',c,3);
            else if(c>='j' && c<='l') decode('j',c,3);
            else if(c>='M' && c<='O') decode('M',c,3);
            else if(c>='m' && c<='o') decode('m',c,3);
            else if(c>='P' && c<='S') decode('P',c,4);
            else if(c>='p' && c<='s') decode('p',c,4);
            else if(c>='T' && c<='V') decode('T',c,3);
            else if(c>='t' && c<='v') decode('t',c,3);
            else if(c>='W' && c<='Z') decode('W',c,4);
            else decode('w',c,4);
            
            printf("%c",c);
            
            scanf("%c",&c);
        }while(c!='\n');
        
        printf("\n");
    }
    
    return 0;
}
