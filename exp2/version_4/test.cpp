#include <vector>
#include "Cinteger_A.h"
#include "Cinteger_B.h"
#include "Serializable.h"
#include "Serializer.h"

using std::vector;

int main() {
	Cinteger_A a1(1), a2(2);
	Cinteger_B b1(10,20) b2(11,21);

	vector<CSerializable *> v;
	v.push_back(&a1);
	v.push_back(&b1);
	v.push_back(&a2);
	v.push_back(&b2);

	CSerializer serial;
	serial.Serialize("data.dat", v);

	vector<CSerializable *> vde;
	Cinteger_A a;
	Cinteger_B b;
	serial.Register(&a);
	serial.Register(&b);
	serial.Deserialize("data.dat", vde);

	for(int i = 0; i < vde.size(); i++)
		vde[i] -> print();

	for(int j = 0; j < vde.size(); j++)
		delete vde[i];

	return 0
}

