#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#define tamA 2000
#define tamB 200000


float Ttotal;

void manual(int *op){

    //Para forçar a entrada no loop
    *op = 0;
    
    while(*op <= 0 || *op > 11){

        puts("\t\t||MANUAL||\n\n1-> Busca sequencial com vetor B desordenado\n2-> Busca sequencial com vetor B ordenado pelo bubble sort.\n3-> Busca binária com vetor B ordenado pelo bubble sort.");
        puts("4-> Busca ponderada com vetor B ordenado pelo bubble sort.\n5-> Busca sequencial com vetor B ordenado pelo insertion sort.\n6-> Busca binária com vetor B ordenado pelo insertion sort.\n7-> Busca ponderada com vetor B ordenado pelo insertion sort.");
        puts("8-> Busca sequencial com vetor B ordenado pelo selection sort.\n9-> Busca binária com vetor B ordenado pelo selection sort.\n10-> Busca ponderada com vetor B ordenado pelo selection sort.\n11-> Sair\n");
        scanf("%d",op);

    }
}

void result(int *f){

//Função para mostrar a quantidade de elementos encontrados
    printf("Foram encontrados %d elementos de A em B\n",(*f));
    *f = 0;

    return;
}

void ptotal(){ //função para mostrar o tempo total

    printf("Tempo total: %.6f(s) \n",Ttotal); 
    Ttotal = 0;

}

//Função para apresentação do tempo
void tempo(struct timeval begin, struct timeval end,float *total){ //Função para mostrar o tempo de cada


    double seg,ms;

    seg = (end.tv_sec - begin.tv_sec); //tempo em segundos, elementos da struct timeval
    ms = ((end.tv_usec) - (begin.tv_usec));// tempo em milisegundos

    seg += (ms/1000000);// transformando todo o tempo para segundos
    *total += seg; //feita essa associação paa mostrar o tempo total

    printf("%.6f(s)\n",seg);

return;
}

void bubble(int vetB[]){

    //Função para ordenação bubble
    //Aqui é feita uma comparação mais direta

    //Variáveis que auxiliarão na troca e no tempo, respectivamente.
    int aux;
    struct timeval comeco, fim;

    //Inicio da contagem
    gettimeofday(&comeco, NULL);

    for(int i = 0; i < tamB; i++){
        for(int j = 0; j < (tamB-i-1);j++){

            if(vetB[j] > vetB[j+1]){ //identifica se um elemento é maior que o seu sucessor, caso verdadeiro, realiza a troca

                aux = vetB[j];
                vetB[j] = vetB[j+1]; 
                vetB[j+1] = aux;
            
            }
        }
    }
    gettimeofday(&fim, NULL); //Fim da contagem de tempo

    printf("Bubble: ");
    tempo(comeco,fim,&Ttotal);

    return;

}

void insertion(int vetB[]){
    
    //Variáveis para composição do código

    int i;
    int j, num;// var para laço e para troca de posições
    struct timeval comeco, fim;
    

    gettimeofday(&comeco, NULL);

    for(i = 1; i < tamB; i++){
        num = vetB[i]; //este valor será comparado com todos dentro do loop do vetor
        j = i -1;

        //Como realizamos os estudos com base da esquerda pra direita, fazemos a divisão do vetor
        //Dividimos o vetor para que realizemos menos operações e já mantenhamos a ordem, economizando no tempo 

        // inicialmente comparamos o elemento 0 e 1, e ordenamos eles
        // depois vamos para o elemento 0, 1 e 2 e faremos isso até j = tamanho - 1

        while(j >= 0 && vetB[j] > num){

            vetB[j+1] = vetB[j]; //vai deixando o valor maior do que num mais a direita
            j--;

        }

        vetB[j+1] = num;

    }

    gettimeofday(&fim, NULL);
    printf("Insertion: ");
    tempo(comeco,fim,&Ttotal);
return;

}

void selection(int vet[]){
    
    //Selection pegaremos o menor item e colocaremos na primeira posição, ou seja, sempre deixar  o lado da esqeurda com o menor termo
    int i, j,menor;
    int aux;
    struct timeval comeco, fim;

    gettimeofday(&comeco, NULL);

    for(i = 0; i < tamB-1; i++){

        menor = i;
        //j sempre começando com um termo a frente de menor, pois não faz sentido comparar um número com ele mesmo

        for(j = i+1; j < tamB; j++){

            if(vet[j] < vet[menor])
                menor = j; //guarda o  indice do menor elemento de todo o vetor percorrido

        }
        
        aux = vet[menor];
        vet[menor] = vet[i]; //Realização da troca
        vet[i] = aux;

    }

    gettimeofday(&fim, NULL);
    printf("Selection: ");
    tempo(comeco,fim,&Ttotal);

   return;
}

void preencher(int vetA[], int vetB[]){

    int i, seed;

    puts("Qual o valor da semente de geração aleatória (entre 0 e 100000)?");
    scanf("%d",&seed);
    srand(seed);

//Abaixo são relacionados os determinados valores de acordo com a seed desejada e rand
    for(i = 0; i < tamA; i++)
        vetA[i] = rand( )%100000;

    for(i = 0; i < tamB; i++)
        vetB[i] = rand( )%100000;

return;

}

void BS(int vetA[],int vetB[],int *f){

    //Busca sequencial por meio de 2 vetores, correndo o vetorB todo a procura de cada elemento de A

    bool keep;
    struct timeval comeco, fim;
    

    gettimeofday(&comeco, NULL);

    for(int i = 0; i < tamA; i++){

        keep = true; //reinicia keep como true para entrar no laço abaixo
        
        for(int j = 0; j < tamB && keep; j++){ //caminha com B até que encontre um igual à A
        
            if(vetA[i] == vetB[j]){

                (*f)++;
                keep = false;

            }
        }
    }

    gettimeofday(&fim, NULL);
    printf("Busca Sequencial: ");
    tempo(comeco,fim,&Ttotal);


    result(f);

return;

}

void verify(int*p0,int*pf,int*pos,int op, bool *keep,int *f){ // como BB e BI tem muitas semelhanças

    if(op == 1)     //op foi utilizado como parâmetro auxiliar para indetificar quais dos comandos seriam executados
         *p0 = (*pos) +1; 

    else if(op == 2) 
        *pf = (*pos) -1;

    else if(op == 3){

        (*f)++;
        *keep = false;
    }

    else{
        *p0 = 0; *pf = tamB-1;
        *keep = true;
    }

}

void BB(int vetA[],int vetB[],int *f){

    struct timeval comeco, fim;
    int p0,pf;
    bool  keep;
    gettimeofday(&comeco, NULL);

    for(int i = 0; i < tamA; i++){

        verify(&p0,&pf,0,4,&keep,f); //inicializa os valores novamente, para fazer corretamente todos os loops

        if(vetA[i] > vetB[p0] || vetA[i] < vetB[pf-1]){
            while(p0 <= pf && keep){

            int pos = (p0+pf)/2;

            if(vetB[pos] == vetA[i]) //este é o caso que acrescetamos 1 no valor de encontrados
                verify(&p0,&pf,&pos,3,&keep,f);

            else if(vetB[pos] < vetA[i]) //caso isso ocorra, alteramos p0
               verify(&p0,&pf,&pos,1,&keep,f);

            else // caso este ocorra, alteramos pf
                verify(&p0,&pf,&pos,2,&keep,f);

            }
        }
    }

    gettimeofday(&fim, NULL);

    printf("Busca Binária: ");
    tempo(comeco,fim,&Ttotal);

    result(f);

return;
}

void BI(int vetA[],int vetB[],int *f){ //duas funções diferentes mas com lógicas semelhantes, while e pos são as grandes mudanças dentro do código

    //todas as lógicas aplicadas na função verify acima se aplicam aqui

    bool keep = true;
    int p0,pf;
    struct timeval comeco, fim;

    gettimeofday(&comeco, NULL);
    
    for(int i = 0; i < tamA; i++){

         verify(&p0,&pf,0,4,&keep,f);

        while(p0 <= pf && vetA[i] >= vetB[p0] && vetA[i] <= vetB[pf] && keep){

            int pos = p0 + (((double)(pf - p0)/(vetB[pf]-vetB[p0]))*(vetA[i] -vetB[p0])); //cálculo realizado para encontrar a posição por onde começaremos as buscas

            if(vetB[pos] == vetA[i])
                verify(&p0,&pf,&pos,3,&keep,f);
            
            if(vetB[pos] < vetA[i])
                verify(&p0,&pf,&pos,1,&keep,f);
            else
                verify(&p0,&pf,&pos,2,&keep,f);
        }
    }

    gettimeofday(&fim, NULL);

    printf("Busca Ponderada: ");
    tempo(comeco,fim,&Ttotal);

   result(f);

return; 

}

int main(){

    bool keep = true;
    int operador;
    int vetA[tamA], vetB[tamB];
    int found = 0;

    while(keep){

        manual(&operador);

        switch(operador){

            case 1: preencher(vetA,vetB);
                    BS(vetA,vetB,&found);
                    break;

            case 2: preencher(vetA,vetB);
                    bubble(vetB);
                    BS(vetA,vetB,&found);
                    break;

            case 3: preencher(vetA,vetB);
                    bubble(vetB);
                    BB(vetA,vetB,&found);
                    break;
            
            case 4: preencher(vetA,vetB);
                    bubble(vetB);
                    BI(vetA,vetB,&found);
                    break;

            case 5: preencher(vetA,vetB);
                    insertion(vetB);
                    BS(vetA,vetB,&found);
                    break;

            case 6: preencher(vetA,vetB);
                    insertion(vetB);
                    BB(vetA,vetB,&found);
                    break;
            
            case 7: preencher(vetA,vetB);
                    insertion(vetB);
                    BI(vetA,vetB,&found);
                    break;

            case 8: preencher(vetA,vetB);
                    selection(vetB);
                    BS(vetA,vetB,&found);
                    break;

            case 9: preencher(vetA,vetB);
                    selection(vetB);
                    BB(vetA,vetB,&found);
                    break;

            case 10: preencher(vetA,vetB);
                     selection(vetB);
                     BI(vetA,vetB,&found);
                     break;

            case 11: keep = false;
                     break;

            default: break;

        }
        ptotal();

    }
}