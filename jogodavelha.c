/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int acaboujogo(int m[3][3]){
    for(int i = 0; i < 3; i++){
        if(m[i][0] != 0 && m[i][0] == m[i][1] && m[i][0] == m[i][2]){
            return m[i][0];
        }
    }
    for(int i= 0; i < 3; i++){
        if(m[0][i] != 0 && m[0][i] == m[1][i] && m[0][i] == m[2][i]){
            return m[0][i];
        }
    }
    if(m[0][0] != 0 && m[0][0] == m[1][1] && m[0][0] == m[2][2]){
        return m[0][0];
    }
    if(m[0][2] != 0 && m[0][2] == m[1][1] && m[0][2] == m[2][0]){
        return m[0][2];
    }
    return 0;
}

void printcerto(int m[3][3], int i, int j){
    if(m[i][j] == 0){
        printf(" ");
    }
    if(m[i][j] == 1){
        printf("x");
    }
    if(m[i][j] == 2){
        printf("o");
    }
}

void printjogodavelha(int m[3][3]){
    for(int i = 0; i < 3; i++){
        printcerto(m,i,0);
        printf("|");
        printcerto(m,i,1);
        printf("|");
        printcerto(m,i,2);
        printf("\n");
        if(i != 2){
            printf("-----\n");
        }
    }
}

int main(){
    printf("Hello World\n");
    int turno = 1;
    int m[3][3];
    int aux;
    int count = 0;
    
    for(int i= 0; i < 3; i++){
        for(int j= 0; j < 3; j++){
            m[i][j] = 0;
        }
    }

    
    while(count < 9){
        printjogodavelha(m);
        while(1){
            printf("Digite a posição que você quer jogar!");
            if(turno == 1){
                printf("Você é X\n");
            }
            else{
                printf("Você é O\n");
            }
            printf("0|1|2\n3|4|5\n6|7|8\n");
            scanf("%d", &aux); 
            if(m[aux/3][aux%3] == 0){
                break;
            }
        }
        
        m[aux/3][aux%3] = turno;
        if(turno == 1){
            turno = 2;
        }
        else{
            turno = 1;
        }
        count++;
        if(acaboujogo(m) == 1){
            printf("X ganhou");
            break;
        }
        if(acaboujogo(m) == 2){
            printf("O ganhou");
            break;
        }
        
        
    }
    
    if(count == 9){
        printf("Deu velha!\n");
    }

    
    return 0;
}
