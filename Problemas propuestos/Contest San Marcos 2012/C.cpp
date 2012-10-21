/*
A Mario le gustan tanto los algoritmos que cada vez que oye una palabra
quiere convertirla en algoritmica, el considera que una palabra es algoritmica,
cuando se puede dividir los caracteres de la palabra en 11 segmentos contiguos
que abarcan toda la palabra, y todos consisten de al menos un caracter,
de manera que:

- El primer segmento consiste solo de caracteres iguales a 'a'
- El segundo segmento consiste solo de caracteres iguales a 'l'
- El tercer segmento consiste solo de caracteres iguales a 'g'
- El cuarto segmento consiste solo de caracteres iguales a 'o'
- El quinto segmento consiste solo de caracteres iguales a 'r'
- El sexto segmento consiste solo de caracteres iguales a 'i'
- El septimo segmento consiste solo de caracteres iguales a 't'
- El octavo segmento consiste solo de caracteres iguales a 'm'
- El noveno segmento consiste solo de caracteres iguales a 'i'
- El decimo segmento consiste solo de caracteres iguales a 'c'
- El onceavo segmento consiste solo de caracteres iguales a 'a'

Para convertir una palabra en algoritmica, Mario debera realizar un cierto numero
de operaciones, cada operacion consiste en cambiar un caracter cualquiera de la
palabra por otro caracter cualquiera.

- L <= 50000
- La palabra consiste solo de caracteres 'a'-'z'

Ejemplo de entrada

4
algoritmica
algalitmica
matematica
aaaaaalllllgoooooooooooollllllllll

Ejemplo de salida

0
2
infinito desprecio!
10
*/

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string alg = "algoritmica";
char s[50001];
int L,memo[11][50000][2];

int solve(int n, int m, int flag){
    if(m == L && n == 10 && flag) return 0;
    if(n == 11 || m == L) return 50000;
    
    int &ret = memo[n][m][flag];
    
    if(ret == -1){
        ret = 50000;
        
        if(flag) ret = min(ret,solve(n + 1,m,0));
        ret = min(ret,(s[m] == alg[n]? 0 : 1) + solve(n,m + 1,1));
    }
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        
        if(L < 11) puts("infinito desprecio!");
        else{
            memset(memo,-1,sizeof memo);
            printf("%d\n",solve(0,0,0));
        }
    }
    
    return 0;
}
