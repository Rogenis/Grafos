

// Universidade Federal do Amazonas
// Rógenis Pereira
// Estrutura de Grafo - Reprsentação por Lista de Adjacência. 

#include <stdio.h>
#include <stdlib.h>

  
// Estrutura representado o Node da lista
struct AdjListNode{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
// Estrutura representando a lista de adjacencia
struct AdjList{ 
    struct AdjListNode *head;  
}; 
  
//Estrutura do Grafo
struct Grafo{ 
    int V; 
    struct AdjList* array; 
}; 
  
// Função que cria novo node na lista
struct AdjListNode* newAdjListNode(int dest){ 
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
// FUnção para iniciar o Grafo
struct Grafo* criaGrafo(int V){

    struct Grafo* grafo =  (struct Grafo*) malloc(sizeof(struct Grafo)); 
    grafo->V = V; 
    grafo->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

    int i; 
    for(i = 0; i < V; ++i) 
    	grafo->array[i].head = NULL; 
  
    return grafo; 
} 
  
// Função pra adicionar um arco no Grafo
void insereAresta(struct Grafo* grafo, int src, int dest){ 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = grafo->array[src].head; 
    grafo->array[src].head = newNode;  
    newNode = newAdjListNode(src); 
    newNode->next = grafo->array[dest].head; 
    grafo->array[dest].head = newNode; 
} 
  
// Imprime Grafo
void imprimeGrafo(struct Grafo* grafo){ 
    int v; 
    for(v = 0; v < grafo->V; ++v){ 
        struct AdjListNode* pCrawl = grafo->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while(pCrawl){ 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 
  

int main(){ 
   
    int V = 5; 
    struct Grafo* grafo = criaGrafo(V); 
    insereAresta(grafo, 0, 1); 
    insereAresta(grafo, 0, 4); 
    insereAresta(grafo, 1, 2); 
    insereAresta(grafo, 1, 3); 
    insereAresta(grafo, 1, 4); 
    insereAresta(grafo, 2, 3); 
    insereAresta(grafo, 3, 4); 
   
    imprimeGrafo(grafo); 
  
    return 0; 
} 
