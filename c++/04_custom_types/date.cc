#include <iostream> 


enum class Months { jan=1 , feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };


class Date{ 

 private: 
  int day;
  Months month; 
  int year; 
  void add_one_day();
  int size_month(); 
 public: 
  Date(int _day, Months _month,int _year ): day{_day}, month{_month},year{_year}  {}
  void setDay(int _day){ day = _day;} 
  void setMonth(Months _month){month = _month;}
  void setYear(int _year){ year = _year;} 
  
  int getDay() const{ return day;} 
  Months getMonth() const {return month;} 
  int getYear() const{ return year; } 
  void add_days(const unsigned int n); 



}; 

Months operator+(Months m,int n)
{ 
 return Months((int(m) + n)%12) ;  //like circular buffer
} 

Months& operator++(Months& m)   //aggiungere il speculare, questo fa solo ++month, fare anche month++;
{
 m = m +1; 
 return m; 
}

int Date::size_month(){ 
 switch(month)
 { 
  case Months::jan:
  case Months::mar:
  case Months::may:
  case Months::jul: 
  case Months::aug:
  case Months::oct: 
  case Months::dec: 
    return 31; 
    break; 
  case Months::apr:
  case Months::jun: 
  case Months::sep:
  case Months::nov: 
    return 30;
    break; 
  case Months::feb: 
    return 28; 
    break; 
  default :
    return 1111111;    
    break; 
  }

}

void Date::add_one_day()
{ 
  if(day == size_month()){ 
   day =1;
   ++month; 
  if(month == Months::jan)
   year++;
  } 
  else day++; 

} 
void Date::add_days(const unsigned int n) { for(unsigned int i{0}; i<n; i++) add_one_day(); };
std::ostream& operator<<(std::ostream& os, const Date& d)
{
	os << d.getDay() << "/" << int(d.getMonth()) <<"/" << d.getYear() << "\n";
	return os;
}

bool operator==(const Date& d1, const Date& d2)
{ 
  return (d1.getDay()==d2.getDay())&&(d1.getMonth()==d2.getMonth())&&(d1.getYear()==d2.getYear()); 
} 

bool operator!=(const Date& d1, const Date& d2)
{ 
 return !(d1==d2); 
} 


	
int main() 
{ 
 
Date today{31,Months::dec,2012};
 
std::cout<<today<<std::endl;
today.add_days(3); 
std::cout<<today<<std::endl;

return 0; 
}




  
