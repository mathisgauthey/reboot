
import java.util.*;

public class Graph {

    // Node class
    public class Node {
        // Attributes
        int value; // A node has just a name

        // Constructor
        public Node(int value) {
            this.value = value;
        }

    }

    // Attributes
    int N; // Number of nodes in the graph
    Map<Node, Set<Node>> adjList; // Adjacent dictionary of the graph
    // The adjacent dictionary is a dictionary of nodes, where each node has a set
    // of neighbor nodes

    // Constructor
    public Graph(int n) {
        N = n;
        this.adjList = new HashMap<>();
        // We then create as many nodes as required
        for (int i = 0; i < N; i++) {
            addNode(i);
        }
    }

    // Create a node inside your graph if it does not exist
    void addNode(int value) {
        Node node = new Node(value);
        adjList.putIfAbsent(node, new HashSet<>());
    }

    // Find two nodes by their values and add an edge between them if they exist
    void addEdge(int src, int dest) {
        Node srcNode = findNode(src);
        Node destNode = findNode(dest);

        if (srcNode != null && destNode != null) {
            adjList.get(srcNode).add(destNode);
            adjList.get(destNode).add(srcNode);
        }
    }

    // Find a node by its value in the graph list of nodes
    // The java.util.HashMap.keySet() method in Java is used to create a set out of
    // the key elements contained in the hash map.
    Node findNode(int val) {
        for (Node node : adjList.keySet()) { // For each node in the graph
            if (node.value == val) {
                return node;
                // If we find the node in the set of nodes, we return it
            }
        }
        return null; // Else we return null
    }

    // Print the whole graph via adjacent list
    public void printGraph() {
        // For each node in the graph...
        for (Node node : adjList.keySet()) {
            System.out.print(node.value + ": "); // Print the node value
            // For each neighbor of the node...
            for (Node neighbor : adjList.get(node)) {
                System.out.print(neighbor.value + " "); // Print them
            }
            System.out.println(); // Print a new line
        }
    }

    // DFS search starting at node with value start
    void dfs(int start) {
        Node startNode = findNode(start); // Find the node with value start
        Set<Node> visited = new HashSet<>(); // Create a set of visited nodes
        if (startNode != null) {
            dfsRecursive(startNode, visited);
        }
    }

    void dfsRecursive(Node currentNode, Set<Node> visited) {
        // If the current node has not been visited yet...
        if (!visited.contains(currentNode)) {
            // Print the node value
            System.out.print(currentNode.value + " ");
            // And the node to the visited list
            visited.add(currentNode);

            // For each neighbor of the current node...
            for (Node neighbor : adjList.get(currentNode)) {
                // If the neighbor has not been visited yet...
                dfsRecursive(neighbor, visited);
            }
        }
    }

    // BFS search starting at node with value start
    void bfs(int start) {
        Node startNode = findNode(start); // Find the node with value start
        if (startNode != null) {
            bfsTraversal(startNode);
        }
    }

    void bfsTraversal(Node startNode) {
        // Generate a queue (FIFO) and a visited list
        Queue<Node> queue = new LinkedList<>();
        Set<Node> visited = new HashSet<>();

        // Add the start node to the queue and the visited list
        queue.add(startNode);
        visited.add(startNode);

        // While the queue is not empty...
        while (!queue.isEmpty()) {
            // Get the first node in the queue
            Node currentNode = queue.poll();
            // Print it's value
            System.out.print(currentNode.value + " ");

            // For each neighbor of the current node...
            for (Node neighbor : adjList.get(currentNode)) {
                // If the neighbor has not been visited yet...
                if (!visited.contains(neighbor)) {
                    // Add it to the queue and the visited list
                    queue.add(neighbor);
                    visited.add(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(7);

        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(2, 4);
        g.addEdge(2, 5);
        g.addEdge(5, 6);

        g.printGraph();

        System.out.println("\nDFS:");
        g.dfs(0);
        System.out.println("\nBFS:");
        g.bfs(0);
    }

}