BOOST="/chroot/debian-7-amd64/home/bw/boost"

LDFLAGS = -L $(BOOST)/stage/lib

CPPFLAGS = -std=c++11 -I$(BOOST)

test : main.o Value.o Groups.o archive.o
	g++ -o test $^ -l boost_serialization $(LDFLAGS)

CPPFLAGS = -std=c++11 -I$(BOOST)

main.o : main.cpp Groups.h Value.h

Groups.o : Groups.cpp Groups.h Value.h

Value.o : Value.cpp Value.h

archive.o : archive.cpp archive.h archive_impl.h

.PHONY : clean

clean :
	@rm -f *.o
