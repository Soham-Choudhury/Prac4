#include "Reverse.h"
#include <iostream>
#include <string>
#include <cctype> //for the "isdigit" function

int Reverse::reverseDigit(int value, int reverse){ 
    //value=1234;
    //https://cplusplus.com/reference/cctype/isdigit/?kw=isdigit
    //int check=isdigit(value); 
    //std::cout<<"Check is "<<check<<std::endl;
    //if(check!=0){ 
    //    return -1; //checking if input value is a integer or not
    //}
    int finaldigit;
    int onebefore;
    int reversenumber=reverse;
    if (value>0){
        finaldigit= value % 10; // getting end digit of number
        //std::cout<<"finaldigit: "<<finaldigit<<std::endl; //Displaying final digit for diagnostics
        onebefore=value/10; //removing end digit of number
        reversenumber=reversenumber*10+finaldigit; //making new number that is reverse
        reversenumber= reverseDigit(onebefore, reversenumber); //reccuring call for function
    }
    
    return reversenumber;
};

std::string Reverse::reverseString(std::string letters,std::string reverse){ 
    //https://www.youtube.com/watch?v=XXBSx0vlm84
    //https://cplusplus.com/reference/string/string/substr/
    //https://www.programiz.com/cpp-programming/examples/concatenate-string
    //https://stackoverflow.com/questions/30501408/how-to-delete-part-of-a-string-in-c
    

    int size=letters.size(); //finding size of input string
    int check=0;
    for (int i=0; i<size; i++){
        if(isdigit(letters[i])){ //checking if input is a string or integer
            check++; //increasing value of variable by 1 for every number found
        }
    };

    if (check>0){
        return "ERROR"; //if numbers found in input, returning "ERROR"
    }
    
    if (size>0){
        std::string last=letters.substr (size-1,1); //selecting final character
        //std::cout<<"Size : "<<size<<std::endl; //Displaying size of input string for diagnostics
        //std::cout<<"Last letter was: "<<last<<std::endl; //Displaying last character of input string for diagnostics
        reverse=reverse+last; //adding last character of current input to reverse of last input
        letters.erase(size-1,1); //erasing last character
        return reverseString(letters,reverse); //recurrence call for function
    }
    else {
        return reverse; //returning reverse of input string
    }
    
};
