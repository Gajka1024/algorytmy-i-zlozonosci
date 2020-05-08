#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

void gen_los(int tablica[], int rozmiar);
void sort_select(int tablica[], int rozmiar);
void wyswietlanie(int tablica[], int rozmiar);
void sort_insert(int tablica[], int rozmiar);
void merge(int pocz, int sr, int kon, int temp[], int tablica[]);
void mergesort(int pocz, int kon, int temp[], int tablica[]);
void sortowanie_przez_scalanie(int tablica[], int temp[], int rozmiar)
{
    mergesort(0, (rozmiar-1), temp, tablica);
}
void quicksort(int A[], int p, int r);
int partition(int A[], int p, int r);
int left(int i);
int right(int i);
int build_heap(int A[], int rozmiar);
int heap_sort(int A[], int rozmiar);
void heapify(int A[], int i, int heap_size);

int main()
{
    clock_t start, stop;
    float roznica, suma=0;
    int rozmiar, t=0, testy = 6;
    cout << "podaj rozmiar tablicy: " << endl;
    cin >> rozmiar;
    cout << endl;

    int *A=new int[rozmiar];
    int *temp = new int[rozmiar];


/* ------- QUICKSORT -------*/

    while(t<testy)
    {
        gen_los(A, rozmiar);        //wygenerowanie liczb losowych do tablicy
        start = clock();            //rozpoczęcie odliczania czasu
        quicksort(A, 0, rozmiar-1);     //wywołanie funkcji
        stop = clock();             //zatrzymanie czasu
        roznica = (float)(stop - start) / (float)(CLOCKS_PER_SEC);      //obliczenie czasu trawania funkcji
        suma = suma + roznica;
        cout << "Czas wykonywania algorytmu QUICKSORT: " << roznica << "s" << endl;
        t++;
    }
        cout << "Sredni czas: " << suma/testy << " sek" << endl<<endl;


/* ------- SORT INSERT ------- */
    int *B=new int[rozmiar];
    t=0, suma=0;
    while(t<testy)
    {
        gen_los(B, rozmiar);
        start = clock();
        sort_insert(B,  rozmiar);
        stop = clock();
        roznica = (float)(stop - start) / (float)(CLOCKS_PER_SEC);
        suma = suma + roznica;
        cout << "Czas wykonywania algorytmu SORT INSERT: " << roznica << endl;
        t++;
    }
    cout << "Sredni czas: " << suma/testy << " sek" << endl<<endl;
    delete [] B;

/* ------- SORT SELECT ------- */
t=0, suma=0;
    while(t<testy)
    {
        gen_los(A, rozmiar);
        start = clock();
        sort_select(A, rozmiar);
        stop = clock();
        roznica = (float)(stop - start) / (float)(CLOCKS_PER_SEC);
        suma = suma + roznica;
        cout << "Czas wykonywania algorytmu SORT SELECT: " << roznica << endl;
        t++;
    }
    cout << "Sredni czas: " << suma/testy << " sek" << endl<<endl;




/* ------- SORT MERGE ------- */
t=0, suma=0;
    while(t<testy)
    {
        gen_los(A, rozmiar);
        start = clock();
        sortowanie_przez_scalanie(A, temp, rozmiar);
        stop = clock();
        roznica = (float)(stop - start) / (float)(CLOCKS_PER_SEC);
        suma = suma + roznica;
        cout << "Czas wykonywania algorytmu SORT MERGE: " << roznica << endl;
        t++;
    }
    cout << "Sredni czas: " << suma/testy << " sek" << endl<<endl;


/* ------- HEAPSORT ------- */

t=0, suma=0;
    while(t<testy)
    {
        gen_los(A, rozmiar);
        start = clock();
        heap_sort(A, rozmiar);
        stop = clock();
        roznica = (float)(stop - start) / (float)(CLOCKS_PER_SEC);
        suma = suma + roznica;
        cout << "Czas wykonywania algorytmu HEAPSORT: " << roznica << endl;
        t++;
    }
    cout << "Sredni czas: " << suma/testy << " sek" << endl<<endl;

    delete [] A;
    delete [] temp;

    system("pause");
    return 0;
}

/*     GENEROWANIE LICZB PSEUDOLOSOWYCH      */
void gen_los(int tablica[], int rozmiar)
{
    for(int i=0; i<rozmiar; i++)
    {
        tablica[i] = rand()%100+1;
    }
}
/* ------- SORT SELECT ------- */
void sort_select(int tablica[], int rozmiar)
{
    int x;
    for( int i = 0; i < rozmiar; i++ )
    {
        x = i;
        for( int j=i+1; j<rozmiar; j++ )
        {
            if( tablica[j]<tablica[x] )  //jeśli jakiś z kolejnych elementów jest mniejszy od elementu na którym jest zmienna x
                x = j;                     //do mniennej przypisuje mniejszą wartość
        }
        swap( tablica[x], tablica[i] );    //zamienia element mniejszy z tym, który znajdował się na pozycji x
    }

}
/* ------- SORT INSERT ------- */
void sort_insert(int tablica[], int rozmiar)
{
    int temp, j;

    for( int i = 1; i<rozmiar; i++ )
    {
        temp = tablica[i];		//przypisanie do zmiennej (na poczatek 2) elementu tablicy

        for( j=i-1; j>=0 && tablica[j]>temp; j-- )		//dopóki poprzedni element jest wiekszt od zmiennej cofaj sie do 1 elementu
            tablica[j+1] = tablica[j];					//przesuwa elementy o jeden w prawo

        tablica[j+1] = temp;		//jesli znajdzie element mniejszy wstawia za niego wartość danej zmiennej
    }
}

/* ------- SORT MERGE ------- */
void merge(int pocz, int sr, int kon, int temp[], int tablica[])
{
    int i,j,q;

    for (i=pocz; i<=kon; i++)
    {
        temp[i]=tablica[i];  // Skopiowanie danych do tablicy pomocniczej
    }
    i=pocz;
    j=sr+1;
    q=pocz; // Ustawienie wskazników tablic
    while (i<=sr && j<=kon)           // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy glównej
    {
        if (temp[i]<temp[j])
        {
            tablica[q++]=temp[i++];
        }
        else
        {
            tablica[q++]=temp[j++];
        }
    }
    while (i<=sr)
    {
        tablica[q++]=temp[i++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór sie skonczyl
    }

}

void mergesort(int pocz, int kon, int temp[], int tablica[])
{
    int sr;
    if (pocz<kon)
    {
        sr=(pocz+kon)/2;
        mergesort(pocz, sr, temp, tablica);    // Dzielenie lewej czesci
        mergesort(sr+1, kon, temp, tablica);   // Dzielenie prawej czesci
        merge(pocz, sr, kon, temp, tablica);   // £¹czenie czêœci lewej i prawej
    }
}

/* ------- QUICKSORT ------- */
void quicksort(int A[], int p, int r)
{
    int q;  //zmienna oznaczajaca srodek
    if (p<r)
    {
        q=partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int partition(int A[], int p, int r)
{

    int x, i;
    x = A[p];   //przypisanie wartosci pierwszego elementu tablicy do zmiennej x
    i=p;        //przypisanie numeru miejsca danego elementu

    for(int j=p+1; j<=r; j++)
    {
        if(A[j]<=x)     //jesli kolejny element jest mniejszy od wybranego na poczatku
        {
            i++;;
            swap(A[i], A[j]);
        }
    }
    swap(A[p], A[i]);       //zamienia pierwszy element z
    return i;
}



int parent(int i)
{
    int a;
    a=i/2;
    return a;
}

int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}

int build_heap(int A[], int rozmiar)
{
    int x = floor(rozmiar/2);
    for(int i=x; i>=0; i--)
    {
        heapify(A,i,rozmiar) ;
    }
}

int heap_sort(int A[], int rozmiar)
{
    build_heap(A, rozmiar);

    for(int i=rozmiar-1; i>0; i--)
    {
        swap(A[0], A[i]);
        rozmiar--;
        heapify(A,0,rozmiar);
    }
}
void heapify(int A[], int i, int heap_size)
{
    int l, r, largest;
    l = left(i);
    r = right(i);
    if(l<heap_size && A[l]>A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if(r<heap_size && A[r]>A[largest])
    {
        largest = r;
    }
    if(largest!=i)
    {
        swap(A[i], A[largest]);
        heapify(A, largest, heap_size);
    }

}

void wyswietlanie(int tablica[], int rozmiar)
{

    for(int i=0; i<rozmiar; i++)
    {
        cout << tablica[i] << " ";
    }
    cout <<endl<<endl;
}
