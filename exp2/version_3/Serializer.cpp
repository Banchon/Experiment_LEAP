#include "Serializer.h"
#include "Cinteger_A.h"
#include "Cinteger_B.h"
#include "filePermission.h"
#include "fcntl.h"
#include "unistd.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool Serializer::Serialize(const char *pFilePath, const vector<Sserialized> &v) {
	int fd = open(pFilePath, O_WRONLY | O_CREAT | O_APPEND, DEFAULT_FILE_PERMISSION);
	if(fd == -1)
		return false;

	for(auto a : v) {
		if(write(fd, &a.nType, sizeof(int)) == -1) {
			close(fd);
			return false;
		}

		if(a.nType == 0) {
			Cinteger_A *ptr = (Cinteger_A *)a.pObj;
			if(ptr->Serialize(fd) == -1) {
				close(fd);
				return false;
			}
		}

		if(a.nType == 1) {
			Cinteger_B *ptr = (Cinteger_B *)a.pObj;
			if(ptr->Serialize(fd) == -1) {
				close(fd);
				return false;
			}
		}
	}
		close(fd);
		return true;
}

bool Serializer::Deserialize(const char *pFilePath, vector<Sserialized> &v){
	int fd = open(pFilePath, O_RDONLY);
	if(fd == -1)
		return false;

	for(;;) {
		int nType;
		int readState = read(fd, &nType, sizeof(int));
		if(readState == -1 || readState == 0) {
			close(fd);
			return false;
		}

		if(nType == 0) {
			Cinteger_A *ptr = new Cinteger_A;
			int revalue = ptr->Deserialize(fd);
			if(revalue == 1) {
				Sserialized temp;
				temp.nType = nType;
				temp.pObj = (void *)ptr;
				v.push_back(temp);
			}
			if(revalue == 0)
				break;
			if(revalue == -1) {
				close(fd);
				return false;
			}
		}

		if(nType == 1) {
			Cinteger_B *ptr = new Cinteger_B;
			int revalue = ptr->Deserialize(fd);
			if(revalue == 1) {
				Sserialized temp;
				temp.nType = nType;
				temp.pObj = (void *)ptr;
				v.push_back(temp);
			}
			if(revalue == 0)
				break;
			if(revalue == -1) {
				close(fd);
				return false;
			}
		}
	}

	close(fd);
	return true;
}	
