/*
 * IntNode.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef INTNODE_H_
#define INTNODE_H_

#include "HuffNode.h"

template <typename E>
class IntNode : public HuffNode<E> {
private:
	HuffNode<E>* leftChild;
	HuffNode<E>* rightChild;
	int weight;
public:
	IntNode(HuffNode<E>* left, HuffNode<E>* right) {
		weight = left->getWeight() + right->getWeight();
		leftChild = left;
		rightChild = right;
	}

	int getWeight() {
		return weight;
	}

	bool isLeaf() {
		return false;
	}

	HuffNode<E>* getLeft() {
		return leftChild;
	}

	HuffNode<E>* getRight() {
		return rightChild;
	}

	void setLeft(HuffNode<E>* left) {
		leftChild = left;
	}

	void setRight(HuffNode<E>* right) {
		rightChild = right;
	}
};

#endif /* INTNODE_H_ */
