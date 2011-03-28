#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string pyr[6];

void print_pyr(){
    for(int i = 0;i < 6;++i)
        puts(pyr[i].c_str());
}

void rot(char &a, char &b, char &c){
    swap(a,b);
    swap(a,c);
}

void rotA(){
    rot(pyr[0][5],pyr[0][16],pyr[0][27]);
    rot(pyr[1][3],pyr[1][14],pyr[1][25]);
    rot(pyr[1][5],pyr[1][16],pyr[1][27]);
    rot(pyr[1][7],pyr[1][18],pyr[1][29]);
}

void rotB(){
    rot(pyr[2][9],pyr[3][12],pyr[2][12]);
    rot(pyr[1][7],pyr[4][14],pyr[2][16]);
    rot(pyr[2][7],pyr[3][14],pyr[2][14]);
    rot(pyr[2][5],pyr[3][16],pyr[1][14]);
}

void rotC(){
    rot(pyr[2][20],pyr[3][20],pyr[2][23]);
    rot(pyr[1][18],pyr[3][16],pyr[2][27]);
    rot(pyr[2][18],pyr[3][18],pyr[2][25]);
    rot(pyr[2][16],pyr[4][18],pyr[1][25]);
}

void rotD(){
    rot(pyr[2][1],pyr[2][31],pyr[5][16]);
    rot(pyr[1][3],pyr[2][27],pyr[4][14]);
    rot(pyr[2][3],pyr[2][29],pyr[4][16]);
    rot(pyr[2][5],pyr[1][29],pyr[4][18]);
}

int main(){
    char start[6],s[4];
    bool first = true;
    
    while(scanf("%s",start) == 1){
        pyr[0] = "    /R\\        /G\\        /B\\";
        pyr[1] = "  /R\\R/R\\    /G\\G/G\\    /B\\B/B\\";
        pyr[2] = "/R\\R/R\\R/R\\/G\\G/G\\G/G\\/B\\B/B\\B/B\\";
        pyr[3] = "           \\Y/Y\\Y/Y\\Y/";
        pyr[4] = "             \\Y/Y\\Y/";
        pyr[5] = "               \\Y/";
        
        if(!first) puts("");
        first = false;
        
        while(true){
            scanf("%s",s);
            
            if(s[0] == 'E') break;
            else if(s[0] == 'A'){
                rotA();
                if(s[1] == '+') rotA();
            }else if(s[0] == 'B'){
                rotB();
                if(s[1] == '+') rotB();
            }else if(s[0] == 'C'){
                rotC();
                if(s[1] == '+') rotC();
            }else{
                rotD();
                if(s[1] == '+') rotD();
            }
        }
        
        print_pyr();
    }
    
    return 0;
}
