#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int rozmiar = 20;


void gen_g(int G[rozmiar][rozmiar]);
void wyswietlanie(int G[rozmiar][rozmiar]);
void initializeSingleSource(int G[rozmiar][rozmiar], int rozmiar);
void relax(int u, int v, int w);
int extractMin(int Q[rozmiar], int rozmiar)
{
    int tempMin = Q[0];
    for(int i = 1; i<rozmiar; i++)
    {
        if( Q[i] < tempMin)
            tempMin = i;
    }
    return tempMin;
}
void Dijkstra(int G[rozmiar][rozmiar], int s, int rozmiar)
{
    int Q=rozmiar, S=0;
    initializeSingleSource(G,s);
    while(Q != 0)
    {
        u = extractMin(Q, rozmiar);
        S ++;
        Q --;
        for(int i = 0; i<rozmiar; )
        {
            relax()
        }
    }
}


int main()
{
    int G [rozmiar][rozmiar];
    gen_g(G);
    wyswietlanie(G);

    system ("pause");
    return 0;
}

/*
*   D[]     - tablica zawieraj¹ca odleg³oœci wierzcho³ków
*   Pi[]    - tablica zawieraj¹ca rodziców
*
*/
void initializeSingleSource(int G[rozmiar][rozmiar], int rozmiar)
{
    int D[rozmiar], Pi[rozmiar];
    for(int i = 0; i<rozmiar; i++)
    {
        D[i] = 10000;   //oznaczenie nieskoñczonoœci
        Pi[i] = -10;    //oznaczenie pustego NIL
    }
    D[rozmiar-1] = 0;
}

/*
*   FUNKCJA
*   u - wierzcho³ek do którego jest najmniejsza odleg³oœæ
*   v -
*   w - waga krawêdzi pomiedzy wierzcho³kami u i v
*/
void relax(int u, int v, int Pi[], int D[])
{
    int W[u][v];
    if(D[v] > D[u] + W[u][v])
    {
        D[v] = D[u] + W[u][v];
        Pi[v] = u;
    }
}

void gen_g(int G[rozmiar][rozmiar])
{
    //generowanie liczb pseudolosowych
    for(int i=0; i<rozmiar; i++){
        for(int j=0; j<rozmiar; j++ )
        {
            if(i==j)
            {
                G[i][j] = 0;
            }
            else
            {
                int x = rand()%2;
                if (x==0){
                    G[i][j] = x;
                }
                else
                {
                    G[i][j] = rand()%100+1;
                }
            }
        }
    }
}

void wyswietlanie(int G[rozmiar][rozmiar])
{
    //numeracja kolumn
    cout<<"      ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    for (int a=0; a<rozmiar; a++)
    {
        cout.width( 3 );
        cout << a <<" ";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<endl<<endl;

    //wyœwietlenie grafu
    for(int i=0; i<rozmiar; i++)
    {
        //numeracja wierszy
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
        cout.width( 4 );
        cout<<i<<"  ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

        //wyœwietlenie grafu
        for(int j=0; j<rozmiar; j++ )
        {
                cout.width( 3 );
                cout << G[i][j] <<" ";
        }
        cout << endl<<endl;
    }
    cout <<endl<<endl;
}

