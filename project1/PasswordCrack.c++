

#include <iostream>
#include <string>
#include <algorithm>

char chars[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


std::string vigenereEncrypt(std::string key, std::string plaintext)
{
  //std::cout<<"\nbefore processing: "<<plaintext;

  transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower); //convert to lowercase
  plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), isspace), plaintext.end()); //remove spaces

//  std::cout<<"\nafter processing: "<<plaintext<<"\n";

  std::string ciphertext;
  int x;

  for(int i = 0, j = 0; i < plaintext.size(); i++)
  {
    x = ((plaintext[i]-97) + (key[j]) - 97) % 26; //encryption formula, corrects for ascii values

    // std::cout<<"\nplaintext["<<i<<"]: " << plaintext[i]
    //          <<"\nkey["<<j<<"]: " << key[j]
    //          <<"\nx: "<<x
    //          <<"\nEncrypted letter: "<<chars[x]<<"\n";

    j = (j+1) % key.size();

    ciphertext.push_back(chars[x]);
  }

  return ciphertext;
}

std::string vigenereDecrypt(std::string key, std::string ciphertext)
{
  std::string plaintext;

  for(int i =0, j=0; i<ciphertext.size(); i++)
  {
    int x = ((ciphertext[i] - 97) - (key[j]-97) + 26) % 26;

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


std::string key1 = "eecs";

int main(int argc, char** argv)
{
  if (argc > 1)
  {
    std::string s = vigenereEncrypt(key1, getPlaintext(argc, argv));
    std::cout<<s<<'\n';
    std::cout<<"decrypt: "<<vigenereDecrypt(key1, s)<<"\n";
  }
  else
  {
    std::cout<<"\nUsage: ./project1 <plaintext string>\n";
  }
  return 0;

}
