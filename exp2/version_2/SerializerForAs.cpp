#include "fcntl.h"
#include "unistd.h"
#include "Cinteger_A.h"
#include "SerializerForAs.h"
#include <vector>
#include "filePermission.h"

using std::vector;

bool SerializerForAs::Serialize(const char *pFilePath, const vector<Cinteger_A> &v) {
	int fd = open(pFilePath, O_WRONLY | O_CREAT | O_APPEND, DEFAULT_FILE_PERMISSION);
	if(fd == -1) {
		cout << "open error." << endl;
		return false;
	}

	for(auto a : v) {
		if(a.Serialize(fd) == -1) {
			close(fd);
			return false;
		}
	}

	close(fd);
	return true;
}


bool SerializerForAs::Deserialize(const char *pFilePath, vector<Cinteger_A> &v) {
	int fd = open(pFilePath, O_RDONLY);
	if(fd == -1) {
		cout << "open error." << endl;
		return false;
	}

	Cinteger_A a;
	int tag;
	for(;;) {
		tag = a.Deserialize(fd);
		if(tag == 1)
			v.push_back(a);
		else if(tag == 0)
			break;
		else  {
			close(fd);
			return false;
		}
	}

	close(fd);
	return true;
}
