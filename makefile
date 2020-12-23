CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = utility.o menu.o item.o character.o player.o fallen.o space.o battle.o free.o search.o game.o main.o

SRCS = utility.cpp menu.cpp item.cpp character.cpp player.cpp fallen.cpp space.cpp battle.cpp free.cpp search.cpp game.cpp main.cpp

HEADERS = utility.hpp menu.hpp item.hpp character.hpp player.hpp fallen.hpp space.hpp battle.hpp free.hpp search.hpp game.hpp  

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o final 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	$(RM) final utility.o menu.o item.o character.o player.o fallen.o space.o battle.o free.o search.o game.o main.o
