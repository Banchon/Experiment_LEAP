#include "Cinteger_A.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using std::cout;
using std::endl;

#define DEFAULT_FILE_PERMISSION S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

bool Cinteger_A::Serialize(const char *pFilePath) const {
	int fd = open(pFilePath, O_WRONLY | O_CREAT | O_TRUNC, DEFAULT_FILE_PERMISSION);
	
	if(fd == -1) {
		cout << "open error." << endl;
		return false;
	}

	if(write(fd, &i, sizeof(int)) == -1) {
		cout << "write error." << endl;
		close(fd);
		return false;
	}

	close(fd);
	return true;
}

bool Cinteger_A::Deserialize(const char *pFilePath) {
	
	int fd = open(pFilePath, O_RDONLY);
	if(fd == -1) {
		cout << "open error." << endl;
		return false;
	}

	int readState = read(fd, &i, sizeof(int));
	if(readState == -1 || readState == 0) {
		cout << "read error" << endl;
		close(fd);
		return false;
	}

	close(fd);
	return true;

}

