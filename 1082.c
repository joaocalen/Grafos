#include <stdio.h>
#include <stdlib.h>
// ANOTACOES FUNCOES
typedef struct vertice Vertice;
typedef struct aresta Aresta;
typedef struct grafo Grafo;
Grafo* inicializa_grafo();
Vertice* inicializa_vertice(char,Grafo*);
Aresta* inicializa_aresta(Vertice*,Vertice*,Grafo*);
void adiciona_conexao(Aresta* a, Vertice* v);
void adiciona_aresta_grafo(Grafo* g, Aresta* a);
void adiciona_vertice_grafo(Grafo* g, Vertice* v);
void imprimir_grafo(Grafo* g);
void verificar_conexos(Grafo* g);
Grafo* componente_conexa(Grafo* g);
void libera_grafo(Grafo* g);

struct grafo
{
    Vertice* vertices[26];
    Aresta* arestas[650];
};

struct vertice
{
    int verificado;
    char identificador;
    Aresta* conexoes[25];
};

struct aresta
{
    int tamanho;
    Vertice* v1;
    Vertice* v2;
};

/*
###################### ROTINA PRINCIPAL ######################
*/

int main(){
    Grafo* grafo = inicializa_grafo();   

    int n;
    scanf("%d\n",&n);
    Grafo* grafos[n];
    int num_vertices, num_arestas;
    char v1,v2;
    for (int i =0; i < n; i++){
        grafos[i] = inicializa_grafo();
        scanf("%d %d\n",&num_vertices, &num_arestas);
       
        for(int k=0; k < num_vertices; k++){
            inicializa_vertice(k+97,grafos[i]);
        }
       
        for(int j=0; j < num_arestas; j++){
            if(j == num_arestas - 1 && i == n -1){
            scanf("%c %c",&v1,&v2);
            }else{
            scanf("%c %c\n",&v1,&v2);
            }
            inicializa_aresta(grafos[i]->vertices[v1-97],grafos[i]->vertices[v2-97],grafos[i]);
        }
    }
    for(int i=0; i<n; i++){
        imprimir_grafo(grafos[i]);
    }

}

/*
################# BIBLIOTECAS ##################
*/

Grafo* inicializa_grafo(){
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));    
    for (int i = 0; i < 26; i++)
    {
        g->vertices[i] == NULL;
    }
    for (int i = 0; i < 650; i++)
    {
        g->arestas[i] == NULL;
    }
    
    return g;
}

Vertice* inicializa_vertice(char identificador, Grafo* g){
    Vertice* v = (Vertice*) malloc(sizeof(Vertice));
    v -> identificador = identificador;
    v-> verificado = 0;
    adiciona_vertice_grafo(g,v);
    return v;
}

Aresta* inicializa_aresta(Vertice* v1, Vertice* v2, Grafo* g){
    Aresta* a = (Aresta*) malloc(sizeof(Aresta));
    a-> v1 = v1;
    a-> v2 = v2;
    a-> tamanho = 1;
    adiciona_conexao(a,v1);
    adiciona_conexao(a,v2);
    adiciona_aresta_grafo(g,a);
    return a;
}

void adiciona_conexao(Aresta* a, Vertice* v){
    for(int i = 0; i < 25; i++){
        if(v->conexoes[i] == NULL){
            v->conexoes[i] = a;
            return;
        }
    }
}

void adiciona_aresta_grafo(Grafo* g, Aresta* a){
    for(int i = 0; i < 650; i++){
        if(g->arestas[i] == NULL){
            g->arestas[i] = a;
            return;
        }
    }
}

void adiciona_vertice_grafo(Grafo* g, Vertice* v){
    if(g==NULL) return;

    for(int i = 0; i < 26; i++){
        if(g->vertices[i] == NULL){
            g->vertices[i] = v;
            return;
        }
    }
}

void imprimir_grafo(Grafo* g){
    printf("\n VERTICES \n");
    for (int i = 0; i < 26; i++)
    {
        if (g->vertices[i])
        {
            printf("Vertice %d: %c \n",i,g->vertices[i]->identificador);
        }else{
            break;
        }
        
    }
    printf ("\n ARESTAS \n");
    for (int i = 0; i < 650; i++)
    {
        if (g->arestas[i])
        {
            printf("Aresta %d: %c <-> %c \n",i, g->arestas[i]->v1->identificador, g->arestas[i]->v2->identificador);
        }else
        {
            break;
        }       
        
    }
    
}

void verificar_conexos(Grafo* g){
Grafo* subgrafo = inicializa_grafo();
subgrafo = componente_conexa(g, g-> vertices[0],subgrafo);
int cont = 0;
while (subgrafo != NULL)
{
    for(int i =0; i < 26; i++){
        
    }
    free(subgrafo);
    subgrafo = inicializa_grafo();
    Vertice* vaux;
    for(int i =0; i < 26; i++){
        if(g->vertices[i]->verificado = 0){            
            vaux = g->vertices[i];
        }
    }
    subgrafo = componente_conexa(g,vaux);
}


}

Grafo* componente_conexa(Grafo* g, Vertice* v,Grafo* subgrafo){    
    v->verificado = 1;
    adiciona_vertice_grafo(subgrafo,v);
    for(int i = 0; i < 25; i++){
        if(v->conexoes[i] != NULL){
            if (! v->conexoes[i] ->v1 ->verificado)
            {
                componente_conexa(g,v->conexoes[i]->v1);
            }else if (! v->conexoes[i] ->v2 ->verificado){
                componente_conexa(g,v->conexoes[i]->v2);
            }
        }else{
            break;
        }
    }
    return subgrafo;
}

void libera_grafo(Grafo* g){

}