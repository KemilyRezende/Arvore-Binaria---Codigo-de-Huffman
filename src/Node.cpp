#include <iostream>
#include <cstddef>
#include "NOde.hpp"

using namespace std;

Node::Node(Word word){
	this->word = word;
	this->Left = NULL;
	this->Right = NULL;
}

void Node::setCont(float counter){
	this->word.setCounter(counter);
}

float Node::getCount(){
	return this->word.getCounter();
}

void Node::setString(string w){
	this->word.setWord(w);
}

string Node::getWord(){
	return this->word.getWord();
}

void Node::setLeft(Node* no){
	this->Left = no;
}

Node* Node::getLeft(){
	return this->Left;
}

void Node::setRight(Node* no){
	this->Right = no;
}

Node* Node::getRight(){
	return this->Right;
}

void Node::setHuffcode(string huff){
	this->word.setHuff(huff);
}

Word Node::HuffmanDFS(Node* rooth, string huff){
	Word w;
	if (rooth->getLeft() == NULL && rooth->getRight() == NULL){
		if (rooth->getWord() == "-1"){
			w = rooth->word;
			rooth = NULL;
			//return w;
		}
		else {
			rooth->setHuffcode(huff);
			Word w = rooth->word;
			rooth = NULL;
			//return w;
		}
	}
	else {
		if (rooth->getLeft() != NULL){
			huff += '0';
			HuffmanDFS(rooth->getLeft(), huff);
		}
		else if (rooth->getRight() != NULL){
			huff += '1';
			HuffmanDFS(rooth->getRight(), huff);
		}
	}
	return w;
}