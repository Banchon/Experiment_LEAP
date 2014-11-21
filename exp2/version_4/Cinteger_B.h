#ifndef CINTEGER_B_H
#define CINTEGER_B_H

#include "Serializable.h"
#include <iostream>
using std::cout;
using std::endl;

class Cinteger_B : public CSerializable {
	public :
		Cinteger_B() : i(0), j(0) { }
		Cinteger_B(int m, int n) : i(m), j(n) { }
		virtual ~Cinteger_B() { }
		void print() const {
			cout << "in Cinteger_B: i = " << i << " j = " << j << endl;
		}
		virtual int GetType() { return 1; }
		virtual bool Serialize(int fd);
		virtual CSerializable * Deserialize(int fd);
	private : 
		int i;
		int j;
};
#endif
