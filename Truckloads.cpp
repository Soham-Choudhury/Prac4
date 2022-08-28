#include "Truckloads.h"


int Truckloads::numTrucks(int numCrates, int loadSize){
    int pile1=0;
    int pile2=0;
    if (numCrates<=0){
        return 0;
    }
    //https://cplusplus.com/doc/tutorial/operators/
    if (numCrates % 2 != 0 ){ //if number of crates is odd
        return 2;
    }
    else { //if number of crates is even
        return 3;
    }

};