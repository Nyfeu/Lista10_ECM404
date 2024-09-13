#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

void ExibirArestas (Grafo g)
{
    int i, j, a;
    printf("\nPeso da Aresta:\n");
    a = 65;
    for (i=0; i<g.nVertices; i++)
        for (j=0; j<g.nVertices; j++)
            if (PesoDaAresta(g, i, j) != 0)
                printf("Aresta %c%i,%i%c: w(%c)=%.1f\n",
                       g.digrafo==0?'{':'(',
                       i, j,
                       g.digrafo==0?'}':')',
                       a++,
                       PesoDaAresta(g, i, j)
                      );
    printf ("\n");
}

void ExibirGrafo (Grafo g)
{
    int i, j;
    // Troque por CLS se estiver usando Windows
    system("clear");
    printf ("Numero de vertices do %s: %i\n", g.digrafo==0?"GRAFO":"DIGRAFO",g.nVertices);
    for (i=0; i <g.nVertices; i++)
    {
        for (j=0; j < g.nVertices; j++)
            printf ("%0.1f   ", PesoDaAresta (g, i, j));
        printf ("\n");
    }
    printf ("\n");
}

void CriarGrafo (Grafo *g, int n, int dig)
{
    int i, j;
    g->nVertices = n;
    g->digrafo = dig;
    for (i=0; i < g->nVertices; i++)
        for (j=0; j < g->nVertices; j++)
            g->Pesos[i][j] = 0;
}


void InserirAresta (Grafo *g, int de, int para, float peso)
{
    g->Pesos[de][para] = peso;
    if (!g->digrafo)
        g->Pesos[para][de] = peso;
}


void RemoverAresta (Grafo *g, int de, int para)
{
    g->Pesos[de][para] = 0;
    if (!g->digrafo)
        g->Pesos[para][de] = 0;
}


float PesoDaAresta (Grafo g, int de, int para)
{
    return g.Pesos[de][para];
}

int GrauDeEntrada (Grafo g, int v)
{

    if (v < 0 || v > g.nVertices) {
        printf("O vértice não pôde ser encontrado!\n");
        exit(1);
    }

    int grau = 0;
    for (int i = 0; i < g.nVertices; i++) {
        if (g.Pesos[i][v]) grau++;
    }

    return grau;

}

int GrauDeSaida (Grafo g, int v)
{

    if (v < 0 || v > g.nVertices) {
        printf("O vértice não pôde ser encontrado!\n");
        exit(1);
    }

    int grau = 0;
    for (int i = 0; i < g.nVertices; i++) {
        if (g.Pesos[v][i]) grau++;
    }

    return grau;

}

int Vertedouro (Grafo g, int v) {

    return GrauDeEntrada(g, v) == 0;

}

int Sorvedouro (Grafo g, int v) {

    return GrauDeSaida(g, v) == 0;

}

int Adjacente (Grafo g, int de, int para) {

    return (g.Pesos[para][de] != 0);

}

void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT]) {

    for (int i = 0; i < g.nVertices; i++) {
        for (int j = 0; j < g.nVertices; j++) {
            w[i][j] = PesoDaAresta(g, i, j) != 0;
        }
    }

    for (int i = 0; i < g.nVertices; i++) {
        for (int j = 0; j < g.nVertices; j++) {
            for (int k = 0; k < g.nVertices; k++) {
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
            }
        }
    }

}

int Alcanca (Grafo g, int de, int para) {

    int w[MAX_VERT][MAX_VERT];
    Warshall(g, w);

    return w[de][para] != 0;

}

float PesoDoPasseio (Grafo g, ListaDeVertices p) {

    float peso = 0;

    for (int i = 0; i < p.nVertices - 1; i++) {
        peso += g.Pesos[p.vertices[i]][p.vertices[i+1]];
    }

}