
#include <iostream>
#include <string>
#include <map>

class TrieNode
{
  public:
    TrieNode()
    {
      isEndOfWord = false;
      for (int i=0; i<26; i++)
        subtries[i] = nullptr;
    }

    TrieNode* subtries[26];
    bool isEndOfWord;
};

class TrieDictionary
{

public:

  TrieNode* m_root;
  std::map <char, int> alphabet;
  std::map <char, int>::iterator it;

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
  // If the key is prefix of trie TrieNode, just
  // marks leaf TrieNode
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

      // mark last TrieNode as leaf
      traverse->isEndOfWord = true;
  }

  // Returns true if key presents in trie, else
  // false
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
      return ((traverse != nullptr) && traverse->isEndOfWord);
  }

  void deleteTrie(TrieNode* subtrie)
  {
    if(subtrie == nullptr)
      return;

    for(int i = 0; i<26; i++)
    {
      deleteTrie(subtrie->subtries[i]);
    }
    delete subtrie;

  }

};

//     int n = sizeof(keys)/sizeof(keys[0]);
