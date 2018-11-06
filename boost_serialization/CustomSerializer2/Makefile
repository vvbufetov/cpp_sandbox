BOOST="../boost"

LDFLAGS = -L $(BOOST)/lib

CPPFLAGS = -std=c++11 -I$(BOOST)/include


test : main.o Object.o archive.o
	g++ -o test $^ -l boost_serialization $(LDFLAGS)

Object.o : Object.cpp Object.h archive.h archive_impl.h

archive.o : archive.cpp archive.h archive_impl.h

.PHONY : clean

clean :
	@rm -f *.o
