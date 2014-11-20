#include "Cinteger_A.h"

int main() {
	Cinteger_A a(10);
	a.Serialize("data.dat");

	Cinteger_A b;
	b.Deserialize("data.dat");
	b.print();
	
	return 0;
}
