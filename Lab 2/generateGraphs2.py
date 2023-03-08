import networkx as nx
import random

def create_graph_adjm(num_nodes):
    # create an empty graph
    G = nx.Graph()

    # add nodes to the graph
    for i in range(1, num_nodes+1):
        G.add_node(i)

    # add random weighted edges to the graph
    for i in range(1, num_nodes+1):
        for j in range(i+1, num_nodes+1):
            if random.choice([True, False]):
                weight = random.randint(1, 10)
                G.add_edge(i, j, weight=weight)

    # make sure the graph is connected
    if not nx.is_connected(G):
        # add edges to connect any disconnected components
        for comp in nx.connected_components(G): # connected_components(G) returns a generator of sets of nodes
            if len(comp) > 1:
                # find a random pair of nodes from different components and connect them
                nodes1 = random.choice(list(comp))
                nodes2 = random.choice(list(set(range(1, num_nodes+1)) - set(comp)))
                weight = random.randint(1, 10)
                G.add_edge(nodes1, nodes2, weight=weight)

    listComps = G.edges(data=True)

    adjm = [[0 for _ in range(num_nodes)] for _ in range(num_nodes)] # generate adjacency matrix from graph edges
    for edge in listComps:
        adjm[edge[0]-1][edge[1]-1] = edge[2]['weight']
        adjm[edge[1]-1][edge[0]-1] = edge[2]['weight']  
    return adjm


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

