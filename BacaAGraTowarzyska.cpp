//Tomasz Jarzabek

#include <iostream>

using namespace std;

int main () {

    int n;
    int i = 0;

    char gracz;
    char przeciwnik;

    char wybor_gracz;
    char wybor_przeciwnik;
    int sila_gracz;
    int sila_przeciwnik;
 
    float wA = 0;
    float pA = 0;
    float rA = 0;
    float wB = 0;
    float pB = 0;
    float rB = 0;
    float wC = 0;
    float pC = 0;
    float rC = 0;
    float wD = 0;
    float pD = 0;
    float rD = 0;

    cin >> n;

    while ( i < n ) {
        
        cin >> gracz;
        cin >> wybor_gracz;
        cin >> sila_gracz;
        cin >> przeciwnik;
        cin >> wybor_przeciwnik;
        cin >> sila_przeciwnik;

            if ( wybor_gracz == 'J'){
            
                if ( wybor_przeciwnik == 'P' || wybor_przeciwnik == 'S') {

                    if (gracz == 'a'){
                        wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                }
                else if ( wybor_przeciwnik == 'J') {
                    if (sila_gracz == sila_przeciwnik){

                        if(gracz == 'a'){
                            rA = rA + 1;

                            if(przeciwnik == 'b'){
                                rB = rB + 1;
                            }
                            if(przeciwnik == 'c'){
                                rC = rC + 1;
                            }
                            if(przeciwnik == 'd'){
                                rD = rD + 1;
                            }
                        }
                        if(gracz == 'b'){
                            rB = rB + 1;

                            if(przeciwnik == 'a'){
                                rA = rA + 1;
                            }
                            if(przeciwnik == 'c'){
                                rC = rC + 1;
                            }
                            if(przeciwnik == 'd'){
                                rD = rD + 1;
                            }
                        }
                        if(gracz == 'c'){
                            rC = rC + 1;

                            if(przeciwnik == 'b'){
                                rB = rB + 1;
                            }
                            if(przeciwnik == 'a'){
                                rA = rA + 1;
                            }
                            if(przeciwnik == 'd'){
                                rD = rD + 1;
                            }
                        }
                        if(gracz == 'd'){
                            rD = rD + 1;

                            if(przeciwnik == 'b'){
                                rB = rB + 1;
                            }
                            if(przeciwnik == 'c'){
                                rC = rC + 1;
                            }
                            if(przeciwnik == 'a'){
                                rA = rA + 1;
                            }
                        }
                    }
                    else if (sila_gracz > sila_przeciwnik){
                        
                        if (gracz == 'a'){
                            wA = wA + 1;

                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'b'){
                            wB = wB + 1;

                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'c'){
                            wC = wC + 1;

                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'd'){
                            wD = wD + 1;

                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                        }

                    }
                    else{
                        if (gracz == 'a'){
                            pA = pA + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                        }
                    }
                }
                else {
                    if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                }
            }

//-----------------------------------------------------------------------------------------------------------------

            if ( wybor_gracz == 'K'){
            
                if ( wybor_przeciwnik == 'J' || wybor_przeciwnik == 'N') {
                    if (gracz == 'a'){
                        wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                }
                else if ( wybor_przeciwnik == 'K') {
                    if (sila_gracz == sila_przeciwnik){
                         
                            if(gracz == 'a'){
                                rA = rA + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'b'){
                                rB = rB + 1;

                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'c'){
                                rC = rC + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'd'){
                                rD = rD + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                            }
                    }
                    else if (sila_gracz > sila_przeciwnik){
                        if (gracz == 'a'){
                            wA = wA + 1;

                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'b'){
                            wB = wB + 1;

                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'c'){
                            wC = wC + 1;

                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'd'){
                            wD = wD + 1;

                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                        }
                    }
                    else{
                        if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                        if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                        }
                    }
                }
                else {
                    if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                }
            }

//--------------------------------------------------------------------

            if ( wybor_gracz == 'N'){
            
                if ( wybor_przeciwnik == 'J' || wybor_przeciwnik == 'P') {
                    if (gracz == 'a'){
                        wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                }
                else if ( wybor_przeciwnik == 'N') {
                    if (sila_gracz == sila_przeciwnik){
                         if(gracz == 'a'){
                                rA = rA + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'b'){
                                rB = rB + 1;

                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'c'){
                                rC = rC + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'd'){
                                rD = rD + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                            }
                    }
                    else if (sila_gracz > sila_przeciwnik){
                        if (gracz == 'a'){
                            wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                    }
                    else{
                        if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                    }
                }
                else {
                    if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                }
            }

//-----------------------------------------------------------------

            if ( wybor_gracz == 'P'){
            
                if ( wybor_przeciwnik == 'K' || wybor_przeciwnik == 'S') {
                    if (gracz == 'a'){
                        wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                }
                else if ( wybor_przeciwnik == 'P') {
                    if (sila_gracz == sila_przeciwnik){
                         if(gracz == 'a'){
                                rA = rA + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'b'){
                                rB = rB + 1;

                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'c'){
                                rC = rC + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'd'){
                                rD = rD + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                            }
                    }
                    else if (sila_gracz > sila_przeciwnik){
                        if (gracz == 'a'){
                            wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                        }
                        if (gracz == 'b'){
                            wB = wB + 1;

                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'c'){
                            wC = wC + 1;

                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'd'){
                                pD = pD + 1;
                            }
                        }
                        if (gracz == 'd'){
                            wD = wD + 1;

                            if(przeciwnik == 'b'){
                                pB = pB + 1;
                            }
                            if(przeciwnik == 'c'){
                                pC = pC + 1;
                            }
                            if(przeciwnik == 'a'){
                                pA = pA + 1;
                            }
                        }
                    }
                    else{
                        if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                        if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                        if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                        }
                    }
                }
                else {
                    if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                }
            }

//---------------------------------------------------------------------------------

            if ( wybor_gracz == 'S'){
            
                if ( wybor_przeciwnik == 'K' || wybor_przeciwnik == 'N') {
                    if (gracz == 'a'){
                        wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                }
                else if ( wybor_przeciwnik == 'S') {
                    if (sila_gracz == sila_przeciwnik){
                         if(gracz == 'a'){
                                rA = rA + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'b'){
                                rB = rB + 1;

                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'c'){
                                rC = rC + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                                if(przeciwnik == 'd'){
                                    rD = rD + 1;
                                }
                            }
                            if(gracz == 'd'){
                                rD = rD + 1;

                                if(przeciwnik == 'b'){
                                    rB = rB + 1;
                                }
                                if(przeciwnik == 'c'){
                                    rC = rC + 1;
                                }
                                if(przeciwnik == 'a'){
                                    rA = rA + 1;
                                }
                            }
                    }
                    else if (sila_gracz > sila_przeciwnik){
                        if (gracz == 'a'){
                        wA = wA + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'b'){
                        wB = wB + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'c'){
                        wC = wC + 1;

                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'd'){
                            pD = pD + 1;
                        }
                    }
                    if (gracz == 'd'){
                        wD = wD + 1;

                        if(przeciwnik == 'b'){
                            pB = pB + 1;
                        }
                        if(przeciwnik == 'c'){
                            pC = pC + 1;
                        }
                        if(przeciwnik == 'a'){
                            pA = pA + 1;
                        }
                    }
                    }
                    else{
                        if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                    }
                }
                else {
                    if (gracz == 'a'){
                        pA = pA + 1;

                        if(przeciwnik == 'b'){
                            wB = wB + 1;
                        }
                        if(przeciwnik == 'c'){
                            wC = wC + 1;
                        }
                        if(przeciwnik == 'd'){
                            wD = wD + 1;
                        }
                        }
                    if (gracz == 'b'){
                            pB = pB + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                        }
                    if (gracz == 'c'){
                            pC = pC + 1;

                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'd'){
                                wD = wD + 1;
                            }
                    }
                    if (gracz == 'd'){
                            pD = pD + 1;

                            if(przeciwnik == 'b'){
                                wB = wB + 1;
                            }
                            if(przeciwnik == 'c'){
                                wC = wC + 1;
                            }
                            if(przeciwnik == 'a'){
                                wA = wA + 1;
                            }
                    }
                }
            }



        i = i + 1;
    }

    if(wA != 0 || rA != 0 || pA != 0){

        cout << "gracz a" << endl;

        if(wA != 0){
            cout << "    wygrane: " << (wA / (wA + rA + pA)) * 100 << "%" << endl;
        }
        if(rA != 0){

            cout << "    remisy: " << (rA / (wA + rA + pA)) * 100 << "%" << endl;
        }
        if(pA != 0){
            cout << "    przegrane: " << (pA / (wA + rA + pA)) * 100 << "%"<< endl;
        }
        
        
        cout << endl;
        
    }

    if(wB != 0 || rB != 0 || pB != 0){

        cout << "gracz b" << endl;

        if(wB != 0){
            cout << "    wygrane: " << (wB / (wB + rB + pB)) * 100 << "%" << endl;
        }
        if(rB != 0){

            cout << "    remisy: " << (rB / (wB + rB + pB)) * 100 << "%" << endl;
        }
        if(pB != 0){
            cout << "    przegrane: " << (pB / (wB + rB + pB)) * 100 << "%"<< endl;
        }
        
        
        cout << endl;
        
    }

    if(wC != 0 || rC != 0 || pC != 0){

        cout << "gracz c" << endl;

        if(wC != 0){
            cout << "    wygrane: " << (wC / (wC + rC + pC)) * 100 << "%" << endl;
        } 
        if(rC != 0){

            cout << "    remisy: " << (rC / (wC + rC + pC)) * 100 << "%" << endl;
        }
        if(pC != 0){
            cout << "    przegrane: " << (pC / (wC + rC + pC)) * 100 << "%"<< endl;
        }
        
        cout << endl;
        
    }

      if(wD != 0 || rD != 0 || pD != 0){

        cout << "gracz d" << endl;

        if(wD != 0){
            cout << "    wygrane: " << (wD / (wD + rD + pD)) * 100 << "%" << endl;
        }
        
        if(rD != 0){

            cout << "    remisy: " << (rD / (wD + rD + pD)) * 100 << "%" << endl;
        }
        if(pD != 0){
            cout << "    przegrane: " << (pD / (wD + rD + pD)) * 100 << "%"<< endl;
        }
        

        cout << endl;
    }




    //trzeba cout tylko na koncu po cyklu wiec trzeba to wszystko jakos zapisac bez tablic

}