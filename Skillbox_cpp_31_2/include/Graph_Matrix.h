#include "Graph.h"


//  матрица смежности
class GraphMatrix : public IGraph
{
    int vertCount = 0;
    std::vector<std::vector<int>> matrix;
public:
    GraphMatrix( int verticies) {
        vertCount = 0;

        if (verticies < 0) {
            std::cerr << "New graph on addr=" << this << " has no verticies";
            return;
        }
        vertCount = verticies;
        initGraph();
    }
    GraphMatrix() : GraphMatrix(10) { }
    void initGraph() {
        matrix.resize(vertCount);
        for (auto it = matrix.begin(); it != matrix.end(); it++) {
            it._Ptr->resize(vertCount);
        }
    }
    ~GraphMatrix() override {}
    void AddEdge(int from, int to) override {
        if (from < vertCount && to < vertCount && from >0 && to >0) {
            matrix[from][to]++;
            matrix[to][from]++;
        }
        else {
            std::cerr << "Graph " << this << " edges verticies out of range" << std::endl;
        }
    }
    int VerticesCount() const  override {
        return (int)matrix.size();
    }
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override {
        vertices.clear();
        if (vertex >= 0 && vertex < matrix.size()) {
            for (int i=0; i < matrix.size(); ++i) {
                if (matrix[vertex][i] != 0) vertices.push_back(i);
            }
        }
    }
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override {
        vertices.clear();
        if (vertex >= 0 && vertex < matrix.size()) {
            for (int i=0; i < matrix.size(); ++i) {
                if (matrix[vertex][i] != 0) vertices.push_back(i);
            }
        }
    }
    void print() {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.at(i).size(); ++j) {
                std::cout << "x/y (" << i << "/" << j << ") = " << matrix.at(i).at(j) << "\n";
            }
        }
    }
    void PrintCLI() override {
        std::cout << "Graph is List of incident vertices" << std::endl
            << "Number of verticies: " << matrix.size() << std::endl
            << "Verticie and verticies that is incendentical to:" << std::endl;

        for (int i = 0; i<matrix.size(); ++i) {
            std::cout << "Vert " << i << ": ";
            auto it2 = matrix.at(i).begin();
            it2++;
            for (; it2 != matrix.at(i).end(); it2++) {
                std::cout << *it2._Ptr << " ";
            }
            std::cout << std::endl;
        }

    }
};