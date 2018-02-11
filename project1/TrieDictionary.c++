
#include <iostream>
#include <string>
#include <map>

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
  std::map <char, int> alphabet;
  std::map <char, int>::iterator it;

  TrieDictionary()
  {
    m_root = new Node();
    init();
  }

  void init()
  { //didnt want to write a loop lol
    alphabet.insert(std::pair <char, int> ('a',0)); alphabet.insert(std::pair <char, int> ('b',1));
    alphabet.insert(std::pair <char, int> ('c',2)); alphabet.insert(std::pair <char, int> ('d',3));
    alphabet.insert(std::pair <char, int> ('e',4)); alphabet.insert(std::pair <char, int> ('f',5));
    alphabet.insert(std::pair <char, int> ('g',6)); alphabet.insert(std::pair <char, int> ('h',7));
    alphabet.insert(std::pair <char, int> ('i',8)); alphabet.insert(std::pair <char, int> ('j',9));
    alphabet.insert(std::pair <char, int> ('k',10)); alphabet.insert(std::pair <char, int> ('l',11));
    alphabet.insert(std::pair <char, int> ('m',12)); alphabet.insert(std::pair <char, int> ('n',13));
    alphabet.insert(std::pair <char, int> ('o',14)); alphabet.insert(std::pair <char, int> ('p',15));
    alphabet.insert(std::pair <char, int> ('q',16)); alphabet.insert(std::pair <char, int> ('r',17));
    alphabet.insert(std::pair <char, int> ('s',18)); alphabet.insert(std::pair <char, int> ('t',19));
    alphabet.insert(std::pair <char, int> ('u',20)); alphabet.insert(std::pair <char, int> ('v',21));
    alphabet.insert(std::pair <char, int> ('w',22)); alphabet.insert(std::pair <char, int> ('x',23));
    alphabet.insert(std::pair <char, int> ('y',24)); alphabet.insert(std::pair <char, int> ('z',25));
  }

  // If not present, inserts key into trie
  // If the key is prefix of trie node, just
  // marks leaf node
  void insert(std::string key)
  {
      Node* traverse = m_root;
      int index;

      for (int i = 0; i < key.length(); i++)
      {
          index = alphabet.find(key[i]) -> second;
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

//     int n = sizeof(keys)/sizeof(keys[0]);
