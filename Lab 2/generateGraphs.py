import random
random.seed(0)

def generate_weighted_graph(n,m):
    adj_matrix = [[0 for x in range(n)] for y in range(n)] # defaults to max edges for the graph if m is greater than max num of possible edges
    maxEdges = int(n*(n-1)/2)
    if (m>maxEdges):
        m = maxEdges

    for i in range(m):
        u,v = random.sample(range(n),2)
        

        if adj_matrix[u][v] == 0 and adj_matrix[v][u] == 0: # check if edge exists
            weight = random.randint(1,20) # max weight is 20, arbitrarily set
            adj_matrix[u][v] = weight
            adj_matrix[v][u] = weight
    
    return adj_matrix

def adjMatrixToList(adj_matrix):
    numVertices = len(adj_matrix)
    sptSet = [0]*numVertices
    adjList = [[] for i in range(numVertices)]
    for i in range(numVertices):
        for j in range(numVertices):
            if adj_matrix[i][j] != 0:
                if (adj_matrix[i][j], j) not in adjList[i]: adjList[i].append((j, adj_matrix[i][j]))
                if (adj_matrix[i][j], i) not in adjList[j]: adjList[j].append((i, adj_matrix[i][j]))
                sptSet[i] = 1
    return adjList
    

# adjm = generate_weighted_graph(5,10)
# 
# print(adjm)
# print(adjMatrixToList(adjm))

