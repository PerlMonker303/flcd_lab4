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
    //Parser* parser = new Parser("FA.in");
    Parser* parser = new Parser("FA_identifiers.in");
    //Parser* parser = new Parser("FA_constants.in");
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

    std::string sequence = "";
    
    // tests for FA.in
    /*
    std::cout << "[Tests for FA.in...]\n";
    sequence = "a";
    assert(parser->verifySequence(sequence) == false);
    sequence = "b";
    assert(parser->verifySequence(sequence) == true);
    sequence = "ab";
    assert(parser->verifySequence(sequence) == true);
    sequence = "aba";
    assert(parser->verifySequence(sequence) == false);
    sequence = "abc";
    assert(parser->verifySequence(sequence) == false);
    sequence = "";
    assert(parser->verifySequence(sequence) == false);
    std::cout << "[... done]\n";
    */

    // tests for FA_identifiers.in
    
    std::cout << "[Tests for FA_identifiers.in...]\n";
    sequence = "";
    assert(parser->verifySequence(sequence) == false);
    sequence = "A";
    assert(parser->verifySequence(sequence) == true);
    sequence = "WORD";
    assert(parser->verifySequence(sequence) == true);
    sequence = "-5";
    assert(parser->verifySequence(sequence) == false);
    
    /*
    // tests for FA_constants.in
    std::cout << "[Tests for FA_constants.in...]\n";
    sequence = "";
    assert(parser->verifySequence(sequence) == false);
    sequence = "0";
    assert(parser->verifySequence(sequence) == true);
    sequence = "-5";
    assert(parser->verifySequence(sequence) == true);
    sequence = "+5";
    assert(parser->verifySequence(sequence) == true);
    sequence = "123";
    assert(parser->verifySequence(sequence) == true);
    sequence = "10203";
    assert(parser->verifySequence(sequence) == true);
    */
    return 0;
}

