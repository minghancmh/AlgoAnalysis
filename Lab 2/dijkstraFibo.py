import FiboHeap2

import sys



class Graph():
    def __init__(self, V):
        self.V = V
        self.adj = [[] for vertexPair in range(V)]

    def addEdge(self, u, v, w): # append a tuple of the vertex as well as the corresponding weight
        self.adj[u].append((v,w)) # v is connected to u (append to u's list)
        self.adj[v].append((u,w)) # u is connected to v (append to v's list)

    def printEdges(self):
        adjlist = self.adj
        print(adjlist)

    def shortestPath(self, src):
        fh = FiboHeap2.FibonacciHeap() # heap contains tuples in the format (dist, vertex)
        fh.insert_node((0, src))

        dist = [sys.maxsize] * self.V # instantiate distance array with infinity, or sysmax values
        sptSet = [False] * self.V
        dist[src] = 0 # set distance to source to 0



        while fh.count!=0:
            w,u = fh.extract_min() # extract min node from pq
            sptSet[u] = True


            for v, weight in self.adj[u]: # look at the vertices that are connected to u
                if weight > 0 and sptSet[v] == False and dist[v] > dist[u] + weight and dist[v] > dist[u] + weight:
                    dist[v] = dist[u] + weight
                    fh.insert_node((dist[v],v)) # node v has been added to the solution set, we push it to the heap

        # print("Node Index \t Distance from source")
        # for i in range(self.V):
        #     print(f"{i} \t\t {dist[i]}")


if __name__ == "__main__":
    # create the graph given in above figure
    V = 9
    g = Graph(V)
 
    # making above shown graph
    g.addEdge(0, 1, 4)
    g.addEdge(0, 7, 8)
    g.addEdge(1, 2, 8)
    g.addEdge(1, 7, 11)
    g.addEdge(2, 3, 7)
    g.addEdge(2, 8, 2)
    g.addEdge(2, 5, 4)
    g.addEdge(3, 4, 9)
    g.addEdge(3, 5, 14)
    g.addEdge(4, 5, 10)
    g.addEdge(5, 6, 2)
    g.addEdge(6, 7, 1)
    g.addEdge(6, 8, 6)
    g.addEdge(7, 8, 7)

    # g.printEdges()
 
    g.shortestPath(0)