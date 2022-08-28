#include "Reverse.h"
#include "Truckloads.h"
#include <string>
#include <iostream> 


int main (){
    std::cout<<"Input 1: ";
    std::string input="";
    std::getline(std::cin >> std::ws,input); //taking input 
    int sizeinput=input.size();
    int category=0;
    int value=0; //input for reverse integer
    std::string letters=""; //declaring string type variable "letters" for reverse string
    int numCrates=0; //declaring variable for number of crates for truckloads
    int loadSize=0; //declaring variable for loadsize for truckloads
    int tempint=0;
    std::string::size_type sz;   // alias of size_t
    for (int i=0;i<sizeinput;i++){
        //std::cout<<input[i];
        if(input[i]==' '){ //checking input for whitespace
            category++;
        }
        else if (category==0){
            //tempint=std::stoi(input[i],&sz);
            tempint=input[i];
            value=value*10+tempint; //isolating input for reverse int function
        }
        else if (category==1){
            letters=letters+input[i];
        }
        else if (category==2){
            numCrates=numCrates*10+input[i];
        }
        else if (category==3){
            loadSize=loadSize*10+input[i];
        }
    };

    //Reverse integers
    Reverse reverseint;
    //std::cout<<"Enter value: ";
    value=12345;
    //std::cin>>value;
    int reversedint=reverseint.reverseDigit(value,0);
    //std::cout<<"Reverse of integer is: "<<reversedint<<std::endl;

    

    //Reverse string
    Reverse reversestring;

    //https://cplusplus.com/reference/string/string/getline/
    //https://www.geeksforgeeks.org/problem-with-getline-after-cin/
    
     //std::string letters="How are you today?"; //test input with special characters and white space
    //std::cout<<"Insert String: ";
    //std::getline(std::cin >> std::ws,letters); //taking input string
    std::string reversestr=reversestring.reverseString(letters,"");
    //std::cout<<"Reverse of string was: "<<reversestr<<std::endl;

  
    //Truckloads problem
    Truckloads truckloads;
    int load=truckloads.numTrucks(numCrates,loadSize);
    std::cout<<"Output 1: "<<reversedint<<" "<<reversestr<<" "<<load<<std::endl;

};