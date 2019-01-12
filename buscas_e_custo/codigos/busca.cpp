#include <random>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include <math.h>

using namespace std;


void quick_sort(vector<unsigned> &vet){
  for(unsigned i=0; i < vet.size(); i++){
    for(unsigned j=i+1; j < vet.size(); j++){
      if(vet[i] > vet[j]){
        unsigned aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
     
    }
  }

}

unsigned* ingenua(unsigned value, vector<unsigned> vet, unsigned *init, unsigned *end, unsigned &cont){
	unsigned *position = NULL;	
	for(init; init<end; init++){
		if(*(init)==value){
			position=init;
			cont++;
			return position;					
		}
		cont++;
	}
	return position;
}

unsigned binaria(unsigned value, vector<unsigned> vet, unsigned init, unsigned end, unsigned &cont){
	unsigned half = (init+ ((end-init)/2));
	unsigned index=-1;
	
	if(value == vet[init]){
		index = init;		
		cont++;
		return index;
	}
	else if(value == vet[end]){
		index = end;		
		cont++;
	   return index;
	}

	while(half != end and half != init){
		if(vet[half] == value){
			index = half;
			cont++;
			return index;		
		}
		else if(vet[half] < value){
			init = half;
			cont++;
		}
		else{
			end = half;
			cont++;					
		}

		half = (init+ ((end-init)/2));
	}
	return index;
}

/*TEST(Ordenar, quick){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	
	for(unsigned i=0; i<4;i++){
		EXPECT_TRUE(vet[i]<vet[i+1]);		
	}
	
}

TEST(Ingenua, nao_possui){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	unsigned* elemento;
	unsigned cont =0;
	elemento=ingenua(8,vet,&vet[0], &vet[vet.size()-1],cont) ;
	EXPECT_TRUE(elemento==NULL);
}

TEST(Ingenua, possui){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	unsigned* position;
	unsigned cont =0;
	position=ingenua(2,vet,&vet[0], &vet[vet.size()-1],cont) ;
	EXPECT_TRUE(position==&vet[1]);
}

TEST(Binaria, possui){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	unsigned cont =0;
	unsigned position;
	position = binaria(2,vet,0,3,cont);
	EXPECT_TRUE(position==1);
}

TEST(Binaria, nao_possui){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	unsigned cont =0;
	unsigned position;
	position = binaria(8,vet,0,3,cont);
	EXPECT_TRUE(position==-1);
}

TEST(Binaria, inicio){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	unsigned cont =0;
	unsigned position;
	position = binaria(1,vet,0,3,cont);
	EXPECT_TRUE(position==0);
}

TEST(Binaria, fim){
	vector<unsigned> vet{5,1,6,2};
	quick_sort(vet);
	unsigned cont =0;
	unsigned position;
	position = binaria(6,vet,0,3,cont);
	EXPECT_TRUE(position==3);
}*/
int main(int argc, char **argv){
	unsigned position;
	unsigned cont = 0;	
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	
		
	for (int vec_size = 10; vec_size < 90000; vec_size+=500) {
      for (int samples = 0; samples < 1; ++samples) {
      	vector<unsigned> random;
			uniform_int_distribution<> dis(1, vec_size);
        for (int n = 0; n < vec_size; ++n) {
            random.push_back(dis(gen));
        }
        
   	   quick_sort(random);
	      //ingenua(dis(gen),random, &random[0], &random[random.size()],cont);
			binaria(dis(gen),random, 0,(random.size()-1),cont);
      	cout << vec_size << " " << cont << endl;
      }
		cont=0;
	}
		
		//::testing::InitGoogleTest(&argc, argv);
      //return RUN_ALL_TESTS();

}
