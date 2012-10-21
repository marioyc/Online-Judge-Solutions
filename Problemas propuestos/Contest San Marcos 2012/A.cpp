/*
A pepe le gusta mucho jugar con los parentesis. Un día pepe
habia armado una parentizacion regular, y decidio darse
un descanso.

Cuando regreso su hermano habia tomado algunos de sus parentesis,
ahora pepe tiene que volver a armar su parentizacion, pero como
sigue cansado te pide que tu lo hagas.

Deberas reemplezar todos los ? por ( ó ) para obtener una parentizacion
valida. Es mas pepe te dice que si existen varias parentizaciones deberas
darle la menor posible lexicograficamente, considerando que ( < ).

L <= 1000

Ejemplo de entrada

3
(?
?)
??

Ejemplo de salida

()
()
()

*/

#include <cstdio>
#include <cstring>

using namespace std;

int L;
char s[1001];
bool memo[1000][1001];
bool done[1000][1001];
char choose[1000][1001];

bool solve(int pos, int diff){
    if(diff < 0) return false;
    
    if(pos == L){
        if(diff == 0) return true;
        return false;
    }
    
    bool &ret = memo[pos][diff];
    
    if(!done[pos][diff]){
        done[pos][diff] = true;
        ret = false;
        
        if(s[pos] == '(') ret = ret || solve(pos + 1,diff + 1);
        
        if(s[pos] == ')') ret = ret || solve(pos + 1,diff - 1);
        
        if(s[pos] == '?'){
            if(solve(pos + 1,diff + 1)){
                choose[pos][diff] = '(';
                ret = true;
            }else if(solve(pos + 1,diff - 1)){
                choose[pos][diff] = ')';
                ret = true;
            }
        }
    }
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        
        L = strlen(s);
        
        memset(done,false,sizeof done);
        
        bool can = solve(0,0);
        
        if(!can) puts("NO");
        else{
            for(int i = 0,diff = 0;i < L;++i){
                if(s[i] == '?'){
                    putchar(choose[i][diff]);
                    
                    if(choose[i][diff] == '(') ++diff;
                    else --diff;
                }else{
                    putchar(s[i]);
                    
                    if(s[i] == '(') ++diff;
                    else --diff;
                }
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
