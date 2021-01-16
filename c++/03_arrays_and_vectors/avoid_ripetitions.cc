#include <iostream> 
#include <vector> 
#include <algorithm> 


int main()
{ 
 std::string word;
 std::vector<std::string> read;

 std::cout<<"Enter a word and then press Enter to insert a new word: " <<std::endl; 
 std::cout<<"Press (CTRL + D) to end"<<std::endl; 
 
 while(std::getline(std::cin,word))
 { 
  read.push_back(word); 
 } 

std::sort( read.begin(), read.end() ); 
std::string prev = "";
std::cout<<"Print Words "<<std::endl;
 for(std::string x: read){
  if(x != prev){
   prev = x; 
         std::cout<<prev<<std::endl;
         //count = 1; 
        } 
} 
return 0; 
}
