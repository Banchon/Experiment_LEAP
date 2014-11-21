#include <vector>
#include "Cinteger_A.h"
#include "Cinteger_B.h"
#include "Serializer.h"

using std::vector;

int main() {
	vector<Sserialized> v;
	Sserialized temp;
	for(int i = 0; i < 3; i++) {
		temp.nType = 0;
		temp.pObj = (void *)(new Cinteger_A(i));
		v.push_back(temp);
	}

	for(int i = 0; i < 3; i++) {
		temp.nType = 1;
		temp.pObj = (void *)(new Cinteger_B(10*i, 10*i + 1));
		v.push_back(temp);
	}

	Serializer serial;
	serial.Serialize("data.dat", v);


	vector<Sserialized> vde;
	serial.Deserialize("data.dat", vde);

	for(auto a : vde) {
		if(a.nType == 0)
		{
			Cinteger_A *ptr = (Cinteger_A *)a.pObj;
			ptr->print();
		}
		if(a.nType == 1) {
			Cinteger_B *ptr = (Cinteger_B *)a.pObj;
			ptr->print();
		}
	}

	return 0;
}
