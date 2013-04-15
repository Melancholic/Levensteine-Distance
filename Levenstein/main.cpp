#include"levenstein.h"
#include<string>
#include<iostream>
#include<climits>
int main(){
	//Levenstein a;
	std::string A;
	std::vector<std::string> Strings;
	Strings.push_back("Programming");
	Strings.push_back("computer");
	Strings.push_back("system");
	Strings.push_back("Tux");

	std::cout<<"\nДоступный словарь:\n";
	for(int i=0;i<Strings.size();i++){
		std::cout<<Strings[i]<<"\n";
	}
	std::cout<<"\nВведите слово из словаря с опечатками : ";
	std::cin>>A;
	long int min=INT_MAX;
	long int IndMin;
	for(int i=0;i<Strings.size();++i){
		long int tmp;
		if (min>=(tmp=Levenstein::get_distance(A,Strings[i]))) {
			min=tmp;
			IndMin=i;
		}
	}
	if(min==0){
		std::cout<<"\nВы верно ввели слово "<<Strings[IndMin]<<". В след. раз попробуйте с опечаткой!";
	}else{
		if(min!=INT_MAX){
			std::cout<<"\nВы, вероятно, допустили опечатку в слове "<<Strings[IndMin]<<".";
		}
	}
	return 0;
}
