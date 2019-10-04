#include <stdio.h>
#include <string.h>

int main(){

    int n=-1; // 4 <= N <= 250 -> num de cidades (vertices)
    int m=-1; // 3 <= M <= n*(n-1) -> num de estradas (arestas)
    int c=-1; // 2 <= C <= n-1 -> num de cidades na rota de serviço (tamanho do caminho)
    int k=-1; // c <= K <= n-1 -> cidade que veículo foi consertado (vertice)    

    while (!(n == 0 && m == 0 & c == 0 && k == 0)){
        scanf("%d %d %d %d", &n, &m, &c, &k);
        int caminhos[m][3];
        for(int i=0; i < m; i++){
            scanf("%d %d %d", &caminhos[i][0],&caminhos[i][1],&caminhos[i][2]);
        }
    }
}


int* buscarRotas(int** caminhos, int m, int posIni, int posFin, int cidadeAtual){
    for(int i=0; i < m; i++){
        
    }
}