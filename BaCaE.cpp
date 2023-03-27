//Tomasz Jarzabek

#include <iostream>

using namespace std;

//unsigned short to 65535

struct MIEJSCE{

    unsigned short towar;
    char etykieta[2];
};

struct POLKA{

    MIEJSCE tablicaMiejsc[128];
    short int miejsca;   
};

struct REGAL{

    POLKA tablicaPolek[128];
    short int polki;
};

struct MAGAZYN{

    REGAL tablicaRegalow[128];
    short int regaly;
    POLKA handyShelf;
};

struct SKLAD{

    MAGAZYN tablicaMagazynow[128];
    short int magazyny;
    REGAL handyRack;
    POLKA handyShelf;
};

SKLAD sklad;

long long suma = 0;

bool porownanie(char polecenie[], char const wyraz[]){

    int i = 0;
    bool wynik = true;

    while(polecenie[i] != '\0'){

        if(polecenie[i] != wyraz[i]){

            wynik = false;
            
        }
        if((polecenie[i + 1] == '\0') && (wyraz[i + 1] != '\0')){

            wynik = false;
        }
        if((wyraz[i + 1] == '\0') && (polecenie[i + 1] != '\0')){

            wynik = false;
        }

        i = i + 1;
    }

    return wynik;
}

void SET_AP(int wb, int rb, int sb, int Pe){

    int temp = 0;

    if(wb >= sklad.magazyny){
        cout << "error" << endl;
    }
    else{
        if(rb >= sklad.tablicaMagazynow[wb].regaly){
            cout << "error" << endl;
        }
        else{
            if(sb >= sklad.tablicaMagazynow[wb].tablicaRegalow[rb].polki){
                cout << "error" << endl;        
            }
            else{

                if(Pe > 128){
                    cout << "error" << endl;
                }
                else{
                    

                    int w = 0;
    
                    temp = sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].miejsca;
                    sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].miejsca = Pe;

                
                    if(Pe > temp){

                        w = temp;

                        while(w < Pe){

                            suma = suma - sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].towar;

                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].towar = 0;
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].etykieta[0] = '0';
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].etykieta[1] = '0';

                            w = w + 1;
                        }
                    }
                    else if(Pe < temp){
                        
                        w = Pe;

                        while(w < temp){

                            suma = suma - sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].towar;

                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].towar = 0;
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].etykieta[0] = '0';
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[w].etykieta[1] = '0';

                            w = w + 1;
                        }   
                    }
                    else{

                    }
                    
                }
            }
        }
    }
}

void SET_AS(int wb, int rb, int Se, int Pe){

    int k = 0;
    int w = 0;
    int temp = 0;

    if(wb >= sklad.magazyny){
        cout << "error" << endl;
    }
    else{
        if(rb >= sklad.tablicaMagazynow[wb].regaly){
            cout << "error" << endl;
        }
        else{
      
            if(Se > 128){
                cout << "error" << endl;
            }
            else{
                
                if(Se == 0){

                    

                    sklad.tablicaMagazynow[wb].tablicaRegalow[rb].polki = Se;

                    while(k < 128){

                        while(w < 128){

                            suma = suma - sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].towar;

                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                            w = w + 1;
                        }
                        
                        sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].miejsca = Pe;

                        w = 0;
                        k = k + 1;
                    }
                
                }
                else{  

                    temp = sklad.tablicaMagazynow[wb].tablicaRegalow[rb].polki;
                    sklad.tablicaMagazynow[wb].tablicaRegalow[rb].polki = Se;

                    if(Se >= temp){

                        k = 0;

                        while(k < sklad.tablicaMagazynow[wb].tablicaRegalow[rb].polki){

                            SET_AP(wb, rb, k, Pe);

                            k = k + 1;
                        }
                    }
                    else if(Se < temp){

                        k = Se;

                        while(k < temp){

                            while(w < 128){

                                suma = suma - sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].towar;

                                sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                w = w + 1;
                            }

                            w = 0;
                            
                            sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[k].miejsca = Pe;

                            k = k + 1;
                        }
                    }  
                }
            }
        }
    }
}

void SET_AR(int wb, int Re, int Se, int Pe){

    int temp = 0;
    int j = 0; 
    int k = 0;
    int w = 0;

    if(wb >= sklad.magazyny){
        cout << "error" << endl;
    }
    else{

        if(Re > 128){
            cout << "error" << endl;
        }
        else{

            if(Re == 0){

                sklad.tablicaMagazynow[wb].regaly = Re;

                while(j < 128){

                    while(k < 128){

                        while(w < 128){

                            suma = suma - sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar;

                            sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                            sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                            sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                            w = w + 1;
                        }
                        
                        sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].miejsca = Pe;

                        w = 0;
                        k = k + 1;
                    }

                    sklad.tablicaMagazynow[wb].tablicaRegalow[j].polki = Se;

                    k = 0;
                    j = j + 1;
                }
            }
            else{   

                temp = sklad.tablicaMagazynow[wb].regaly;
                sklad.tablicaMagazynow[wb].regaly = Re;

                if(Re >= temp){

                    j = 0;

                    while(j < sklad.tablicaMagazynow[wb].regaly){

                        SET_AS(wb, j, Se, Pe);
                        j = j + 1;
                    }
                }

                else if(Re < temp){

                    j = 0;

                    while(j < temp){

                        int k = 0;
                        int w = 0;


                        while(k < 128){

                            while(w < 128){

                                suma = suma - sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar;

                                sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                w = w + 1;
                            }
                            
                            sklad.tablicaMagazynow[wb].tablicaRegalow[j].tablicaPolek[k].miejsca = Pe;

                            w = 0;
                            k = k + 1;
                        }

                        k = 0;

                        sklad.tablicaMagazynow[wb].tablicaRegalow[j].polki = Se;
                        j = j + 1;
                    }
                }
            }
        }
    }
}


int main(){


    long long sum = 0;

    char polecenie[20] = "AAA";

    bool sprawdza = false;

    int W;
    int R;
    int S;
    int P;
    int A;

    int i = 0;
    int j = 0;
    int k = 0;
    int w = 0;

    //set
    int wb;
    int rb;
    int sb;
    int Pe;
    int Se;
    int Re;
    int We;

    int temp;

    //put
    int r;
    int s;
    int p;

    //mov
    int we;
    int re;
    int se;

    int difference = 0;

    int pierwszy;
    int drugi;

    const int USHORT = 65535;


    cin >> polecenie;

    while( !porownanie(polecenie, "END")){

        if(porownanie(polecenie, "FILL")){

            sprawdza = false;

            cin >> W;
            cin >> R;
            cin >> S;
            cin >> P;
            cin >> A;     
            
            if(W > 128){
               W = 128;
               sprawdza = true;
            }
            if(R > 128){
                R = 128;
                sprawdza = true;
            }
            if(S > 128){
                S = 128;
                sprawdza = true;
            }
            if(P > 128){
                P = 128;
                sprawdza = true;
            } 

            if(sprawdza == true){

                cout << "error" << endl;
            }
            else{

                suma = 0;

                sklad.magazyny = W;

                sklad.handyRack.polki = S;

                while(k < S){

                    sklad.handyRack.tablicaPolek[k].miejsca = P;

                    while(w < P){

                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar = A;
                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                        suma = suma + A;

                        w = w + 1;
                    }

                    w = 0;

                    k = k + 1;
                }

                w = 0;
                k = 0;

                sklad.handyShelf.miejsca = P;

                while(w < P){

                    sklad.handyShelf.tablicaMiejsc[w].towar = A;
                    sklad.handyShelf.tablicaMiejsc[w].etykieta[0] = '0';
                    sklad.handyShelf.tablicaMiejsc[w].etykieta[1] = '0';

                    suma = suma + A;

                    w = w + 1;
                }

                w = 0;

                while(i < W){

                    sklad.tablicaMagazynow[i].regaly = R;

                    while(j < R){

                        sklad.tablicaMagazynow[i].tablicaRegalow[j].polki = S;

                        while(k < S){

                            sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].miejsca = P;

                            while(w < P){

                                sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar = A;
                                sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                suma = suma + A;
                                w = w + 1;
                            }

                            w = 0;

                            k = k + 1;
                        }

                        w = 0;

                        k = 0;

                        j = j + 1;
                    }

                    sklad.tablicaMagazynow[i].handyShelf.miejsca = P;

                    w = 0;

                    while(w < P){

                        sklad.tablicaMagazynow[i].handyShelf.tablicaMiejsc[w].towar = A;
                        sklad.tablicaMagazynow[i].handyShelf.tablicaMiejsc[w].etykieta[0] = '0';
                        sklad.tablicaMagazynow[i].handyShelf.tablicaMiejsc[w].etykieta[1] = '0';

                        suma = suma + A;

                        w = w + 1;
                    }

                    w = 0;

                    j = 0;

                    i = i + 1;
                }
            }
        } //dziala

        else if(porownanie(polecenie, "GET-E")){

            cout << suma << endl;
        } //dziala

        else if(porownanie(polecenie, "GET-W")){
            
            int W;

            j = 0;
            k = 0;
            w = 0;

            cin >> W;

            if(W >= (sklad.magazyny)){

                cout << "error" << endl;
            }
            else{
     
                while(j < sklad.tablicaMagazynow[W].regaly){

                    while(k < sklad.tablicaMagazynow[W].tablicaRegalow[j].polki){

                        while(w < sklad.tablicaMagazynow[W].tablicaRegalow[j].tablicaPolek[k].miejsca){

                            sum = sum + sklad.tablicaMagazynow[W].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar;
                            w = w + 1;
                        }

                        w = 0;

                        k = k + 1;
                    }

                    k = 0;  
                        
                    j = j + 1;
                }

                w = 0;
         
                while(w < sklad.tablicaMagazynow[W].handyShelf.miejsca){

                    sum = sum + sklad.tablicaMagazynow[W].handyShelf.tablicaMiejsc[w].towar;

                    w = w + 1;
                }

                w = 0; 

                cout << sum << endl;
            } 
        } //dziala

        else if(porownanie(polecenie, "GET-RW")){

            int W;
            int R;

            cin >> W;
            cin >> R;

            k = 0;
            w = 0;

            if(W >= sklad.magazyny){
                cout << "error" << endl;
            }
            else{
                
                if(R >= sklad.tablicaMagazynow[W].regaly){
                    cout << "error" << endl;
                }
                else{
                
                    while(k < sklad.tablicaMagazynow[W].tablicaRegalow[R].polki){

                        while(w < sklad.tablicaMagazynow[W].tablicaRegalow[R].tablicaPolek[k].miejsca){

                            sum = sum + sklad.tablicaMagazynow[W].tablicaRegalow[R].tablicaPolek[k].tablicaMiejsc[w].towar;
                            w = w + 1;
                        }

                        w = 0;

                        k = k + 1;
                    }

                    cout << sum << endl;
                }
            }
        } //dziala

        else if(porownanie(polecenie, "GET-RH")){

            while(k < sklad.handyRack.polki){

                while(w < sklad.handyRack.tablicaPolek[k].miejsca){

                    sum = sum + sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar;

                    w = w + 1;
                }

                w = 0;

                k = k + 1;
            }

            cout << sum << endl;
        
        } //dziala

        else if(porownanie(polecenie, "GET-SW")){

            int W;
            int R;
            int S;

            cin >> W;
            cin >> R;
            cin >> S;

            if(W >= sklad.magazyny){
                cout << "error" << endl;
            }
            else{

                if(R >= sklad.tablicaMagazynow[W].regaly){
                    cout << "error" << endl;
                }
                else{

                    if(S >= sklad.tablicaMagazynow[W].tablicaRegalow[R].polki){
                        cout << "error" << endl;
                    }
                    else{

                        w = 0;

                        while(w < sklad.tablicaMagazynow[W].tablicaRegalow[R].tablicaPolek[S].miejsca){

                            sum = sum + sklad.tablicaMagazynow[W].tablicaRegalow[R].tablicaPolek[S].tablicaMiejsc[w].towar;
                            w = w + 1;
                        }

                        cout << sum << endl;

                    }
                }
            }
        } //dziala

        else if(porownanie(polecenie, "GET-SH")){

            int W;

            cin >> W;

            if(W >= sklad.magazyny){
                cout << "error" << endl;
            }
            else{

                w = 0;

                while(w < sklad.tablicaMagazynow[W].handyShelf.miejsca){

                    sum = sum + sklad.tablicaMagazynow[W].handyShelf.tablicaMiejsc[w].towar;

                    w = w + 1;
                }

                cout << sum << endl;
            }
        } //dziala

        else if(porownanie(polecenie, "GET-SR")){

            int S;

            cin >> S;

            if(S >= sklad.handyRack.polki){
                
                cout << "error" << endl;
            }
            else{
                while(w < sklad.handyRack.tablicaPolek[S].miejsca){

                    sum = sum + sklad.handyRack.tablicaPolek[S].tablicaMiejsc[w].towar;

                    w = w + 1;
                }

                cout << sum << endl;
            }
        } //dziala

        else if(porownanie(polecenie, "GET-S")){


            while(w < sklad.handyShelf.miejsca){

                sum = sum + sklad.handyShelf.tablicaMiejsc[w].towar;

                w = w + 1;
            }

            cout << sum << endl;
            
        } //dziala

        else if(porownanie(polecenie, "SET-AP")){

            cin >> wb;
            cin >> rb;
            cin >> sb;
            cin >> Pe;
            
            SET_AP(wb, rb, sb, Pe);
            
        }

        else if(porownanie(polecenie, "SET-AS")){

            cin >> wb;
            cin >> rb;
            cin >> Se;
            cin >> Pe;
            
            SET_AS(wb, rb, Se, Pe);
            
        }

        else if(porownanie(polecenie, "SET-AR")){

            cin >> wb;
            cin >> Re;
            cin >> Se;
            cin >> Pe;
            
            SET_AR(wb, Re, Se, Pe);
            
        }

        else if(porownanie(polecenie, "SET-AW")){

            cin >> We;
            cin >> Re;
            cin >> Se;
            cin >> Pe;


            if(We > 128){
                cout << "error" << endl;
            }
            else{

                if(We == 0){

                    sklad.magazyny = We;

                    i = 0;
                    j = 0;
                    k = 0;
                    w = 0;

                    while(i < 128){

                        while(j < 128){

                            while(k < 128){

                                while(w < 128){

                                    suma = suma - sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar;

                                    sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                    sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                    sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                    w = w + 1;
                                }
                                
                                sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].miejsca = Pe;

                                w = 0;
                                k = k + 1;
                            }

                            sklad.tablicaMagazynow[i].tablicaRegalow[j].polki = Se;

                            k = 0;
                            j = j + 1;
                        }
                        sklad.tablicaMagazynow[i].regaly = Re;

                        j = 0;
                        i = i + 1;
                    }

                }
                else{

                    temp = sklad.magazyny;
                    sklad.magazyny = We;

                    if(We >= temp){

                        i = 0;

                        while(i < sklad.magazyny){

                            SET_AR(i, Re, Se, Pe);
                            i = i + 1;
                        }
                    }
                    else if(We < temp){

                        i = We;

                        while(i < temp){

                            while(j < 128){

                                while(k < 128){

                                    while(w < 128){

                                        suma = suma - sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar;

                                        sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                        sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                        sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                        w = w + 1;
                                    }
                                    
                                    sklad.tablicaMagazynow[i].tablicaRegalow[j].tablicaPolek[k].miejsca = Pe;

                                    w = 0;
                                    k = k + 1;
                                }

                                sklad.tablicaMagazynow[i].tablicaRegalow[j].polki = Se;

                                k = 0;
                                j = j + 1;
                            }
                            sklad.tablicaMagazynow[i].regaly = Re;

                            j = 0;

                            i = i + 1;
                        }
                    }
                }
            }
            
        }

        else if(porownanie(polecenie, "SET-HW")){

            cin >> wb;
            cin >> P;

            if(wb >= sklad.magazyny){
                cout << "error" << endl;
            }
            else{
                if(P > 128){
                    cout << "error" << endl;
                }
                else{

                    temp = sklad.tablicaMagazynow[wb].handyShelf.miejsca;
                    sklad.tablicaMagazynow[wb].handyShelf.miejsca = P;

                    if(P > temp){

                        w = temp;

                        while(w < sklad.tablicaMagazynow[wb].handyShelf.miejsca){

                            suma = suma - sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].towar;

                            sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].towar = 0;
                            sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].etykieta[0] = '0';
                            sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].etykieta[1] = '0';

                            w = w + 1;
                        }

                    }
                    else if(P < temp){

                        w = P;

                        while(w < temp){

                            suma = suma - sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].towar;

                            sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].towar = 0;
                            sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].etykieta[0] = '0';
                            sklad.tablicaMagazynow[wb].handyShelf.tablicaMiejsc[w].etykieta[1] = '0';

                            w = w + 1;
                        }
                    }
                    else{

                    }

                }
            }
        }

        else if(porownanie(polecenie, "SET-HR")){

            cin >> S;
            cin >> P;

            int temp2 = 0;

            if(S > 128){
                cout << "error" << endl;
            }
            else{
                if(P > 128){
                    cout << "error" << endl;
                }
                else{

                    if(S == 0){

                        sklad.handyRack.polki = S;

                        k = 0;
                        w = 0;

                        while(k < 128){

                            while(w < 128){

                                suma = suma - sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar;

                                sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                w = w + 1;
                            }

                            w = 0;
                            k = k + 1;

                            sklad.handyRack.tablicaPolek[k].miejsca = P;
                        }

                    }
                    else{

                        temp = sklad.handyRack.polki;
                        sklad.handyRack.polki = S;
                        k = 0;

                        if(S < temp){

                            k = S;

                            while(k < temp){

                                temp2 = sklad.handyRack.tablicaPolek[k].miejsca;
                                sklad.handyRack.tablicaPolek[k].miejsca = P;

                                if(P > temp2){

                                    w = temp2;

                                    while(w < P){

                                        suma = suma - sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar;

                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                        w = w + 1;
                                    }
                                }
                                else if(P < temp2){

                                    w = P;

                                    while(w < temp2){

                                        suma = suma - sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar;

                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                        w = w + 1;
                                    }
                                }
                                else{

                                }
                                
                                k = k + 1;
                                w = 0;
                            }

                        }
                        else if(S > temp){

                            k = temp;

                            while(k < S){

                                temp2 = sklad.handyRack.tablicaPolek[k].miejsca;
                                sklad.handyRack.tablicaPolek[k].miejsca = P;

                                if(P > temp2){

                                    w = temp2;

                                    while(w < P){

                                        suma = suma - sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar;

                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                        w = w + 1;
                                    }
                                }
                                else if(P < temp2){

                                    w = P;

                                    while(w < temp2){

                                        suma = suma - sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar;

                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].towar = 0;
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[0] = '0';
                                        sklad.handyRack.tablicaPolek[k].tablicaMiejsc[w].etykieta[1] = '0';

                                        w = w + 1;
                                    }
                                }
                                else{

                                }
                                
                                k = k + 1;
                                w = 0;
                            }

                        }
                        else{

                        }
                    }  
                } 
            }
        }

        else if(porownanie(polecenie, "SET-HS")){

            cin >> P;

            if(P > 128){
                cout << "error" << endl;
            }
            else{

                temp = sklad.handyShelf.miejsca;
                sklad.handyShelf.miejsca = P;

                if(P > temp){

                    w = temp;

                    while(w < sklad.handyShelf.miejsca){

                        suma = suma - sklad.handyShelf.tablicaMiejsc[w].towar;

                        sklad.handyShelf.tablicaMiejsc[w].towar = 0;
                        sklad.handyShelf.tablicaMiejsc[w].etykieta[0] = '0';
                        sklad.handyShelf.tablicaMiejsc[w].etykieta[1] = '0';

                        w = w + 1;
                    }
                }
                else if(P < temp){

                    w = P;

                    while(w < temp){

                        suma = suma - sklad.handyShelf.tablicaMiejsc[w].towar;

                        sklad.handyShelf.tablicaMiejsc[w].towar = 0;
                        sklad.handyShelf.tablicaMiejsc[w].etykieta[0] = '0';
                        sklad.handyShelf.tablicaMiejsc[w].etykieta[1] = '0';

                        w = w + 1;
                    }   
                }
                else{

                }
            }
        }

        //polecenia PUT

        else if(porownanie(polecenie, "PUT-W")){

            cin >> w;
            cin >> r;
            cin >> s;
            cin >> p;
            cin >> A;

            if((w >= sklad.magazyny)){

                cout << "error" << endl;
            }
            else{
                if(r >= sklad.tablicaMagazynow[w].regaly){
                    cout << "error" << endl;
                }
                else{
                    if(s >= sklad.tablicaMagazynow[w].tablicaRegalow[r].polki){
                        cout << "error" << endl;
                    }
                    else{
                        if(p >= sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].miejsca){
                            cout << "error" << endl;
                        }
                        else{

                            if((sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar + A) > USHORT){
                                suma = suma + (USHORT - sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar);
                                sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar = USHORT;
                            }
                            else{
                                sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar = sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar + A;
                                suma = suma + A;
                            }
                        }
                    }
                }
            }
        } //dziala

        else if(porownanie(polecenie, "PUT-H")){

            cin >> w;
            cin >> p;
            cin >> A;

            if(w >= sklad.magazyny){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.tablicaMagazynow[w].handyShelf.miejsca){
                    cout << "error" << endl;
                }
                else{
                    if((sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar + A) > USHORT){
                        suma = suma + (USHORT - sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar);
                        sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar = USHORT;
                    }
                    else{
                        sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar = sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar + A;
                        suma = suma + A;
                    }
                }
            }
        } //dziala na testerce nie na BaCy

        else if(porownanie(polecenie, "PUT-R")){

            cin >> s;
            cin >> p;
            cin >> A;

            if(s >= sklad.handyRack.polki){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.handyRack.tablicaPolek[s].miejsca){
                    cout << "error" << endl;
                }
                else{
                    if((sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar + A) > USHORT){
                        suma = suma + (USHORT - sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar);
                        sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar = USHORT;
                    }
                    else{
                        sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar = sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar + A;
                        suma = suma + A;
                    }
                }
            }
        } //dziala na testerce nie na BaCy

        else if(porownanie(polecenie, "PUT-S")){
            
            cin >> p;
            cin >> A;

            if(p >= sklad.handyShelf.miejsca){
                cout << "error" << endl;
            }
            else{

                if((sklad.handyShelf.tablicaMiejsc[p].towar + A) > USHORT){
                    suma = suma + (USHORT - sklad.handyShelf.tablicaMiejsc[p].towar);
                    sklad.handyShelf.tablicaMiejsc[p].towar = USHORT;
                }
                else{
                    sklad.handyShelf.tablicaMiejsc[p].towar = sklad.handyShelf.tablicaMiejsc[p].towar + A;
                    suma = suma + A;
                }
            }
        } //dziala

        //polecenia POP

        else if(porownanie(polecenie, "POP-W")){

            cin >> w;
            cin >> r;
            cin >> s;
            cin >> p;
            cin >> A;

            if((w >= sklad.magazyny)){

                cout << "error" << endl;
            }
            else{
                if(r >= sklad.tablicaMagazynow[w].regaly){
                    cout << "error" << endl;
                }
                else{
                    if(s >= sklad.tablicaMagazynow[w].tablicaRegalow[r].polki){
                        cout << "error" << endl;
                    }
                    else{
                        if(p >= sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].miejsca){
                            cout << "error" << endl;
                        }
                        else{

                            if((sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar - A) < 0){
                                suma = suma - (sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar - 0);
                                sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar = 0;
                            }
                            else{
                                sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar = sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar - A;
                                suma = suma - A;
                            }
                        }
                    }
                }
            }
        } //dziala

        else if(porownanie(polecenie, "POP-H")){

            cin >> w;
            cin >> p;
            cin >> A;

            if(w >= sklad.magazyny){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.tablicaMagazynow[w].handyShelf.miejsca){
                    cout << "error" << endl;
                }
                else{
                    if((sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar - A) < 0){
                        suma = suma - (sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar - 0);
                        sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar = 0;
                    }
                    else{
                        sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar = sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar - A;
                        suma = suma - A;
                    }
                }
            }
        } //dziala na testerce nie na BaCy

        else if(porownanie(polecenie, "POP-R")){

            cin >> s;
            cin >> p;
            cin >> A;

            if(s >= sklad.handyRack.polki){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.handyRack.tablicaPolek[s].miejsca){
                    cout << "error" << endl;
                }
                else{
                    if((sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar - A) < 0){
                        suma = suma - (sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar - 0);
                        sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar = 0;
                    }
                    else{
                        sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar = sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar - A;
                        suma = suma - A;
                    }
                }
            }
        } //dziala na testerce nie na BaCy

        else if(porownanie(polecenie, "POP-S")){
            
            cin >> p;
            cin >> A;

            if(p >= sklad.handyShelf.miejsca){
                cout << "error" << endl;
            }
            else{

                if((sklad.handyShelf.tablicaMiejsc[p].towar - A) < 0){
                    suma = suma - (sklad.handyShelf.tablicaMiejsc[p].towar - 0);
                    sklad.handyShelf.tablicaMiejsc[p].towar = 0;
                }
                else{
                    sklad.handyShelf.tablicaMiejsc[p].towar = sklad.handyShelf.tablicaMiejsc[p].towar - A;
                    suma = suma - A;
                }
            }
        } //dziala

        //polecenia etykietowe

        else if(porownanie(polecenie, "SET-LW")){

            cin >> w;
            cin >> r;
            cin >> s;
            cin >> p;

            if((w >= sklad.magazyny)){
                cout << "error" << endl;
            }
            else{
                if(r >= sklad.tablicaMagazynow[w].regaly){
                    cout << "error" << endl;
                }
                else{
                    if(s >= sklad.tablicaMagazynow[w].tablicaRegalow[r].polki){
                        cout << "error" << endl;
                    }
                    else{
                        if(p >= sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].miejsca){
                            cout << "error" << endl;
                        }
                        else{
                            cin >> sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].etykieta[0];
                            cin >> sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].etykieta[1];
                        }
                    }
                }
            }
        }

        else if(porownanie(polecenie, "SET-LH")){

            cin >> w;
            cin >> p;

            if((w >= sklad.magazyny)){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.tablicaMagazynow[w].handyShelf.miejsca){
                    cout << "error" << endl;
                }
                else{
                    cin >> sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].etykieta[0];
                    cin >> sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].etykieta[1];
                }
            }            
        }

        else if(porownanie(polecenie, "SET-LR")){

            cin >> s;
            cin >> p;

            if(s >= sklad.handyRack.polki){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.handyRack.tablicaPolek[s].miejsca){
                    cout << "error" << endl;
                }
                else{
                    cin >> sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].etykieta[0];
                    cin >> sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].etykieta[1];
                }
            }
        }

        else if(porownanie(polecenie, "SET-LS")){
            
            cin >> p;

            if(p >= sklad.handyShelf.miejsca){
                cout << "error" << endl;
            }
            else{
                cin >> sklad.handyShelf.tablicaMiejsc[p].etykieta[0];
                cin >> sklad.handyShelf.tablicaMiejsc[p].etykieta[1];
            }
        }

        else if(porownanie(polecenie, "GET-LW")){

            cin >> w;
            cin >> r;
            cin >> s;
            cin >> p;

            if((w >= sklad.magazyny)){
                cout << "error" << endl;
            }
            else{
                if(r >= sklad.tablicaMagazynow[w].regaly){
                    cout << "error" << endl;
                }
                else{
                    if(s >= sklad.tablicaMagazynow[w].tablicaRegalow[r].polki){
                        cout << "error" << endl;
                    }
                    else{
                        if(p >= sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].miejsca){
                            cout << "error" << endl;
                        }
                        else{
                            if((sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].etykieta[0] == '0') && (sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].etykieta[1] == '0')){
                                cout << "--" << endl;
                            }
                            else{
                                cout << sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].etykieta[0];
                                cout << sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].etykieta[1] << endl;
                            }
                        }
                    }
                }
            }
        }

        else if(porownanie(polecenie, "GET-LH")){

            cin >> w;
            cin >> p;

            if((w >= sklad.magazyny)){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.tablicaMagazynow[w].handyShelf.miejsca){
                    cout << "error" << endl;
                }
                else{
                    if((sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].etykieta[0] == '0') && (sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].etykieta[1] == '0')){
                        cout << "--" << endl;
                    }
                    else{
                        cout << sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].etykieta[0];
                        cout << sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].etykieta[1] << endl;
                    }
                }
            }            
        }

        else if(porownanie(polecenie, "GET-LR")){

            cin >> s;
            cin >> p;

            if(s >= sklad.handyRack.polki){
                cout << "error" << endl;
            }
            else{
                if(p >= sklad.handyRack.tablicaPolek[s].miejsca){
                    cout << "error" << endl;
                }
                else{
                    if((sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].etykieta[0] == '0') && (sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].etykieta[1] == '0')){
                        cout << "--" << endl;
                    }
                    else{
                        cout << sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].etykieta[0];
                        cout << sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].etykieta[1] << endl;
                    }
                }
            }
        }

        else if(porownanie(polecenie, "GET-LS")){
            
            cin >> p;

            if(p >= sklad.handyShelf.miejsca){
                cout << "error" << endl;
            }
            else{
                if((sklad.handyShelf.tablicaMiejsc[p].etykieta[0] == '0') && (sklad.handyShelf.tablicaMiejsc[p].etykieta[1] == '0')){
                    cout << "--" << endl;
                }
                else{
                    cout << sklad.handyShelf.tablicaMiejsc[p].etykieta[0];
                    cout << sklad.handyShelf.tablicaMiejsc[p].etykieta[1] << endl;
                }
            }
        }
        //labels dziala

        //polecenia przenoszace towar
        else if(porownanie(polecenie, "MOV-W")){

            cin >> wb;
            cin >> rb;
            cin >> sb;
            cin >> we;
            cin >> re;
            cin >> se;
            cin >> p;
            cin >> A;

            if((wb >= sklad.magazyny) /*|| (we >= sklad.magazyny) */){
                cout << "error" << endl;
            }
            else{
                if((rb >= sklad.tablicaMagazynow[wb].regaly) /*|| (re >= sklad.tablicaMagazynow[we].regaly) */){
                    cout << "error" << endl;
                }
                else{
                    if((sb >= sklad.tablicaMagazynow[wb].tablicaRegalow[rb].polki) /*|| (se >= sklad.tablicaMagazynow[we].tablicaRegalow[re].polki)*/){
                        cout << "error" << endl;
                    }
                    else{
                        if((p >= sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].miejsca) /*|| (p >= sklad.tablicaMagazynow[we].tablicaRegalow[re].tablicaPolek[se].miejsca)*/){
                            cout << "error" << endl;
                        }
                        else{

                            pierwszy = sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[p].towar;
                            drugi = sklad.tablicaMagazynow[we].tablicaRegalow[re].tablicaPolek[se].tablicaMiejsc[p].towar;

                            if(drugi == 65535){

                            }
                            else{

                                if((pierwszy - A) < 0){
                                    difference = pierwszy;

                                    if((drugi + difference) > USHORT){

                                        while((drugi + difference) > USHORT){

                                            difference = difference - 1;
                                        }
                                    }

                                    sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[p].towar = pierwszy - difference;
                                }
                                else{
                                    difference = A;

                                    if((drugi + difference) > USHORT){

                                        while((drugi + difference) > USHORT){

                                            difference = difference - 1;

                                        }
                                    }

                                    sklad.tablicaMagazynow[wb].tablicaRegalow[rb].tablicaPolek[sb].tablicaMiejsc[p].towar = pierwszy - difference;
                                }
                           
                                sklad.tablicaMagazynow[we].tablicaRegalow[re].tablicaPolek[se].tablicaMiejsc[p].towar = drugi + difference;
                            }
                        }
                    }
                }
            }
        } //dziala na testerce na BaCy nie

        else if(porownanie(polecenie, "MOV-H")){

            cin >> w;
            cin >> r;
            cin >> s;
            cin >> p;
            cin >> A;

            if((w >= sklad.magazyny)){
                cout << "error" << endl;
            }
            else{
                if(r >= sklad.tablicaMagazynow[w].regaly){
                    cout << "error" << endl;
                }
                else{
                    if(s >= sklad.tablicaMagazynow[w].tablicaRegalow[r].polki){
                        cout << "error" << endl;
                    }
                    else{
                        if((p >= sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].miejsca) || (p >= sklad.tablicaMagazynow[w].handyShelf.miejsca)){
                            cout << "error" << endl;
                        }
                        else{

                            pierwszy =  sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar;
                            drugi = sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar;

                            if(drugi == 65535){

                            }
                            else{

                                if((pierwszy - A) < 0){
                                    difference = pierwszy;

                                    if((drugi + difference) > USHORT){

                                        while((drugi + difference) > USHORT){

                                            difference = difference - 1;
                                        }
                                    }

                                    sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar = pierwszy - difference;
                                }
                                else{
                                    difference = A;

                                    if((drugi + difference) > USHORT){

                                        while((drugi + difference) > USHORT){

                                            difference = difference - 1;
                                        }
                                    }

                                    sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].tablicaMiejsc[p].towar = pierwszy - difference;
                                }
                           
                                sklad.tablicaMagazynow[w].handyShelf.tablicaMiejsc[p].towar = drugi + difference;
                            }
                        }
                    }
                }
            }
        } //dziala
        
        else if(porownanie(polecenie, "MOV-R")){

            cin >> w;
            cin >> r;
            cin >> sb;
            cin >> se;
            cin >> p;
            cin >> A;

            if((w >= sklad.magazyny)){
                cout << "error" << endl;
            }
            else{
                if(r >= sklad.tablicaMagazynow[w].regaly){
                    cout << "error" << endl;
                }
                else{
                    if((sb >= sklad.tablicaMagazynow[w].tablicaRegalow[r].polki) /*|| (se >= sklad.handyRack.polki) */){
                        cout << "error" << endl;
                    }
                    else{
                        if((p >= sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[s].miejsca) /*|| (p >= sklad.handyRack.tablicaPolek[se].miejsca)*/){
                            cout << "error" << endl;
                        }
                        else{

                            pierwszy = sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[sb].tablicaMiejsc[p].towar;
                            drugi = sklad.handyRack.tablicaPolek[se].tablicaMiejsc[p].towar;

                            if(drugi == 65535){

                            }
                            else{

                                if((pierwszy - A) < 0){
                                    difference = pierwszy;

                                    if((drugi + difference) > USHORT){

                                        while((drugi + difference) > USHORT){

                                            difference = difference - 1;
                                        }
                                    }

                                    sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[sb].tablicaMiejsc[p].towar = pierwszy - difference;
                                }
                                else{
                                    difference = A;

                                    if((drugi + difference) > USHORT){

                                        while((drugi + difference) > USHORT){

                                            difference = difference - 1;
                                        }
                                    }

                                    sklad.tablicaMagazynow[w].tablicaRegalow[r].tablicaPolek[sb].tablicaMiejsc[p].towar = pierwszy - difference;
                                }
                           
                                sklad.handyRack.tablicaPolek[se].tablicaMiejsc[p].towar = drugi + difference;
                            }
                        }
                    }
                }
            }
        } //dziala na testerce na BaCy nie

        else if(porownanie(polecenie, "MOV-S")){

            cin >> s;
            cin >> p;
            cin >> A;

            if(s >= sklad.handyRack.polki){
                cout << "error" << endl;
            }
            else{
                if((p >= sklad.handyRack.tablicaPolek[s].miejsca) || (p >= sklad.handyShelf.miejsca)){
                    cout << "error" << endl;
                }
                else{

                    pierwszy = sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar;
                    drugi = sklad.handyShelf.tablicaMiejsc[p].towar;

                    if(drugi == 65535){

                    }
                    else{

                        if((pierwszy - A) < 0){
                            difference = pierwszy;

                            if((drugi + difference) > USHORT){

                                while((drugi + difference) > USHORT){

                                    difference = difference - 1;
                                }
                            }

                            sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar = pierwszy - difference;
                        }
                        else{
                            difference = A;

                            if((drugi + difference) > USHORT){

                                while((drugi + difference) > USHORT){

                                    difference = difference - 1;

                                }
                            }

                            sklad.handyRack.tablicaPolek[s].tablicaMiejsc[p].towar = pierwszy - difference;
                        }
                    
                        sklad.handyShelf.tablicaMiejsc[p].towar = drugi + difference;
                    }
                }
            }
        } //dziala



        sum = 0;

        i = 0;
        j = 0;
        k = 0;
        w = 0;
        sprawdza = false;

        difference = 0;
        pierwszy = 0;
        drugi = 0;

        cin >> polecenie;
    }


    return 0;
}