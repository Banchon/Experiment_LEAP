#include "Serializer.h"
#include "Serializable.h"
#include "filePermission.h"
#include "fcntl.h"
#include "unistd.h"
#include <vector>

using std::vector;


bool CSerializer::Serialize(const char *pFilePath, const vector<CSerializable *> &v) {
	int fd = open(pFilePath, O_WRONLY | O_CREAT | O_APPEND, DEFAULT_FILE_PERMISSION);
	if (fd == -1)
		return false;
	for(int i = 0; i < v.size(); i++) {
		int nType = v[i] -> GetType();

		if(write(fd, &nType, sizeof(int)) == -1) {
			close(fd);
			return false;
		}

		if(!(v[i] -> Serialize(fd))) {
			close(fd);
			return false;
		}
	}

	close(fd);
	return true;
}


bool CSerializer::Deserialize(const char *pFilePath, vector<CSerializable *> &v) {
	int fd = open(pFilePath, O_RDONLY);
	if(fd == -1)
		return false;

	for(;;) {
		int nType;
		int readState = read(fd, &nType, sizeof(int));
		if(readState == -1) {
			close(fd);
			return false;
		}
		if(readState == 0)
			break;

		for(int i = 0; i < m_vHandleRange.size(); i++) {
			if(m_vHandleRange[i]->GetType() == nType)
			{
				CSerializable *ptr = m_vHandleRange[i]->Deserialize(fd);
				if(ptr == 0) {
					close(fd);
					return false;
				}
				v.push_back(ptr);
			}
		}
	}
	close(fd);
	return true;
}
