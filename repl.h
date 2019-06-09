#ifndef REPL

#define REPL

#include <string>
#include <list>

using namespace std;


int splitExpression(string sIn);


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
    int splitExpression(char* sIn, int len, int depth);
    int NewSplitExpression();

};

#endif