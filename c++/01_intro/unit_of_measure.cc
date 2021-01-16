#include <iostream> 


#define FACTOR 0.0254

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
 
  std::string unit; 
  double measure; 
  
 std::cout<<"Enter the value to convert and its original unit of measure, 'm' for meters and 'i' for inch"<<std::endl; 
  measure = get_double(); 
  
  std::cin>>unit;


  if((unit == "m") | (unit == "meters"))
   {
     measure /=FACTOR; 
     std::cout<<measure<<" in"<<std::endl;  
   } 
    else if((unit=="in") | (unit == "inch"))
   {
     measure *=FACTOR;
     std::cout<<measure<<" m"<<std::endl;     
   }
    else
   { 
      std::cout<<"Wrong measure unit"<<std::endl;
   }
   

     
    

return 0; 
}
  
