#include <iostream> 


const int SIZE = 100;
int* resize(int* arr, int new_size)
{ 
 int* new_array{new int[new_size]}; 
 for(int i= 0; i<new_size; i++)
 { new_array[i] = arr[i];
 } 
 delete[] arr; 
 return new_array; 
 
 } 
int main(){ 

 //for sure there from 2 to SIZE there are no more prime numbers then SIZE/2
 //si I allocate an array having size SIZE/2 then I reduce it. 
 int *primes{new int[SIZE/2]};
 int count{0};
 primes[0]=2; 
 int j{};
 int r{};
 for(int i{3}; i<SIZE; i+=2)
 { 
   j= int(i/2); 
   r =1; 
   while(j>1 && r!=0)
   {
     r = i%j;
     j--;
    }
    if(r) primes[++count] = i;
  } 

  
  primes = resize(primes,count+1);
  for(int i = 0; i<=count; i++){ 
    std::cout<<primes[i]<<std::endl; 
  } 
  delete[] primes; 
  return 0;
  } 

 


