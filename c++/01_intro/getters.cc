#include <iostream> 


int get_int()
{
 int i; 
 while(!(std::cin>>i))
 { 
   std::cin.clear();
   std::cin.ignore();
 }

 return i; 
} 

double get_double()
{ 
 double d; 
 while(!(std::cin>>d))
 { 
   std::cin.clear(); 
   std::cin.ignore(); 
 } 
 return d; 
}

int main()
{ 
 std::cout<<"inser an integer "<<std::endl;
 int i = get_int();
 std::cout<<i<<std::endl; 
 std::cout<<"inser a double "<<std::endl;
 double d = get_double(); 
 std::cout<<d<<std::endl; 
 
 return 0; 
}
  
 

