//Tomasz Jarzabek

#include <iostream>

using namespace std;

int size(int zbior[]){
    int size = 1;
    int i = 0;

    while(zbior[i] != (-1)){

        i = i + 1;
        size = size + 1;
    }

    return size;
} //dziala

void sort(int zbior[], int size){
    int temp;
    int i, j;

    for (i = 0; i < size - 1; i++){

        for (j = 0; j < size - i - 1; j++){

            if ((zbior[j] > zbior[j + 1]) && ( (zbior[j] != (-1)) && (zbior[j + 1]) != (-1))){          //-1 non lo sortiamo

                temp = zbior[j];
                zbior[j] = zbior[j + 1];
                zbior[j + 1] = temp;
            }
        }    
    }
} //dziala

void Add(int dodawany, int zbior[]){                //dodajemy liczbe do zbioru
    
    int i = 0;
    int giri = 0;
    int n = size(zbior);

    if(dodawany >= 1 && dodawany <= 4095){          //liczba nalezy do uniwersum

         while(zbior[i] != (-1)){

            if(zbior[i] == dodawany){               //to co dodejemy nie moze juz byc w zbiorze

                giri = giri + 1;
            }

            i = i + 1;
        }

        if(giri == 0){
            zbior[n - 1] = dodawany;
            zbior[n] = -1;
            sort(zbior, n);
        }   
    }
    else{
        //nic nie robimy
    }
} //dziala

void Create(int size, int tablica[], int zbior[] ){          //tworzymy zbior z dowolnych wartosci int
    int i = 0;
    int j = 0;
    int k = 0;
    int temp;
    int giri = 0;
    //powinno tez dzialac dla 0 i 1
    while(i < size){        //uzywamy n elementow z tej tablicy wyjdzie z tego mniejszy zbior
        
        if(tablica[i] >= 1 && tablica[i] <= 4095){      //musza byc z Uniwersum
            
            temp = tablica[i];

            while(k < j){
                if(zbior[k] == temp){
                    giri = giri + 1;                    //elementy zbioru sa rozne
                }
                k = k + 1;
            }
            if(giri == 0){
                zbior[j] = temp;
                j = j + 1;
            }

            giri = 0;
            k = 0;
 
        }

        i = i + 1;        
    }

    zbior[j] = -1;      //na koniec dodajemy -1 bo musi byc zbiorem

    sort(zbior, size);              //za kazdym razem jak oddajem zbior to go sortujemy
} //dziala

void Complement(int dopelniany[], int dopelniajacy[]){                  //dopelnienie zbioru
    
    int i = 0;
    int j = 0;
    int element = 1;
    int giri = 0;

    int sizeP = size(dopelniany);

    while(element <= 4095){
        while(i < sizeP){
            if(dopelniany[i] == element){
                giri = giri + 1;
            }

            i = i + 1;
        }

        i = 0;

        if(giri == 0){
            dopelniajacy[j] = element;
            j = j + 1;
        }

        giri = 0;
        element = element + 1;
    }

    dopelniajacy[j] = -1;

    //sort(dopelniajacy, j + 1);
}

void Union(int pierwszy[], int drugi[], int suma[]){                //suma zbiorow
    int i = 0;
    int j = 0;
    int k = 0;
    int giri = 0;

    int sizeP = size(pierwszy);
    int sizeD = size(drugi);

    while(i < (sizeP - 1)){                   //pierwszego zbioru musza byc wszystkie elementy

        suma[k] = pierwszy[i];

        i = i + 1;
        k = k + 1;
    }

    i = 0;

     while(j < (sizeD - 1)){                       //jak elementu nie dodalismy juz z pierwszego to dodajemy

        while(i < (sizeP - 1)){

            if(drugi[j] == pierwszy[i]){            
                giri = giri + 1;
            }

            i = i + 1;
        }

        if(giri == 0){                          
            suma[k] = drugi[j];
            k = k + 1;
        }

        i = 0;
        giri = 0;

        j = j + 1;
    }

    suma[k] = -1;

    int sizeK = size(suma);

    sort(suma, sizeK);  
} //dziala

void Intersection(int pierwszy[], int drugi[], int przeciecie[]){                    //przeciecie logiczne jak na LTM

    int i = 0;
    int j = 0;
    int k = 0;

    int sizeP = size(pierwszy);
    int sizeD = size(drugi);        //lavoro in corso

    while(i < (sizeP - 1)){               //prendiamo solo gli elementi in comune

        while(j < (sizeD - 1)){

            if(pierwszy[i] == drugi[j]){

                przeciecie[k] = pierwszy[i];
                k = k + 1;
                j = sizeD;
            }

            j = j + 1;
        }

        j = 0;

        i = i + 1;
    }

    przeciecie[k] = -1;

    int sizeK = size(przeciecie);

    sort(przeciecie, sizeK);
} //dziala

void Difference(int pierwszy[], int drugi[], int roznica[]){

    int i = 0;
    int j = 0;
    int giri = 0;
    int k = 0;

    int sizeP = size(pierwszy);
    int sizeD = size(drugi);        //lavoro in corso

    while(i < (sizeP - 1)){               //prendiamo solo gli elementi in comune

        while(j < (sizeD - 1)){

            if(pierwszy[i] == drugi[j]){

                giri = giri + 1;
                j = sizeD;
            }

            j = j + 1;
        }

        if(giri == 0){
            roznica[k] = pierwszy[i];
            k = k + 1;
        }

        giri = 0;
        j = 0;

        i = i + 1;
    }

    roznica[k] = -1;

    int sizeK = size(roznica);

    sort(roznica, sizeK);
}

void Symmetric(int pierwszy[], int drugi[], int roznica[]){         //roznica symetryczna

    int i = 0;
    int j = 0;
    int k = 0;
    int giri = 0;

    int sizeP = size(pierwszy) - 1;                   
    int sizeD = size(drugi) - 1;

    while(i < sizeP){               //dla kazdego z A sprawdzamy czy w B

        while(j < sizeD){

            if(pierwszy[i] == drugi[j]){        //jak tak to nie wchodzi
                giri = giri + 1;
            }

            j = j + 1;
        }

        if(giri == 0){
            roznica[k] = pierwszy[i];
            k = k + 1;
        }

        j = 0;
        giri = 0;

        i = i + 1;
    }

    i = 0;
    giri = 0;
    j = 0;

    while(j < sizeD){               //dla kazdego z B sprawdzamy czy w A

        while(i < sizeP){

            if(drugi[j] == pierwszy[i]){        //jak tak to nie wchodzi
                giri = giri + 1;
            }

            i = i + 1;
        }

        if(giri == 0){
            roznica[k] = drugi[j];
            k = k + 1;
        }

        i = 0;
        giri = 0;

        j = j + 1;
    }

    roznica[k] = -1;

    int sizeR = size(roznica);

    sort(roznica, sizeR);
} //dziala

bool Subset(int pierwszy[], int drugi[]){
    int i = 0;                                  //nie wiemy czy sa uporzadkowane wiec dwie petle
    int j = 0;
    int giri = 0;
    bool sprawdza = true;

    int sizeP = size(pierwszy);     //zawierany
    int sizeD = size(drugi);        //zawierajacy

    if(sizeP <= sizeD){
        
        while(i < sizeP){

            while(j < sizeD){

                if(pierwszy[i] == drugi[j]){            //kazdy element z pierwszego musi byc w drugim zbiorze
                    //nic sie nie dzieje bo sprawdza true
                    giri = giri + 1;
                }
                
                j = j + 1;
            }

            if(giri == 0){              //nie znalezlismy napewno nie rowne, wychodzimy
                sprawdza = false;
                i = sizeP;
            }
            giri = 0;
            j = 0;

            i = i + 1;
        }
    }
    else{
        sprawdza = false;
    }

    return sprawdza;
} //dziala

bool Equal(int pierwszy[], int drugi[]){        //sprawdzamy czy dwa zbiory sa takie same
    int i = 0;                                  //nie wiemy czy sa uporzadkowane wiec dwie petle
    int j = 0;
    int giri = 0;
    bool sprawdza = true;

    int sizeP = size(pierwszy) - 1;
    int sizeD = size(drugi) - 1;

    if(sizeP == sizeD){
        
        while(i < sizeP){

            while(j < sizeP){

                if(pierwszy[j] == drugi[i]){
                    //nic sie nie dzieje bo sprawdza true
                    giri = giri + 1;
                }
                
                j = j + 1;
            }

            if(giri == 0){              //nie znalezlismy napewno nie rowne, wychodzimy
                sprawdza = false;
                i = sizeP;
            }
            giri = 0;
            j = 0;

            i = i + 1;
        }
    }
    else{
        sprawdza = false;
    }

    return sprawdza;
} //teraz dziala

bool Empty(int zbior[]){                //sprawdza czy zbior jest pusty
    bool sprawdza = false;

    if(zbior[0] == (-1)){               //zbior bedzie pusty tylko jak jego pierwszy
        sprawdza = true;                //element to -1. bo to jest zawsze ostatni element
    }

    return sprawdza;
}
//dziala

bool Nonempty(int zbior[]){             //sprawdza czy zbior jest niepusty
    bool sprawdza = true;

     if(zbior[0] == (-1)){               //zbior bedzie pusty tylko jak jego pierwszy
        sprawdza = false;                //element to -1. bo to jest zawsze ostatni element
    }

    return sprawdza;
}   //tak samo jak wczesniej tylko wartosci sprawdza zamienione
//dziala

bool Element(int element, int zbior[]){            //sprawdza czy element nalezy do zbioru
    bool sprawdza = false;
    int i = 0;

    while(zbior[i] != (-1)){
        if(zbior[i] == element){
            sprawdza = true;
        }

        i = i + 1;
    }

    return sprawdza;
} 
//dziala

double Arithmetic(int zbior[]){

    double srednia = 0;
    double suma = 0;

    int sizeP = size(zbior) - 1;
    int i = 0;

    if(sizeP == 0){
        srednia = 0;
    }
    else{
        while(i < sizeP){

            suma = suma + zbior[i];

            i = i + 1;
        }

        srednia = suma / sizeP;
    }

    return srednia;
} //dziala tez dla dlugosci 0

double Harmonic(int zbior[]){                      //srednia harmoniczna

    double srednia = 1;
    double suma = 0;

    double sizeP = size(zbior) - 1;
    double jeden = 1;
    int i = 0;

    if(sizeP == 0){
        srednia = 1;                    //dla zbioru pustego rowna sie 1
    }
    else{
        while(i < sizeP){

            suma = suma + (jeden / zbior[i]);

            i = i + 1;
        }

        srednia = sizeP / suma;
    }

    return srednia;
} //dziala

void MinMax(int zbior[], int* min, int& MAX){            //min jest wskaznikowa a MAX jest referencjina

    int n = size(zbior);

    int i = 0;

    if(n == 1){

    }
    else{

        *min = zbior[i];
        MAX = zbior[i];

        while(i < (n - 1)){

            if(zbior[i] < *min){

                *min = zbior[i];
            }

            if(zbior[i] > MAX){

                MAX = zbior[i];
            }

            i = i + 1;
        }
    }
} //dziala

void Cardinality(int zbior[], int* moc){            //okresla moc zbioru

    if(zbior[0] == (-1)){
        *moc = 0;
    }
    else{
        *moc = size(zbior) - 1;
    }

} //dziala

void Properties(int zbior[], char ciag[], double& arytmetyczna, double* harmoniczna, int& min, int* MAX, int& moc ){

    int i = 0;
    int sizeP = size(zbior);

    while(ciag[i] != '\0'){

        if(ciag[i] == 'a'){
            arytmetyczna = Arithmetic(zbior);
        }

        else if(ciag[i] == 'h'){
            *harmoniczna = Harmonic(zbior);
        }

        else if(ciag[i] == 'm'){
            MinMax(zbior, &min, *MAX);
        }

        else if(ciag[i] == 'c'){
            Cardinality(zbior, &moc);
        }

        i = i + 1;
    }

} //dziala