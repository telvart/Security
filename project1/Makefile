project1: PasswordCrack.o TrieDictionary.o
	g++ -g -Wall -std=c++11 -O3 -o project1 PasswordCrack.o TrieDictionary.o
PasswordCrack.o: PasswordCrack.c++
	g++ -g -Wall -std=c++11 -c -O3 PasswordCrack.c++
TrieDictionary.o: TrieDictionary.c++
	g++ -g -Wall -std=c++11 -c -O3 TrieDictionary.c++
clean:
	rm *.o project1
