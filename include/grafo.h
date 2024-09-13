#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#define MAX_VERT 100
#define MAX_VERT_LISTA 100

typedef struct
{
    float Pesos[MAX_VERT][MAX_VERT];
    int nVertices;
    int digrafo;
} Grafo;

typedef struct
{
    int vertices[MAX_VERT_LISTA];
    int nVertices;
} ListaDeVertices;

// Métodos de exibição de grafos e arestas
void ExibirGrafo (Grafo g);
void ExibirArestas (Grafo g);

// Cria um grafo de n vértices.
// Se dig for 1, trata-se de um digrafo. Se for 0, é grafo normal.
void CriarGrafo (Grafo *g, int n, int dig);

// Insere/Remove aresta de um grafo indicando o vértice de origem e de destino.
// Assume-se que NÃO teremos duas arestas que fazem exatamente o mesmo caminho.
void InserirAresta (Grafo *g, int de, int para, float peso);
void RemoverAresta (Grafo *g, int de, int para);

// Retorna o peso da aresta
float PesoDaAresta (Grafo g, int de, int para);

// Retorna grau de entrada/saida de um determinado vértice.
int GrauDeEntrada (Grafo g, int v);
int GrauDeSaida (Grafo g, int v);

// Retorna 1 se o vértice em questão trata-se de um vertedouro/sorvedouro.
// Retorna 0 se o vértice não for vertedouro/sorvedouro.
int Vertedouro (Grafo g, int v);
int Sorvedouro (Grafo g, int v);

// Retorna 1 se o vértice 'para' for adjacente ao vértice 'de'.
int Adjacente (Grafo g, int de, int para);

// Implementação do algoritmo de Warshall
void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT]);

// Retorna 1 se o vértice 'para' for alcançável pelo vértice 'de' 
int Alcanca (Grafo g, int de, int para);

// Retorna o peso total de um passeio definido pela lista de vértices 'p'
float PesoDoPasseio (Grafo g, ListaDeVertices p);

#endif // GRAFO_H_INCLUDED