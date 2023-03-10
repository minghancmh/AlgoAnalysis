import random
import dijkstraMatrix
import dijkstraList
# import dijkstraFibo
import generateGraphs2
import time
import random
import csv

def generate_graph(num_vertices, num_edges):
    # create an empty adjacency matrix
    adj_matrix = [[0] * num_vertices for _ in range(num_vertices)]
    # generate a connected graph
    for i in range(num_vertices - 1):
        adj_matrix[i][i+1] = adj_matrix[i+1][i] = random.randint(1, 10)
    # generate remaining edges
    num_remaining_edges = num_edges - (num_vertices - 1)
    edge_list = []
    for i in range(num_vertices):
        for j in range(i+1, num_vertices):
            if i != j:
                edge_list.append((i, j))
    random.shuffle(edge_list)
    for i in range(num_remaining_edges):
        edge = edge_list[i]
        weight = random.randint(1, 10)
        adj_matrix[edge[0]][edge[1]] = adj_matrix[edge[1]][edge[0]] = weight
    
    # create adjacency list
    adj_list = [[] for _ in range(num_vertices)]
    for i in range(num_vertices):
        for j in range(num_vertices):
            if adj_matrix[i][j] != 0:
                adj_list[i].append((j, adj_matrix[i][j]))
                
    return adj_matrix, adj_list

header = ['numEdge', 'matrix', 'list(binary)']
with open('dz.csv', 'w', encoding='UTF8', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(header)


    for i in range(1999, 1999000000, 200000000):
            

        adjm, adjl = generate_graph(2000, i)

        startMatrix = time.time()
        g = dijkstraMatrix.Graph(2000)
        g.graph = adjm
        g.dijkstra(0)
        endMatrix = time.time()

        startList = time.time()
        g=dijkstraList.Graph(2000)
        g.adj = adjl
        g.shortestPath(0)
        endList = time.time()

        matrixTime = endMatrix-startMatrix
        listTime = endList-startList

        print("Num Edge: ", i)
        print("Time for Matrix:", matrixTime)
        print("Time for List(Binary):", listTime)
        # print("Time for List(Fibo):", fiboTime)
        writer.writerow([i,matrixTime, listTime])
