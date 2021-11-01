#include "Parser.h"
#include "Helper.h"

Parser::Parser(std::string faPath) {
	this->faPath = faPath;
}

void Parser::readFA() {
	std::ifstream file(this->faPath);

	std::string statesString = "";
	std::string alphabetString = "";
	std::string finalStatesString = "";

	std::getline(file, statesString);
	std::getline(file, alphabetString);

	this->states = Helper::splitString(statesString, ' ');
	this->alphabet = Helper::splitString(alphabetString, ' ');

	// read transitions
	int noTransitions = 0;
	std::string transitionString;
	std::vector<std::string> transitionVector;
	file >> noTransitions;
	for (int i = 0; i < noTransitions; i++) {
		std::getline(file, transitionString);
		transitionVector = Helper::splitString(transitionString, ' ');
		if (transitionVector.size() == 0) {
			i--;
			continue;
		}
		Transition tr;
		tr.s1 = transitionVector[0];
		tr.t = transitionVector[1];
		tr.s2 = transitionVector[2];
		this->transitions.push_back(tr);
	}

	std::getline(file, this->initialState);

	std::getline(file, finalStatesString);
	this->finalStates = Helper::splitString(finalStatesString, ' ');
}

void Parser::displayStates() {
	std::cout << "[States ...]\n";
	std::cout << "{ ";
	for (int i = 0; i < this->states.size(); i++) {
		std::cout << this->states[i] << ' ';
	}
	std::cout << "}\n";
	std::cout << "[... done]\n";
}

void Parser::displayAlphabet() {
	std::cout << "[Alphabet ...]\n";
	std::cout << "{ ";
	for (int i = 0; i < this->alphabet.size(); i++) {
		std::cout << this->alphabet[i] << ' ';
	}
	std::cout << "}\n";
	std::cout << "[... done]\n";
}

void Parser::displayTransitions() {
	std::cout << "[Transitions ...]\n";
	for (int i = 0; i < this->transitions.size(); i++) {
		std::cout << "delta(" << this->transitions[i].s1 << ", " << this->transitions[i].t << ") = " << this->transitions[i].s2 << '\n';
	}
	std::cout << "[... done]\n";
}

void Parser::displayInitialState() {
	std::cout << "[Initial state ...]\n";
	std::cout << this->initialState << '\n';
	std::cout << "[... done]\n";
}

void Parser::displayFinalStates() {
	std::cout << "[Final states ...]\n";
	std::cout << "{ ";
	for (int i = 0; i < this->finalStates.size(); i++) {
		std::cout << this->finalStates[i] << ' ';
	}
	std::cout << "}\n";
	std::cout << "[... done]\n";
}
