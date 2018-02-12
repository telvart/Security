project1: PasswordCrack.o TrieDictionary.o
	g++ -g -std=c++11 -lpthread -O3 -o project1 PasswordCrack.o TrieDictionary.o
PasswordCrack.o: PasswordCrack.c++
	g++ -g -std=c++11 -c -O3 PasswordCrack.c++
TrieDictionary.o: TrieDictionary.c++
	g++ -g -std=c++11 -c -O3 TrieDictionary.c++
clean:
	rm *.o project1
