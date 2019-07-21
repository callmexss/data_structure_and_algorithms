#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>


template <typename Graph>
class ReadGraph
{
public:
    ReadGraph(Graph &graph, const std::string &filename)
    {
        std::ifstream file(filename); // open a data file
        std::string line; // set a line as buffer to read each line's data
        int V, E; // Vertexs, Edges' count

        assert(file.is_open()); // assure the file is open

        assert(getline(file, line)); // read the first line to line
        std::stringstream ss(line); // convert line to string stream
        ss >> V >> E; // redirection data from string stream to int variables

        assert(V == graph.V()); // assure the read data matches requirement

        for (int i = 0; i < E; i++) // read edges information
        {
            assert(getline(file, line));
            std::stringstream ss(line);

            int a, b;
            ss >> a >> b;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);

            graph.addEdge(a, b);
        }
    }

};
