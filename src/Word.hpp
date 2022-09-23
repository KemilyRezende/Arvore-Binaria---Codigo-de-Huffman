#include <iostream> 
#ifndef _Word__HPP 
#define _Word__HPP
 
using namespace std; 

class Word{ 
	private: 
		float counter; 
		string word; 
		string huff;
	public: 
		void setWord(string word); 
		string getWord(); 
		void setHuff(string huff);
		string getHuff();
		void setCounter(float counter); 
		float getCounter(); 
};

#endif
