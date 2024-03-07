#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Vertex {
public:
    int value;
    Vertex* next;
    
    Vertex(int val) {
        this->value = val;
        next = NULL;
    }
};

class Graph {
    int vertices;
    Vertex** adjacencyList;

public:
    Graph(int numVertices) {
        vertices = numVertices;
        adjacencyList = new Vertex*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjacencyList[i] = NULL;
        }
    }

    void addLink(int v, int w) {
        Vertex* newNode = new Vertex(w);
        newNode->next = adjacencyList[v];
        adjacencyList[v] = newNode;

        newNode = new Vertex(v);
        newNode->next = adjacencyList[w];
        adjacencyList[w] = newNode;
    }

    void displayGraph() {
        for (int v = 0; v < vertices; ++v) {
            cout << "Adjacent vertices of node " << v << ": ";
            Vertex* current = adjacencyList[v];
            while (current) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void traverseBFS(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }

        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal starting from node " << startVertex << ": ";
        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            Vertex* temp = adjacencyList[currentVertex];
            while (temp) {
                int adjVertex = temp->value;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        cout << endl;
    }

    void traverseDFS(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }

        stack<int> s;

        visited[startVertex] = true;
        s.push(startVertex);

        cout << "DFS Traversal starting from node " << startVertex << ": ";
        while (!s.empty()) {
            int currentVertex = s.top();
            cout << currentVertex << " ";
            s.pop();

            Vertex* temp = adjacencyList[currentVertex];
            while (temp) {
                int adjVertex = temp->value;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    s.push(adjVertex);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        cout << endl;
    }

    void findLink(int v, int w) {
        Vertex* current = adjacencyList[v];
        while (current) {
            if (current->value == w) {
                cout << "Link found between nodes " << v << " and " << w << endl;
                return;
            }
            current = current->next;
        }
        cout << "No link found between nodes " << v << " and " << w << endl;
    }

    void removeLink(int v, int w) {
        Vertex* current = adjacencyList[v];
        Vertex* prev = NULL;

        while (current && current->value != w) {
            prev = current;
            current = current->next;
        }

        if (current && current->value == w) {
            if (prev == NULL) {
                adjacencyList[v] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Link between nodes " << v << " and " << w << " removed successfully." << endl;
        } else {
            cout << "Link between nodes " << v << " and " << w << " not found." << endl;
        }
    }
};

int main() {
	cout<<"Name: Hamayun, RegId: 225158"<<endl;
	cout<<"----------------------------------"<<endl;
    Graph g(5);

    g.addLink(0, 1);
    g.addLink(0, 4);
    g.addLink(1, 2);
    g.addLink(1, 3);
    g.addLink(1, 4);
    g.addLink(2, 3);
    g.addLink(3, 4);

    g.displayGraph();

    g.traverseBFS(0);
    g.traverseDFS(0);

    g.findLink(1, 2); 
    g.removeLink(1, 3); 
    return 0;
}

