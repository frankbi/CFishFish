#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>
#include <string>
#include <vector>

class Token ;

/* This enumerated type is used to keep track of what kind of
   construct was matched.
*/
enum tokenEnumType {

    // Keywords
    nameKwd, platformKwd, initialKwd, stateKwd,
    gotoKwd, whenKwd, performingKwd, exitKwd,

    intKwd, floatKwd, booleanKwd, stringKwd, charKwd,

    trueKwd, falseKwd,

    // Constants
    intConst, floatConst, stringConst, charConst,

    // Names
    variableName ,

    // Punctuation
    leftParen, rightParen,
    leftCurly, rightCurly,

    leftAngle, rightAngle,
    colon, comma, semiColon,
    assign,

    plusSign, star, dash, forwardSlash,
    equalsEquals, lessThanEquals, greaterThanEquals, notEquals,

    // Special terminal types
    endOfFile , //38
    lexicalError, //39
} ;

enum whitespaceRegexType {
    whitespace, blockComment, lineComment
};

typedef enum tokenEnumType tokenType ;

using namespace std;

/*
static const int last_regex = 37; //last regular regex that we have to match against
static const int special_regex_start = 40; //whitespace regexes
static const int special_regex_end = 42;*/

class Token {
    public:
        Token();
        Token(tokenType terminal, Token* next, std::string lexeme);
        tokenType terminal;
        std::string lexeme;
        Token* next;
};

class Scanner {
    public:
        Scanner();
        Token* scan(const char* text);
        void initialize_regex();
        Token* make_token(const char* text);
	    bool make_token_tester(const char* text, tokenType t, const char* lexeme);
	    vector<regex_t*> regexes;
	    vector<regex_t*> whitespace_regexes; //for whitespace and comment regexes for which we do not need to produce tokens
        int consume_white_space_and_comments(const char* text);
};


#endif /* SCANNER_H */
