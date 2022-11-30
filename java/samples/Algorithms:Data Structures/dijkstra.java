package thomasandraos6280341;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    static int vertCount = 0;
    static int edgeCount = 0;
    static String[] vertex;
    static int INF = 1000000;
    Node[] dist = new Node[vertCount];
    static String endVert;
    static String startVert;

    public static void main(String[] args) throws FileNotFoundException {
        try {

            Scanner fileP = new Scanner(System.in);
            System.out.println("Enter file path: ");
            String txtFile = fileP.nextLine();
            File f = new File(txtFile);
            Scanner fileIn = new Scanner(f);

            vertCount = fileIn.nextInt(); // getting number of edges and verticies from file
            edgeCount = fileIn.nextInt();

            vertex = new String[vertCount]; // creating arrays
            int[][] vertCo = new int[2][vertCount];
            int[][] edges = new int[vertCount][vertCount];
            Path[] paths = new Path[vertCount];

            for (int i = 0; i < vertCount; i++) // getting co ordinates from txt file
            {
                int count = 0;
                vertex[i] = fileIn.next();
                vertCo[count][i] = fileIn.nextInt();
                count += 1;
                vertCo[count][i] = fileIn.nextInt();
            }

            for (int i = 0; i < edgeCount; i++) // filling edges matrix with edges
            {
                String temp = fileIn.next();
                int id = 0;
                String temp1 = fileIn.next();
                int id1 = 0;

                for (int j = 0; j < vertCount; j++) {
                    if (temp.equals(vertex[j])) {
                        id = j;
                    }

                    if (temp1.equals(vertex[j])) {
                        id1 = j;
                    }
                }
                edges[id][id1] = fileIn.nextInt();
            }

            while (fileIn.hasNext()) // setting start and goal verticies
            {
                startVert = fileIn.next();
                endVert = fileIn.next();
            }

            Main m = new Main(); //creating new main and running methods
            int start = Integer.parseInt(startVert) - 1;
            int end = Integer.valueOf(endVert) - 1;

            m.dijkstra(edges, start);
            if (m.dist[end].distance != INF) {
                m.findShortestPath(start, end, edges, paths);
            }
            m.print(paths, start, vertCo);

        } catch (FileNotFoundException e) {
            System.out.println("File was not found");
            System.exit(0);
        }
    }

    int findMinDistance(Node dist[], Boolean visited[]) { //calculating minimum distance
        int min = INF;
        int index = -1;
        for (int i = 0; i < vertCount; i++)
            if (!visited[i] && dist[i].distance <= min) {
                min = dist[i].distance;
                index = i;
            }
        return index;
    }

    public void dijkstra(int graph[][], int src_node) { //calculates distance values to nodes

        Boolean visited[] = new Boolean[vertCount];
        for (int i = 0; i < vertCount; i++) {
            Node n = new Node(INF, vertex[i], i, -1);
            dist[i] = n;
            visited[i] = false;
        }

        dist[src_node].distance = 0;
        while (true) {
            int u = findMinDistance(dist, visited);
            if (u == -1) {
                return;
            }
            visited[u] = true;
            for (int i = 0; i < vertCount; i++) {
                if (!visited[i] && isAdjacent(u, i, graph) && graph[u][i] != 0 && dist[u].distance != INF && dist[u].distance + graph[u][i] < dist[i].distance) {

                    dist[i].distance = dist[u].distance + graph[u][i];
                    dist[i].setPreviousNode(u);
                }
            }
        }
    }

    private boolean isAdjacent(int u, int v, int graph[][]) {
        return (graph[u][v] != 0);
    }


    void findShortestPath(int start, int goal, int graph[][], Path[] paths) { //finding the shortest path

        dijkstra(graph, start);

        int i, u;
        int path[] = new int[vertCount];
        int tempPath[] = new int[vertCount];
        int totalDistance = 0;
        int count = 0;

        while (goal != start) {
            count++;
            path[count] = goal;
            u = dist[goal].getPreviousNode();
            totalDistance += graph[u][goal];
            goal = u;
        }
        count++;
        path[count] = start;

        for (i = count; i >= 1; i--) {
            tempPath[i] = path[i] + 1;
        }

        Path p = new Path(start, String.valueOf(goal), totalDistance, tempPath, count);
        paths[start] = p;
    }

    public void print(Path[] paths, int src, int[][] coOrds) { //printing the results
        try {
            System.out.println("\nNumber of Vertices: " + vertCount + "\nNumber of Edges: " + edgeCount);
            System.out.println("Start Vertex: " + (paths[src].src + 1) + " Destination Vertex: " + endVert);
            System.out.print("\nShortest Path: ");
            for (int i = paths[src].count; i >= 1; i--) {
                System.out.print(paths[src].path[i] + " ");
            }
            System.out.println("\nThe Shortest Distance is: " + paths[src].distance);
            System.out.print("The Euclidean Distance between vertices " + (paths[src].src + 1) + " and " + endVert + " is ");
            System.out.println(calcEuclideanDist(coOrds[0][Integer.parseInt(startVert) - 1], coOrds[0][Integer.parseInt(endVert) - 1], coOrds[1][Integer.parseInt(startVert) - 1], coOrds[1][Integer.parseInt(endVert) - 1]));
        } catch (NullPointerException e) {
            System.out.println("ERROR: Path between nodes does not exist.");
        }
    }

    public double calcEuclideanDist(int x1, int x2, int y1, int y2) {
        return Math.sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    }
}

class Node {
    int distance;
    String name;
    int alphIndex;
    int previousNode;

    public Node(int dis, String name, int ind, int prev) {
        this.distance = dis;
        this.name = name;
        this.alphIndex = ind;
        this.previousNode = prev;
    }

    public int getPreviousNode() {
        return previousNode;
    }

    public void setPreviousNode(int previousNode) {
        this.previousNode = previousNode;
    }
}

class Path {

    int src;
    String destination;
    int distance;
    int[] path;
    int count;

    public Path(int src, String destination, int distance, int[] path, int count) {
        this.src = src;
        this.destination = destination;
        this.distance = distance;
        this.path = path;
        this.count = count;
    }
}
