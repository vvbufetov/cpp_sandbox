BOOST="/chroot/debian-7-amd64/home/bw/boost"

LDFLAGS = -L $(BOOST)/stage/lib

CPPFLAGS = -std=c++11 -I$(BOOST)


test : main.o Object.o
	g++ -o test $^ -l boost_serialization $(LDFLAGS)

Object.o : Object.cpp Object.h

.PHONY : clean

clean :
	@rm -f *.o