/*
Refação da avaliação 02
AED1 - 12/06/2024
ALUNA: ALESSANDRA FARIA RODRIGUES
MATRICULA: 828333
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q_01(int m, int n, int a[]){
    int x = 0;
    if(0<m && m<n-1 && a[m-1]-a[m]>0 && a[m]-a[m+1]<0){x = 1;}
    if(0<m && m<n)
    if(x>=0) {x = x + q_01(m-1, n, a);}
    else {x=-m;}
    return (x);
}
//saida = 2


void q_02(char *p, char *q){
    char *r=calloc(strlen(p)*strlen(q)+1, sizeof(char));
    int k = 0;
    for(int x=0; x<strlen(p);x++){
        for(int y=0; y<strlen(q); y++){
            if(x==strlen(p)/2){
                r[k] = p[x]; r[k+1] = q[y]; k = k + 2;
                if(k>6) {y = strlen(q); x = strlen(p); }
            }
        }
    }
    printf("[%s]\n", r);
}
//saida = [bqbubebi]

void q_03(int a, int b, int c, char m[][3][7]){
    for(int x=0; x<a; x++){
        for(int y=0; y<b; y++)
        if('A'<m[x][0][0] && m[x][0][0]<'Z'){
            printf("%8s", m[x][2]); y=b;
        }
        printf("\n");
    }
}
//saida =  Weiss Grun

void q_04(char *p){
    int x = 0;
    for(int y=0; y<strlen(p); y=y+1){
        if(y<strlen(p)-1 && p[y]=='a' || p[y]=='o'){
            for(int z=y; z<strlen(p); z=z+1){
                p[z]=p[z+1];
            }
        }
        printf("[%s]\n", p);
    }
}
//saida = [cstnhlda]

char* q_05(int x, int y, char *p){
    char c = '_';
    if(0<=x && x<strlen(p) && 0<=y && y<strlen(p)){
        c = p[x]; p[x] = p[y]; p[y] = c;
    }
    return (p);
}
//saida = padre perda

int main(void){
    printf("QUESTAO 01: \n");
    int array[] = {7,9,6,8,3,5};
    int n = 6;
    printf("q01 = %d\n", q_01(n-1, n, array));

    printf("\nQUESTAO 02: \n");
    char p[] = "goiabada";
    char q[] = "queijo";
    q_02(p,q);

    printf("\nQUESTAO 03: \n");
    char m[][3][7] = {{{"Azul" }, {"Blue" }, {"Blau" }},
                      {{"Branco" }, {"White" }, {"Weiss" }},
                      {{"Verde" }, {"Green" }, {"Grun" }}};
    q_03(3,3,7,m);

    printf("\nQUESTAO 04: \n");
    char p2[] = "acastanholada";
    q_04(p2);

    printf("\nQUESTAO 05: \n");
    char p3[] = {"perda"};
    char *exemplo1;
    exemplo1 = q_05(1,4,q_05(2,3,p3));
    printf("[%s]\n", exemplo1);
    exemplo1 = q_05(2,3,q_05(1,4,p3));
    printf("[%s]\n", exemplo1);
return 0;
}
