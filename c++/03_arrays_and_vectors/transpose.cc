#include <iostream> 
#include <array> 
#include <utility> 


//modificare per formattare gli spazi 


template<size_t N> 
std::array<double,N> matrix_create()
{ 
 std::array<double,N> matrix; 
 for(size_t i=0; i<N; i++)
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
     

int main(){
const std::size_t row = 4; 
const std::size_t col = 5;
const std::size_t size =row*col; 

std::cout<<"Rectangular Matrix"<<std::endl;
std::array<double,size>matrix = matrix_create<size>();
printMatrix<size>(matrix,row,col);
transpose<size>(matrix,row,col);
std::cout<<"Transpose Matrix"<<std::endl;
printMatrix<size>(matrix,col,row);

std::cout<<"Square Matrix"<<std::endl; 
const std::size_t size2 = col*col;
std::array<double,size2>matrix2 = matrix_create<size2>();
printMatrix<size2>(matrix2,col,col);
transpose<size2>(matrix2,col,col);
std::cout<<"Transpose Matrix"<<std::endl;
printMatrix<size2>(matrix2,col,col);



return 0; 
}



