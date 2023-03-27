//Tomasz Jarzabek

#include <iostream>                 //tylko to wiec zadnych abs

using namespace std;

int main () {

    int wejscia;
    int n;
    int uindeks;
    int findeks;
    int succ;
    int fragment;

    int koniec = 0;
    int poczatek = 0;
    int kontrola = 0;
    int temp = 0;
    bool prawda = false;
    int nkoniec = 0;
    int giri = 0;
    
    int przesuniecie = 0;
    int ostatni;
    int npoczatek;

    char operacja = 'A';            //zeby przypadkiem nie bylo F na starcie
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;

    cin >> wejscia;
 
    while (i < wejscia){

        cin >> n;

        int tablica[n];

        prawda = false;
        giri = 0;                               //resetujemy wszystkie zmienne
        k = 0;
        j = 0;
        z = 0;
        succ = 0;
        operacja = 'A';

        while (j < n){

            cin >> tablica[j];
            j = j + 1;
        }
        j = 0;

        while (j < n){

            if ((j + 1) == n){
                cout << tablica[j] << endl;
            }
            else{
                cout << tablica[j] << " ";
            }
        
            j = j + 1;
        }
        j = 0;


        while(operacja != 'F'){

            prawda = false;
            giri = 0;                               //resetujemy wszystkie zmienne
            k = 0;
            j = 0;
            z = 0;
            succ = 0;

            cin >> operacja;

            if (operacja == 'F'){                   //konczy sie petla, to najwazniejsze wiec jedyny if, wszystko zalezy od tego

                j = 0;
                while (j < n){                      //wypisujemy koncowy wynik

                    if ((j + 1) == n){
                        cout << tablica[j] << endl;
                    }
                    else{
                        cout << tablica[j] << " ";
                    }
                
                    j = j + 1;
                }

                i = i + 1;
            }



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------



            else if (operacja == 'R'){                   //operacja odwracania

                cin >> uindeks;
                cin >> fragment;                        //mniejsze lub rowne n wiec zawsze mozliwe

                if (uindeks < 0){
                    
                    findeks = ((uindeks % n) + n) % n;              //dzialaaaaa
                }
                else{
                    findeks = uindeks % n;
                }

                if(fragment == 0 || fragment > n || fragment == 1){ 

                }

                else{
                    
                    poczatek = findeks;
                    koniec = (poczatek + fragment - 1 ) % n;             //wartosci na pewno dodatnie bo findeks zawsze dodatni
                    
                    kontrola = poczatek;
                    nkoniec = koniec;
                    
                    while (prawda == false){                            //sprawdzamy czy miescza sie nastepne fragmenty

                        j = 0;

                        while (j < (fragment / 2)){
                            
                            if( (koniec - j) < 0){
                                k = ( ( (koniec - j) % n) + n ) % n;
                            }
                            else {
                                k = (koniec - j) % n;
                            } 
                            
                            if( (poczatek + j) < 0){
                                z = ( ( (poczatek + j) % n) + n ) % n;
                            }
                            else {
                                z = (poczatek + j) % n;
                            } 
                            
                            temp = tablica[k];
                            tablica[k] = tablica[z];
                            tablica[z] = temp;

                            j = j + 1;
                        }

                        //koniec stary to nowy poczatek

                        poczatek = (nkoniec + 1) % n;
                        npoczatek = poczatek;
                    
                        if((poczatek + fragment - 1) < 0){
                            koniec = (((poczatek + fragment - 1) % n) + n) % n;
                        }
                        else{
                            koniec = (poczatek + fragment - 1) % n;
                        }
                        nkoniec = koniec;

                        if(npoczatek == kontrola){
                            prawda = true;
                        }
                        else{

                            while (npoczatek != nkoniec ){

                                if (npoczatek == kontrola){                            //zaden element nie moze sie powtorzyc
                                    prawda = true;
                                    npoczatek = koniec;
                                }
                                
                                if(prawda == false){
                                    npoczatek = (npoczatek + 1) % n;
                                }

                                if(npoczatek == koniec && koniec == kontrola){
                                    prawda = true;
                                }
                            }
                        }
                        giri = giri + 1;
                    }
                }
            } //dziala n 12 i n 6


//--------------------------------------------------------------------------------------------------------------------------



            else if (operacja == 'M'){                   

                cin >> uindeks;
                cin >> fragment;                        //mniejsze lub rowne n wiec zawsze mozliwe
                cin >> przesuniecie;

                if(fragment == 0 || fragment == 1 || fragment > n){

                }
                
                else{

                    if (uindeks < 0){
                        findeks = ((uindeks % n) + n) % n;              
                    }
                    else{
                        findeks = uindeks % n;
                    }
                    poczatek = findeks;

                    j = 0;                                  //jesli nie to robimy pierwszy raz na pusto

                    if (przesuniecie < 0){                   //PRZESUWAMY W LEWO

                        if((poczatek + fragment - 1) < 0){
                            koniec = (((poczatek + fragment - 1) % n) + n) % n;
                        }
                        else{
                            koniec = (poczatek + fragment - 1) % n;
                        }
                        kontrola = poczatek;

                        while(prawda == false){

                        
                            //tyle razy sie to zrobi, za kazdym razem o jedna pozycje sie przesuwa

                            j = 0;

                            while (j > przesuniecie){

                                //findeks = poczatek

                                k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                ostatni = tablica[poczatek];

                                while (k != koniec){
                                    
                                    tablica[k] = tablica[(k + 1) % n];

                                    k = (k + 1) % n;
                                }
                                tablica[koniec] = ostatni;

                                j = j - 1;
                            }

                            poczatek = (koniec + 1) % n;
                            npoczatek = poczatek;
                            if((poczatek + fragment - 1) < 0){
                                koniec = (((poczatek + fragment - 1) % n) + n) % n;
                            }
                            else{
                                koniec = (poczatek + fragment - 1) % n;
                            }

                            if(((npoczatek + 1) % n) == kontrola || npoczatek == kontrola){
                                prawda = true;

                                //cout << "Prawda: " << prawda;
                            }
                            else{
                                while(npoczatek != koniec){

                                    if(npoczatek == kontrola){
                                        prawda = true;                  //ale trzeba zrobic jeszce jedno okrazenie dla ostatnej czeszci mniejszej od fragmentu

                                        j = 0;
                                        /*
                                        if((n % fragment) == 0){                //NIE WIEM CO TO ROBI

                                            if((npoczatek - 1) < 0){
                                                npoczatek = (((npoczatek - 1) % n) + n) % n;
                                            }
                                            else{
                                                npoczatek = (npoczatek - 1) % n;
                                            }

                                            while (j > przesuniecie){                           //tu byl bardzo dlugi warunek

                                                //findeks = poczatek

                                                k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                                ostatni = tablica[poczatek];

                                                while (k != (npoczatek)){
                                                    
                                                    tablica[k] = tablica[(k + 1) % n];

                                                    k = (k + 1) % n;
                                                }
                                                tablica[(npoczatek)] = ostatni;

                                                j = j - 1;
                                            }
                                            npoczatek = koniec;                 //musimy wyjsc z tego while
                                        }*/

                                        

                                            if((npoczatek - 1) < 0){
                                                npoczatek = (((npoczatek - 1) % n) + n) % n;
                                            }
                                            else{
                                                npoczatek = (npoczatek - 1) % n;
                                            }

                                            while (j > przesuniecie){

                                                //findeks = poczatek

                                                k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                                ostatni = tablica[poczatek];

                                                while (k != (npoczatek)){
                                                    
                                                    tablica[k] = tablica[(k + 1) % n];

                                                    k = (k + 1) % n;
                                                }
                                                tablica[(npoczatek)] = ostatni;

                                                j = j - 1;
                                            }

                                            npoczatek = koniec;
        
                                    }
                                    if(prawda == false){
                                        npoczatek = (npoczatek + 1) % n;
                                    }
                                    else{

                                    }

                                    if(npoczatek == koniec && koniec == kontrola){
                                        prawda = true;

                                        j = 0;

                                        if((npoczatek - 1) < 0){
                                                npoczatek = (((npoczatek - 1) % n) + n) % n;
                                            }
                                            else{
                                                npoczatek = (npoczatek - 1) % n;
                                            }

                                            while (j > przesuniecie){

                                                //findeks = poczatek

                                                k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                                ostatni = tablica[poczatek];

                                                while (k != (npoczatek)){
                                                    
                                                    tablica[k] = tablica[(k + 1) % n];

                                                    k = (k + 1) % n;
                                                }
                                                tablica[(npoczatek)] = ostatni;

                                                j = j - 1;
                                            }

                                            npoczatek = koniec;
                                    }
                                }
                            }

                            giri = giri + 1;
                        }
                    }
                    else{                                   //PRZESUWAMY W PRAWO 0 nic nie robi

                        przesuniecie = przesuniecie % fragment;             //bo nie ma senso robic 7 na 5 jak to jest tak samo jak dwa

                  
                        koniec = (poczatek + fragment - 1) % n;             //problematyczne kiedy poczatek = 0 jak jest samo, sprawdzamy na poczatku
                        
                        kontrola = poczatek;                //gdzies siegamy poza zakres

                        while(prawda == false){

                        
                            j = 0;

                            while (j < przesuniecie){

                                        // robimy manualnie pierwszy przypadek
                                ostatni = tablica[koniec];

                                k = koniec;                                 // k - 1 jest negatywne!!!!!!!!!!!

                                while (k != poczatek){

                                    if((k - 1) < 0){
                                        succ = (((k - 1) % n) + n) % n;
                                    }
                                    else{
                                        succ = (k - 1) % n;
                                    }

                                    tablica[k] = tablica[succ];

                                    k = succ;
                                }

                                tablica[poczatek] = ostatni;
                                j = j + 1;
                            }
                            
                            poczatek = (koniec + 1) % n;
                            npoczatek = poczatek;

                            if((poczatek + fragment - 1) < 0){
                                koniec = (((poczatek + fragment - 1) % n) + n) % n;
                            }
                            else{
                                koniec = (poczatek + fragment - 1) % n;
                            }
                            

                            //cout << "npoczatek: " << npoczatek << endl;
                            //cout << "koniec: " << koniec << endl;

                            if(((npoczatek + 1) % n) == kontrola || npoczatek == kontrola){
                                prawda = true;

                                //cout << "Prawda: " << prawda;
                            }
                            else{
                                
                                //cout << "Tu" << endl;
                                while(npoczatek != koniec){                                             // w ten sposob omijamy przypadek gdzie koniec == kontrola


                                    if(npoczatek == kontrola){

                                        prawda = true;

                                        j = 0;
                                                      

                                            if((npoczatek - 1) < 0){
                                                npoczatek = (((npoczatek - 1) % n) + n) % n;
                                            }
                                            else{
                                                npoczatek = (npoczatek - 1) % n;
                                            }
                  
                                            while (j < przesuniecie){               //robimy ostatni fragment

                                                
                                                ostatni = tablica[npoczatek];

                                                k = npoczatek;

                                                while (k != poczatek){
                                                    if((k - 1) < 0){
                                                        succ = (((k - 1) % n) + n) % n;
                                                    }
                                                    else{
                                                        succ = (k - 1) % n;
                                                    }

                                                    tablica[k] = tablica[succ];

                                                    k = succ;
                                                }

                                                tablica[poczatek] = ostatni;
                                                j = j + 1;
                                            }
                                            npoczatek = koniec;

                                            //cout << "npoczatek"<< endl << npoczatek;
                                        
                                    }
                                    if(prawda == false){
                                        npoczatek = (npoczatek + 1) % n;
                                    }
                                    else{

                                    }

                                    if(npoczatek == koniec && koniec == kontrola){
                                        prawda = true;

                                        j = 0;

                                        if((npoczatek - 1) < 0){
                                                npoczatek = (((npoczatek - 1) % n) + n) % n;
                                        }
                                        else{
                                            npoczatek = (npoczatek - 1) % n;
                                        }
                  
                                        while (j < przesuniecie){               //robimy ostatni fragment

                                                
                                            ostatni = tablica[npoczatek];

                                            k = npoczatek;

                                            while (k != poczatek){
                                                if((k - 1) < 0){
                                                    succ = (((k - 1) % n) + n) % n;
                                                }
                                                else{
                                                    succ = (k - 1) % n;
                                                }

                                                tablica[k] = tablica[succ];

                                                k = succ;
                                            }

                                            tablica[poczatek] = ostatni;
                                            j = j + 1;
                                        }
                                        npoczatek = koniec;
                                    }
                                }

                            }
                            
                            giri = giri + 1;

                            //cout << "Giri: " << giri << endl;
                        }
                    }   
                }
            }       //dziala i w lewo i w prawo



//-------------------------------------------------------------------------------------------------------------------



            else if (operacja == 'C'){                   //operacja zamiany parami

                cin >> uindeks;
                cin >> fragment;

                if(fragment != 0){
                
                    if((n / fragment) < 2 || fragment > n){                 //w tym przypadku nic nie robimy bo nie ma sasiadujacych fragmentow

                    }

                    else{

                        if (uindeks < 0){
                            findeks = ((uindeks % n) + n) % n;              
                        }
                        else{
                            findeks = uindeks % n;
                        }

                        if( (findeks + fragment  - 1 ) < 0){
                            koniec = ( ( (findeks + fragment - 1 ) % n) + n ) % n;
                        }
                        else {
                            koniec = (findeks + fragment - 1 ) % n;
                        }

                        poczatek = (koniec + 1) % n;                      //to dla k, drugi fragment pary

                        j = findeks;
                        k = poczatek;
                        giri = 0;
                        succ = n;

                        while ((2 * fragment) <= succ){
                            succ = succ - fragment - fragment;

                            while(giri < fragment){
                                
                                temp = tablica[j];
                                tablica[j] = tablica[k];
                                tablica[k] = temp;

                                j = (j + 1 ) % n;                       
                                                    
                                k = (k + 1 ) % n;
                                
                                giri = giri + 1;
                            }

                            giri = 0;
                            
                            j = k;
                            k = (k + fragment) % n;                          //ci prepariamo al secondo giro
                        }  
                    }
                }
            } //dziala 12 dlugosc indeks -9 fragment 3



//--------------------------------------------------------------------------------------------------------------------------




            else if (operacja == 'S'){                   //operacja sortowania

                cin >> uindeks;
                cin >> fragment;

                if (uindeks < 0){
                    findeks = ((uindeks % n) + n) % n;              
                }
                else{
                    findeks = uindeks % n;
                }

                poczatek = findeks;
                j = poczatek;
                giri = 0;                                  //jesli nie to robimy pierwszy raz na pusto

                if (fragment == 0 || fragment == 1 || fragment == -1){

                }
                
                else{

                    if (fragment < 0){                      //PORZADEK NIEROSNACY

                        if (fragment <= (-n)){
                            fragment = n;
                        }
                        else{
                            fragment = -fragment;               //potrzebujemy wartosc pozytywna do operacji
                        }
                        koniec = (poczatek + fragment - 1) % n;
                        kontrola = poczatek;
                        succ = n;

                        while(giri < (n / fragment) || giri < 1){
                            
                            //tyle razy sie to zrobi, za kazdym razem o jedna pozycje sie przesuwa
                            succ = succ - fragment;                 //i to konczy BaCe
                            j = poczatek;

                            while (j != koniec){

                                k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                    
                                while (k != koniec){

                                    if(tablica[k] < tablica[(k + 1) % n]){

                                        temp = tablica[k];
                                        tablica[k] = tablica[(k + 1) % n];
                                        tablica[(k + 1) % n] = temp;
                                    }
                                    
                                    k = (k + 1) % n;
                                }
                                j = (j + 1) % n;
                            }

                            poczatek = (koniec + 1) % n;
                            npoczatek = poczatek;
                            if((poczatek + fragment - 1) < 0){
                                koniec = (((poczatek + fragment - 1) % n) + n) % n;
                            }
                            else{
                                koniec = (poczatek + fragment - 1) % n;
                            }
                            
                            if(((giri + 1) >= (n / fragment)) && (succ > 1) && ( (npoczatek != kontrola) )){
                                j = poczatek;

                                if((kontrola - 1) < 0){
                                    kontrola = (((kontrola - 1) % n) + n) % n;
                                }
                                else{
                                    kontrola = (kontrola - 1) % n;
                                }

                                while (j != kontrola){

                                    k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                    
                                    while (k != kontrola){

                                        if(tablica[k] < tablica[(k + 1) % n]){

                                            temp = tablica[k];
                                            tablica[k] = tablica[(k + 1) % n];
                                            tablica[(k + 1) % n] = temp;
                                        }
                                    
                                        k = (k + 1) % n;
                                    }
                                    j = (j + 1) % n;
                                }
                            }

                            giri = giri + 1;
                        }
                    }
                    else{                                   //PORZADEK NIEMALEJACY

                        if(fragment > n){
                            fragment = n;
                        }

                        koniec = (poczatek + fragment - 1) % n;
                        kontrola = poczatek;
                        succ = n;
                
                        while(giri < (n / fragment) || giri < 1){
                            
                            succ = succ - fragment;
                            //tyle razy sie to zrobi, za kazdym razem o jedna pozycje sie przesuwa

                            j = poczatek;

                            while (j != koniec){

                                k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                    
                                while (k != koniec){

                                    if(tablica[k] > tablica[(k + 1) % n]){

                                        temp = tablica[k];
                                        tablica[k] = tablica[(k + 1) % n];
                                        tablica[(k + 1) % n] = temp;
                                    }
                                    
                                    k = (k + 1) % n;
                                }
                                
                                j = (j + 1) % n;
                            }

                            poczatek = (koniec + 1) % n;
                            npoczatek = poczatek;
                            if((poczatek + fragment - 1) < 0){
                                koniec = (((poczatek + fragment - 1) % n) + n) % n;
                            }
                            else{
                                koniec = (poczatek + fragment - 1) % n;
                            }

                            if ( ( ( (giri + 1) >= (n / fragment) ) && (succ > 1) && ( (npoczatek != kontrola) ) )){
                                j = poczatek;

                                //cout << "Wchodzimy";

                                if((kontrola - 1) < 0){
                                    kontrola = (((kontrola - 1) % n) + n) % n;
                                }
                                else{
                                    kontrola = (kontrola - 1) % n;
                                }

                                while (j != kontrola){

                                    k = poczatek;                                          // robimy manualnie pierwszy przypadek
                                    
                                    while (k != kontrola){

                                        if(tablica[k] > tablica[(k + 1) % n]){

                                            temp = tablica[k];
                                            tablica[k] = tablica[(k + 1) % n];
                                            tablica[(k + 1) % n] = temp;
                                        }
                                    
                                        k = (k + 1) % n;
                                    }
                                    j = (j + 1) % n;
                                }
                            }
                            
                            giri = giri + 1;
                        }   
                    }
                }
            }                   

        }
        
    }

    return 0;
}