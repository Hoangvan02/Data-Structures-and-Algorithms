#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* create_node(int v);

struct Graph {
  int numVertices;
  int* traversed;
  struct node** adjLists;
};

void DFS(struct Graph* graph, int data) {
  struct node* adjList = graph->adjLists[data];
  struct node* temp = adjList;

  graph->traversed[data] = 1;
  printf("%d đã được duyệt \n", data);

  while (temp != NULL) {
    int connecteddata = temp->data;

    if (graph->traversed[connecteddata] == 0) {
      DFS(graph, connecteddata);
    }
    temp = temp->next;
  }
}

struct node* create_node(int v) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->data = v;
  new_node->next = NULL;
  return new_node;
}

struct Graph* create_graph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->traversed = malloc(vertices * sizeof(int));
  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->traversed[i] = 0;
  }
  return graph;
}

void add_edge(struct Graph* graph, int src, int dest) {
  struct node* new_node = create_node(dest);
  new_node->next = graph->adjLists[src];
  graph->adjLists[src] = new_node;
  new_node = create_node(src);
  new_node->next = graph->adjLists[dest];
  graph->adjLists[dest] = new_node;
}

void print(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\nDanh sách liền kề của đỉnh %d\n ", v);
    while (temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = create_graph(5);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 4, 6);
  add_edge(graph, 2, 5);
  print(graph);
  DFS(graph, 2);
  return 0;
}
