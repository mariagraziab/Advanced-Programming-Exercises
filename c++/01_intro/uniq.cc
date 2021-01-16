#include <iostream> 
#include <sstream> 

int main(){ 

std::string line; 
std::string prev_line{}; 
std::ostringstream tot_string; 
int n;
int count{1};


std::cout<<"Insert some lines , insert CTRL+d to stop"<<std::endl; 

while(std::getline(std::cin,line))
{ 
 
 
  while(line.back() == 32)
  { 
    line = line.substr(0,line.length()-1); 
  } 
  n = line.length();
  if(n==0) continue;
  if(line == prev_line){ count ++;} 
  else if(prev_line != "")
  {    //the condition is only for the defoult first line
    tot_string<<prev_line<<" "<<count<<"\n"; 
    count = 1; 
  } 

  prev_line = line; 

}

tot_string<< prev_line << " " << count<< "\n";

std::cout << tot_string.str() << std::endl;



return 0; 
}


