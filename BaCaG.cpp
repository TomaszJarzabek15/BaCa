//Tomasz Jarzabek

using namespace std;

struct DANA{

    int cyfra;
    string zdanie;
    char znak;
    bool bool1, bool2, bool3, bool4;
    int char1, char2, char3, char4;
    float float1, float2, float3, float4;
};

bool Equal(struct DANA dana, struct DANA min){

    bool wynik = true;

    if((dana.cyfra != min.cyfra) || (dana.zdanie != min.zdanie) || (dana.znak != min.znak) || (dana.bool1 != min.bool1) || (dana.bool2 != min.bool2) || (dana.bool3 != min.bool3) || (dana.bool4 != min.bool4)){
        wynik = false;
    }
    if((dana.char1 != min.char1) || (dana.char2 != min.char2) || (dana.char3 != min.char3) || (dana.char4 != min.char4)){
        wynik = false;
    }
    if((dana.float1 != min.float1) || (dana.float2 != min.float2) || (dana.float3 != min.float3) || (dana.float4 != min.float4)){
        wynik = false;
    }

    return wynik;
}

void MaxSortInt(string jeden, string dwa, string trzy){

    fstream inFile;
    fstream outFile;
    fstream outFile2;

    //int number;
    bool check = false;
    int len = 0;
    int length;
    int counter = 0;

    string newline;

    DANA dana;
    DANA min;

    min.cyfra = -5;
    
    inFile.open(jeden.c_str(), fstream::in);

    inFile.seekg(0, fstream::end);  
    if (inFile.tellg() == 0) {    

    }
    else{

        inFile.seekg(0, fstream::beg);  
        
        while(inFile >> dana.cyfra){

            getline(inFile, newline);

            getline(inFile, dana.zdanie);
            dana.znak = inFile.get();
            inFile >> dana.bool1 >> dana.char1 >> dana.float1;
            inFile >> dana.bool2 >> dana.char2 >> dana.float2;
            inFile >> dana.bool3 >> dana.char3 >> dana.float3;
            inFile >> dana.bool4 >> dana.char4 >> dana.float4;
            
            len++;
        }
                
        inFile.close();

        outFile.open(dwa.c_str(), fstream::out);

        while(len > 0){

            if((counter % 2) == 0){

                inFile.open(jeden.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.cyfra > min.cyfra){
                        min = dana;     //rownanie miedzy dwoma strulturami, podstawienie na wszystkich polach
                    }
                }

                inFile.close();

                outFile << min.cyfra << endl;
                outFile << min.zdanie << endl;
                outFile << min.znak << endl;
                outFile << min.bool1  << ' ' << min.char1 << ' ' << min.float1 << endl;
                outFile << min.bool2  << ' ' << min.char2 << ' ' << min.float2 << endl;
                outFile << min.bool3  << ' ' << min.char3 << ' ' << min.float3 << endl;
                outFile << min.bool4  << ' ' << min.char4 << ' ' << min.float4;

                if(len != 1){
                    outFile << endl;
                }

                inFile.open(jeden.c_str(), fstream::in);
                outFile2.open(trzy.c_str(), fstream::out);

                length = len;

                while(length > 0){

                    inFile >> dana.cyfra;

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((Equal(dana, min)) && (check == false)){
                        check = true;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4;

                        if(length != 1){
                            outFile2 << endl;
                        }
                    }
                    length--;
                }
            }
            else{

                inFile.open(trzy.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get(); 
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.cyfra > min.cyfra){
                        min = dana;
                    }
                }

                inFile.close();


                outFile << min.cyfra << endl;
                outFile << min.zdanie << endl;
                outFile << min.znak << endl;
                outFile << min.bool1  << ' ' << min.char1 << ' ' << min.float1 << endl;
                outFile << min.bool2  << ' ' << min.char2 << ' ' << min.float2 << endl;
                outFile << min.bool3  << ' ' << min.char3 << ' ' << min.float3 << endl;
                outFile << min.bool4  << ' ' << min.char4 << ' ' << min.float4;

                if(len != 1){
                    outFile << endl;
                }

                inFile.open(trzy.c_str(), fstream::in);

                outFile2.open(jeden.c_str(), fstream::out);

                length = len;

                while(length > 0){

                    inFile >> dana.cyfra;

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((Equal(dana, min)) && (check == false)){
                        check = true;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4;

                        if(length != 1){
                            outFile2 << endl;
                        }
                    }
                    length--;
                }
            }

            min.cyfra = -5;

            outFile2.close();
            inFile.close();
            check = false;
            counter++;
            len--;
        }
        
        outFile.close();

        inFile.open(dwa.c_str(), fstream::in);
        outFile.open(jeden.c_str(), fstream::out);

        do{
            char c;
            c = inFile.get();

            if(inFile.eof()){
                break;
            }

            outFile << c;
        }while(true);

        outFile.close();
    }
    inFile.close();
}

void SortCount(string jeden, string dwa, string trzy){      //wynik suma char modulo 256

    MaxSortInt(jeden.c_str(), dwa.c_str(), trzy.c_str());       //w ten sposob wynik mamy posortowany po wielkosci

    //teraz musimy posortowac po liczebnosci, znajdujemy dane z maksymalna i wypisujemy do drugiego pliku

    fstream inFile;
    fstream outFile;
    fstream outFile2;

    outFile.open(dwa.c_str(), fstream::out);    //czyscimy pomocznicze pliki
    outFile.close();

    outFile.open(trzy.c_str(), fstream::out);
    outFile.close();

    DANA dana;
    DANA min;       //min tu jest max, dla kopiowania

    string newline;
    int previous;
    int maximum = -5;
    int liczba;

    int counter = 1;
    int licznik = 0;
    int len = 0;


    inFile.open(jeden.c_str(), fstream::in);
    outFile.open(dwa.c_str(), fstream::out);    //output na drugi plik

    inFile.seekg(0, fstream::end);  
    if (inFile.tellg() == 0) {    
        //jak plik jest pusty to nie robimy nic
    }
    else{

        inFile.seekg(0, fstream::beg);
        inFile.close();

        inFile.open(jeden.c_str(), fstream::in);


        while(inFile >> dana.cyfra){

            getline(inFile, newline);

            getline(inFile, dana.zdanie);
            dana.znak = inFile.get();
            inFile >> dana.bool1 >> dana.char1 >> dana.float1;
            inFile >> dana.bool2 >> dana.char2 >> dana.float2;
            inFile >> dana.bool3 >> dana.char3 >> dana.float3;
            inFile >> dana.bool4 >> dana.char4 >> dana.float4;
            
            len++;
        }
                
        inFile.close();

        while(len > 0){
        
            if((licznik % 2) == 0){

                inFile.open(jeden.c_str(), fstream::in);
                outFile2.open(trzy.c_str(), fstream::out);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(previous == dana.cyfra){
                        counter++;
                    }
                    if(counter > maximum){
                        maximum = counter;
                        liczba = dana.cyfra;
                    }
                    if(previous != dana.cyfra){
                        counter = 1;
                    }

                    previous = dana.cyfra;
                }

                inFile.close();


                inFile.open(jeden.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.cyfra == liczba){

                        outFile << dana.cyfra << endl;
                        outFile << dana.zdanie << endl;
                        outFile << dana.znak << endl;
                        outFile << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                }

                inFile.close();
                outFile2.close();
            }
            else{
                inFile.open(trzy.c_str(), fstream::in);
                outFile2.open(jeden.c_str(), fstream::out);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(previous == dana.cyfra){
                        counter++;
                    }
                    if(counter > maximum){
                        maximum = counter;
                        liczba = dana.cyfra;
                    }
                    if(previous != dana.cyfra){
                        counter = 1;
                    }

                    previous = dana.cyfra;
                }
                inFile.close();

                inFile.open(trzy.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.cyfra == liczba){

                        outFile << dana.cyfra << endl;
                        outFile << dana.zdanie << endl;
                        outFile << dana.znak << endl;
                        outFile << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                }

                inFile.close();
                outFile2.close();
            }

            len = len - maximum;
            counter = 1;
            maximum = -5;
            licznik++;
        }

        outFile.close();

        inFile.open(dwa.c_str(), fstream::in);
        outFile.open(jeden.c_str(), fstream::out);

        do{
            char c;
            c = inFile.get();

            if(inFile.eof()){
                break;
            }

            outFile << c;
        }while(true);

        inFile.close();
        outFile.close();



        //trzeba jeszcze posortowac chary
        inFile.open(jeden.c_str(), fstream::in);
        outFile.open(dwa.c_str(), fstream::out);

        len = 0;
        licznik = 0;
        int suma = 0;
        bool pierwszy = true;
        maximum = -5;

        while(inFile >> dana.cyfra){

            getline(inFile, newline);

            getline(inFile, dana.zdanie);
            dana.znak = inFile.get();
            inFile >> dana.bool1 >> dana.char1 >> dana.float1;
            inFile >> dana.bool2 >> dana.char2 >> dana.float2;
            inFile >> dana.bool3 >> dana.char3 >> dana.float3;
            inFile >> dana.bool4 >> dana.char4 >> dana.float4;
            
            len++;
        }
                
        inFile.close();

        while(len > 0){
        
            if((licznik % 2) == 0){

                inFile.open(jeden.c_str(), fstream::in);
                outFile2.open(trzy.c_str(), fstream::out);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((previous == dana.cyfra) || (pierwszy == true)){
                        pierwszy = false;
                        suma = (dana.char1 + dana.char2 + dana.char3 + dana.char4) % 256;

                        if(suma > maximum){
                            maximum = suma;
                            liczba = dana.cyfra;
                        }
                    }
                    else{
                        break;
                    }
                    
                    previous = dana.cyfra;
                }

                inFile.close();


                inFile.open(jeden.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    suma = (dana.char1 + dana.char2 + dana.char3 + dana.char4) % 256;

                    if((suma == maximum) && (liczba == dana.cyfra)){

                        outFile << dana.cyfra << endl;
                        outFile << dana.zdanie << endl;
                        outFile << dana.znak << endl;
                        outFile << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                }

                inFile.close();
                outFile2.close();
            }
            else{
                inFile.open(trzy.c_str(), fstream::in);
                outFile2.open(jeden.c_str(), fstream::out);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((previous == dana.cyfra) || (pierwszy == true)){
                        pierwszy = false;

                        suma = (dana.char1 + dana.char2 + dana.char3 + dana.char4) % 256;

                        if(suma > maximum){
                            maximum = suma;
                            liczba = dana.cyfra;
                        }
                    }
                    else{
                        break;
                    }
                    
                    previous = dana.cyfra;
                }
                inFile.close();

                inFile.open(trzy.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    suma = (dana.char1 + dana.char2 + dana.char3 + dana.char4) % 256;

                    if((suma == maximum) && (liczba == dana.cyfra)){

                        outFile << dana.cyfra << endl;
                        outFile << dana.zdanie << endl;
                        outFile << dana.znak << endl;
                        outFile << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;
                    }
                }

                inFile.close();
                outFile2.close();
            }

            len--;
            counter = 1;
            pierwszy = true;
            maximum = -5;
            licznik++;
        }

        outFile.close();

        inFile.open(dwa.c_str(), fstream::in);
        outFile.open(jeden.c_str(), fstream::out);

        do{
            char c;
            c = inFile.get();

            if(inFile.eof()){
                break;
            }

            outFile << c;
        }while(true);

        inFile.close();
        outFile.close();
    }
}

void SymmetricDifference(string jeden, string dwa, string trzy){    //do pierwszego argumentu dodaje te z drugiego argumentu ktorych nie ma w pierwszym

    //dla kazdego w drugim sprawdzam czy jest w pierwszym, jak go nie ma to go dodaje z app
    //i usuwam go kopiujac caly plik bez niego

    fstream inFile;
    fstream inFile2;
    fstream outFile;
    fstream outFile2;

    outFile2.open(trzy.c_str(), fstream::out);       //czyscimy trzeci plik
    outFile2.close();

    string newline;

    bool sprawdza = false;
    int pozycja = 0;

    inFile2.open(dwa.c_str(), fstream::in);

    DANA dana;
    DANA min;

    while(inFile2 >> dana.cyfra){

        getline(inFile2, newline);

        getline(inFile2, dana.zdanie);
        dana.znak = inFile2.get();
        inFile2 >> dana.bool1 >> dana.char1 >> dana.float1;
        inFile2 >> dana.bool2 >> dana.char2 >> dana.float2;
        inFile2 >> dana.bool3 >> dana.char3 >> dana.float3;
        inFile2 >> dana.bool4 >> dana.char4 >> dana.float4;

        inFile.open(jeden.c_str(), fstream::in);

        while(inFile >> min.cyfra){

            getline(inFile, newline);

            getline(inFile, min.zdanie);
            min.znak = inFile.get();
            inFile >> min.bool1 >> min.char1 >> min.float1;
            inFile >> min.bool2 >> min.char2 >> min.float2;
            inFile >> min.bool3 >> min.char3 >> min.float3;
            inFile >> min.bool4 >> min.char4 >> min.float4;

            if(Equal(dana, min)){
                sprawdza = true;
            }
        } 

        inFile.close();

        if(sprawdza == false){

            outFile.open(jeden.c_str(), fstream::app|fstream::out);     //dodajemy to co w drugim na koniec pierwszego

            outFile << dana.cyfra << endl;
            outFile << dana.zdanie << endl;
            outFile << dana.znak << endl;
            outFile << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
            outFile << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
            outFile << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
            outFile << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;

            outFile.close();

            //tej danej ma nie byc wiec jej nie kopiujemy do treciego pliku
        }
        else{

            outFile2.open(trzy.c_str(), fstream::app|fstream::out);

            outFile2 << dana.cyfra << endl;
            outFile2 << dana.zdanie << endl;
            outFile2 << dana.znak << endl;
            outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
            outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
            outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
            outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4 << endl;

            outFile2.close();
        }

        sprawdza = false;
    }

    inFile2.close();

    //po tym kopiujemy z trzeciego do drugiego

    inFile2.open(trzy.c_str(), fstream::in);
    outFile2.open(dwa.c_str(), fstream::out);

    do{
        char c;
        c = inFile2.get();

        if(inFile2.eof()){
            break;
        }

        outFile2 << c;
    }while(true);

    outFile2.close();
    inFile2.close();
}

void SortString(string jeden, string dwa, string trzy){

    fstream inFile;
    fstream outFile;
    fstream outFile2;

    bool check = false;
    int len = 0;
    int length;
    int counter = 0;

    string newline;

    DANA dana;
    DANA min;

    min.zdanie = "zzzzzzzzzzzzzzzzzzzzzzzzzz";
    
    inFile.open(jeden.c_str(), fstream::in);

    inFile.seekg(0, fstream::end);  
    if (inFile.tellg() == 0) {    

    }
    else{

        inFile.seekg(0, fstream::beg);  
        
        while(inFile >> dana.cyfra){

            getline(inFile, newline);

            getline(inFile, dana.zdanie);
            dana.znak = inFile.get();
            inFile >> dana.bool1 >> dana.char1 >> dana.float1;
            inFile >> dana.bool2 >> dana.char2 >> dana.float2;
            inFile >> dana.bool3 >> dana.char3 >> dana.float3;
            inFile >> dana.bool4 >> dana.char4 >> dana.float4;
            
            len++;
        }
                
        inFile.close();

        outFile.open(dwa.c_str(), fstream::out);

        while(len > 0){

            if((counter % 2) == 0){

                inFile.open(jeden.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.zdanie < min.zdanie){
                        min = dana;     //rownanie miedzy dwoma strulturami, podstawienie na wszystkich polach
                    }
                }

                inFile.close();

                outFile << min.cyfra << endl;
                outFile << min.zdanie << endl;
                outFile << min.znak << endl;
                outFile << min.bool1  << ' ' << min.char1 << ' ' << min.float1 << endl;
                outFile << min.bool2  << ' ' << min.char2 << ' ' << min.float2 << endl;
                outFile << min.bool3  << ' ' << min.char3 << ' ' << min.float3 << endl;
                outFile << min.bool4  << ' ' << min.char4 << ' ' << min.float4;

                if(len != 1){
                    outFile << endl;
                }

                inFile.open(jeden.c_str(), fstream::in);
                outFile2.open(trzy.c_str(), fstream::out);

                length = len;

                while(length > 0){

                    inFile >> dana.cyfra;

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((Equal(dana, min)) && (check == false)){
                        check = true;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4;

                        if(length != 1){
                            outFile2 << endl;
                        }
                    }
                    length--;
                }
            }
            else{

                inFile.open(trzy.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.zdanie < min.zdanie){
                        min = dana;
                    }
                }

                inFile.close();


                outFile << min.cyfra << endl;
                outFile << min.zdanie << endl;
                outFile << min.znak << endl;
                outFile << min.bool1  << ' ' << min.char1 << ' ' << min.float1 << endl;
                outFile << min.bool2  << ' ' << min.char2 << ' ' << min.float2 << endl;
                outFile << min.bool3  << ' ' << min.char3 << ' ' << min.float3 << endl;
                outFile << min.bool4  << ' ' << min.char4 << ' ' << min.float4;

                if(len != 1){
                    outFile << endl;
                }

                inFile.open(trzy.c_str(), fstream::in);

                outFile2.open(jeden.c_str(), fstream::out);

                length = len;

                while(length > 0){

                    inFile >> dana.cyfra;

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((Equal(dana, min)) && (check == false)){
                        check = true;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4;

                        if(length != 1){
                            outFile2 << endl;
                        }
                    }
                    length--;
                }
            }

            min.zdanie = "zzzzzzzzzzzzzzzzzzzzzzzzzz";

            outFile2.close();
            inFile.close();
            check = false;
            counter++;
            len--;
        }
        
        outFile.close();

        inFile.open(dwa.c_str(), fstream::in);
        outFile.open(jeden.c_str(), fstream::out);

        do{
            char c;
            c = inFile.get();

            if(inFile.eof()){
                break;
            }

            outFile << c;
        }while(true);

        outFile.close();
    }
    inFile.close();

}

void SortInt(string jeden, string dwa, string trzy){

    fstream inFile;
    fstream outFile;
    fstream outFile2;

    //int number;
    bool check = false;
    int len = 0;
    int length;
    int counter = 0;

    string newline;

    DANA dana;
    DANA min;

    min.cyfra = 99999999;
    
    inFile.open(jeden.c_str(), fstream::in);

    inFile.seekg(0, fstream::end);  
    if (inFile.tellg() == 0) {    

    }
    else{

        inFile.seekg(0, fstream::beg);  
        
        while(inFile >> dana.cyfra){

            getline(inFile, newline);

            getline(inFile, dana.zdanie);
            dana.znak = inFile.get();
            inFile >> dana.bool1 >> dana.char1 >> dana.float1;
            inFile >> dana.bool2 >> dana.char2 >> dana.float2;
            inFile >> dana.bool3 >> dana.char3 >> dana.float3;
            inFile >> dana.bool4 >> dana.char4 >> dana.float4;
            
            len++;
        }
                
        inFile.close();

        outFile.open(dwa.c_str(), fstream::out);

        while(len > 0){

            if((counter % 2) == 0){

                //cout << "wchodzi" << endl;

                inFile.open(jeden.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.cyfra < min.cyfra){
                        min = dana;     //rownanie miedzy dwoma strulturami, podstawienie na wszystkich polach
                    }
                }

                inFile.close();

                outFile << min.cyfra << endl;
                outFile << min.zdanie << endl;
                outFile << min.znak << endl;
                outFile << min.bool1  << ' ' << min.char1 << ' ' << min.float1 << endl;
                outFile << min.bool2  << ' ' << min.char2 << ' ' << min.float2 << endl;
                outFile << min.bool3  << ' ' << min.char3 << ' ' << min.float3 << endl;
                outFile << min.bool4  << ' ' << min.char4 << ' ' << min.float4;

                if(len != 1){
                    outFile << endl;
                }

                inFile.open(jeden.c_str(), fstream::in);
                outFile2.open(trzy.c_str(), fstream::out);

                length = len;

                while(length > 0){

                    inFile >> dana.cyfra;

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((Equal(dana, min)) && (check == false)){
                        check = true;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4;

                        if(length != 1){
                            outFile2 << endl;
                        }
                    }
                    length--;
                }
            }
            else{

                inFile.open(trzy.c_str(), fstream::in);

                while(inFile >> dana.cyfra){

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();  
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if(dana.cyfra < min.cyfra){
                        min = dana;
                    }
                }

                inFile.close();


                outFile << min.cyfra << endl;
                outFile << min.zdanie << endl;
                outFile << min.znak << endl;
                outFile << min.bool1  << ' ' << min.char1 << ' ' << min.float1 << endl;
                outFile << min.bool2  << ' ' << min.char2 << ' ' << min.float2 << endl;
                outFile << min.bool3  << ' ' << min.char3 << ' ' << min.float3 << endl;
                outFile << min.bool4  << ' ' << min.char4 << ' ' << min.float4;

                if(len != 1){
                    outFile << endl;
                }

                inFile.open(trzy.c_str(), fstream::in);

                outFile2.open(jeden.c_str(), fstream::out);

                length = len;

                while(length > 0){

                    inFile >> dana.cyfra;

                    getline(inFile, newline);

                    getline(inFile, dana.zdanie);
                    dana.znak = inFile.get();
                    inFile >> dana.bool1 >> dana.char1 >> dana.float1;
                    inFile >> dana.bool2 >> dana.char2 >> dana.float2;
                    inFile >> dana.bool3 >> dana.char3 >> dana.float3;
                    inFile >> dana.bool4 >> dana.char4 >> dana.float4;

                    if((Equal(dana, min)) && (check == false)){
                        check = true;
                    }
                    else{
                        outFile2 << dana.cyfra << endl;
                        outFile2 << dana.zdanie << endl;
                        outFile2 << dana.znak << endl;
                        outFile2 << dana.bool1  << ' ' << dana.char1 << ' ' << dana.float1 << endl;
                        outFile2 << dana.bool2  << ' ' << dana.char2 << ' ' << dana.float2 << endl;
                        outFile2 << dana.bool3  << ' ' << dana.char3 << ' ' << dana.float3 << endl;
                        outFile2 << dana.bool4  << ' ' << dana.char4 << ' ' << dana.float4;

                        if(length != 1){
                            outFile2 << endl;
                        }
                    }
                    length--;
                }
            }

            min.cyfra = 99999999;

            outFile2.close();
            inFile.close();
            check = false;
            counter++;
            len--;
        }
        
        outFile.close();

        inFile.open(dwa.c_str(), fstream::in);
        outFile.open(jeden.c_str(), fstream::out);

        do{
            char c;
            c = inFile.get();

            if(inFile.eof()){
                break;
            }

            outFile << c;
        }while(true);

        outFile.close();
    }
    inFile.close();
}