/*
 * HuffNode.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef HUFFNODE_H_
#define HUFFNODE_H_

template <typename E>
class HuffNode {
public:
	virtual ~HuffNode() {}
	virtual int getWeight() = 0;
	virtual bool isLeaf() = 0;
};



#endif /* HUFFNODE_H_ */
