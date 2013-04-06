// Michael Cistera, Frank Bi
// CSCI 3081W Iteration #1

#include "scanner.h"
#include <iostream>
#include <string>
#include <cstring>
#include "regex.h"

using namespace std;

Scanner::Scanner() {
    initialize_regex();
}

Token::Token() {
    terminal = lexicalError;
    next = NULL;
    lexeme = "";
}

Token::Token(tokenType terminal, Token* next, std::string lexeme) {
    this->terminal = terminal;
    this->next = next;
    this->lexeme = lexeme;
}


//argument text is the source file read into a char buffer
//returns the first in a chain of tokens
Token* Scanner::scan(const char* text) {
    int len = strlen(text);
    int i = consume_white_space_and_comments(text);
    Token * start;
    start = make_token(text + i);
    
    if (start != NULL) {
        i += start->lexeme.length();
    } else {
        i = len; // to skip to the end and just return an end of file is the string is all whitespace
    }
    
    Token* prev = start;
    
    while (i < len) {
        int x;
        if ( (x = consume_white_space_and_comments(text + i)) == 0) {
                Token* t = make_token(text + i);
                if (t == NULL) {
                    break;
                }
                //cout << "made token " << t->terminal << " " << t->lexeme << endl;
                if (prev != NULL) {
                    prev->next = t;
                }
                prev = t;
                i+= t->lexeme.length();
        } else {
            i += x;
        }
    }

    Token * end = new Token(endOfFile, NULL, "");
    if (prev != NULL) {
        prev->next = end;
    }
    
    if (start != NULL) { 
        return start;
    } else {
        return end;
    }
}


//Takes a regex string, makes the regex, and inserts it into slot index of regexvec, expanding the vector with zeroes if necessary
//When calling, use an enumerated type for index and the order of the enum will no longer matter
void add_regex(vector<regex_t*>& regexvec, unsigned int index, const char* regex_string){
    if(index + 1 > regexvec.size()){ //if the vector is not large enough resize it
        regexvec.resize(index + 1);
        }
    regexvec[index] = makeRegex(regex_string);
}

void Scanner::initialize_regex(){
    add_regex(regexes, nameKwd, "^name");
    add_regex(regexes, platformKwd, "^platform");
    add_regex(regexes, initialKwd, "^initial");
    add_regex(regexes, stateKwd, "^state");
    add_regex(regexes, gotoKwd, "^goto");
    add_regex(regexes, whenKwd, "^when");
    add_regex(regexes, performingKwd, "^performing");
    add_regex(regexes, exitKwd, "^exit");

    add_regex(regexes, intKwd, "^int");
    add_regex(regexes, floatKwd, "^float");
    add_regex(regexes, booleanKwd, "^boolean");
    add_regex(regexes, stringKwd, "^string");
    add_regex(regexes, charKwd, "^char");

    add_regex(regexes, trueKwd, "^true");
    add_regex(regexes, falseKwd, "^false");

    add_regex(regexes, intConst, "^[0-9]+");
    add_regex(regexes, floatConst, "^[0-9]*\\.[0-9]+");
    add_regex(regexes,  stringConst, "^\"([^\"]|(\\\\\"))*\"");// makeRegex("^\"[^\"]*\"");
    add_regex(regexes,  charConst, "^'(.|(\\\\[0bnrt\\\\\\'\\\"]))'");

    add_regex(regexes, variableName, "^[_A-Za-z]+[-_A-Za-z0-9]*");

    add_regex(regexes, leftParen, "^\\(");
    add_regex(regexes, rightParen, "^\\)");
    add_regex(regexes, leftCurly,"^\\{");
    add_regex(regexes, rightCurly,"^}");

    add_regex(regexes, leftAngle, "^<");
    add_regex(regexes, rightAngle, "^>");
    add_regex(regexes, colon, "^:");
    add_regex(regexes, comma, "^,");
    add_regex(regexes, semiColon, "^;");
    add_regex(regexes, assign, "^:=");

    add_regex(regexes, plusSign, "^\\+");
    add_regex(regexes, star, "^\\*");
    add_regex(regexes, dash, "^\\-");
    add_regex(regexes, forwardSlash, "^/");
    add_regex(regexes, equalsEquals, "^==");
    add_regex(regexes, lessThanEquals, "^<=");
    add_regex(regexes, greaterThanEquals, "^>=");
    add_regex(regexes, notEquals, "^!=");


    add_regex(whitespace_regexes, whitespace, "^[\n\t\r ]+");
    add_regex(whitespace_regexes, blockComment, "^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
    add_regex(whitespace_regexes, lineComment, "^//[^\n\r]+");

}


//make a token from start of text to the last character before a delimiter
Token* Scanner::make_token(const char* text){
//    cout << "Make token: " << text << "|||\n";
///must consume whitespace beforehand
if(strlen(text) == 0) return NULL;
Token* longest_match = new Token(lexicalError, NULL, text);
int max_len = 0; int cur_match_len = 0;
for(unsigned int t = 0; t < regexes.size(); t++){
        if((cur_match_len = matchRegex(regexes[t], text))){
            if(cur_match_len > max_len){ //found a longer match
                max_len = cur_match_len;
                longest_match->terminal = (tokenType)t;
            }
        }
    }
    if(longest_match->terminal == lexicalError) max_len = 1;
    longest_match->lexeme.erase(max_len, string::npos); //erase all parts of the lexeme after the match

    return longest_match;
}

//return true for success
bool Scanner::make_token_tester(const char* text, tokenType t, const char* lexeme){
    //match token in text
    //verify that returned token type is type t and lexeme matches
    Token* tok = make_token(text);
    if(tok == NULL) return false;
    if(tok->terminal != t || strcmp(tok->lexeme.c_str(), lexeme) != 0){ cout << "tokenType: " << tok->terminal << " Expected: " << t << " Lexeme: " << tok->lexeme << " Expected: " << lexeme << endl; return false;}
    return true;
}

//returns number of characters consumed
int Scanner::consume_white_space_and_comments(const char* text){
    const char* cur_pos = text;
    int ret = 0; int cur_matched = 0;
    bool matched = true;
    while(matched){ //continue until no matched left
        matched = false;
        for(unsigned int t = 0; t < whitespace_regexes.size(); t++){
            if( (cur_matched = matchRegex(whitespace_regexes[t], cur_pos)) ){ //match
                matched = true;
                ret += cur_matched;
                cur_pos += cur_matched;
            }
        }
    }
    return ret;
}
