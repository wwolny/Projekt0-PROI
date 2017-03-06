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
    int flag, i=0;
    do
    {
        flag=(str1[i]==str2[i]);
    }
    while(flag && str1[i]!=0 && str2[i++]!=0);
    return flag;

}

void LaczSlowa(char* chrwynik, char* chr1, char* chr2, int chr1len, int chr2len) //funkcja wypisuje polaczone dwa ciagi znakow,
//gdzie najpierw wypisane jest drugi ciag bez pierwszego znaku, a pozniej wypisuje drugi ciąg bez ostatniego znaku
{
    int intDl, i=1;
    intDl=chr1len+chr2len-2; //dlugosc wyniku

    for(i=1; i<chr2len; i++) //Zaczynamy od 1 bo nie chcemy w wyniku miec pierwszego znaku drugiego slowa
    {
            chrwynik[i-1]=chr2[i];
    }

    for (i=chr2len-1; i<intDl; i++)
    {
            chrwynik[i]=chr1[i-chr2len+1];
    }
}


int main()
{
    char chr1[100];
    char chr2[100];

    cout<<"Podaj pierwsze slowo, ktore straci ostatnia litere i pojdzie na drugie miejsce: "<<endl;
    cin>>chr1;
    cout<<"Podaj drugie slowo, ktore straci pierwsza litere i pojdzie na pierwsze miejsce: "<<endl;
    cin>>chr2;

    int intDl, intDl1, intDl2;
    intDl1=mystrlen(chr1);
    intDl2=mystrlen(chr2);
    intDl=intDl1+intDl2-2;//dlugosc wyniku (bez dwoch znakow)

    cout<<"Dlugosc ciagu znakowego"<<chr1<<" wynosi"<<intDl1<<endl;
    cout<<"Dlugosc ciagu znakowego"<<chr2<<" wynosi"<<intDl2<<endl;

    char *chrwynik;
    chrwynik=(char*)malloc(intDl*sizeof(char)+1); //przydzielenie pamieci wynikowi
    LaczSlowa( chrwynik, chr1, chr2, intDl1, intDl2);
    cout<<"wynik to: "<<chrwynik;
    free(chrwynik); //uwolnienie pamieci
    return 0;
}

