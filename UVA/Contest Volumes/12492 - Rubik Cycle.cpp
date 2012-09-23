#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int M[54],aux[54];
int M2[21],M3[21];

void rotate(){
    int pos = 0;
    
    M3[pos++] = M2[6]; M3[pos++] = M2[3]; M3[pos++] = M2[0];
    M3[pos++] = M2[7]; M3[pos++] = M2[4]; M3[pos++] = M2[1];
    M3[pos++] = M2[8]; M3[pos++] = M2[5]; M3[pos++] = M2[2];
    M3[pos++] = M2[18]; M3[pos++] = M2[19]; M3[pos++] = M2[20];
    M3[pos++] = M2[9]; M3[pos++] = M2[10]; M3[pos++] = M2[11];
    M3[pos++] = M2[12]; M3[pos++] = M2[13]; M3[pos++] = M2[14];
    M3[pos++] = M2[15]; M3[pos++] = M2[16]; M3[pos++] = M2[17];
}

void move(){
    for(int i = 0;i < 54;++i)
        aux[i] = M[i];
    
    for(int i = 0;i < 21;++i)
        M[ M2[i] ] = aux[ M3[i] ];
}

void moveF(int rep){
    for(int it = 0;it < rep;++it){
        int pos = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j){
                M2[pos] = 9 + pos;
                ++pos;
            }
        
        M2[pos++] = 6; M2[pos++] = 7; M2[pos++] = 8;
        M2[pos++] = 36; M2[pos++] = 39; M2[pos++] = 42;
        M2[pos++] = 20; M2[pos++] = 19; M2[pos++] = 18;
        M2[pos++] = 53; M2[pos++] = 50; M2[pos++] = 47;
        
        rotate();
        move();
    }
}

void moveB(int rep){
    for(int it = 0;it < rep;++it){
        int pos = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j){
                    M2[pos] = 27 + pos;
                    ++pos;
                }
        
        M2[pos++] = 24; M2[pos++] = 25; M2[pos++] = 26;
        M2[pos++] = 44; M2[pos++] = 41; M2[pos++] = 38;
        M2[pos++] = 2; M2[pos++] = 1; M2[pos++] = 0;
        M2[pos++] = 45; M2[pos++] = 48; M2[pos++] = 51;
        
        rotate();
        move();
    }
}

void moveU(int rep){
    for(int it = 0;it < rep;++it){
        int pos = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j){
                M2[pos] = pos;
                ++pos;
            }
        
        M2[pos++] = 33; M2[pos++] = 34; M2[pos++] = 35;
        M2[pos++] = 38; M2[pos++] = 37; M2[pos++] = 36;
        M2[pos++] = 11; M2[pos++] = 10; M2[pos++] = 9;
        M2[pos++] = 47; M2[pos++] = 46; M2[pos++] = 45;
        
        rotate();
        move();
    }
}

void moveD(int rep){
    for(int it = 0;it < rep;++it){
        int pos = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j){
                M2[pos] = 18 + pos;
                ++pos;
            }
        
        M2[pos++] = 15; M2[pos++] = 16; M2[pos++] = 17;
        M2[pos++] = 42; M2[pos++] = 43; M2[pos++] = 44;
        M2[pos++] = 29; M2[pos++] = 28; M2[pos++] = 27;
        M2[pos++] = 51; M2[pos++] = 52; M2[pos++] = 53;
        
        rotate();
        move();
    }
}

void moveL(int rep){
    for(int it = 0;it < rep;++it){
        int pos = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j){
                M2[pos] = 45 + pos;
                ++pos;
            }
        
        M2[pos++] = 0; M2[pos++] = 3; M2[pos++] = 6;
        M2[pos++] = 9; M2[pos++] = 12; M2[pos++] = 15;
        M2[pos++] = 18; M2[pos++] = 21; M2[pos++] = 24;
        M2[pos++] = 27; M2[pos++] = 30; M2[pos++] = 33;
        
        rotate();
        move();
    }
}

void moveR(int rep){
    for(int it = 0;it < rep;++it){
        int pos = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j){
                M2[pos] = 36 + pos;
                ++pos;
            }
        
        M2[pos++] = 8; M2[pos++] = 5; M2[pos++] = 2;
        M2[pos++] = 35; M2[pos++] = 32; M2[pos++] = 29;
        M2[pos++] = 26; M2[pos++] = 23; M2[pos++] = 20;
        M2[pos++] = 17; M2[pos++] = 14; M2[pos++] = 11;
        
        rotate();
        move();
    }
}

int lcm(int a, int b){
    return a / __gcd(a,b) * b;
}

int main(){
    char s[81];
    int L;
    
    while(scanf("%s",s) == 1){
        for(int i = 0;i < 54;++i) M[i] = i;
        
        L = strlen(s);
        
        for(int i = 0;i < L;++i){
            if(s[i] == 'F') moveF(1);
            else if(s[i] == 'f') moveF(3);
            else if(s[i] == 'B') moveB(1);
            else if(s[i] == 'b') moveB(3);
            else if(s[i] == 'U') moveU(1);
            else if(s[i] == 'u') moveU(3);
            else if(s[i] == 'D') moveD(1);
            else if(s[i] == 'd') moveD(3);
            else if(s[i] == 'L') moveL(1);
            else if(s[i] == 'l') moveL(3);
            else if(s[i] == 'R') moveR(1);
            else moveR(3);
        }
        
        int ans = 1;
        
        for(int i = 0;i < 54;++i){
            int pos = i,cont = 0;
            
            do{
                pos = M[pos];
                ++cont;
            }while(pos != i);
            
            ans = lcm(ans,cont);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
