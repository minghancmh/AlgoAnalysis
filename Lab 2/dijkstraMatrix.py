import sys

class Graph():

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)] # initialise adjacency matrix

    
    def minDistance(self, dist, sptSet): # maintaining a pq through an array
        min = sys.maxsize

        for u in range(self.V):
            # dist[u] < min : implementation of the pq, always return minimum dist
            # sptSet[u] == False : checks that vertex is not already in solution set
            if dist[u] < min and sptSet[u] == False: 
                min = dist[u]
                min_index = u

        return min_index
    

    def dijkstra(self, src):
        dist = [sys.maxsize] * self.V # initialise distance array
        dist[src] = 0 
        sptSet = [False] * self.V # initialise solutionSet array
        for cout in range(self.V):
            x = self.minDistance(dist, sptSet) # x is the index of the minimum dist
        
            sptSet[x] = True # greedily include x into the solution set 

            for y in range(self.V): 
                # self.graph[x][y] > 0 : checks that weight is non negative
                # sptSet[y] == False : checks that new node to be added is not in the solution set
                # disy[y] > dist[x] + self.graph[x][y] : checks that we are decreasing the distance to y
                if self.graph[x][y] > 0 and sptSet[y] == False and dist[y] > dist[x] + self.graph[x][y]:
                    dist[y] = dist[x] + self.graph[x][y]

        


if __name__ == "__main__":
    g = Graph(9)
    g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
               [4, 0, 8, 0, 0, 0, 0, 11, 0],
               [0, 8, 0, 7, 0, 4, 0, 0, 2],
               [0, 0, 7, 0, 9, 14, 0, 0, 0],
               [0, 0, 0, 9, 0, 10, 0, 0, 0],
               [0, 0, 4, 14, 10, 0, 2, 0, 0],
               [0, 0, 0, 0, 0, 2, 0, 1, 6],
               [8, 11, 0, 0, 0, 0, 1, 0, 7],
               [0, 0, 2, 0, 0, 0, 6, 7, 0]
               ]
 
    g.dijkstra(0)