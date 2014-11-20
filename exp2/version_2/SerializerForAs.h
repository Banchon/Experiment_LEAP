#ifndef SERIALIZERFORAS_H
#define SERIALIZERFORAS_H
#include "Cinteger_A.h"
#include <vector>

using std::vector;

class SerializerForAs {
	public:
		bool Serialize(const char *pFilePath, const vector<Cinteger_A> &v);
		bool Deserialize(const char *pFilePath, vector<Cinteger_A> &v);
};

#endif
