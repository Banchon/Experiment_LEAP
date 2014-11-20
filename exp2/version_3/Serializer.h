#ifndef SERIALIZER_H
#define SERIALIZER_H

#include<vector>

using std::vector;

typedef struct Sserialized {
	int nType; //0 for A; 1 for B
	void *pObj;
}Sserialized;

class Serializer {
	public:
	   	bool Serialize(const char *pFilePath, const vector<Sserialized> &v);
		bool Deserialize(const char *pFilePath, vector<Sserialized> &v);
};

#endif


