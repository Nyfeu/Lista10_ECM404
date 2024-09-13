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