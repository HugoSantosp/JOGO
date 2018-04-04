/* JOGO DA VELHA EM C*/
#include <stdio.h>
#include <stdlib.h>

void tabuleiro (char casas2 [3][3]){
    system("cls");
     printf("\t %c | %c | %c \n",casas2[0][0],casas2[0][1],casas2[0][2]);
     printf("\t-----------\n");
     printf("\t %c | %c | %c \n",casas2[1][0],casas2[1][1],casas2[1][2]);
     printf("\t-----------\n");
     printf("\t %c | %c | %c \n",casas2[1][0],casas2[2][1],casas2[2][2]);
     
}

int main() {
    
    char casas[3][3] = {  {'1','2','3'},
                       {'4','5','6'},
                       {'7','8','9'},};
    char res;
    int qdt_jogadas,l,c, vez =0;
    int i,j;
    
    do{
        qdt_jogadas = 1;
        //tabuleiro
        for(i=0;i<=2;j++){
            for(j=0;j<=2;j++){
                casas[i][j] = ' ';
            }
            
        }
             do{
                    tabuleiro(casas);
                    if (vez%2==0){
                        printf("JOgador 1 [usando X] ");
                    }else{
                        printf("JOgador 2 [Usando O] ");
                    }
                    
                    //escolha do usuario
                    printf("Digite as coordenadas da jogada linha");
                    scanf("%d",&l);
                    printf("Agora digite a coluna: ");
                    scanf("%d",&c);
                    
                    //JOGADAS DO USUÁRIO 
                    if (l < 1 || c < 1 || l > 3 || c > 3){
                        l = 0;
                        c = 0;
                        
                    }else if( casas [l-1][c -1] != ' '){
                        l = 0;
                        c = 0;
                    }else{
                        if (vez%2 == 0){
                            casas [l-1] [c-1] = 'X';
                        }else{
                            casas [l-1] [c-1] = 'O';
                        }
                          vez ++;
                          qdt_jogadas++;
                    }
//VITÓRIA DO JOGADOR 'X'-------------------------------------------------------------------------
                    //vitória pelas linhas
                    if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){ qdt_jogadas = 11;};
                    if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){ qdt_jogadas = 11;};
                    if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){ qdt_jogadas = 11;};
                    //vitória pelas colunas
                    if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){ qdt_jogadas = 11;};
                    if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){ qdt_jogadas = 11;};
                    if(casas[0][0] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){ qdt_jogadas = 11;};
                    //vitória pelas diagonais
                    if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){ qdt_jogadas = 11;};
                    if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){ qdt_jogadas = 11;};
  //VITÓRIA DO JOGADOR 'O'------------------------------------------------------------------------------
                     //vitória pelas linhas
                    if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){ qdt_jogadas = 1;};
                    if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){ qdt_jogadas = 1;};
                    if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){qdt_jogadas =1;};
                    //vitória pelas colunas
                    if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){ qdt_jogadas = 1;};
                    if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){ qdt_jogadas = 1;};
                    if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){ qdt_jogadas = 1;};
                    //vitória pelas diagonais
                    if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){ qdt_jogadas = 1;};
                    if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){ qdt_jogadas = 1;};
                    
             }while(qdt_jogadas <= 9);
                tabuleiro(casas);
            //VITÓRIAS
                if (qdt_jogadas == 10){           
                    printf("JOGO EMPATADO!");
               }if(qdt_jogadas == 11){
                   printf("JOGADOR 1 [USANDO 'X'] É O VENCEDOR!!!!");
               }if(qdt_jogadas == 12){
                   printf("JOGADOR 2 [USANDO 'O'] É O VENCEDOR!!!!");
               };
                
        printf("Deseja jogar novamente? [S-N]");
        scanf("%s",&res);
        
    }while(res=='s');
    
    return 0;
}

