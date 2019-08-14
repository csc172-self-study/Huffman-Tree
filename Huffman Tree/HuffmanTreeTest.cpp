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
	const int NUM_LETTERS = 27;
	int count = 0;
	string testString = "this is an example huffman tree string to encode weeeeeeeeeeeeee";

	int stringLength = testString.size();
	int freq[NUM_LETTERS];

	for (int i = 0; i < NUM_LETTERS; ++i) {
		freq[i] = 0;
	}

	for (int i = 0; i < stringLength; ++i) {
		if (testString[i] == ' ') {
			freq[NUM_LETTERS-1]++;
		} else {
			freq[testString[i] - 'a']++;
		}
	}

	for (int i = 0; i < NUM_LETTERS; ++i) {
		if (freq[i] != 0) count++;
	}

	// freq is changing in here and I don't know why
	HuffTree<char>* initialArray[count];
	int j = 0;
	for (int i = 0; i < NUM_LETTERS; ++i) {
		if (freq[i] != 0) {
			int letterFreq = freq[i];
			if (i == 26) {
				initialArray[j] = new HuffTree<char>(' ', letterFreq);
				j++;
			} else {
				initialArray[j] = new HuffTree<char>((char) (i + 'a'), letterFreq);
				j++;
			}
		}
	}

	HuffTree<char>* constructedTree = initialArray[0]->buildHuff(initialArray, count);

	constructedTree->createTable("");

	string encoded = constructedTree->encodeText(testString);

	cout << "\n\nDecoding string: \n";

	constructedTree->decodeText(encoded);

}


