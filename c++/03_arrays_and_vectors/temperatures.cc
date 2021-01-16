#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
std::vector<double> read_temp(std::string);
double mean_comp(const std::vector<double>);
double median_comp(const std::vector<double>);
int main()
{
 
 std::string filename = "temperatures.txt";
 std::vector<double>temperatures = read_temp(filename);
 //for(auto x: temperatures)
  // std::cout<<x<<std::endl; 
 double mean = mean_comp(temperatures); 
 std::cout<<mean<<std::endl; 
 double median = median_comp(temperatures); 
 std::cout<<median<<std::endl; 

 return 0; 
} 


std::vector<double> read_temp(std::string filename)
{

 std::vector<double> temperatures; 
 std::ifstream input;
 input.open(filename); 
 double temp{}; 

 while(input>>temp){ 
 
 //input>>temp; 
 temperatures.push_back(temp); 
 
 } 
 
 return temperatures; 

}


double mean_comp(const std::vector<double> temperatures)
{ 
 double mean{0.0}; 
 for(auto x: temperatures)
   mean += x;

 mean = mean/temperatures.size();
 
 return mean; 
} 

double median_comp(std::vector<double> temperatures)
{
 std::sort(temperatures.begin(),temperatures.end());
 int dim = temperatures.size(); 
 if(dim%2) return temperatures[int(dim/2)]; 
 return (temperatures[dim/2]+temperatures[dim/2 -1])/2.0; 
 } 




