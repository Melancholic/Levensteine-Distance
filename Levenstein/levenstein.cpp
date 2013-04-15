#include"levenstein.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define wRpc 1 //weight replace
#define wDlt 1 //weight delete
#define wIns 1 //weight insert
long int Levenstein::get_distance(std::string S1, std::string S2){
	long int **D=new long int*[S1.length()+1];
	for ( int i=0; i<S1.length()+1;++i){
		D[i]=new long int[S2.length()+1];
	}
	for(int i=0; i<=S1.length();++i){
		D[i][0]=i;
	}
        for(int i=0; i<=S2.length();++i){
                D[0][i]=i;
        } 
	for(int i=1; i<=S1.length();++i){
               for(int j=1; j<=S2.length();++j){
			int err;
			if(S1[i-1]==S2[j-1])err=0; else err=1;
			D[i][j]=std::min(std::min(D[i-1][j]+wDlt,D[i][j-1]+wIns),D[i-1][j-1]+wRpc*err);
		}
        }
	int a = S1.length();
    	int b = S2.length();
	long int Dist = D[S1.length()][S2.length()];
	std::cout<<"Редакционное расстояние Левенштейна: "<<Dist;
   	while (a > 0 && b > 0 || (a == 0)^(b == 0)){
        	if (a-1>=0&&(D[a][b]==D[a-1][b]+wDlt)) {
			std::cout<<"\nудалить символ " <<S1[a - 1]<< " в <"<<S1<< "> стоящий на " <<(a)<< " месте";
           		 a--;
        	}else
            		if (a-1>=0&&(D[a][b]==D[a][b-1]+wIns)){
                		std::cout<<"\nвставить символ "<<S2[b-1]<<" в <"<< S1 << "> на " << (b) << " место";
               			b--;
            		}else{
                if (S1[a-1] != S2[b-1])
			std::cout<<"\nзаменить "<<(a)<<" символ "<< S1[a - 1]<<" из <"<<S1+"> на "<<(b)<< " символ "<<S2[b - 1]<< " из <" << S2<<">";
                	a--;
                	b--;
            }
    	}	
	for ( int i=0; i<S1.length()+1;++i){
               delete  D[i];
        }
	delete[] D;
	std::cout<<"\n";
	return Dist;


}


