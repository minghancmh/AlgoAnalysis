import dijkstraMatrix
import dijkstraList
import dijkstraFibo
import generateGraphs2
import time
import random
import csv

random.seed(5)

numberOfVertices = 0
header = ['n', 'matrix', 'list(binary)', 'list(fibo)']

with open('results5.csv', 'w', encoding='UTF8', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(header)

    for i in range(3, 500, 10):
        numberOfVertices = i


        adjm = generateGraphs2.create_graph_adjm(numberOfVertices)
        adjl = generateGraphs2.adjMatrixToList(adjm)
        adjl2 = adjl.copy()

        startMatrix = time.time()
        g = dijkstraMatrix.Graph(numberOfVertices)
        g.graph = adjm
        g.dijkstra(0)
        endMatrix = time.time()

        startFibo = time.time()
        g = dijkstraFibo.Graph(numberOfVertices)
        g.adj = adjl2
        g.shortestPath(0)
        endFibo = time.time()


        startList = time.time()
        g=dijkstraList.Graph(numberOfVertices)
        g.adj = adjl
        g.shortestPath(0)
        endList = time.time()







        matrixTime = endMatrix-startMatrix
        listTime = endList-startList
        fiboTime = endFibo-startFibo
        print("N: ", i)
        # print("Time for Matrix:", matrixTime)
        # print("Time for List(Binary):", listTime)
        # print("Time for List(Fibo):", fiboTime)
        writer.writerow([i,matrixTime, listTime, fiboTime])