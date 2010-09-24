#include<iostream>
#include<string>

using namespace std;

int main(){    
    int min,max,m;
    string s;
    
    while(1){
        min=0;
        max=11;
        
        scanf("%d\n",&m);
        
        if(m==0) break;
        
        getline(cin,s);
        
        if(s[0]=='r'){
            printf("Stan may be honest\n");
            continue;
        }else{
            switch(s[4]){
                case 'l':
                    min>?=m;
                    break;
                case 'h':
                    max<?=m;
                    break;
            }
        }
        
        while(1){
            scanf("%d\n",&m);
            getline(cin,s);
            
            if(s[0]=='r') break;
            else{
                switch(s[4]){
                    case 'l':
                        min>?=m;
                        break;
                    case 'h':
                        max<?=m;
                        break;
                }
            }
        }
        
        if(m>min && m<max) printf("Stan may be honest\n");
        else printf("Stan is dishonest\n");
    }
    
    return 0;
}
