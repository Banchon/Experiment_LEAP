OBJ = Cinteger_A.o Cinteger_B.o Serializer.o test.o
test : ${OBJ}
	g++ -o test ${OBJ} --std=c++11
	rm *.o
Cinteger_A.o : Cinteger_A.cpp Cinteger_A.h filePermission.h
	g++ -c -o Cinteger_A.o Cinteger_A.cpp --std=c++11
Cinteger_B.o : Cinteger_B.cpp Cinteger_B.h filePermission.h
	g++ -c -o Cinteger_B.o Cinteger_B.cpp --std=c++11
Serializer.o : Serializer.cpp Serializer.h Cinteger_A.h Cinteger_B.h filePermission.h
	g++ -c -o Serializer.o Serializer.cpp --std=c++11
test.o : test.cpp Cinteger_A.h Cinteger_B.h Serializer.h
	g++ -c -o test.o test.cpp --std=c++11
clean :
	rm test data.dat
