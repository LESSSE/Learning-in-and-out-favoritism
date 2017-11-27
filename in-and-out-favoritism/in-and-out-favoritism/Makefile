CXX=g++
RM=rm -f
CXXFLAGS=-Wall

all: main.exe

main.exe: agent interaction move coopgame
	$(CXX) $(CXXFLAGS) -o $@ *.h *.cpp

agent: Agent.cpp Agent.h

interaction: Interaction.cpp Interaction.h

coopgame: CoopGame.cpp CoopGame.h

move: Move.cpp Move.h

clean:
	$(RM) main.exe 
