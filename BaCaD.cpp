//Tomasz Jarzabek

#include <iostream>

using namespace std;

int main(){

    int n;

    cin >> n;           //dlugosc krawedzi

    long long int tablica[n][n][n];


    long long int wyznacznik;
    long long int znak = 1;
    long long int temp;
    int m = 0;
    bool sprawdza = false;
    bool exit = false;

    int d = 0;
    int w = 0;
    int h = 0;

    char operacja;

    while(d < n){

        while(h < n){
            
            while(w < n){
                
                cin >> tablica[w][h][d];
                w = w + 1;
            }

            w = 0;
            h = h + 1;
        }
        
        h = 0;
        d = d + 1;
    }

    int l;      //poziom wierzcholka
    int v;      //pion wierzcholka
    int p;      //panel wierzcholka

    int suma = 0;

    int sprawdzaL;
    int sprawdzaV;
    int sprawdzaP;

    int i = 0;          //w
    int j = 0;          //d
    int k = 0;          //h

    int realW;
    int realD;
    int realH;

    //cout << "---------------" << endl;

    cin >> operacja;

    while(operacja != 'E'){         //jak mamy E to konczymy program

        long long int macierz[n][n];

        if(operacja == 'C'){                //prostopadloscian

            int height;      //wysokosc
            int width;      //szerokosc
            int depth;      //glebokosc

            cin >> l;
            cin >> v;
            cin >> p;
            cin >> height;
            cin >> width;
            cin >> depth;

            //cout << "---------------" << endl;

            if((height == 0) && (width == 0) && (depth == 0)){

                if((l >= 0) && (v >= 0) && (p >= 0)){
                    if((l < n) && (v < n) && (p < n)){
                        suma = tablica[v][l][p];
                    }
                }
            }
            else{
                if(l > ((n - 1) / 2)){              //od l do dolu
                    sprawdzaL = -1;
                }
                else{                       //od l do gory
                    sprawdzaL = 1;
                }

                if(v > ((n - 1) / 2)){
                    sprawdzaV = -1;
                }
                else{
                    sprawdzaV = 1;
                }
                
                if(p > ((n - 1) / 2)){
                    sprawdzaP = -1;
                }
                else{
                    sprawdzaP = 1;
                }

                while(k <= depth){

                    while(j <= height){

                        while(i <= width){
                            
                            realW = v + (i * sprawdzaV);
                            realH = l + (j * sprawdzaL);
                            realD = p + (k * sprawdzaP);

                            if((realW >= 0 && realW < n) && (realH >= 0 && realH < n) && (realD >= 0 && realD < n)){

                                suma = suma + tablica[realW][realH][realD];
                            }

                            i = i + 1;
                        }

                        i = 0;
                        j = j + 1;
                    }

                    j = 0;
                    k = k + 1;
                }
            }

            cout << suma << endl;
        }   //dziala

        else if(operacja == 'T'){           //czworoscian

            cin >> l;
            cin >> v;
            cin >> p;

            int e;

            cin >> e;

            //cout << "---------------" << endl;

            if(e == 0){

                if((l >= 0) && (v >= 0) && (p >= 0)){
                    if((l < n) && (v < n) && (p < n)){
                        suma = tablica[v][l][p];
                    }
                }
            }
            else{
                if(l > ((n - 1) / 2)){              //od l do dolu
                    sprawdzaL = -1;
                }
                else{                       //od l do gory
                    sprawdzaL = 1;
                }

                if(v > ((n - 1) / 2)){
                    sprawdzaV = -1;
                }
                else{
                    sprawdzaV = 1;
                }
                
                if(p > ((n - 1) / 2)){
                    sprawdzaP = -1;
                }
                else{
                    sprawdzaP = 1;
                }

                while(k <= e){

                    while(j <= (e - k)){

                        while(i <= (e - k - j)){
                            
                            realW = v + (i * sprawdzaV);
                            realH = l + (j * sprawdzaL);
                            realD = p + (k * sprawdzaP);

                            if((realW >= 0 && realW < n) && (realH >= 0 && realH < n) && (realD >= 0 && realD < n)){

                                //if((realW + realH + realD) <= e){

                                    suma = suma + tablica[realW][realH][realD];
                                
                                //}
                            }

                            i = i + 1;
                        }

                        i = 0;
                        j = j + 1;
                    }

                    j = 0;
                    k = k + 1;
                }

            }

            cout << suma << endl;

        }

        else if(operacja == 'O'){           //oktal

            cin >> l;
            cin >> v;
            cin >> p;

            int radius;

            cin >> radius;

            if(radius == 0){

                if((l >= 0) && (v >= 0) && (p >= 0)){
                    if((l < n) && (v < n) && (p < n)){
                        suma = tablica[v][l][p];
                    }
                }
            }
            else{

                if(l > ((n - 1) / 2)){              //od l do dolu
                    sprawdzaL = -1;
                }
                else{                       //od l do gory
                    sprawdzaL = 1;
                }

                if(v > ((n - 1) / 2)){
                    sprawdzaV = -1;
                }
                else{
                    sprawdzaV = 1;
                }
                
                if(p > ((n - 1) / 2)){
                    sprawdzaP = -1;
                }
                else{
                    sprawdzaP = 1;
                }

                while(k <= radius){

                    while(j <= radius){

                        while(i <= radius){
                            
                            realW = v + (i * sprawdzaV);
                            realH = l + (j * sprawdzaL);
                            realD = p + (k * sprawdzaP);

                            if((realW >= 0 && realW < n) && (realH >= 0 && realH < n) && (realD >= 0 && realD < n)){
                                
                                if( ( ( (v - realW) * (v - realW) ) + ( (l - realH) * (l - realH) ) + ( (p - realD) * (p - realD) ) ) <= (radius * radius) ){

                                    suma = suma + tablica[realW][realH][realD];
                                }
                            }

                            i = i + 1;
                        }

                        i = 0;
                        j = j + 1;
                    }
                    
                    j = 0;
                    k = k + 1;
                }
            }

            cout << suma << endl;
        }   //dziala

        else if(operacja == 'D'){           //wyznacznik

            char wybor;             //moze byc l, v, p czyli poziom, pion, panel
            int numer;

            cin >> wybor;
            cin >> numer;

            k = 0;
            j = 0;
            i = 0;

            if(wybor == 'l'){                   //to jest wybrany poziom

                while(i < n){

                    while(j < n){

                        macierz[i][j] = tablica[i][numer][j];

                        j = j + 1;
                    }

                    j = 0;

                    i = i + 1;
                }
            }
            else if(wybor == 'v'){

                while(i < n){

                    while(j < n){

                        macierz[i][j] = tablica[numer][i][j];

                        j = j + 1;
                    }

                    j = 0;

                    i = i + 1;
                }
            }
            else if(wybor == 'p'){

                while(i < n){

                    while(j < n){

                        macierz[i][j] = tablica[i][j][numer];

                        j = j + 1;
                    }

                    j = 0;

                    i = i + 1;
                }
            }

            i = 0;
            j = 0;
            k = 0;

            while(k < (n - 1)){
                    
                if(macierz[k][k] == 0){

                    m = k + 1;
                    while((m < n) && (exit == false)){

                        if(macierz[m][k] != 0){

                            while(i < n){

                                temp = macierz[m][i];
                                macierz[m][i] = macierz[k][i];
                                macierz[k][i] = temp;

                                i = i + 1;
                            }

                            znak = -znak;
                            exit = true;
                        }

                        if(exit == false){
                            m = m + 1;
                        }
                    }
                        

                    if(m == n){
                        wyznacznik = 0;
                        sprawdza = true;
                    }
                } 
    
                i = k + 1;

                while(i < n){

                    j = k + 1;

                    while(j < n){

                        macierz[i][j] = ((macierz[i][j] * macierz[k][k]) - (macierz[i][k] * macierz[k][j]));

                        if(k != 0){
                            if(macierz[k-1][k-1] != 0){
                                macierz[i][j] = (macierz[i][j] / macierz[k-1][k-1]);
                            }
                        }

                        j = j + 1;
                    }

                    i = i + 1;
                }

                k = k + 1;
                m = 0;
                i = 0;
                exit = false;
            }

            if(sprawdza == false){
                wyznacznik = znak * macierz[n - 1][n - 1];
            }
            
            cout << wyznacznik << endl;
        }

        i = 0;
        j = 0;
        k = 0;
        m = 0;
        suma = 0;
        znak = 1;
        sprawdza = false;
        exit = false;

        cin >> operacja;
    }

    return 0;
}