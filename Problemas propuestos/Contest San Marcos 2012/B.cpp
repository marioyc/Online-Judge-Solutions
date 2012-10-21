/*
A pepe le gusta el alpinismo, ayer fue de paseo a las montañas, y hoy
pensaba contarle a sus amigos sobre su recorrido, en cada paso de su
recorrido (en total dio L pasos) pepe subió o bajó un metro,
además empezó en una altura 0, y nunca bajó de esta, 
y finalmente volvío a la altura 0.

Lo malo es que pepe no tiene muy buena memoria y solo cree recordar los ultimos
K pasos de su recorrido. Dados estos ultimos K pasos, ayuda a pepe a hallar
un camino valido que pueda contar a sus amigos. Si existen varios imprime
el menor lexicografico, sino imprime "Que mala memoria pepe!"

L <= 100000
K <= L

Ejemplo de entrada

3
4
)
5
()
6
()

Ejemplo de salida

(())
Que mala memoria pepe!
(())()

*/

#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

char s[100001];

int main(){
    int T,L,Ltotal;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %s",&Ltotal,s);
        
        L = strlen(s);
        assert(L <= Ltotal);
        
        int delta = 0;
        
        for(int i = 0;i < L;++i){
            if(s[i] == '(') ++delta;
            else --delta;
        }
        
        delta = -delta;
        
        if(delta < 0 || delta > Ltotal - L) puts("Que mala memoria pepe!");
        else{
            // a : parentesis (
            // b : parentesis )
            // a+b = Ltotal - L
            // a-b = delta
            
            if((Ltotal - L + delta) % 2 != 0) puts("Que mala memoria pepe!");
            else{
                bool ok = true;
                
                for(int i = 0,aux = delta;i < L;++i){
                    if(s[i] == '(') ++aux;
                    else --aux;
                    
                    if(aux < 0) ok = false;
                }
                
                if(!ok) puts("Que mala memoria pepe!");
                else{
                    int a = (Ltotal - L + delta) / 2;
                    int b = Ltotal - L - a;
                    
                    for(int i = 0;i < a;++i) putchar('(');
                    for(int i = 0;i < b;++i) putchar(')');
                    puts(s);
                }
            }
        }
    }
    
    return 0;
}
