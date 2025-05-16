#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


//QUESTAO 01
int f_01(char p[]){
    int x = 0, y = 0;
    bool r = false, s = false, t = false;
    bool u = false, v = false, w = false;
    for(x = 0; x < strlen(p); x=x+1){
        r = ('a' <= p[x] && p[x] <= 'z');
        s = ('A' <= p[x] && p[x] <= 'Z');
        t = ('0' <= p[x] && p[x] <= '9');
        u = (r||s)&&!w; v = !u && t; w = !v;
        if(u) y=y+1; else if(v) y=y-1;
    }
    return (y);
} //saida = -1

//QUESTAO 02
int f_02(int a, int b){
    if(a%2==0 && b%2==0) return (f_02(a/2,b/2));
    else
        if(a%2!=0 && b%2==0) return (f_02(b%a,b/2));
    else
        if(a%2==0 && b%2!=0) return (f_02(a/2,a%b));
    return ((a-1)%(b-1)/2);
} //saida = 1

//QUESTAO 03
void f_03(){
    for(int x=1; x<=5; x=x+1){
        printf("\nx = %d", 2*x+1);
        printf("\n");
    }
    //int a=1, b=5+3;
    //int a=3, b=5+3;
    int a=3, b=5*3;
    //int a=1, b=5*3;
    for(int x=a; x<=b; x=x+3){
        //int c = 2*x-3;
        //int c = 3*x/2-3;
        int c = (2*x+3)/3;
        //int c = x-x/3;
        printf("\nx = %d", c);
    }
}
//saida do primeiro for = 3 5 7 9 11
//saida opção a = -1 5 11
//saida opção b = 1 6
//saida opção c = 3 5 7 9 11 CORRETA
//saida opção d = 1 3 5 7 9

//QUESTAO 04
void p_04(){
    int x=1, y=1, v=0, w=0, m=2, n=0;
    printf("\nn="); scanf("%d", &n); getchar();
    printf("%d %d ", x, y);
    while(m<n){v=x+y; m=m+1; printf("%d ", v);
        if(m<n-1){w=x+y+v; m=m+1; printf("%d ", w);}
    x=v; y = w;}

}//saida para n = 5: 1 1 2 4 6

//QUESTAO 05
int f_05(char *s){
    int x=0, y=strlen(s)-1;
    while(x<=y && s[x]==s[y]){x=x+1; y=y-1;}
    return (x-y + s[x]-s[y]);
} //saida = 2

int main(void){
    printf("QUESTAO 1\nSaida = ");
    printf("%d", f_01("5aP4+O_8r4nKO"));

    printf("\n\nQUESTAO 2\nSaida = ");
    printf("f_02(30,72) = %d\n", f_02(30,72));

    printf("\n\nQUESTAO 3\n");
    f_03();

    printf("\n\nQUESTAO 4\n");
    p_04();

    printf("\n\nQUESTAO 5\n");
    printf("%d ", f_05("14641"));
return 0;
}
