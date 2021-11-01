#include <iostream>
#include <fstream>
#include "Parser.h"
#include <assert.h>

// FA.in structure:
// states
// alphabet
// number of transitions followed by the transitions on separate lines
// initial state
// final states

int main()
{
    Parser* parser = new Parser("FA.in");
    parser->readFA();
    if (parser->getEncounteredError() != "") {
        std::cout << parser->getEncounteredError();
        return 0;
    }
    parser->displayStates();
    parser->displayAlphabet();
    parser->displayTransitions();
    parser->displayInitialState();
    parser->displayFinalStates();

    std::string sequence = "abc";
    std::cout << parser->verifySequence(sequence);
    
    // tests
    sequence = "a";
    assert(parser->verifySequence(sequence) == false);
    sequence = "ab";
    assert(parser->verifySequence(sequence) == true);
    sequence = "aba";
    assert(parser->verifySequence(sequence) == false);
    sequence = "abc";
    assert(parser->verifySequence(sequence) == false);
    sequence = "";
    assert(parser->verifySequence(sequence) == false);

    return 0;
}

