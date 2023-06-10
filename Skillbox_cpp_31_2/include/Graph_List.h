#include "Graph.h"


#define GHRAPH_RESERVE 5
//Класс Графов со смежным списком
class GraphList : public IGraph
{
    int vertCount;
    std::vector<std::vector<int>> m_list;
public:
    GraphList(int vert) {
        vertCount = 0;
        if (vert > 0) {
            vertCount = vert;
            initGraph();
        }
        else {
            std::cerr << "Cannot create Graph with " << vert << " verticies" << std::endl;
        }
    }

    GraphList() : GraphList(10) {}
    ~GraphList() override {
        for (auto it = m_list.begin(); it != m_list.end();it++) {
            it._Ptr->clear();
        }
        m_list.clear();
    }
    void initGraph() {
        m_list.resize(vertCount);
        for (int i = 0; i < vertCount; ++i) {
            m_list[i].reserve(5);
            m_list[i].resize(1,0);
            m_list[i][0]=i;
        }
    }

    void AddEdge(int from, int to) override {
        int count = 0x03;
        for (auto i = m_list.begin(); i != m_list.end(); i++) {
            if (i._Ptr->at(0) == from && (count & 0x01)) {
                i._Ptr->push_back(to);
                count &= ~ 0x01;
            }
            else if (i._Ptr->at(0) == to && (count & 0x02)) {
                i._Ptr->push_back(from);
                count &= ~ 0x02;
            }
        }
        
        if (count) {
            std::cerr << "There is no such verticies as: " << ((count & 0x01) ? std::to_string(from) : "") << ((count & 0x02) ? " " + std::to_string(to) : "") << "\n";
        }
    }

    int VerticesCount() const override {
        return (int)m_list.size();
    }

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override {
        vertices.clear();
        vertices.reserve(m_list.size());
        std::vector<int>* tmp_list = nullptr;
        for (auto i = m_list.begin(); i != m_list.end(); i++) {
            if (i._Ptr->at(0) == vertex) tmp_list = i._Ptr;
        }
        for (auto i = tmp_list->crbegin(); tmp_list && i != tmp_list->crend(); i++) {
            if (*i != 0) {
                vertices.push_back(*i);
            };
        }
    }

    void GetPrevVertices(int vertex, std::vector<int>& vertices) const  override {
        vertices.clear();
        std::vector<int>* tmp_list = nullptr;
        for (auto i = m_list.begin(); i != m_list.end(); i++) {
            if (i._Ptr->at(0) == vertex) tmp_list = i._Ptr;
        }
        for (auto i = tmp_list->crbegin(); tmp_list && i != tmp_list->crend(); i++) {
            if (*i != 0) {
                vertices.push_back(*i);
            };
        }
    }
    void PrintCLI() override {
        std::cout << "Graph is List of incident vertices" << std::endl 
            << "Number of verticies is " << vertCount << std::endl
            << "Verticie and verticies that is incendentical to:" << std::endl;
        for (auto it = m_list.begin(); it != m_list.end(); it++) {
            std::cout << "Vert " << it._Ptr->at(0) << ": ";
            auto it2 = it._Ptr->begin();
            it2++;
            for (; it2 != it._Ptr->end(); it2++) {
                std::cout << *it2._Ptr << " ";
            }
            std::cout << std::endl;
        }
    }
};
