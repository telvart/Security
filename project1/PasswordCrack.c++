
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <thread>
#include <mutex>

#include "TrieDictionary.c++"

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

void generateKeysRec(std::string prefix, int keyLength)
{
  if (keyLength == 0)
  {
    std::cout<<prefix<<"\n";
    return;
  }

  for(int i=0; i<26; ++i)
  {
    std::string temp = prefix + chars[i];
    generateKeysRec(temp, keyLength-1);
  }
}

void generateKeys(int keyLength)
{
  generateKeysRec("", keyLength);
}

void breakCipher(int keyLength, int firstWordLength, std::string ciphertext)
{
  TrieDictionary d = pullWords(firstWordLength);
}

/*
1. "MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX";

key length = 2; firstWordLength = 6

2. "OOPCULNWFRCFQAQJGPNARMEYUODYOUNRGWORQEPVARCEPBBSCEQYEARAJUYGWWYACYWBPRNEJBMDTEAEYCCFJNENSGWAQRTSJTGXNRQRMDGFEEPHSJRGFCFMACCB"

keyLength=3; firstWordLength = 7

3. "MTZHZEOQKASVBDOWMWMKMNYIIHVWPEXJA"

keyLength=4; firstWordLength = 10

4. "HUETNMIXVTMQWZTQMMZUNZXNSSBLNSJVSJQDLKR"

keyLength=5; firstWordLength = 11

5. "LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS"

keyLength=6; firstWordLength = 9

6. "VVVLZWWPBWHZDKBTXLDCGOTGTGRWAQWZSDHEMXLBELUMO"

keyLength=7; firstWordLength = 13
*/

int main(int argc, char** argv)
{

  //if (argc > 1)
  //{
    //std::string s = vigenereEncrypt(key1, getPlaintext(argc, argv));
    //std::cout<<s<<'\n';
    //std::cout<<"decrypt: "<<vigenereDecrypt(key1, s)<<"\n";

    //breakCipher(2, 6, "hello");
    generateKeys(7);

  //}
  //else
  //{
  //  std::cout<<"\nUsage: ./project1 <plaintext string>\n";
  //}
  return 0;

}
