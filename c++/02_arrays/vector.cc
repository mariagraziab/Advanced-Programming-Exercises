#include <iostream> 
#include <vector> 
#include <cmath>

void sieve_calc(size_t n, std::vector<bool>& primes){ 
  auto max = (size_t)(std::sqrt(n+1));
   for(size_t i= 2; i<= max; i++)
   { 
     if (primes.at(i-2)){ 
                     for(size_t j=i*i;j<n+2;j=j+i)
                     { 
                       primes.at(j-2) = false; 
                      } 
    } 
   }
    
 }

int main()
{ 
  size_t n; 
  std::cout<<"Insert an integer number: "<<std::endl; 
  std::cin>>n; 
  
  std::vector<bool> primes(n-1, 1);
  sieve_calc(n-1,primes);
 for(size_t i =0; i<n-1; i++)
 {
  if(primes[i]) std::cout<<(primes[i])*(i+2)<<std::endl;
 }

  return 0; 
}
