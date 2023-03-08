
import numpy as np

numNodes=0

for height in range(0,5):
    if height==0:
        print("height: ", height)
        print("min number of nodes: ", 1)
        print("max number of nodes: ", 1)
        print("")
        numNodes = numNodes + 1
        continue

    print("height: ", height)
    print("min number of nodes: ", numNodes+1)
    print("max number of nodes: ", numNodes+2**height)


    print(np.log2(numNodes+1))
    print(np.log2(numNodes+2**height+1)-1)
    numNodes = numNodes + 2**height
    print("")