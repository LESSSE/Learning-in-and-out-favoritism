CXX=g++
RM=rm -f
CXXFLAGS=-Wall

all: main.exe

main.exe: agent interaction move coop_game
	$(CXX) $(CXXFLAGS) -o $@ *.h *.cpp

agent: Agent.cpp Agent.h

interaction: Interaction.cpp Interaction.h

coop_game: Coop_Game.cpp Coop_Game.h

move: Move.cpp Move.h

clean:
	$(RM) *.o 
