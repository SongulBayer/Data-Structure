/**
* @file List
* @description Doubly Circular Linked List structure
* @course Veri Yapıları 1-C
* @assignment 1
* @date 27.11.2020
* @author Furkan Cebar (furkan.cebar@ogr.sakarya.edu.tr)
*/

#ifndef LIST_HPP
#define LIST_HPP

#include <sstream>
#include "Iterator.hpp"

class List{
public:
	int sizeL;
	int sizeR;
	Node *middleNode;
	Iterator *iterator;
public:

	//region Constructor and Destructor methods

	//List Constructor with 1 node
	explicit List(int data = 0) {
		this->middleNode = new Node(data);
		this->iterator = new Iterator(this->middleNode);
		this->sizeR = 0;
		this->sizeL = 0;
	}

	//Clears all nodes except middleNode
	void Clear() {
		int count = this->sizeR;
		for (int i = 1; i <= count; ++i) {
			this->RemoveAt(1);
		}
		count = this->sizeL;
		for (int i = 1; i <= count; ++i) {
			this->RemoveAt(-1);
		}
	}

	~List() {
		this->Clear();
		delete this->middleNode;
		delete this->iterator;
	}

	//endregion

	//region Iterator
private:
	//Reset the Iterator's location
	void reset() {
		delete this->iterator;
		this->iterator = new Iterator(this->middleNode);
	}
public:
	//
	int FindByIndex(int location) {
		if (abs(this->iterator->Index() - location) <= abs(location)) {// Closer than 0
			location = location - this->iterator->Index();
		} else {
			this->reset();
		}
		this->iterator->GoFromCurrent(location);

		return this->iterator->Current();
	}

	int Size() const {
		return this->sizeL + 1 + this->sizeR;
	}

	//endregion

	//region Insert - Add and RemoveAt methods

	void Insert(int location, int data) {
		this->FindByIndex(location);
		this->iterator->Insert(data);
		if (location < 0) this->sizeL++;
		else if (location >= 0) this->sizeR++;
	}

	void AddRight(int data) {
		this->Insert(this->sizeR + 1, data);
	}

	void AddLeft(int data) {
		this->Insert((this->sizeL + 1) * -1, data);
	}

	void RemoveAt(int location) {
		this->FindByIndex(location);
		this->iterator->Remove();
		if (location < 0) this->sizeL--;
		else if (location > 0) this->sizeR--;
	}

	//endregion


	Node* GetMiddleNode() const {
		return this->middleNode;
	}


	std::string String() {
		this->FindByIndex(this->sizeL * -1);
		std::stringstream writer;
		for (int i = this->sizeL * -1; i <= this->sizeR; i++) {
			writer << this->iterator->Current() << " ";
			this->iterator->Next();
		}
		return writer.str();
	}

	friend std::ostream& operator<<(std::ostream&, List*);
	friend void operator>>(int*, List&);
};

std::ostream& operator<<(std::ostream& os, List *ls) {
	os << ls->String();
	return os;
}

void operator>>(int* numbers, List &ls) {
	ls.Clear();
	int count = *numbers++;
	ls.GetMiddleNode()->Data = *numbers++;
	for (int i = 0; i < count / 2; ++i) {
		ls.AddLeft(*numbers++);
	}
	for (int i = 0; i < count / 2; ++i) {
		ls.AddRight(*numbers++);
	}
}

#endif