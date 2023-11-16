import java.util.Iterator;
import java.util.LinkedList;

public class Graph {

    // Number of vertices in the graph
    private int V;

    // array of linked lists (adj[]) where each element of the array represents a
    // vertex, and the corresponding linked list represents the adjacent vertices of
    // that vertex.
    private LinkedList<Integer> adj[];
    // IMPORTANT STUFF TO UNDERSTAND
    // Array : int[] array = new int[size];
    // List : List<Integer> list = new ArrayList<Integer>();
    // Array of references to LinkedList<Integer> objects :
    // private LinkedList<Integer>[] adj;
    // Array of LinkedList<Integer> objects directly :
    // private LinkedList<Integer> adj[];

    // Constructor
    @SuppressWarnings("unchecked")
    Graph(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new LinkedList<Integer>();
        }
    }

    // Function to add an edge into the graph
    void addEdge(int v, int w) {
        // Add w to v's list.
        adj[v].add(w);
    }

    void DFSUtil(int v, boolean visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        System.out.println(v + " ");

        // Recur for all the vertices adjacent to this vertex
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n])
                DFSUtil(n, visited);
        }
    }

    void DFS(int v) {
        // Mark all the vertices as false (not visited)
        // In java, boolean array is initialized to false by default
        boolean visited[] = new boolean[V];

        // Call the recursive helper function to print DFS traversal
        DFSUtil(v, visited);
    }

    public static void main(String[] args) {
        Graph g = new Graph(7);

        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(2, 4);
        g.addEdge(2, 5);
        g.addEdge(5, 6);
        g.addEdge(6, 5);

        System.out.println(
                "Following is Depth First Traversal "
                        + "(starting from vertex 2)");

        // Function call
        g.DFS(0);
    }
}
