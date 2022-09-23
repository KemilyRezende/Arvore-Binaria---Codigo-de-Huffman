#include <iostream> 
#include "Word.hpp" 

using namespace std;
 
 void Word::setWord(string word){
	this->word = word; 
} 

void Word::setCounter(float counter){
	this->counter = counter;
} 

string Word::getWord(){ 
	return this->word; 
} 

float Word::getCounter(){ 
	return this->counter; 
}

void Word::setHuff(string huff){
	this->huff = huff;
}

string Word::getHuff(){
	return this->huff;
}
