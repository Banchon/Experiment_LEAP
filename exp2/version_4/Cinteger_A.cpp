#include "Cinteger_A.h"
#include <fcntl.h>
#include <unistd.h>

bool Cinteger_A::Serialize(int fd) {
	if(fd == -1)
		return false;

	if(write(fd, &i, sizeof(int)) == -1)
		return false;

	return true;
}

CSerializable * Cinteger_A::Deserialize(int fd) {
	if (fd == -1)
		return 0;

	Cinteger_A *ptr = new Cinteger_A;
	if(ptr == 0)
		return 0;

	int readState = read(fd, &(ptr->i), sizeof(int));
	if(readState == -1 || readState == 0) {
		delete ptr;
		return 0;
	}

	return ptr;
}


