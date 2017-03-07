//student: Wojciech Wolny Informatyka sem.1 grupa 5
//nr. albumu 283786
//wwolny@elka.pw.edu.pl
//prowadzacy: M. Modrzejewski
//				                Projekt 0
//                                  TESt
#include <iostream>
#include <stdlib.h>
using namespace std;

int mystrlen(char* str) //funkcja sprawdza dlugosc slowa
{
    int i=0;
    while(str[i++]!=0);
    return i-1;
}

int mystrcmp(char* str1, char* str2) //funkcja sprawdza czy slowa sa identyczne
{
    int flag=0, i=0;
    do
    {
        flag=(str1[i]==str2[i]);
    }
    while(flag && str1[i]!=0 && str2[i++]!=0);
    return flag;

}

void LaczSlowa(char* chrwynik, char* chr1, char* chr2, int chr1len, int chr2len) //funkcja wypisuje polaczone dwa ciagi znakow,
//gdzie najpierw wypisane jest drugi ciag bez pierwszego znaku, a pozniej wypisuje pierwszy ciąg bez ostatniego znaku
{
    int intDl=0;
    intDl=chr1len+chr2len-2; //dlugosc wyniku

    for(int i=1; i<chr2len; i++) //Zaczynamy od 1 bo nie chcemy w wyniku miec pierwszego znaku drugiego slowa
    {
            chrwynik[i-1]=chr2[i];
    }

    for (int i=chr2len-1; i<intDl; i++)
    {
            chrwynik[i]=chr1[i-chr2len+1];
    }
	chrwynik[intDl] = '\0';
}


int main()
{
    char* chr1=NULL;
    char* chr2=NULL;
    chr1=new char[100];
    chr2=new char[100];
    cout<<"Podaj pierwsze slowo, ktore straci ostatnia litere i pojdzie na drugie miejsce: "<<endl;
    cin>>chr1;
    cin.ignore(1000,'\n');
    cout<<"Podaj drugie slowo, ktore straci pierwsza litere i pojdzie na pierwsze miejsce: "<<endl;
    cin>>chr2;
    cin.ignore(1000,'\n');

    int intDl=0, intDl1=0, intDl2=0;
    intDl1=mystrlen(chr1);
    intDl2=mystrlen(chr2);
    intDl=intDl1+intDl2-2;//dlugosc wyniku (bez dwoch znakow)

    cout<<"Dlugosc ciagu znakowego \""<<chr1<<"\" wynosi: "<<intDl1<<endl;
    cout<<"Dlugosc ciagu znakowego \""<<chr2<<"\" wynosi: "<<intDl2<<endl;
	
    char *chrwynik = new char[intDl+1]; //przydzielenie pamieci wynikowi
    LaczSlowa(chrwynik, chr1, chr2, intDl1, intDl2);
    cout<<"wynik to: "<<chrwynik;
    delete [] chr1;
    delete [] chr2;
    delete [] chrwynik; //uwolnienie pamieci
	system("pause");
    return 0;
}

