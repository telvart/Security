
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
    char a = 'a';
    for(int i=0; i<26; i++, a++)
    {
      alphabet.insert(std::pair <char, int> (a,i));
    }
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
      deleteTrie(subtrie->subtries[i]);

    delete subtrie;

  }

};
