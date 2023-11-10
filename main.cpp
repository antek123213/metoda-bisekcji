#include <iostream>
#include <cmath>
#include<string>
#include<iomanip>

using namespace std;

double f(double x,double st,double a[])
{
    double wynik=0;
    for(int i=st; i>=0; i--)
    {
        wynik+=pow(x,i)*a[i];
    }
    return wynik;
}

double zabezpiecz_boga()
{
    bool kupa=false;
    string s;
    double k;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        k++;
        if(s[i]>=48&&s[i]<=57||s[i]=='.'||s[i]=='-')
        {
            kupa=true;
        }
        else
        {
            kupa=false;
            break;
        }
    }
    if(kupa==false)
    {
        cout<<"Bledne dane podaj jeszcze raz: ";
        zabezpiecz_boga();
    }
    else
    {
        k=stof(s);
    }
    return k;
}

int main()
{
    cout<<"Program uzywa metody bisekcji."<<endl<<"Podaj stopien wielomianu: ";
    int st=zabezpiecz_boga();
    if(st>=1&&st<=5)
    {
        double a[st];
        cout<<"Podaj wspolczynik a1: ";
        a[0]=zabezpiecz_boga();
        while(a[0]==0)
        {
            cout<<"Pierwszy wspolczynnik nie moze byc zerem podaj jeszcze raz: ";
            a[0]=zabezpiecz_boga();
            cout<<a[0];
        }
        for(int i=1; i<=st; i++)
        {
            cout<<"Podaj a"<<i+1<<": ";
            a[i]=zabezpiecz_boga();
            cout<<a[i];

        }
        double p,k,dok;
        cout<<"Podaj poczatek przedzialu: ";
        p=zabezpiecz_boga();
        cout<<"Podaj koniec przedzialu: ";
        k=zabezpiecz_boga();
        if(p>k)
        {
            swap(p,k);
            cout<<"Zamienilem przedzial"<<endl;
        }
        cout<<"Podaj dokladnosc: ";
        dok=zabezpiecz_boga();
        int n=0;
        double l=dok;
        while(l<=1)
        {
            n++;
            l*=10;
        }
        if(f(k,st,a)*f(p,st,a)<0)
        {
            int ile=0;
            double x;
            while(fabs(k-p)>dok)
            {
                ile++;
                x=(p+k)/2.0;
                if(f(p,st,a)*f(x,st,a)<=dok)
                    k=x;
                else if(f(k,st,a)*f(x,st,a)<=dok)
                    p=x;
                else
                {
                    break;
                }

            }
            cout<<"Miejsce zerowe to: ";
            cout<<setprecision(n)<<p<<endl;
            cout<<"Ilosc iteracji to: "<<ile;

        }
        else if(f(p,st,a)*f(k,st,a)<=dok)
        {
            if(f(p,st,a)<=dok)
            {
                cout<<"Miejsce zerowe to: ";
                cout<<setprecision(n)<<p;
            }
            else
            {
                cout<<"Miejsce zerowe to: ";
                cout<<setprecision(n)<<k;

            }
        }
        else
            cout<<"Funkcja nie ma miejsca zerowego";

    }

}
