# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -g -Wall -Wextra -Wpedantic
# Target executable
streamflix : main.o movies.o tvshows.o users.o
	$(CXX) $(CXXFLAGS) -o streamflix main.o movies.o tvshows.o users.o

# Rule to compile main.cpp into main.o
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile movie.cpp into movie.o
movies.o: Movies.cpp Movies.h
	$(CXX) $(CXXFLAGS) -c Movies.cpp

# Rule to compile tvshow.cpp into tvshow.o
tvshows.o: tvshow.cpp TVshows.h
	$(CXX) $(CXXFLAGS) -c tvshow.cpp

# Rule to compile users.h into users.o
users.o: Users.h
	$(CXX) $(CXXFLAGS) -c Users.h

# Clean rule
clean:
	rm -f *.o programname