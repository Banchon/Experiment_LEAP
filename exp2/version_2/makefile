OBJ = Cinteger_A.o SerializerForAs.o test.o
test : ${OBJ}
	g++ -o test ${OBJ} --std=c++11
	rm *.o
Cinteger_A.o : Cinteger_A.cpp Cinteger_A.h
	g++ -c -o Cinteger_A.o Cinteger_A.cpp --std=c++11
SerializerForAs.o : SerializerForAs.cpp SerializerForAs.h Cinteger_A.h
	g++ -c -o SerializerForAs.o SerializerForAs.cpp --std=c++11
test.o : test.cpp SerializerForAs.h Cinteger_A.h
	g++ -c -o test.o test.cpp --std=c++11

