/**
* @file Node
* @description Node class that holding data and 2 other nodes[next and previous]
* @course Veri Yapıları 1-C
* @assignment 1
* @date 26.11.2020
* @author Furkan Cebar (furkan.cebar@ogr.sakarya.edu.tr)
*/

#ifndef NODE_HPP
#define NODE_HPP

class Node{
public:
	int Data;
	Node *Next;
	Node *Previous;

	//Creates a Node and connect itself to next and previous nodes
	explicit Node(int data = 0,Node *previous = nullptr, Node *next = nullptr)
	{
		if (previous == nullptr) previous = this;
		if (next == nullptr) next = this;
		this->Data = data;
		this->Previous = previous;
		this->Next = next;
		this->Previous->Next = this;
		this->Next->Previous = this;

	}

	//Deletes itself and connect next and previous
	~Node() {
		if (Next != this && Previous != this) {
			this->Next->Previous = this->Previous;
			this->Previous->Next = this->Next;
		}
	}
};
#endif