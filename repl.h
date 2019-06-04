#include <string>
#include <list>

using namespace std;

int read();
int eval();
int print();
int repl();

class sExpression {

  private:
    string s;

  public:
    sExpression(string sIn);
    ~sExpression();
    list<string> queue;

  public: 
    string getS();
    void setS(string s1);
    void printS();
    list <string> getQueue();

};