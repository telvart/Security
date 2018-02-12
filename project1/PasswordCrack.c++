
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <thread>

#include "TrieDictionary.c++"
#include "SyncQueue.hpp"

char chars[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

std::string vigenereEncrypt(std::string key, std::string plaintext)
{
  transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower); //convert to lowercase
  plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), ::isspace), plaintext.end()); //remove spaces

  std::string ciphertext;
  int x;

  for(int i = 0, j = 0; i < plaintext.size(); i++)
  {
    x = ((plaintext[i]-97) + (key[j]) - 97) % 26; //encryption formula, corrects for ascii values
    j = (j+1) % key.size();

    ciphertext.push_back(chars[x]);
  }
  return ciphertext;
}

std::string vigenereDecrypt(std::string key, std::string ciphertext)
{
  std::string plaintext;
  int x;

  for(int i =0, j=0; i<ciphertext.size(); i++)
  {
    x = ((ciphertext[i] - 97) - (key[j]-97) + 26) % 26;
    j = (j+1) % key.size();

    plaintext.push_back(chars[x]);
  }

  return plaintext;
}

std::string getPlaintext(int argc, char** argv)
{
  std::string plaintext;
  for(int i=1; i<argc; i++)
  {
    if(i != argc-1)
    {
      plaintext = plaintext + argv[i] + " ";
    }
    else
    {
      plaintext = plaintext + argv[i];
    }
  }
  return plaintext;
}

TrieDictionary pullWords(int wordlength)
{
  std::ifstream fileIn("dict.txt");
  std::string temp;
  TrieDictionary dic = TrieDictionary();
  while(fileIn >> temp)
  {
    if(temp.length() == wordlength)
    {
      transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
      dic.insert(temp);
    }
  }
  fileIn.close();
  return dic;
}

void generateKeysRec(std::string prefix, int keyLength, SyncQueue<std::string>* q2)
{
  if (keyLength == 0)
  {
    q2->enqueue(prefix);
    return;
  }

  for(int i=0; i<26; ++i)
  {
    std::string temp = prefix + chars[i];
    generateKeysRec(temp, keyLength-1, q2);
  }
}

void generateKeys(int keyLength, SyncQueue<std::string>* q)
{
  generateKeysRec("", keyLength, q);
}

void breakingThread(std::string key, std::string ciphertext)
{

}

void breakCipher(int keyLength, int firstWordLength, std::string ciphertext)
{
  transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::tolower);
  std::string firstWord = ciphertext.substr(0, firstWordLength);

  TrieDictionary dic = pullWords(firstWordLength);
  SyncQueue<std::string>* buffer = new SyncQueue<std::string>();
  generateKeys(keyLength, buffer);

  while(!buffer->empty())
  {
    std::string key = buffer->dequeue();
    std::string temp = vigenereDecrypt(key, firstWord);
     if(dic.search(temp) == true)
     {
       std::cout<<vigenereDecrypt(key, ciphertext)<<"\n";
     }
  }
}

int main(int argc, char** argv)
{

    breakCipher(2, 6, "MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX");
    //breakCipher(3, 7, "OOPCULNWFRCFQAQJGPNARMEYUODYOUNRGWORQEPVARCEPBBSCEQYEARAJUYGWWYACYWBPRNEJBMDTEAEYCCFJNENSGWAQRTSJTGXNRQRMDGFEEPHSJRGFCFMACCB");
    //breakCipher(4, 10, "MTZHZEOQKASVBDOWMWMKMNYIIHVWPEXJA");
    //breakCipher(5, 11, "HUETNMIXVTMQWZTQMMZUNZXNSSBLNSJVSJQDLKR");
    //breakCipher(6, 9, "LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS");
    //breakCipher(7, 13, "VVVLZWWPBWHZDKBTXLDCGOTGTGRWAQWZSDHEMXLBELUMO");

    //NOTE do not run with 6 or 7 currently

  //  std::cout<<"\nUsage: ./project1 <plaintext string>\n";

  return 0;
}
