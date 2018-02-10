
//NOTE: I did not write this code, it was taken from https://www.geeksforgeeks.org/trie-insert-and-search/
//NOTE: I modified to make it a class and use it to store the dictionary for the password cracking

// C++ implementation of search and insert
// operations on Trie

#include <iostream>
#include <string>
//#include "PasswordCrack.c++"
using namespace std;

const int ALPHABET_SIZE = 26;


char chars[26] =
{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s',
't','u','v','w','x','y','z'};


// trie node
struct TEMPORARY
{
    struct TEMPORARY *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    // x = chars[0];
    bool isEndOfWord;
};

class Node
{
  public:
    Node()
    {
      isEndOfWord = false;
      for (int i=0; i<26; i++)
        subtries[i] = nullptr;
    }

    Node* subtries[26];
    bool isEndOfWord;
};


class TrieDictionary
{

public:

  Node* m_root;

  TrieDictionary()
  {
    m_root = getNode();
  }

  // Returns new trie node (initialized to NULLs)
  Node* getNode()
  {
      // Node* temp =  new Node();
      //
      // pNode->isEndOfWord = false;
      //
      // for (int i = 0; i < ALPHABET_SIZE; i++)
      //     pNode->children[i] = NULL;

      return new Node();
  }

  // If not present, inserts key into trie
  // If the key is prefix of trie node, just
  // marks leaf node
  void insert(std::string key)
  {
      Node* traverse = m_root;

      for (int i = 0; i < key.length(); i++)
      {
          int index = key[i] - 'a';
          std::cout<<"key["<<i<<"]"<<key[i]
                   <<"   index:"<<index<<"\n";
          if (traverse->subtries[index] == nullptr)
          {
            traverse->subtries[index] = new Node();
          }
          traverse = traverse->subtries[index];
      }

      // mark last node as leaf
      traverse->isEndOfWord = true;
  }

  // Returns true if key presents in trie, else
  // false
  bool search(std::string key)
  {
      Node* traverse = m_root;

      for (int i = 0; i < key.length(); i++)
      {
          int index = key[i] - 97;
          if (traverse->subtries[index] == nullptr)
              return false;

          traverse = traverse->subtries[index];
      }

      return ((traverse != nullptr) && traverse->isEndOfWord);
  }


};


// int main()
// {
//     // Input keys (use only 'a' through 'z'
//     // and lower case)
//     string keys[] = {"the", "a", "there",
//                     "answer", "any", "by",
//                      "bye", "their" };
//     int n = sizeof(keys)/sizeof(keys[0]);
//
//     struct TEMPORARY *root = getNode();
//
//     // Construct trie
//     for (int i = 0; i < n; i++)
//         insert(root, keys[i]);
//
//     // Search for different keys
//     search(root, "the")? cout << "Yes\n" :
//                          cout << "No\n";
//     search(root, "these")? cout << "Yes\n" :
//                            cout << "No\n";
//     return 0;
// }
