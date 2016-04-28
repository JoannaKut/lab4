#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string numberToNumeral(int n);
unsigned long long findK(int n);

int main(int argc, char *argv[])
{
	int n=atoi(argv[1]);
	unsigned long long k=findK(n);

	cout << "Wprowadzona liczba naturalna n = " << n <<"\t czytaj:  " << numberToNumeral(n) << endl;
	cout << "znalezione k = " << k <<"\t czytaj:  " << numberToNumeral(k) << endl;
	cout << "wynik iloczynu n*k = " << k*n <<"\t czytaj:  " << numberToNumeral(n*k) << endl; cout << endl;
}

string numberToNumeral(int n)
{
	int digit[6];

	if (n<1 || n>999999)
	{
		if (n==0) return("zero");
		else if (n==1000000) return("milion");
		else printf("Podana liczba poza zakresem");
		exit;
	} 

	for (int i=0; i<6; i++)
	{
		digit[i]=n%10;
		n/=10;
	}	

	string 	unities[]={"","jeden ","dwa ","trzy ","cztery ","piec ","szesc ","siedem ","osiem ","dziewiec "};
	string 	teens[]={"dziesiec ","jedenascie ","dwanascie ","trzynascie ","czternascie ","pietnascie ","szesnascie ","siedemnascie ","osiemnascie ","dziewietnascie "};
	string 	tens[]={"","","dwadziescia ","trzydziesci ","czterdziesci ","piecdziesiat ","szescdziesiat ","siedemdziesiat ","osiemdziesiat ","dziewiecdziesiat "};
	string	hundreds[]={"","sto ","dwiescie ","trzysta ","czterysta ","piecset ","szescset ","siedemset ","osiemset ","dziewiecset "};
	string	thousands[]={"","tysiac ","tysiace ","tysiecy "};

	string word1, word2, word3, word4, word5, word6, thousand;

	for (int i=0; i<10; i++)
	{
		if (digit[5]==i) word1=hundreds[i];
		if (digit[2]==i) word4=hundreds[i];

		if (digit[4]==1)
		{
			word2=tens[0];
			if (digit[3]==i) 
				{
					word3=teens[i];
				}
		}
		else if (digit[4]==i)
		{
			word2=tens[i];
			for (int j=0; j<10; j++)
				if (digit[3]==j) word3=unities[j];
		}

		if (digit[1]==1)
		{
			word5=tens[0];
			if (digit[0]==i) 
				{
					word6=teens[i];
				}
		}
		else if (digit[1]==i)
		{
			word5=tens[i];
			for (int j=0; j<10; j++)
				if (digit[0]==j) word6=unities[j];
		}
	}
	if (digit[5]==0 && digit[4]==0 && digit[3]==0)
		thousand=thousands[0];
	else if (digit[5]==0 && digit[4]==0 && digit[3]==1)
		thousand=thousands[1];
	else if (digit[4]!=1 && (digit[3]==2 || digit[3]==3 || digit[3]==4))
		thousand=thousands[2];
	else
		thousand=thousands[3];

	return word1+word2+word3+thousand+word4+word5+word6;
}

unsigned long long findK(int n)
{
	for (unsigned long long k=1; ; k++) 
	{
		unsigned long long result=n*k;

		while (result%10==0 || result%10==1 ) 
		{
			if (result==0 || result==1) 
				return k;
			else 
				result/=10;
		}
	}
}