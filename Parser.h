#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

// delta(s1,t) = s2
struct Transition {
	std::string s1;
	std::string t;
	std::string s2;
};

class Parser
{
private:
	std::string faPath;
	std::vector<std::string> states;
	std::vector<std::string> alphabet;
	std::vector<Transition> transitions;
	std::string initialState;
	std::vector<std::string> finalStates;

public:
	Parser(std::string faPath);
	void readFA();
	void displayStates();
	void displayAlphabet();
	void displayTransitions();
	void displayInitialState();
	void displayFinalStates();

	// M = (Q, sigma, delta, q0, F)
};