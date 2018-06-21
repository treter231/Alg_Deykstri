#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <limits.h>
#include "graph.h"
#include "heap.h"

#define N 20

int d[N];
int prev[N];
int path[N];

void ShortestPathDijkstra (struct graph *g, int src);
int RecoveryPath (struct graph *g, int src, int dst);
void ShortestPathDijkstra (struct graph *g, int  src);
int RecoveryPath (struct graph *g, int  src, int dst);

#endif
