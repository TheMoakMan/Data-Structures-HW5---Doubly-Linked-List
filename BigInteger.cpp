#include "BigInteger.h"

const std::string USERNAME = "ebmy83";
const std::string STUDENT_ID = "12422230";

void get_identity(std::string my_id[])
{
  my_id[0] = USERNAME;
  my_id[1] = STUDENT_ID;
}

/*~~EXCEPTION~~~*/
BigIntException Big_Ex;

//Determines if the string is a correctly input integer string
//Ex, "888665858449" is valid. Ex, "-97949330" is also valid.
bool valid_int_string(std::string & str)
{
  bool valid = true;
  int i = 0;
  
  if(str[i] == '-')
	i = 1;

  while(valid && i < str.length()){
	valid = false;
    if(str[i] >= '0' && str[i] <= '9')
	  valid = true;
	  
	i++;  
  }
  
  return valid;
	
}

template <typename T>
void string_to_list(MyList<T> & l, std::string str)
{
  //Clear the array before building	
  l.clear();
  
  //Build the integer vector
    for(int i = 0; i < str.length(); i++){
      l.push_back(str[i]); 
    }	   
}

std::string list_to_string(MyList<int> list)
{
  std::string big_number;
  MyList<int> bigNum(list);
  
  if(bigNum.front() == '-'){
	big_number += '-';
    for(int i = 1; i < bigNum.size(); i++){
      big_number += (bigNum.front() + '0');
      bigNum.erase(1);	  
    }
  }
  else
	for(int i = 0; i < bigNum.size(); i++){
      big_number += (bigNum.front() + '0');
      bigNum.erase(1);	  
    }
	  
  return big_number;
}

void to_valid_int(MyList<int> & number)
{
  MyList<int> tempList(number);
  number.clear();
  
  //Set each element to a valid integer value
  if(tempList.front() == '-'){
	number.push_back('-');
	tempList.erase(1);
	
	for(int i = 1; i < tempList.size(); i++){
	  number.push_back(tempList.front() - '0');
	  tempList.erase(1);
	}
  }
  else if(tempList.front() != '-')
    for(int i = 0; i < tempList.size(); i++){
	  number.push_back(tempList.front() - '0');
	  tempList.erase(1);
	}		
}

/*~~~BIGINTEGER FUNCTIONS~~~*/
BigInteger::BigInteger()
{
  digit_list.clear();	
  isNegative = false;	
}

BigInteger::BigInteger(std::string really_big_number)
{
  //Check if the string is a valid integer
  bool valid_string = valid_int_string(really_big_number);

  if(valid_string){
    if(really_big_number[0] == '-')
      isNegative = true;
    else
	  isNegative = false;
    
    string_to_list(digit_list, really_big_number);

	to_valid_int(digit_list);

  } 
  else{ 
    throw Big_Ex;
  }	
	
}

std::string BigInteger::to_string()
{
  std::string big_number;
  MyList<int> tempList(digit_list);
  
  if(isNegative){
	big_number += '-';
    for(int i = 1; i < tempList.size(); i++){
      big_number += (tempList.front() + '0'); 
      tempList.erase(1);	  
    }
  }	
  else
	for(int i = 0; i < tempList.size(); i++){
      big_number += (tempList.front() + '0');	
      tempList.erase(1);	  
    }
	 
  return big_number;
}

bool BigInteger::is_prime()
{
	
	
}

/*~~~~OPERATOR OVERLOADS~~~~*/
BigInteger operator+(const BigInteger &bi1, const BigInteger &bi2)
{
	
	
}

BigInteger operator-(const BigInteger &bi1, const BigInteger &bi2)
{
	
	
}

BigInteger operator*(const BigInteger &bi1, const BigInteger &bi2)
{
	
	
}

BigInteger operator/(const BigInteger &bi1, const BigInteger &bi2)
{
	
	
}

