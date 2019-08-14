/*
 * LeafNode.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef LEAFNODE_H_
#define LEAFNODE_H_

#include "HuffNode.h"

template <typename E>
class LeafNode : public HuffNode<E> {
private:
	E element;
	int weight;
public:
	LeafNode(const E& val, int freq) {
		element = val;
		weight = freq;
	}

	int getWeight() {
		return weight;
	}

	E getVal() {
		return element;
	}

	bool isLeaf() {
		return true;
	}
};


#endif /* LEAFNODE_H_ */
