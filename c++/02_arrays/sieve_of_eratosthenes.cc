#include <iostream> 
#include <cmath>

bool* sieve_init(size_t n)
{
   bool *primes = nullptr; 
   primes = new bool[n]; 
   auto max = (size_t)(std::sqrt(n+1));  
   
   std::fill(primes,primes+n, true); 
   for(size_t i= 2; i<= max; i++)
   { 
     if (primes[i-2]){ 
                     for(size_t j=i*i;j<n+2;j=j+i)
                     { 
                       primes[j-2] = false; 
                      } 
    } 
   }
   
   return primes;
}


int main()
{ 
 

 //int n{};
 size_t n; 
 std::cout<<"Insert an integer number: "<<std::endl; 
 std::cin>>n; 
 std::cout<<"Prime numbers:"<<std::endl;
 bool *primes = sieve_init(n-1); 
 for(size_t i =0; i<n-1; i++)
 {
  if(primes[i]) std::cout<<(primes[i])*(i+2)<<std::endl;
 }
 delete[] primes;
 return 0; 
}
