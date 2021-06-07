/***************************************************************
 * Dijkstra Algorithm on Graph with adjecency list 
 * representation, by Mayuresh Shinde
 * Code Copyrighted to Mayuresh Shinde
***************************************************************/

// including headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// class graph node declaration
class node;

// ADT for links in adjecency list
class links_struct {
    public:
    int weight;
    node* link;
};

// ADT for graph node
class node {
    public:
    std::string value;
    int distance;
    std::vector<links_struct*> links;
    node() {
        value = "null";
        distance = INT32_MAX;
    }
};

// function displays given vector
template<typename t>
void display_vector(
    std::vector<t> g, 
    std::string instring, 
    std::string statement
) {
    std::cout << statement;
    for (int i = 0; i < g.size(); i++) {
        std::cout << g[i] -> value << instring;
    }
}

// function gets the index of element inside given vector
template<typename vectortype, typename argtype>
int get_index(std::vector<vectortype> v, argtype tofind) {
    int i;
    for (i = 0; i < v.size(); i++) {
        if (v[i] -> value == tofind) {
            return i;
        }
    }
    return -1;
}

// function for detailed display of adjacency list graph
template<typename t>
void display_graph_detailed(std::vector<t> g) {
    for (int i = 0; i < g.size(); i++) {
        std::cout << "vertex : " << g[i] -> value 
        << " -> connected to " 
        << g[i] -> links.size() << " vertices : -" << std::endl;
        for (int j = 0; j < g[i] -> links.size(); j++) {
            std::cout << "\t(" << g[i] -> links[j] -> link -> value 
            << ", w(" << g[i] -> links[j] -> weight << ")), " 
            << std::endl;
        }
    }
}

// function returns node which has minimum distance in 
// given vector
node* get_minimum_distance_node(std::vector<node*> g) {
    if (g.size() > 0) {
        node* minimum_node = g[0];
        for (int i = 0; i < g.size(); i++) {
            if(minimum_node -> distance > g[i] -> distance) {
                minimum_node = g[i];
            }
        }
        return minimum_node;
    } else {
        return nullptr;
    }
    
}

// edges input function declaration
void get_undirected_edges(std::vector<node*> g);
void get_directed_edges(std::vector<node*> g);

// function performs dijkstra on given graph
void perform_dijkstra(std::vector<node*> g, node* traverse_node) {
    std::vector<node*> nonvisited_nodes;
    int sum;
    std::copy(g.begin(), g.end(), std::back_inserter(nonvisited_nodes));
    int total_vector_nodes = g.size();
    traverse_node -> distance = 0;
    while (nonvisited_nodes.size() && traverse_node) {
        for (int i = 0; i < traverse_node -> links.size(); i++) {
            if (get_index(nonvisited_nodes, traverse_node -> links[i] -> link -> value) >= 0) {
                sum = traverse_node -> distance + 
                    traverse_node -> links[i] -> weight;
                if (traverse_node -> links[i] -> link -> distance > sum) {
                    traverse_node -> links[i] -> link -> distance = sum;
                }
            }
        }
        nonvisited_nodes.erase(
            nonvisited_nodes.begin() + 
                get_index(nonvisited_nodes, traverse_node -> value)
        );
        traverse_node = get_minimum_distance_node(nonvisited_nodes);
    }
}

// function to display output of dijkstra
void dijkstra_output(std::vector<node*> g, node* starting_node) {
    for (int i = 0; i < g.size(); i++) {
        std::cout << " from " << starting_node -> value << " to " 
        << g[i] -> value << " distance is : ";
        if (g[i] -> distance == INT32_MAX) {
            std::cout << "infinite";
        } else {
            std::cout << g[i] -> distance;
        }
        std::cout << std::endl;
    }
}

// ADT for graph
// has some imp required functions
class graph {
    private:
    std::vector<node*> g;
    // int number_of_edges;
    bool isDirected;

    public:
    void get_vertices();
    // void get_directed_edges();
    // void get_undirected_edges();
    void get_edges() {
        if (isDirected) {
            // number_of_edges = get_directed_edges(g);
            get_directed_edges(g);
        } else {
            // number_of_edges = get_undirected_edges(g);
            get_undirected_edges(g);
        }
    }
    void change_to_directed() {
        isDirected = true;
    }
    void change_to_undirected() {
        isDirected = false;
    }
    void display_vertices();
    void display_graph() {
        std::cout << "Graph Type: ";
        if (isDirected) {
            std::cout << "Directed";
        } else {
            std::cout << "Undirected";
        }
        std::cout << std::endl;
        display_graph_detailed(g);
    }
    void get_shortest_paths();
    graph();
};

// constructor
graph::graph() {
    isDirected = false;
    // number_of_edges = 0;
}

void graph::display_vertices() {
    display_vector(g, ", ", "graph vertices: ");
}

void graph::get_vertices() {
    std::string input;
    node* new_node;
    std::cout << ": ";
    std::cin >> input;
    while (
        input != "d" && 
        input != "e" && 
        input != "done" && 
        input != "exit"
    ) {
        new_node = new node;
        new_node -> value = input;
        g.push_back(new_node);
        std::cout << ": ";
        std::cin >> input;
    }
    if (input == "d" || input == "done") {
        return;
    } else if (input == "e" || input == "exit") {
        exit(0);
    }
}

void get_undirected_edges(std::vector<node*> g) {
    int i, j, weight; //, edge_count = 0;
    links_struct* link_node;
    std::string input;
    while (true) {
        connect_from : std::cout << std::endl << "connect vertex: ";
        std::cin >> input;
        if (input == "d" || input == "done") {
            return;
        } else if (input == "e" || input == "exit") {
            exit(0);
        }
        i = get_index(g, input);
        if (i < 0) {
            std::cout << "value not found!" << std::endl;
            goto connect_from;
        }
        connect_to : std::cout << "and vertex: ";
        std::cin >> input;
        if (input == "d" || input == "done") {
            return;
        } else if (input == "e" || input == "exit") {
            exit(0);
        }
        j = get_index(g, input);
        if (j < 0) {
            std::cout << "value not found!" << std::endl;
            goto connect_to;
        }
        while (
            std::cout << "with weight: " && 
            !(std::cin >> weight)
        ) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), 
                '\n'
            );
            std::cout << "please enter numirecial values only!" 
            << std::endl;
        }
        link_node = new links_struct;
        link_node -> weight = weight;
        link_node -> link = g[j];
        g[i] -> links.push_back(link_node);
        link_node = new links_struct;
        link_node -> weight = weight;
        link_node -> link = g[i];
        g[j] -> links.push_back(link_node);
        // edge_count++;
        
    }
    // return edge_count;
}

void get_directed_edges(std::vector<node*> g) {
    int i, j, weight; //, edge_count;
    links_struct* link_node;
    std::string input;
    while (true) {
        std::cout << std::endl;
        connect_from : std::cout << "connect from vertex: ";
        std::cin >> input;
        if (input == "d" || input == "done") {
            return;
        } else if (input == "e" || input == "exit") {
            exit(0);
        }
        i = get_index(g, input);
        if (i < 0) {
            std::cout << "value not found!" << std::endl;
            goto connect_from;
        }
        connect_to : std::cout << "to vertex: ";
        std::cin >> input;
        if (input == "d" || input == "done") {
            return;
        } else if (input == "e" || input == "exit") {
            exit(0);
        }
        j = get_index(g, input);
        if (j < 0) {
            std::cout << "value not found!" << std::endl;
            goto connect_to;
        }
        while (
            std::cout << "with weight: " && 
            !(std::cin >> weight)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), 
                '\n'
            );
            std::cout << "please enter numirecial values only!" 
            << std::endl;
        }
        link_node = new links_struct;
        link_node -> weight = weight;
        link_node -> link = g[j];
        g[i] -> links.push_back(link_node);
        // edge_count++;
        
    }
    // return edge_count;
}

void graph::get_shortest_paths() {
    std::string input;
    int i;
    wrong_value : std::cout << std::endl << "enter starting node: ";
    std::cin >> input;
    i = get_index(g, input);
    if (i < 0) {
        std::cout << "value not found!";
        goto wrong_value;
    }
    perform_dijkstra(g, g[i]);
    std::cout << "Done...." << std::endl << std::endl 
    << "Shortest distance to differet nodes from starting nodes are: -"
    << std::endl;
    dijkstra_output(g, g[i]);
}

// main operational function
void operations() {
    graph g;
    std::string input;
    std::cout << "What type of graph you want directed or undirected?" 
    << std::endl << std::endl << "Enter: -" << std::endl 
    << " d -> for directed" << std::endl << " ud -> for undirected";
    wrong_input : std::cout << std::endl << "(d/ud) : ";
    std::cin >> input;
    if (input == "d") {
        g.change_to_directed();
    } else if (input == "ud") {
        g.change_to_undirected();
    } else {
        std:: cout << "please enter proper input!";
        goto wrong_input;
    }
    std::cout << std::endl << "Enter vertices: -" << std::endl
    << "* type (d/done) for done entering vertices " 
    << "and (e/exit) to exit" << std::endl;
    g.get_vertices();
    g.display_vertices();
    std::cout << std::endl << std::endl << "Connect vertices: -" 
    << std::endl << "* type (d/done) for done connecting vertices " 
    << "and (e/exit) to exit" << std::endl;
    g.get_edges();
    std::cout << std::endl << "Displaying graph: -" << std::endl;
    g.display_graph();
    std::cout << std::endl << "Performing dijkstra....";
    g.get_shortest_paths();
    std::cout << std::endl;
}

// the small main function
int main() {
    operations();
    exit(0);
}
