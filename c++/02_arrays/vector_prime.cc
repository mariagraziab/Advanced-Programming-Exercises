#include <iostream> 
#include <vector> 

const int SIZE = 100;
int main()
{ 
 
 std::vector<int> primes(1,2); 
 int j{}, r{};
 for(int i{3}; i<SIZE;i+=2)
 {
   j = int(i/2); 
   r = 1; 
   while(j>1 && r!=0)
   { 
     r = i%j; 
     j--; 
    }
   if(r) primes.push_back(i);
  } 

  for(auto& x : primes)
    std::cout<<x<<std::endl; 

 return 0; 

 }
