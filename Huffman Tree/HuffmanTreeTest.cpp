/*
 * HuffmanTreeTest.cpp
 *
 * Driver to test Huffman coding tree implementation.
 *
 *  Created on: Aug 13, 2019
 *      Author: alex
 */

#include "HuffTree.h"
#include <string>
using std::string;

int main() {
	const int NUM_LETTERS = 26;
	int count = 0;
	string testString = "this is an example huffman tree string to encode weeeeeeeeeeeeee";

	int stringLength = testString.size();
	int freq[NUM_LETTERS];

	for (int i = 0; i < NUM_LETTERS; ++i) {
		freq[i] = 0;
	}

	for (int i = 0; i < stringLength; ++i) {
		freq[testString[i] - 'a']++;
	}

	for (int i = 0; i < NUM_LETTERS; ++i) {
		if (freq[i] != 0) count++;
	}

	// freq is changing in here and I don't know why
	HuffTree<char>* initialArray[count];
	int j = 0;
	for (int i = 0; i < NUM_LETTERS; ++i) {
		if (freq[i] != 0) {
			initialArray[j] = new HuffTree<char>((char) (i + 'a'), freq[i]);
			j++;
		}
	}

	HuffTree<char>* constructedTree = initialArray[0]->buildHuff(initialArray, count);

	constructedTree->createTable("");

	constructedTree->encodeText(testString);

	//constructedTree->decodeText()

}


