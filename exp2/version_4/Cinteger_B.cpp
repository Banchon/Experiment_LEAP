#include "Cinteger_B.h"
#include <fcntl.h>
#include <unistd.h>


bool Cinteger_B::Serialize(int fd) {
	if(fd == -1)
		return false;

	if(write(fd, &i, sizeof(int)) == -1)
		return false;

	if(write(fd, &j, sizeof(int)) == -1)
		return false;

	return true;
}


CSerializable * Cinteger_B::Deserializable(int fd) {
	if(fd == 0)
		return 0;

	Cinteger_B *ptr = new Cinteger_B;
	if(ptr == 0)
		return 0;

	int readState = read(fd, &(ptr->i), sizeof(int));
	if(readState == -1 || readState == 0) {
		delete ptr;
		return 0;
	}

	readState = read(fd, &(ptr->j), sizeof(int));
	if(readState == -1 || readState == 0) {
		delete ptr;
		return 0;
	}

	return ptr;
}
