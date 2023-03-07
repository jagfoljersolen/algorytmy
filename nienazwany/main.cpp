#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;


void przydzielPamiec1D(int *&tab, int n)
{
    tab=new int[n];
}
void przydzielPamiec2D(int**&tab, int w, int k)
{
    tab = new int*[w];
    for(int i = 0; i<2; i++){
        tab[i] = new int[k];
    }

}
void wypelnijTablice1D(int *tab, int n, int a, int b)
{
    for(int i = 0; i<n; i++)
    {
        tab[i]= rand()%(b-a+1)+a;
    }

}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b)
{
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            tab[i][j]=rand()%(b-a+1)+a;
        }
    }
}
void usunTablice1D(int *&tab)
{
    delete []tab;
}
void usunTablice2D(int **&tab, int w)
{
    for(int i = 0; i<w; i++ ){
        delete [] tab[i];
    }
    delete [] tab;
}
void wyswietl1D(int* tab, int n)
{
    for(int i = 0; i<n; ++i)
    {
        cout<<tab[i];
    }
    cout<<endl;
}
void wyswietl2D(int** tab, int w, int k)
{
    for(int i=0; i<w; ++i){
        for(int j=0; j<k; ++j){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    srand(time(NULL));
    int n = 4;
    int* tab1=nullptr;
    cout<<"TABLICA JEDNOWYMIAROWA"<<endl;
    przydzielPamiec1D(tab1,n);
    int a = 1;
    int b = 8;
    wypelnijTablice1D(tab1,n,a,b);
    wyswietl1D(tab1,n);
    usunTablice1D(tab1);


    int w = 2;
    int k = 3;

    cout<<"TABLICA DWUWYMIAROWA"<<endl;
    int **tab2=nullptr;
    przydzielPamiec2D(tab2, w, k);
    wypelnijTablice2D(tab2,w,k,a,b);
    wyswietl2D(tab2,w,k);
    usunTablice2D(tab2,w);

    int c;
    cout<<"wybierz opcje 1-4:";
    cin>>c;

    switch(c){
    case 1:
    {
        cout<<"minimalny element"<<endl;
        cout<<"podaj rozmiar tablicy"<<endl;
        cin>>n;
        przydzielPamiec1D(tab1,n);
        cout<<"podaj zakres od a do b"<<endl;
        cout<<"a= ";
        cin>>a;
        cout<<endl;
        cout<<"b= ";
        cin>>b;
        cout<<endl;
        wypelnijTablice1D(tab1,n,a,b);

        int min = tab1[0];
        cout<<"min= "<<min<<endl;
        for(int i = 0; i<n; ++i)
        {
            if (tab1[i]<min){
                min = tab1[i];
            }

        }
        for(int i = 0; i<n; i++)
        {
            cout<<tab1[i];
            cout<<" ";
        }
        cout<<endl;
        usunTablice1D(tab1);
        cout<<"min= " <<min<<endl;

        //sprawdzam czy min jest liczbą pierwszą
        bool pierwsza = true;
        if(min<=1){
            pierwsza = false;
        }
        for(int i = 2; i<=n/2; i++)
        {
            if(n%i==0){

                pierwsza = false;
                break;
            }
        }
        if(pierwsza){
            cout<<min<<" jest liczba pierwsza"<<endl;
        }else{
            cout<<min<<" nie jest liczba pierwsza"<<endl;
        }


        break;
    }
    case 2:
    {
        cout<<"zliczanie elementow tablicy"<<endl;
        cout<<"podaj rozmiar tablicy"<<endl;
        cin>>n;
        przydzielPamiec1D(tab1,n);
        wypelnijTablice1D(tab1,n,0,9);
        int counts[10] = {0}; // tablica zliczająca wystąpienia każdej cyfry (0-9)

           // wypełnienie tablicy losowymi liczbami
           srand(time(nullptr));
           for (int i = 0; i < n; i++) {
               tab1[i] = rand() % 10; // losowanie liczby z przedziału <0, 9>
           }
           for(int i = 0; i<n; ++i)
           {
               cout<<tab1[i];
               cout<<endl;
           }
           cout<<endl;

           // zliczenie wystąpień każdej cyfry w tablicy
           for (int i = 0; i < n; i++) {
               counts[tab1[i]]++;
           }

           usunTablice1D(tab1);

           // wyświetlenie wyniku
           for (int i = 0; i < 10; i++) {
               cout << "Cyfra " << i << " - " << counts[i] << " razy" << endl;
           }
        break;
    }
    case 3:{

        cout<<"maksymalny element"<<endl;
        cout<<"podaj liczbę wierszy"<<endl;
        cin>>w;
        cout<<"podaj liczbę kolumn"<<endl;
        cin>>k;
        przydzielPamiec2D(tab2,w,k );
        cout<<"podaj zakres od a do b"<<endl;
        cout<<"a= ";
        cin>>a;
        cout<<endl;
        cout<<"b= ";
        cin>>b;
        cout<<endl;
        wypelnijTablice2D(tab2,3,5,1,9);
        wypelnijTablice2D(tab2,w,k,a,b);
        wyswietl2D(tab2,w,k);
        int maks = tab2[0][0];
        for(int i=0; i<w; i++){
            for(int j=0; j<k; j++){
                if(tab2[i][j]>maks){
                    maks = tab2[i][j];
                }
            }
        }
        usunTablice2D(tab2,w);
        cout<<"maks= "<<maks<<endl;
        int suma = 0;
        while(maks!=0){
            suma += maks%10;
            maks = maks/10;
        }
        cout<<"suma = "<<suma<<endl;


        break;
    }
    case 4:{
        cout<<"srednia"<<endl;
        cout<<"podaj rozmiar"<<endl;
        int w;
        cin>>w;


        przydzielPamiec2D(tab2,w,w);
        wypelnijTablice2D(tab2,w,w,7,122);
        wyswietl2D(tab2,w,w);
        int suma_nad = 0, ilosc_nad = 0;
        int suma_pod = 0, ilosc_pod =0;

        for(int i=0; i<w;++i){
            for(int j=0;j<w;++j){
                if(j>i){
                    suma_nad+=tab2[i][j];
                    ++ilosc_nad;
                }
                else if(j<i){
                    suma_pod += tab2[i][j];
                    ++ilosc_pod;
                }
            }
        }
        usunTablice2D(tab2,w);
        double srednia_nad = (double)suma_nad/ilosc_nad;
        double srednia_pod = (double)suma_pod/ilosc_pod;

        cout << "srednia elementów nad przekatna: " << srednia_nad << endl;
        cout << "srednia elementów pod przekatna: " << srednia_pod << endl;



        break;
    }
    }


}


