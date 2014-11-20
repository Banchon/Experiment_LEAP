#ifndef CINTEGER_B_H
#define CINTEGER_B_H

#include <iostream>

using std::cout;
using std::endl;

class Cinteger_B {
	public :
		Cinteger_B() : i(0), j(0) { }
		Cinteger_B(int m, int n) : i(m), j(n) { }
		virtual ~Cinteger_B() { }
		void print() const {
			cout << "in Cinteger_B: i = " << i << " j = " << j << endl;
		}
		bool Serialize(const char *pFilePath) const;
		bool Deserialize(const char *pFilePath);

		int Serialize(int fd) const;
		int Deserialize(int fd);
	private : 
		int i;
		int j;
};
#endif
