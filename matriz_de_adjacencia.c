
// Universidade Federal do Amazonas
// Rógenis Pereira
// Estrutura de Grafo - Reprsentação por Matriz de Adjacência 


#include <stdio.h>
#include <stdlib.h>

// Estrutura do grafo 
struct grafo{
   int V; //Vértices
   int A; // Arestas
   int **adj; 
};
typedef struct grafo *Grafo;

// Alocação da Matriz
static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for(int i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for(int i = 0; i < r; ++i)
      for(int j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

// Inicialização do Grafo
Grafo iniciaGrafo(int V){ 
   Grafo G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}

// Função pra inserir arco
void insereGrafo(Grafo G, int v, int w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}

// Função que remove arco do Grafo
void removeGrafo(Grafo G, int v, int w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}

// Função pra imprimir o Grafo
void imprimeGrafo(Grafo G){ 
   for(int v = 0; v < G->V; ++v){
      printf( "%2d:", v);
      for(int w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}


int main(){

	int V = 6;
	Grafo G = iniciaGrafo(V);
	insereGrafo(G,0,1);
	insereGrafo(G,0,5);
	insereGrafo(G,1,0);
	insereGrafo(G,1,5);
	insereGrafo(G,2,4);
	insereGrafo(G,3,1);
	insereGrafo(G,5,3);
	imprimeGrafo(G);
}