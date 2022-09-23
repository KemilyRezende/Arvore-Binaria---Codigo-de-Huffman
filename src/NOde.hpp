#include <iostream>
#include "Word.hpp"
#ifndef __NODE__HPP
#define __NODE__HPP

using namespace std;

class Node{
	private:
		Word word;
		Node* Right;
		Node* Left;
	public:
		Node(Word word);
		void setString(string w);
		string getWord();
		void setCont(float counter);
		float getCount();
		void setHuffcode(string huff);
		void setRight(Node* no);
		Node* getRight();
		void setLeft(Node* no);
		Node* getLeft();
		Word HuffmanDFS(Node* rooth, string huff);
};

#endif
