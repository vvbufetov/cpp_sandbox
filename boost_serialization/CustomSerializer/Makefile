BOOST="/chroot/debian-7-amd64/home/bw/boost"

LDFLAGS = -L $(BOOST)/stage/lib

CPPFLAGS = -std=c++11 -I$(BOOST)


test : main.o Object.o archive.o
	g++ -o test $^ -l boost_serialization $(LDFLAGS)

Object.o : Object.cpp Object.h archive.h archive_impl.h

archive.o : archive.cpp archive.h archive_impl.h

.PHONY : clean

clean :
	@rm -f *.o
