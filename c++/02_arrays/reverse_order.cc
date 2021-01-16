#include <iostream> 
#include <typeinfo> 


template <typename T> 
T* create_array(std::size_t size)
{ 
 T* new_array{new T[size]}; 
 std::cout<<"Enter "<<size<<" values for the array of type "<<typeid(T).name()<<std::endl;
 for(std::size_t i{0}; i<size; i++)
 { 
   std::cout<<"Enter value number "<<i+1<<": "<<std::endl; 
   std::cin >> new_array[i];
 } 
 
 return new_array; 
} 




template <typename T> 
void print_reverse(T* arr, std::size_t size)
{
 for( size_t i = size; i>= 1; i--) 
 { 
   std::cout<<"arr["<<i-1<<"]: "<<arr[i-1]<<std::endl; 
 } 

} 


int main()
{
 size_t size{}; 
 std::cout<<"Eneter a value for the size of the array : "<<std::endl; 
 std::cin>>size; 
 int * arr1 = nullptr; 
 arr1 = create_array<int>(size);

 double * arr2 = nullptr; 
 arr2 = create_array<double>(size); 
 
 
 print_reverse(arr1,size); 
 print_reverse(arr2,size);

 delete[] arr1; 
 delete[] arr2; 

 
 

 return 0; 
}

  
 
 
