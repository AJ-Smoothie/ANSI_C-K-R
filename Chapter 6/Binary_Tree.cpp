#include <iostream>
using namespace std;

struct tnode {
  char *word;
  int count;
  tnode *left;
  tnode *right;
};

/*
          Jax
        /    \
      Wax    Fax
    /    \
  Axe   Sax


          Jax
        /    \
      Wax    Fax

*/

// tree print: in-order print of tree p
void treeprint(tnode *p)
{
  if (p != NULL)
    {
      treeprint(p->left);
      cout << p->count << p->word;
      treeprint(p->right);
    }
}