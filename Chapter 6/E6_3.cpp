#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

struct tnode {
  char *word;
  int count;
  tnode *left;
  tnode *right;
};

// Function prototypes
void treeprint(tnode *p);
tnode *makeNode();
void freeTree(tnode *root);
tnode *addtree(tnode *p, char *w);
vector<string> getWord(const char *str);
void printWords(const char *str);

/**
 * Currently we can read from the file and store the words in a vector.
 * 
 */


int main()
{
  FILE *file = fopen("C:/Users/ajrob/Desktop/Bagel.txt", "r");
  if (file == NULL) { perror("Error opening file"); return 1; }

  char str[100];
  fgets(str, 100, file);

  vector<string>document = getWord(str);
  // how do I print the words in the document?
  for (int i = 0; i < document.size(); i++) cout << document[i] << endl;

  
  
  fclose(file);

  return 0;
}


void treeprint(tnode *p)
{
  if (p != NULL)
    {
      treeprint(p->left);
      std::cout << p->count << p->word;
      treeprint(p->right);
    }
}

tnode *makeNode()
{
  return new tnode;
}
// Function to deallocate the entire tree
void freeTree(tnode *root) 
{
  if (root != nullptr) 
    {
      freeTree(root->left);
      freeTree(root->right);
      delete root;
    }
}

tnode *addtree(tnode *p, char *w)
{
  int cond;

  if (p == nullptr)
   {
      p = makeNode();
      p->word = strdup(w);
      p->count = 1;
      p->left = p->right = nullptr;
   }
  else if (cond = strcmp(w, p->word) == 0) p->count++;
  else if (cond < 0) p->left = addtree(p->left, w);
  else p->right = addtree(p->right, w);
  return p;
}

vector<string> getWord(const char * str)
{
  vector<string>words; // create a string vector to save the words to
  stringstream ss(str); // create a stringstream object to read from the string
  string word; // create a word string to save a word to
  while (ss >> word) words.push_back(word);
  return words;
}



/**
 * If the tnode we passed into the tree doesn't point to anything, we create a new node and assign the word to it.
 * If the word is the same as the word in the node, we increase the count.
 * If the word is less than the word in the node, we recursively call the function with the left node.
 * We're now back at the top of the function(nth). First we check to see if p(left) is pointing to anything.
 * If p(left) is not pointing at anything, we can then create a new node (on the left) and assign a word to it. 
 * The rest is skipped and we return p.
 * The previous node's left pointer will now point to the new node. 
 * We skip p->right statement and return p.
 * We're now back to the first fucntion call. The rest is skipped and we return p.
 */
