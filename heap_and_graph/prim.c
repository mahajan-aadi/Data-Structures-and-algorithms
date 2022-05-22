#include <stdio.h>
#include <stdbool.h>

#define V 6
#define INT_MAX 99999

bool createsMST(int u, int v, bool inMST[]){
   if (u == v)
      return false;
   if (inMST[u] == false && inMST[v] == false)
      return false;
   else if (inMST[u] == true && inMST[v] == true)
      return false;
   return true;
}

void printMinSpanningTree(int graph[V][V]){
   bool inMST[V]={false};
   inMST[0] = true;
   int edgeNo = 0, MSTcost = 0;
   while (edgeNo < V - 1) {
      int min = INT_MAX, a = -1, b = -1;
      for (int i = 0; i < V; i++) {
         for (int j = 0; j < V; j++) {
            if (graph[i][j] < min) {
               if (createsMST(i, j, inMST)) {
                  min = graph[i][j];
                  a = i;
                  b = j;
               }
            }
         }
      }
      if (a != -1 && b != -1) {
         printf("Edge %d: (%d , %d) : cost = %d \n",edgeNo++,a,b,min);
         MSTcost += min;
         inMST[b] = inMST[a] = true;
      }
   }
   printf("Cost of Minimum spanning tree =%d",MSTcost);
}
int main()
{
    int graph[V][V] = { { 0 , 10, 8, 0, 0, 0 },
                        { 10, 0 , 3, 4, 2, 0 },
                        { 8 , 3 , 0, 2, 3, 2 },
                        { 0 , 4 , 2, 0, 4, 5 },
                        { 0 , 2 , 3, 4, 0, 7 },
                        { 0 , 0 , 2, 5, 7, 0 } };

    for (int i=0;i<=V;i++)
	  for (int j=0;j<=V;j++) {
		if(graph[i][j]==0)
		    graph[i][j]=INT_MAX;
	}
    printMinSpanningTree(graph);

    return 0;
}
