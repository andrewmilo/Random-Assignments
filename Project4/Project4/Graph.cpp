#include "Graph.h"
#include "BinaryHeap.h"

Graph::Graph(void)
{
}

Graph::~Graph(void)
{
}

bool Graph::Contains(const std::string &name) const
{
	for(int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i].name_ == name)
			return true;
	}

	return false;
}

const Node* Graph::Find(const std::string & name) const
{
	for(int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i].name_ == name)
			return &vertices_[i];
	}

	return NULL;
}

void Graph::AddVertex(std::string name)
{
    if(!this->Contains(name))
        vertices_.push_back(new Node(name));
}

void Graph::AddEdge(const std::string vertex1, const std::string vertex2, float value)
{
	AddVertex(vertex1);
    Node& v1 = vertices_[vertices_.size() - 1];
	AddVertex(vertex2);
    Node& v2 = vertices_[vertices_.size() - 1];
        
	v1->AddEdge(value, v2);
}

void Graph::Dijkstra(const std::string & source) const
{
	Queue<string> queue;
	queue.Enqueue(source);

}