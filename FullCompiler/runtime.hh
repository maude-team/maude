#define MAX_NR_ARGS	20

struct Flags
{
  unsigned int sortIndex : 16;
  unsigned int evacuated : 1;
};

struct Node
{
  union
  {
    int symbol;
    Node* fwd;
  };
  Flags flags;
  Node* args[0];
};

union Link
{
  Link* l;
  int i;
  Node* n;
};

struct Context
{
  long long count;
  Link* safePtr;
  char* memNext;
  char* memEnd;
  int nrArgs;
  Node* args[MAX_NR_ARGS];
};

void collectGarbage();
int compare(Node*, Node*);
Node* eval(Node*);

extern Context g;
extern const char inFileName[];
extern const char outFileName[];
