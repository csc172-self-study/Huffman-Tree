/*
 * HuffTree.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include "LeafNode.h"
#include "IntNode.h"
#include "MinHeap.h"
#include <map>
#include <bitset>
#include <string>
#include <iostream>
using std::string; using std::cout;

template <typename E>
class HuffTree {
private:
	HuffNode<E>* root;
	std::map<char,string> codeTable;
public:
	HuffTree(const E& val, int freq) {
		root = new LeafNode<E>(val, freq);
	}

	HuffTree(HuffTree<E>* left, HuffTree<E>* right) {
		root = new IntNode<E>(left->root, right->root);
	}

	~HuffTree(){}

	HuffNode<E>* getRoot() {
		return root;
	}

	int weight() {
		return root->getWeight();
	}

	HuffTree<E>* buildHuff(HuffTree<E>** TreeArray, int count) {
		MinHeap<HuffTree<E>*> forest = MinHeap<HuffTree<E>*>(TreeArray, count, count);
		HuffTree<E> *temp1, *temp2, *temp3 = NULL;
		while (forest.getSize() > 1) {
			temp1 = forest.removeFirst();
			temp2 = forest.removeFirst();
			temp3 = new HuffTree<E>(temp1,temp2);
			forest.insert(temp3);
			delete temp1;
			delete temp2;
		}
		return temp3;
	}

	void createTable(string curCode = "") {
			this->createTable(root, curCode);
		}

	void createTable(HuffNode<E>* curNode, string curCode) {
		string leftCode = curCode + "0";
		string rightCode = curCode + "1";
		if (curNode->isLeaf()) {
			codeTable[((LeafNode<E>*) curNode)->getVal()] = curCode;
		} else {
			createTable(((IntNode<E>*) curNode)->getLeft(), leftCode);
			createTable(((IntNode<E>*) curNode)->getRight(), rightCode);
		}
	}

	string encodeText(string inputString) {
		string output = "";
		for (char& c: inputString) {
			string code = codeTable.find(c)->second;
			cout << code << std::flush;
			output += code;
		}
		cout << "\nDone encoding.";
		return output;
	}

	void decodeText(string inputCode) {
		HuffNode<E>* curNode = root;
		for (char& c: inputCode) {
			if (c == '0') {
				if (!curNode->isLeaf()) curNode = ((IntNode<E>*) curNode)->getLeft();
			} else if (c == '1') {
				if (!curNode->isLeaf()) curNode = ((IntNode<E>*) curNode)->getRight();
			} else {
				throw "Invalid encoding.";
			}

			if (curNode->isLeaf()) {
				cout << ((LeafNode<E>*)curNode)->getVal();
				curNode = root;
			}
		}
	}

};

#endif /* HUFFTREE_H_ */
