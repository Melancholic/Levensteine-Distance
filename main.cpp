#include"levenstein.h"
#include<string>
#include<iostream>
int main(){
	//Levenstein a;
	std::string A;
	std::string B;
	std::cout<<"\nВведите 1ю строку: ";
	std::cin>>A;
	std::cout<<"\nВведите 2ю строку: ";
	std::cin>>B;
	Levenstein::get_distance(A,B);
	return 0;
}
