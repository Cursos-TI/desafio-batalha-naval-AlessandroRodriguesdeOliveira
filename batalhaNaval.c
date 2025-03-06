#include <stdio.h>

/*Esse programa é construção de um campo de batalha naval com navios na horizontal, vertical e 
diagonal para a direita e para a esquerda, como também áreas de habilidades em forma de cone, cruz e octaedro.
*/


int main(){

    /*Parâmetros:

        -> int tabuleiro[][]: Matriz para o campo de batalha naval.
        -> int navio(algo)[]: Navios.tabuleiro
        -> int coordenadas(algo): Coordenadas de navio os áreas de habilidades.
        

    Retornos:
        Campo de batalha naval com 4 navios: horizontal, vertical, diagonal direita e esquerda. mostrar com 3.
        Áreas de habilidades em forma de: cruz, cone, octaedro(losango). mostrar com 5.
        Verificar se as coordenadas não estrapolam o campo. 
        Se houver navio nas áreas afetadas trocar 3 por 1. 
        Não deixar navios sobrepostos.
        
              
    */

//Criação do tabuleiro/campo (array bidimensional/matriz de 10 por 10 elementos)
    int tabuleiro[10][10];
    
//Criação dos navios (array de 3 elementos)
    int navio1[3] = {3,3,3};

    int navio2[3] = {3,3,3};

    int navio3[3] = {3,3,3};

    int navio4[3]= {3,3,3};

//coordenadas de inserção do primeiro navio, na horizontal
    int coordenadaHX = 1;
    int coordenadaHY = 8;

//coordenadas de inserção do segundo navio, na vertical
    int coordenadaVX = 8;
    int coordenadaVY = 8;

//coordenadas de inserção do segundo navio, na vertical direita
    int coordenadaDX1 = 3;
    int coordenadaDY1 = 10;

//coordenadas de inserção do segundo navio, na vertical esquerda
    int coordenadaDX2 = 3;
    int coordenadaDY2 = 3;

//coordenada para a área de cone
    int coordenadaConeX = 2;
    int coordenadaConeY = 8;

//coordenada para a área de cruz
    int coordenadaCruzX = 8;
    int coordenadaCruzY = 8;

//coordenada para a área de octaedro
    int coordenadaOctaX = 8;
    int coordenadaOctaY = 2;

//Inserir no array do tabuleiro 0s de forma a iniciá-lo
    for(int linhas = 0; linhas < 10; linhas++){
        for (int colunas = 0; colunas < 10;colunas++){
            tabuleiro[linhas][colunas] = 0;
        }
    }


//Cria-se um contador, variáveis para armazenar as coordenadas x e y do navio. O for irá até
//o contador ter número 3, o que indica que foi percorrido o tamanho do navio que é 3.
    for (int contador = 0, x = coordenadaVX, y = coordenadaVY; contador < 3; contador++){
      
//Primeiro verifica-se se não ultrapassou os limites do tabuleiro. Então, se a coordenada em questão for maior que 9
// ou negativa, o que estrapola o tamanho do array, vai avisar isso e  parar.
        if((x+contador-1 > 9 || y-1 < 0) ){
            printf("\nVocê ultrapassou os limites do campo\n\n");
            break;
        }else{

//Se não, vai verificar se não há outro navio posionado entre as coordenadas a seguir.
//Se houver um 3, o que indica um navio, no array tabuleiro, nessas posicões, vai mostrar isso e parar.
            if(tabuleiro[x+contador-1][y-1] == 3){
                printf("\nHá um navio está em (%d, %d). Mude as coordenadas!\n", x+contador, y);
                break;
                
            }else{

//Se não, na última rodada, depois de todas as 3 verificações, se o contador for 2 (último),
//Insere o que estiver no array do navio, no tabuleiro.
                if(contador == 2){

//Esse é um navio na vertical.
                    for (int contador = 0; contador < 3; contador ++){
                        
//O x irá ser incrementado pela soma com o contador e o y estagnado, assim só anda 
//pelo x fazendo ficar na vertical.
                        tabuleiro[x-1+contador][y-1] = navio2[contador];
      
                    }
                    
                }

            }
            
        }          
    }


//Cria-se um contador, variáveis para armazenar as coordenadas x e y do navio. O for irá até
//o contador ter número 3, o que indica que foi percorrido o tamanho do navio que é 3.
    for (int contador = 0, x = coordenadaHX, y = coordenadaHY; contador < 3; contador++){

//Primeiro verifica-se se não ultrapassou os limites do tabuleiro. Então, se a coordenada em questão for maior que 9
// ou negativa, o que estrapola o tamanho do array, vai avisar isso e parar.
        if((y-1+contador > 9 || y-1 < 0) ){
            printf("\nVocê ultrapassou os limites do campo\n\n");
            break;
        }else{

//Se não, vai verificar se não há outro navio posionado entre as coordenadas a seguir.
//Se houver um 3, o que indica um navio, no array tabuleiro, nessas posicões, vai mostrar isso e parar.
            if((tabuleiro[x-1][y+contador-1] == 3)){
                printf("\nHá um navio está em (%d, %d). Mude as coordenadas!\n", x, y+contador);
                break;
            
            }else{

//Se não, na última rodada, depois de todas as 3 verificações, se o contador for 2 (último),
//Insere o que estiver no array do navio, no tabuleiro.
                if(contador == 2){

//Esse navio é na horizontal.
                    for(int contador = 0; contador < 3; contador++){
                        
// O x irá ficar estagnado e o y vai ser incrementado com o contador, o que faz que apenas mova-se 
//pelas colunas o que fica na horizontal.
                        tabuleiro[x-1][y+contador-1] = navio1[contador];
                    }
                    
                }

            }
            
        }          
    }

    
//Cria-se um contador, variáveis para armazenar as coordenadas x e y do navio. O for irá até
//o contador ter número 3, o que indica que foi percorrido o tamanho do navio que é 3.
    for (int contador = 0, x = coordenadaDX1, y = coordenadaDY1; contador < 3; contador++){

//Primeiro verifica-se se não ultrapassou os limites do tabuleiro. Então, se a coordenada em questão for maior que 9
// ou negativa, o que estrapola o tamanho do array, vai avisar isso e parar.
        if((x+contador+1 > 9  || y-contador-1 < 0)){
            printf("\nVocê ultrapassou os limites do campo\n\n");
            break;
        }else{

//Se não, vai verificar se não há outro navio posionado entre as coordenadas a seguir.
//Se houver um 3, o que indica um navio, no array tabuleiro, nessas posicões, vai mostrar isso e parar.
            if((tabuleiro[x+contador-1][y-contador-1] == 3) ){
                printf("\nUm navio está em (%d, %d). Mude as coordenadas!\n", x+contador, y-contador);
                break;
                
            }else{

//Se não, na última rodada, depois de todas as 3 verificações, se o contador for 2 (último),
//Insere o que estiver no array do navio, no tabuleiro.
                if(contador == 2){

//Esse navio é na diagonal direita
                 for(int contador = 0, x = coordenadaDX1, y = coordenadaDY1; contador < 3; contador++, x++, y--){

//O x irá ser incrementado e o y decrementado
                        tabuleiro[x-1][y-1] = navio3[contador];
                    }
                    
                }

            }
            
        }          
    }

    
//Cria-se um contador, variáveis para armazenar as coordenadas x e y do navio. O for irá até
//o contador ter número 3, o que indica que foi percorrido o tamanho do navio que é 3.
    for (int contador = 0,x = coordenadaDX2, y = coordenadaDY2; contador < 3; contador++){

//Primeiro verifica-se se não ultrapassou os limites do tabuleiro. Então, se a coordenada em questão for maior que 9
// ou negativa, o que estrapola o tamanho do array, vai avisar isso e parar.
        if((x-contador-1 < 0 || y-1-contador < 0)){
            printf("\nVocê ultrapassou os limites do campo\n\n");
            break;
        }else{

//Se não, vai verificar se não há outro navio posionado entre as coordenadas a seguir.
//Se houver um 3, o que indica um navio, no array tabuleiro, nessas posicões, vai mostrar isso e parar.
            if((tabuleiro[x-contador-1][y-contador-1] == 3) ){
                printf("\nUm navio está em (%d, %d). Mude as coordenadas!\n", x-contador, y-contador);
                break;
                
            }else{

//Se não, na última rodada, depois de todas as 3 verificações, se o contador for 2 (último),
//Insere o que estiver no array do navio, no tabuleiro.
                if(contador == 2){

//Esse navio é diagonal esquerda
                 for(int contador = 0, x = coordenadaDX2, y = coordenadaDY2; contador < 3; contador++, x--, y--){

//O x irá ser decrementado e o y decrementado
                        tabuleiro[x-1][y-1] = navio4[contador];
                    }
                    
                }

            }
            
        }          
    }


 //cone
//A variável linhas controlará o for em três vezes, a colunaaux irá fazer com que diminua a coluna em 1 sempre que mudar de linha,
//assim fomando a forma de pirâmide, a variável menos irá somar com 2 quando a linha mudar com o próposito de aumentar o loop
//das colunas. 
    for(int linhas = 0, colunaaux = 0, menos = 1, x = coordenadaConeX, y = coordenadaConeY; linhas < 3; linhas++, colunaaux-=1, menos+=2){

//Aqui sempre o loop irá mudar quando mudar as linhas, será 2 colunas a mais
        for (int colunas = 0; colunas < menos; colunas++)
        {
//Aqui verifica se não tem algum navio, se tiver troca o 3 por 1, se não põe 5
            if (tabuleiro[x-1+linhas][y-1+colunas+colunaaux] == 3)
            {
                tabuleiro[x-1+linhas][y-1+colunas+colunaaux] = 1;
            }else{
                tabuleiro[x-1+linhas][y-1+colunas+colunaaux] = 5;
            }
        }
    }


//cruz
//A variável linhas controlará o for em três vezes, a linhaaux irá fazer com que controle por onde começar, no caso pelo meio,
//assim fomando uma cruz, a variável menos irá ser 2 ou 0 dependendo da linha, a colunaaux irá controla o loop das colunas e a quanttidade.
    for (int linhas = 0, linhaaux = 0, menos = 0, x = coordenadaCruzX, y = coordenadaCruzY, colunaaux = 1; linhas < 3; linhas++)
    {

//Se for a primeira linha a linhaaux muda para 1, começando na linha posterior.
        if (linhas == 0)
        {
            linhaaux = 1;
        }else{

//Quando for a segunda, ela faz voltar para a primeira.
            if (linhas == 1)
            {
                linhaaux = 0;
//E na última vai para trás uma casa da origem que é o centro da cruz fazendo a outra ponta.
            }else{
                
                linhaaux = -1;
            }
        }
        
//Quando for a segunda linha a colunaaux aumenta 4 e o menos 2 para aumentar o loop das colunas abaixo
//para fazer o corpo da cruz, quando sair do segundo loop volta para uma coluna e o x aumenta mais 1
//para fazer a ponta.
        if (linhas == 1)
        {
            colunaaux += 4;
            menos += 2;
            
        }else{
            colunaaux = 1;
            menos+= 0;
            
        }
        
        
        for(int colunas = 0; colunas < colunaaux;colunas++){
            if (linhas == 2)
            {
                colunas = 2;
            }
//Aqui verifica se não tem algum navio, se tiver troca o 3 por 1, se não põe 5
            if (tabuleiro[x-1+linhaaux][y-1+colunas-menos] == 3)
            {
                tabuleiro[x-1+linhaaux][y-1+colunas-menos] = 1;
            }else{
                tabuleiro[x-1+linhaaux][y-1+colunas-menos] = 5;
            } 
        }
    }


//octaedro
//A variável linhas controlará o for em três vezes, a linhaaux irá controlar por onde começa, no caso no meio, igual a cruz,
//a variável menos irá somar com 1 quando a linha mudar com o próposito de aumenta ou diminuir as colunas. A colunaaux irá controlar 
 //o loop das colunas. 
    for (int linhas = 0, linhaaux = 0, menos = 0, x = coordenadaOctaX, y = coordenadaOctaY, colunaaux = 1; linhas < 3; linhas++)
    {

//Se for a primeira linha a linhaaux muda para 1, começando na linha posterior.
        if (linhas == 0)
        {
            linhaaux = 1;
        }else{
//Quando for a segunda, ela faz voltar para a primeira.
            if (linhas == 1)
            {
                linhaaux = 0;
            }else{
//E na última vai para trás uma casa da origem que é o centro da cruz fazendo a outra ponta
                linhaaux = -1;
            }
        }

//Quando for a segunda linha a colunaaux aumenta 2 ou diminui para 1 e o menos 1 ou diminui para 0, para aumentar o loop das colunas abaixo
//para fazer o corpo da mini cruz(octaedro), quando sair do segundo loop volta a ordem normal ou para trás para fazer as pontas.
        
        if (linhas == 1)
        {
            colunaaux += 2;
            menos += 1;
        }else{
            colunaaux = 1;
            menos+= 0;
            
        }
        
        
        for(int colunas = 0; colunas < colunaaux;colunas++){
            if (linhas == 2)
            {
                colunas = 1;
            }

//Aqui verifica se não tem algum navio, se tiver troca o 3 por 1, se não põe 5
            if (tabuleiro[x-1+linhaaux][y-1+colunas-menos] == 3)
            {
                tabuleiro[x-1+linhaaux][y-1+colunas-menos] = 1;
            }else{
                tabuleiro[x-1+linhaaux][y-1+colunas-menos] = 5;
            }    
        }
    }


//Imprimir as referências.
    printf("ÁGUA (0)\n");
    printf("NAVIOS (3)\n");
    printf("ÁREAS AFETADAS PELAS HABILIDADES (5)\n");
    printf("NAVIOS EM ÁREAS AFETADAS PELAS HABILIDADES (1)\n\n");


//Imprimir cabeçalho, os números de cima.
    for (int colunas = 0; colunas < 10; colunas++){
        if (colunas == 0){
            printf("   %d ",colunas+1);
        }else{
            if (colunas == 9){
                printf("%d\n",colunas+1);
                
            }else{
                printf("%d ",colunas+1);
            }
        }
    }


    //Inserir campos de 0 junto com os números da lateral.
    for(int linhas = 0; linhas < 10; linhas++){
        linhas < 9 ? printf(" %d", linhas+1): printf("%d", linhas+1);

        for (int colunas = 0; colunas < 10;colunas++){
            printf(" %d", tabuleiro[linhas][colunas]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;

}
