#include <iostream> 
#include <array> 
#include <utility> 
#include <sstream>
//#include <sys/time.h>
#include <sys/resource.h>
//#include <errno.h>

template<size_t N> 
std::array<double,N> matrix_create(size_t n)
{ 
 std::array<double,N> matrix; 
 for(size_t i=0; i<n; i++)
    matrix[i] = i;
 
 return matrix;

}

template<size_t N> 
void transpose(std::array<double,N>&matrix, size_t row, size_t col)
{ 
 std::array<double,N> temp; 
 

for(size_t j{0}; j<col; j++)
  for(size_t i{0}; i<row; i++) 
     temp[j*row +i] = matrix[i*col+j];

 std::swap(matrix,temp);


}
template<size_t N> 
void printMatrix(std::array<double,N>& matrix, size_t row, size_t col)
{ 
  for(size_t i{0}; i<row; i++){
   for(size_t j{0}; j< col; j++){
      std::cout<<matrix[i*col +j]<<" ";
      }
   std::cout<<std::endl; 
  } 

}

int main(int argc, char* argv[]) 
{ 
  if(argc<3)
  {
    std::cout<<"Error :  provide the number of columns and rows"<<std::endl; 
    exit(-1);
  }
  size_t row, col;
  std::istringstream is{argv[1]}; 
  std::istringstream is2{argv[2]};
  is >> row; 
  is2>>col; 
  
  struct rlimit sl; 
  int  returnVal = getrlimit(RLIMIT_STACK, &sl);
  
  std::cout << "stackLimit soft - max : " << sl.rlim_cur<<std::endl;
  
  if(sl.rlim_cur < 8388608)
  { 
    std::cout<<"set a bigger stack size to execute the program"<<std::endl; 
    exit(-1); 
   
  } 
 /* constexpr size_t size = (8388608 - 2*sizeof(is) -9*sizeof(size_t) -sizeof(sl) -sizeof(int) -4*sizeof(double))/16;*/

  constexpr size_t size = 8300000/16;
  
  

std::array<double,size>matrix = matrix_create<size>(row*col);
printMatrix<size>(matrix,row,col);
transpose<size>(matrix,row,col);
std::cout<<"Transpose Matrix"<<std::endl;

printMatrix<size>(matrix,col,row);

return 0; 
}
