/***************************************************************************************************************
* NOTE Algorithms for this data structure were read from https://www.geeksforgeeks.org/trie-insert-and-search/                                                            *
*      I modified to make a class and use as an implemntation of a dictionary with efficient searching operation
* NOTE The destructor was written by me, not taken from the website
*
*****************************************************************************************************************/
#include <string>
#include <map>

#ifndef TRIEDICTIONARY
#define TRIEDICTIONARY

class TrieNode
{
  public:
    TrieNode()
    {
      isLeaf = false;
      for (int i=0; i<26; i++)
        subtries[i] = nullptr;
    }

    TrieNode* subtries[26];
    bool isLeaf;
};

class TrieDictionary
{

public:

  TrieNode* m_root;
  std::map <char, int> alphabet;

  TrieDictionary()
  {
    m_root = new TrieNode();
    init();
  }

  ~TrieDictionary()
  {
    deleteTrie(m_root);
  }

  void init()
  {
    char a = 'a';

    for(int i=0; i<26; i++, a++)
      alphabet.insert(std::pair <char, int> (a,i));
  }

  void insert(std::string key)
  {
      TrieNode* traverse = m_root;
      int index;

      for (int i = 0; i < key.length(); i++)
      {
          index = alphabet.find(key[i]) -> second;
          if (traverse->subtries[index] == nullptr)
          {
            traverse->subtries[index] = new TrieNode();
          }
          traverse = traverse->subtries[index];
      }
      traverse->isLeaf = true;
  }

  bool search(std::string key)
  {
      TrieNode* traverse = m_root;
      int index;

      for (int i = 0; i < key.length(); i++)
      {
          index = alphabet.find(key[i]) -> second;
          if (traverse->subtries[index] == nullptr)
              return false;

          traverse = traverse->subtries[index];
      }
      return ((traverse != nullptr) && traverse->isLeaf);
  }

  void deleteTrie(TrieNode* subtrie) //used for destructor
  {
    if(subtrie == nullptr)
      return;

    for(int i = 0; i<26; i++)
      deleteTrie(subtrie->subtries[i]);

    delete subtrie;
  }
};

#endif
