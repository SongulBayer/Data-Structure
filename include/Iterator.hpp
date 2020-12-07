/**
* @file Iterator
* @description Iterator for searching and changing inside List
* @course Veri Yapıları 1-C
* @assignment 1
* @date 28.11.2020
* @author Furkan Cebar (furkan.cebar@ogr.sakarya.edu.tr)
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

class Iterator{
private:
	int currentIndex;
	Node *currentNode;
public:

	explicit Iterator(Node *node = nullptr, int index = 0) {
		currentNode = node;
		currentIndex = index;
	}

	//region Get current and index

	int Current() const {
		return this->currentNode->Data;
	}

	int Index() {
		return this->currentIndex;
	}

	void AddIndex(int index) {
		this->currentIndex += index;
	}

	//endregion

	//region Move Previous, Next and Location

	void Previous() {
		currentNode = currentNode->Previous;
		currentIndex--;
	}

	void Next() {
		currentNode = currentNode->Next;
		currentIndex++;
	}

	//Goes to relatively location from currentIndex
	// ((Example: if currentIndex = 5, GoFromCurrent(-3) = currentIndex = 2))
	void GoFromCurrent(int location) {
		if (location < 0) {
			for (int i = 0; i > location; --i) {
				this->Previous();
			}
		} else if (location > 0) {
			for (int i = 0; i < location; ++i) {
				this->Next();
			}
		}
	}

	//endregion

	//region Insert and Remove

	//Insert new node to selected index (pushes current data to away from index[0])
	void Insert(int data) {
		if (this->currentIndex < 0) {
			currentNode = new Node(//Node class connect nodes automatically
					data, //Data
					this->currentNode, //Previous Node
					this->currentNode->Next); //Next Node
		} else if (this->currentIndex >= 0) {
			currentNode = new Node(//Node class connect nodes automatically
					data,//Data
					this->currentNode->Previous, //Previous Node
					this->currentNode); //Next Node
		}

	}
	//Removes selected node
	void Remove() {
		if (this->currentIndex > 0) {
			this->Previous();
			delete this->currentNode->Next; //Node class connect nodes automatically
		} else if (this->currentIndex < 0) {
		this->Next();
		delete this->currentNode->Previous; //Node class connect nodes automatically
		}
	}

	//endregion


};
#endif