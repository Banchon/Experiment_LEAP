#ifndef CINTEGER_A_H
#define CINTEGER_A_H

#include <iostream>

using std::cout;
using std::endl;

class Cinteger_A {
	public :
		Cinteger_A() : i(0) { }
		Cinteger_A(int k) : i(k) { }
		virtual ~Cinteger_A() { }
		void print() const {
			cout << "in Cinteger_A: i = " << i << endl;
		}
		bool Serialize(const char *pFilePath) const;
		bool Deserialize(const char *pFilePath);
	private : 
		int i;
};
#endif
