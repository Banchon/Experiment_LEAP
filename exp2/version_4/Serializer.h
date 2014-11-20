#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "Serializable.h"
#include <vector>

using std::vector;

class CSerializer {
	public:
	   	bool Serialize(const char *pFilePath, const vector<CSerializable *> &v);
		bool Deserialize(const char *pFilePath, vector<CSerializable *> &v);
		void Register(CSerializable * ptr) { m_vHandleRange.push_back(ptr);}
	private:
		vector<CSerializable *> m_vHandleRange;
};

#endif


