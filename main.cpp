#include <iostream>
#include <fstream>
#include "Parser.h"

int main()
{
    Parser* parser = new Parser("FA.in");
    parser->readFA();
    parser->displayStates();
    parser->displayAlphabet();
    parser->displayTransitions();
    parser->displayInitialState();
    parser->displayFinalStates();
    return 0;
}

// FA.in structure:
// states
// alphabet
// number of transitions followed by the transitions on separate lines
// initial state
// final states