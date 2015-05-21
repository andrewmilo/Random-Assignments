/***
/* Linked Templated Graph Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #4
/* May 1st, 2015
***/

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include "Node.h"
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

template <class T>
class Graph
{
public:
	bool Contains(const std::string&) const;
	void AddVertex(std::string);
	void AddEdge(const std::string& node1, const std::string& node2, float value);
	void LoadGraph(const std::string& filepath);
	Graph(void);
	~Graph(void);
private:
	class Node
	{
	public:
		void AddEdge(float distance, Node& destination);
		bool operator==(const Node&) const;
		bool operator!=(const Node&) const;
		Node();
		Node(T);
		~Node(void);
	private:
		struct Edge
		{
			unsigned float value_;
			Node destination_;
			Edge(unsigned float, Node&);
			~Edge(void);
		};
		T data_;
		std::vector<Edge> edges_;
	};
	std::vector<Node> vertices_;
};

template <class T>
Graph<T>::Node::Node(T data)
{
	this->data_ = data;
}

template <class T>
Graph<T>::Node::~Node(void)
{
}

template <class T>
void Graph<T>::Node::AddEdge(float distance, Node& dest)
{
	Edge* edge = new Edge(distance, dest);
    edges_.push_back(edge);
}

template <class T>
bool Graph<T>::Node::operator==(const Node& other) const
{
	if(this->name_ == other.name_)
		return true;

	return false;
}

template <class T>
bool Graph<T>::Node::operator!=(const Node& other) const
{
	return !(*this == other);
}

template <class T>
Graph<T>::Graph(void)
{
}

template <class T>
Graph<T>::~Graph(void)
{
}

template <class T>
bool Graph<T>::Contains(const std::string &name) const
{
	for(int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i].GetName() == name)
			return true;
	}

	return false;
}

template <class T>
Node& Graph<T>::AddVertex(T data)
{
	Node temp = new Node(data);
	vertices_.push_back(temp);
	return temp;
}

template <class T>
void Graph<T>::AddEdge(const T& vertex1, const T& vertex2, unsigned float value)
{
    if(!this->Contains(name))
	{
		AddVertex(vertex1);

	}
		
    //Node* v1 = vertices_[vertices_.size() - 1];
	if(!this->Contains(name))
		AddVertex(vertex2);
    //Node* v2 = vertices_[vertices_.size() - 1];
        
	//v1->AddEdge(value, *v2);
}

template <class T>
void Graph<T>::Djisktra(const Node& source) const
{

}

#endif
