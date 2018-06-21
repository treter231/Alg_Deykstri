/*	Задание 3
	Алгоритм Дейкстры

Постановка задачи
	Реализовать алгоритм Дейкстры поиска кратчайшего пути от заданной вершины до
	всех остальных. Для хранения длин кратчайших путей (массив d[i]) следует использовать
	бинарную кучу (min-heap). Для хранения графа использовать матрицу смежности.

Экспериментальное исследование
	Сформировать связный граф из 20 вершин и найти в нем кратчайший путь от вершины
	1 до всех остальных. Граф и найденные кратчайшие пути включить в отчет.
	На экран вывести путь и его длину.
http://graphonline.ru/
*/

#include <ctype.h>
#include <math.h>
#include "dijkstra.h"

int Read(char *IFILE, int *mas);

int main() {
	int Mas[400] = {0};
	int i, j, n, len;
	n = Read("mygraph.txt", Mas);
	i = (int)sqrt(n);
	if (i * i != n) {
		printf("Incorrect graph\n");
		exit(2);
	} else {
		n = i;
		for (i = 0; i < n; ++i) {
			if (n < i) {
				break;
			}
			if (Mas[i * n + i] != 0) {
				printf("There are nodes!\n");
				exit(3);
			}
		}
	}
	struct graph *g;
	g = graph_create (N);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (0 < Mas[i * n + j]) {
				graph_set_edge(g, (i + 1), (j + 1), Mas[i * n + j]);
			}
		}
	}
	ShortestPathDijkstra(g, 1);

	for (i = 1; i <= N; i++) {
		len = RecoveryPath (g, 1, i);
		printf("Shortest way = ");
		for (j = 1; j < len; j++) {
			printf("%d -> ", path[j] - 1);
		}
		printf("%d\n", path[j] - 1);
		printf("Long: %d\n\n", d[j]);
	}
	return 0;
}

int Read(char *IFILE, int *mas) {
	char word[100]= {' '};
	int CountWord = 0, CountSpace = 0;
	FILE* f;
	if((f = fopen(IFILE, "r")) == NULL) {
		perror("fopen");
		exit(1);
	}
	register int inWord = 0;
	int c;
	int WLen = 0;
	while((c = getc(f)) != EOF) {
		if(isspace(c) || c == '\n') {
			inWord = 0;
			CountSpace++;
			if (WLen) {
				word[WLen] = '\0';
				mas[CountWord - 1] = atoi(word);
			}
			WLen = 0;
		} else {
			word[WLen] = c;
			WLen++;
			if(inWord == 0) {
				inWord = 1;
				CountWord++;
			}
		}
	}
	return CountWord;
}
