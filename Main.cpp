#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cmath>


struct Member {
	int val;
	std::string name;

	Member(std::string n, int v) {
		val = v;
		name = n;
	}
};


void shuffleMembers(std::vector<Member>& _members) {
	std::srand(std::time(0));
	int randomNumA = std::rand() % _members.size();
	int randomNumB = std::rand() % _members.size();

	std::swap(_members[randomNumA], _members[randomNumB]);
	
	//std::cout << "NUM A: " << randomNumA << " " << "NUM B: " << randomNumB << "\n";
}

bool isSorted(std::vector<Member>& _members) {
	for (int x = 0; x < _members.size(); x++) {
		if (_members.at(x).val != x+1) {
			return false;
		}
	}
	return true;
}

int main() {

	Member newMem1("Carl", 1);
	Member newMem2("Hank", 4);
	Member newMem3("Sanford", 2);
	Member newMem4("Pat", 3);
	Member newMem5("Deimos", 5);
	Member newMem6("Jeremy", 8);
	Member newMem7("Gav", 7);
	Member newMem8("Scrimblo", 6);

	std::vector<Member> memArr = {newMem1, newMem2, newMem3, newMem4, newMem5, newMem6, newMem7, newMem8};


	while (!isSorted(memArr)) {
		shuffleMembers(memArr);
		for (const auto& member : memArr) {
			std::cout << member.val << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "SORTED!";


	return -1;
}