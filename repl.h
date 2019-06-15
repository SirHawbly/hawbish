/*
 * Copyright (c) 2019 Christopher Bartlett
 * [This program is licensed under the "MIT License"]
 * Please see the file LICENSE in the source
 * distribution of this software for license terms.
 */

#ifndef REPL

#define REPL

#include <string>
#include <list>

using namespace std;


int splitExpression(string sIn);


struct sChar {

  int pos;
  int type;
};


class sExpression {

  private:
    string s;
    list <sExpression*> argqueue;
    list <int> posqueue;
  
  public:
    string delims = "() ";

    sExpression();
    sExpression(string sIn);
    ~sExpression();

    string getS();
    void setS(string s1);
    void printS();

    int read();
    int eval();
    int print();
    int repl();

    list <sExpression*> getQueue();

    int splitExpression();
    vector <vector <string>> splitExpression(char* sIn, int len, int start, int end);
    int NewSplitExpression();

};

#endif