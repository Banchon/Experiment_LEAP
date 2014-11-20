#include "Cinteger_A.h"
#include "SerializerForAs.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	vector<Cinteger_A> v;
	
	Cinteger_A a(10), b(20), c(30), d(40);

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

	SerializerForAs serializer;
	serializer.Serialize("data.dat", v);

	vector<Cinteger_A> vde;
	serializer.Deserialize("data.dat", vde);

	for(auto e : vde)
		e.print();

	return 0;
}
