#include "pch.h"
#include "CH1.h"



void testCH1() {
	// q1
	std::cout << "Checking Unique..." << std::endl;
	assert(unique("asdfghjkl"));
	assert(!unique("racecar"));

	// q1 variant
	std::cout << "Checking Unique2..." << std::endl;
	assert(unique2("asdfghjkl"));
	assert(!unique2("racecar"));

	// q2
	std::cout << "Checking checkPermutation..." << std::endl;
	assert(checkPermutation("aaasssdddfff", "asdfasdfasdf"));
	assert(!checkPermutation("aaasssdddfff", "asdfasdfwsdf"));

	// q3
	std::cout << "Checking URLify..." << std::endl;
	char name[18] = "Mr John Smith    ";
	assert(URLify(name, 13) == "Mr%20John%20Smith");

	// q4
	std::cout << "Checking palindromePermutation..." << std::endl;
	assert(palindromePermutation("racerac"));
	assert(!palindromePermutation("abc"));

	// q5
	std::cout << "Checking oneAway..." << std::endl;
	assert(oneAway("hello", "henlo"));
	assert(!oneAway("hello", "hewwo"));
	assert(oneAway("pale", "ple"));
	assert(oneAway("pales", "pale"));


}


//============ Q1 ===========
bool unique(string s) {
	if (s.length() > 128)
		return false;
	map<char, int> m = {};
	for (char c : s) {
		auto search = m.find(c);
		if (search == m.end())
			m[c] = 1;
		else
			return false;
	}
	return true;
}

bool unique2(string s) {
	if (s.length() > 128)
		return false;
	std::sort(s.begin(), s.end());
	for (auto it = s.begin(); it != s.end() - 1; ++it) {
		if (*it == *(it + 1))
			return false;
	}
	return true;
}

//============ Q2 ==============

bool checkPermutation(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	map<char, int> m1, m2;
	for (char c : s1)
		m1[c]++;
	for (char c : s2)
		m2[c]++;
	if (m1 == m2)
		return true;
	return false;
}

//============ Q3 ==============

string URLify(char str[], int len) {
	int spacecount = 0;
	for (int i = 0; i != len - 1; i++) {
		if (str[i] == ' ')
			spacecount++;
	}
	int index = len + spacecount*2;

	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[index - 1] = '0';
			str[index - 2] = '2';
			str[index - 3] = '%';
			index = index - 3;
		}
		else {
			str[index-1] = str[i];
			index--;
		}
	}
	return str;
}

//============ Q4 ==============

bool palindromePermutation(string s) {
	map<char, int> m;
	for (char c : s) {
		if(isalpha(c))
			m[tolower(c)]++;
	}
	int oddcount = 0;
	for (auto x : m) {
		if (x.second % 2 == 1)
			oddcount++;
		if (oddcount > 1)
			return false;
	}
	return true;
}

//============ Q5 ==============
bool oneAway(string s1, string s2) {
	if (s1 == s2)
		return true;
	if (s1.length() == s2.length()) {
		int differences = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) {
				if (differences == 1)
					return false;
				differences++;
			}
		}
		return true;
	}
	else if ( std::abs((int)s1.length() - (int)s2.length()) == 1 ) {
		return palindromePermutation(s1 + s2);
	}
	return false;
}

//============ Q6 ==============
string stringCompression(string s) {

}
