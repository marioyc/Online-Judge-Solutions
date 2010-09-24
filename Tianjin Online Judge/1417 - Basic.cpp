#include <cstdio>
#include <cstring>

using namespace std;

bool isdigit(const char c){
    return (c>='0' && c<='9');
}

bool valid_char(const char c){
    return (isdigit(c) || (c>='a' && c<='f'));
}

int value(const char c){
    if(isdigit(c)) return c-'0';
    return c-'a'+10;
}

int main(){
    int n,L,L2,pos,base;
    scanf("%d",&n);
    
    char s[81],s2[81];
    bool decimal,valid;
    
    for(int tc=1;tc<=n;tc++){
        scanf("%s",s);
        L=strlen(s);
        
        decimal=true;
        for(int i=0;i<L;i++) if(!isdigit(s[i])) decimal=false;
        
        if(decimal) printf("yes\n");
        else{
            valid=false;
            
            for(int i=0;i<L;i++){
                if(s[i]=='#'){
                    valid=true;
                    pos=i;
                    break;
                }
            }
            
            if(!valid){
                printf("no\n");
                continue;
            }
            
            if(pos==0) valid=false;
            else if(pos==1){
                if(!isdigit(s[0]) || s[0]=='0' || s[0]=='1') valid=false;
                else base=s[0]-'0';
            }else if(pos==2){
                if((!isdigit(s[0]) && !isdigit(s[1])) || ((s[0]-'0')*10+s[1]-'0'<2) || ((s[0]-'0')*10+s[1]-'0'>16)) valid=false;
                else base=(s[0]-'0')*10+s[1]-'0';
            }else{
                for(int i=0;i<pos-2;i++) if(s[i]!='0') valid=false;
                
                if((s[pos-2]-'0')*10+s[pos-1]-'0'<2) valid=false;
            }
            
            if(!valid || pos==L-1 || !valid_char(s[pos+1])){
                printf("no\n");
                continue;
            }
            
            pos++;
            
            while(1){
                L2=0;
                
                while(1){
                    if(s[pos]=='#') break;
                    
                    if(pos==L){
                        valid=false;
                        break;
                    }
                    
                    if(!valid_char(s[pos]) || value(s[pos])>=base){
                        valid=false;
                        break;
                    }
                    if(L2!=0 || (L2==0 && s[pos]!='0')) s2[L2++]=s[pos];
                    
                    pos++;
                }
                
                if(!valid || pos==L-1) break;
                else{
                    if(pos+2>=L-1 || s[pos+1]!='#' || !valid_char(s[pos+2])){
                        valid=false;
                        break;
                    }
                    
                    pos+=2;
                    
                    if(L2>5) valid=false;
                    else{
                        int base2=0;
                        
                        for(int i=0;i<L2;i++){
                            base2=base2*base+value(s2[i]);
                            if(base2>16){
                                valid=false;
                                break;
                            }
                        }
                        
                        base=base2;
                    }
                    
                    if(base>16){
                        valid=false;
                        break;
                    }
                }
            }
            
            if(!valid) printf("no\n");
            else printf("yes\n");
        }
    }
    
    return 0;
}
