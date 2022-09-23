#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Word.hpp" 
#include "NOde.hpp"

using namespace std;

void insertWord(vector<Word> vet, string word, int size){
//Search if the word has already been allocated in the vector, if not, inserts it into 
//the vector, else increment the word's counter
	bool search = false; 
	for (int i = 0; i < size; i++){
		if(vet[i].getWord() == word){
			vet[i].setCounter(vet[i].getCounter() + 1);
			search = true;
			break;
		}
	}
	if (!(search)){
		Word w;
		w.setWord(word);
		w.setHuff("0");
		w.setCounter(1.0);
		vet.push_back(w);
	}
}

void StopList(vector<string>SW){ //Fill the list with the stop words from the file
	ifstream stopList;
	string word;
	stopList.open("StopWords.txt");
	while (!(stopList.eof())){
		getline(stopList, word, '\n');
		SW.push_back(word);
	}
}

bool StopWord(vector<string> SW, string word){ //If the word is a stop word returns "true", else returns "false"
	bool sw = false;
	for (long unsigned int i = 0; i < SW.size(); i++){
		if (SW[i] == word){
			sw = true;
			break;
		}
	}
	return sw;
}

bool cmp(Word a, Word b){ //Parameter to Sort vector Word
	return (a.getCounter() < b.getCounter());
}

bool cmpNode(Node* a, Node* b){ //Parameter to Sort vector Node
	return (a->getCount() < b->getCount());
}

void createTree(vector<Node*> tree){ //Create the Huffman Tree
	Node* n;
	Node* one;
	Node* two;
	Word w;
	float counter;
	while (tree.size() > 1){
		one = tree[0];
		two = tree[1];
		counter = one->getCount() + two->getCount();
		w.setWord("-1");
		w.setCounter(counter);
		w.setHuff("0");
		n = new Node(w);
		n->setLeft(one);
		n->setRight(two);
		tree.erase(tree.begin(), tree.begin()+1);
		tree.push_back(n);
		sort(tree.begin(), tree.end(), cmpNode);
	}
}

int Hashing(string word, int size){ //Hash function
	float a = 0.6180339887;
	int l = word.length();
	int sum = 0;
	for (int i = 0; i < l; i++){
		sum += word[i];
	}
	float key = sum * a;
	key = key - (int)key;
	return (int)(size*key);
}
 
 int main(){
 	vector<Word> vet;
 	Node* n;
 	vector<Node*> tree;
 	int size = 0;
 	vector<string> SW;
 	StopList(SW);
 	string word, word1, f_name;
 	ifstream file;
 	cout << "File name: ";
 	cin >> f_name;
	cout << "Erro";
 	file.open(f_name);
 	while (getline(file, word1, '\n')){ //Read the words from a file
		word1.append(" ");
 		stringstream s(word1);
 		while (getline(s, word, ' ')){
 			while (word.back() == ',' || word.back() == '.' || word.back() == '!' || word.back() == '?' || word.back() == ';' || word.back() == ':' || word.back() == ')' || word.back() == '\'' || word.back() == '\"' || word.back() == '/' || word.back() == '-'){
 				word.pop_back(); //Remove signs from the word's last char
			}
			while (word.front() == '(' || word.front() == '-'|| word.front() == '\''|| word.front() == '\"'){
				word.erase(word.begin()); //Remove signs from the word's first char
			}
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (!(StopWord(SW, word))){ //Search if the word is a stop word
				insertWord(vet, word, size); //If not inserts it on Word vector
				size++;
			}
		}
	}
	float max = 0, min = vet[0].getCounter(), counter;
	for (int i = 0; i < size; i++){ //Finds max(RP) and min(RP)
		if (vet[i].getCounter() > max)
	 		max = vet[i].getCounter();
		else if (vet[i].getCounter() < min)
			min = vet[i].getCounter();
	}
	 
	for (int i = 0; i < size; i++){ //Resets counters based on the given equation
		counter = vet[i].getCounter()/(max - min);
		vet[i].setCounter(counter);
	 }
	 
 	sort(vet.begin(), vet.end(), cmp); 
 	 
	for (long unsigned int i = 0; i < vet.size(); i++){
		n = new Node(vet[i]);
 	 	tree.push_back(n);
	}
	vet.erase(vet.begin(), vet.end());
	createTree(tree);
	  
	Word Hash[size];
	int pos;
	Word w;
	string huff;
	
	while (tree[0] != NULL){ //Create a Hash table with the Words
		huff = '1';
		w = n->HuffmanDFS(tree[0], huff);
		if (w.getWord() != "-1"){
			pos = Hashing(w.getWord(), size);
			Hash[pos] = w;
		}
	}
	tree.erase(tree.begin(), tree.end());
	ofstream file2("CodyfiedText.txt");
	
	while (!(file.eof())){ //Read the file again and creates a file with the binary codes
 		getline(file, word1, '\n');
		word1.append(" ");
 		stringstream S(word1);
 		while (getline(S, word, ' ')){
 			while (word.back() == ',' || word.back() == '.' || word.back() == '!' || word.back() == '?' || word.back() == ';' || word.back() == ':' || word.back() == ')' || word.back() == '\'' || word.back() == '\"' || word.back() == '/' || word.back() == '-'){
 				word.pop_back(); //Remove signs from the word's last char
			}
			while (word.front() == '(' || word.front() == '-'|| word.front() == '\''|| word.front() == '\"'){
				word.erase(word.begin()); //Remove signs from the word's first char
			}
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (!(StopWord(SW, word))){ //Search if the word is a stop word
				pos = Hashing(word, size);
				file2 << Hash[pos].getHuff() << " ";
			}
		}
	}
	
	file.close();
	file2.close();
	return 0;
 }
