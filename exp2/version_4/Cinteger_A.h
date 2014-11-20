#ifndef CINTEGER_A_H
#define CINTEGER_A_H

#include <iostream>
#include "Serializable.h"

using std::cout;
using std::endl;

class Cinteger_A : public CSerializable {
	public :
		Cinteger_A() : i(0) { }
		explicit Cinteger_A(int k) : i(k) { }
		virtual ~Cinteger_A() { }
		void print() const {
			cout << "in Cinteger_A: i = " << i << endl;
		}
		virtual int GetType() { return 0; }
		virtual bool Serialize(int fd);
		virtual CSerializable * Deserialize(int fd);
	private : 
		int i;
};
#endif
