//Tomasz Jarzabek

#include <string>

using namespace std;

string FormatujNapis(string napis, string parametrA, string parametrB, string parametrC){

    string wynik = "";
    string parametr1 = parametrA;
    string parametr2 = parametrB;
    string parametr3 = parametrC;
    string eliminacja = "";
    int i = 0;
    int j = 0;
    int k = 0;
    int w = 0;
    int z = 0;
    int d = 0;
    int v = 0;
    int b = 0;

    int start = 0;

    int check = 0;
    bool sprawdza = false;
    bool uwaga = false;

    int numer = 0;

    int n = 0;
    int n2 = 0;
    char c;
    char litera;
    int m = 0;


    while(napis[z] != '\0'){

        m = d;

        while((napis[d] != '{') && (napis[d] != '\0')){

            d++;
            if(napis[d] == '\0'){

                while(m < d){

                    wynik = wynik + napis[m];
                    m++;
                }
            }
            else{

            }
        }

        if(napis[d] == '{'){

            j = d;
            k = d + 1;

            litera = napis[k];

            if((litera == 'p') || (litera == 'u') || (litera == 'w') || (litera == 'W') || (litera == 'U')){

                i = check;
                while(i < d){       //czesc wspolna, to co jest przed nawiasem zostaje takie same
                    
                    wynik = wynik + napis[i];
                    
                    i++;
                }
                

                if(litera == 'p'){

                    k = k + 2;
                    n = napis[k] - '0';

                    k = k + 2;
                    c = napis[k];

                    w = 0;
                    while(w < n){
                        
                        wynik = wynik + c;

                        w = w + 1;
                    }
                    d = j + 7;
                    check = d;
                    z = d;   
                    sprawdza = true;  
                    
                }
                else if(litera == 'u'){

                    k = k + 2;
                    n = napis[k] - '0';

                    w = 0;

                    d = k + 2;

                    while(w < n){

                        w = w + 1;
                        d = d + 1;
                    }

                    check = d;
                    sprawdza = true;
                }
                else if(litera == 'w'){

                    k = k + 2;
                    n = napis[k] - '0';

                    if(n == 1){
                        
                        wynik = wynik + parametrA;
                    }
                    else if(n == 2){
                        
                        wynik = wynik + parametrB;
                    }
                    else if(n == 3){
                        
                        wynik = wynik + parametrC;
                    }

                    d = k + 2;                      
                    check = d;
                    z = d;

                }
                else if(litera == 'W'){

                    start = k;

                    k = k + 2;
                    n = napis[k] - '0';

                    k = k + 2;
                    m = napis[k] - '0';

                    w = 0;

                    if(n == 1){

                        w = parametr1.size();

                        if(w > m){

                            parametr1.resize(m);

                            wynik = wynik + parametr1;
                        }
                        else if(w < m){

                            parametr1.resize(m, ' ');

                            wynik = wynik + parametr1;

                        }
                        else{   //w==m

                            wynik = wynik + parametr1;
                        }
                    }
                    else if(n == 2){

                        w = parametr2.size();

                        if(w > m){

                            parametr2.resize(m);

                            wynik = wynik + parametr2;
                        }
                        else if(w < m){

                            parametr2.resize(m, ' ');

                            wynik = wynik + parametr2;

                        }
                        else{   //w==m

                            wynik = wynik + parametr2;
                        }

                    }
                    else if(n == 3){

                        w = parametr3.size();

                        if(w > m){

                            parametr3.resize(m);

                            wynik = wynik + parametr3;
                        }
                        else if(w < m){

                            parametr3.resize(m, ' ');

                            wynik = wynik + parametr3;
                        }
                        else{   //w==m

                            wynik = wynik + parametr3;
                        }

                    }
                
                    d = k + 2;
                    z = d;
                    check = d;
                    sprawdza = true;
                }
                else if(litera == 'U'){

                    k = k + 2;
                    n = napis[k] - '0';

                    i = 0;

                    if(wynik.size() > n){

                        while((i < (wynik.size() - n))){

                            if((i < (wynik.size() - n)) && (wynik[i] != '\0')){

                                eliminacja = eliminacja + wynik[i];
                            }
                            else{
                                i = (wynik.size() - n);
                            }

                            i++;
                        }
                        i++;
                    }

                    wynik = eliminacja;

                    eliminacja = "";

                    d = k + 2;
                    sprawdza = true;
                    check = d;
                    z = d;
                }
            }
        }

        uwaga = false;

        if(sprawdza == true){
            sprawdza = false;
        }
        else{
            z = z + 1;
        }
    }

    return wynik;
}

string NajwiekszeSlowo(string napis){

    string wynik = "";

    string slowoA = "";
    string slowoB = "";
    int slowa = 1;
    int i = 0;
    int j = 0;
    int check = 0;
    int licznik = 0;
    int counter = 0;

    while(napis[i] != '\0'){

        if(napis[i] == ' '){

            slowa = slowa + 1;
        }

        i = i + 1;
    }


    i = 0;

    if(slowa == 1){

        while(napis[i] != '\0'){

            wynik = wynik + napis[i];
            i = i + 1;
        }
    }
    else{

        i = 0;

        while(licznik < slowa){

            slowoA = "";

            while((napis[i] != ' ') && (napis[i] != '\0')){
                slowoA = slowoA + napis[i];
                i = i + 1;
            }

            //cout << slowoA << endl;

            while(counter < slowa){

                slowoB = "";

                while((napis[j] != ' ') && (napis[j] != '\0')){
                    slowoB = slowoB + napis[j];
                    j = j + 1;
                }

                if(slowoA >= slowoB){
                    check = check + 1;
                }
                else{
                    counter = (slowa + 1);
                }

                j = j + 1;

                counter = counter + 1;
            }

            counter = 0;
            j = 0;

            if(check == slowa){
                wynik = wynik + slowoA;
                licznik = slowa;
            }
            else{

                check = 0;

                if(napis[i] == ' '){

                    licznik = licznik + 1;
                    i = i + 1;
                }

                if(napis[i] == '\0'){

                    licznik = licznik + 1;
                    i = i + 1;
                }
            }
        }
    }

    return wynik;
}   //dziala


string NormalizujNapis(string napis){       //tylko litery spacje, kropki i przecinki

    string wynik = "";

    int i = 0;
    int j = 0;
    bool check = false;
    int sameSpacje = 0;
    int w = 0;

    if(napis[0] == ' '){

        while(napis[i] == ' '){

            i = i + 1;
        }
    }

    while(napis[i] != '\0'){

        if((napis[i] != ' ') && (napis[i] != '.') && (napis[i] != ',')){
            wynik = wynik + napis[i];
        }
        else{
            check = true;

            if(napis[i] == ' '){

                j = i;

                w = j;
                while(napis[w] != '\0'){

                    if(napis[w] == ' '){
                        sameSpacje++;
                    }

                    w++;
                }
         
                sameSpacje = 0;

                while(napis[j] == ' '){
                    j = j + 1;
                }
                if(j == w){

                }
                else{

                    if((napis[j] == '.') || (napis[j] == ',')){
                        
                        wynik = wynik + napis[j];

                        w = j;
                        while(napis[w] != '\0'){

                            if(napis[w] == ' '){
                                sameSpacje++;
                            }

                            w++;
                        }
                        //cout << sameSpacje << endl;
                        //cout << (w - j) << endl;

                        if(sameSpacje == (w - j - 1)){
                            

                        }
                        else{
                            wynik = wynik + ' ';
                        }
                        j = j + 1;
                        
                    }
                    else{
                        wynik = wynik + ' ';
                    }
                
                }
                i = j;
            }
            else if((napis[i] == '.') || (napis[i] == ',')){

                wynik = wynik + napis[i];
                check = false;

                if((napis[i + 1] != ' ') && (napis[i + 1] != '\0')){
                    wynik = wynik + ' ';
                }
                else if(napis[i + 1] != '\0'){

                    w = i;
                    while(napis[w] != '\0'){

                        if(napis[w] == ' '){
                            sameSpacje++;
                        }

                        w++;
                    }
                    if(sameSpacje == (w - i - 1)){
                        
                        wynik = wynik + ' ';
                    }
                }
            }
        }

        sameSpacje = 0;
        
        if(check == true){
            check = false;
        }
        else{
            i = i + 1;
        }
    }

    return wynik;
} //dziala

string UsunSlowo(string napis, int n){

    string wynik = "";

    int i = 0;
    int licznik = 1;
    int slowa = 1;
    int j = 0;
    bool check = false;

    if(napis[0] == ' '){

        licznik = 0;
        slowa = 0;
    }

    while(napis[i] != '\0'){

        if( (napis[i] == ' ') && ( (napis[i + 1] != ' ') && (napis[i + 1] != '\0') ) ){

            slowa = slowa + 1;
        }

        i = i + 1;
    }

    i = 0;

    if((n > slowa) || (n <= 0)){

        while(napis[i] != '\0'){

            wynik = wynik + napis[i];

            i = i + 1;
        }
    }
    else{
    
        while((napis[i] != '\0') && (check == false)){

            if(n == licznik){

                check = true;

                j = 0;

                while(j < i){

                    wynik = wynik + napis[j];

                    j = j + 1;
                }
                while((napis[j] != ' ') && (napis[j] != '\0')){

                    j = j + 1;
                }
                //wynik = wynik + napis[j];
                while(napis[j] != '\0'){

                    wynik = wynik + napis[j];
                    j = j + 1;
                }
            }

            if( (napis[i] == ' ') && ( (napis[i + 1] != ' ') && (napis[i + 1] != '\0') ) ){
                licznik = licznik + 1;
            }

            i = i + 1;
        }
    }
    
    return wynik;
}   //dziala