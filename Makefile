# Application Name-- Still TBA!
APP = Hatchet

# Object files 
OBJS = Player.o

# g++ options and flags
CXX = g++
DEBUG = -g
CHECKS = -Wall -Werror 
INCLUDES = -lvlc 
CFLAGS = -std=c++11 $(CHECKS) $(INCLUDES) -c
LFLAGS = -std=c++11 $(CHECKS) $(INCLUDES)
OUT = -o $@

# Relevant directories
SRCDIR = src/
BINDIR = bin/
OBJDIR = obj/
AUDIO = $(SRCDIR)audio/

# Relevant source files, by object
PSRC = Player.cpp Player.h

# Extras 
TARBALL = $(APP)_src.tar
BACKUP = build_$$(date +%Y%m%d_%H%M%S).tar


#############################################
############## BUILD TARGETS ################
#############################################


all: $(APP)

$(APP): $(addprefix $(OBJDIR), $(OBJS))
	$(CXX) $(LFLAGS) -o $@ $<

obj/Hatchet.o: src/Hatchet.cpp
	$(CXX) $(CFLAGS) src/Hatchet.cpp $(OUT)

obj/Player.o: $(addprefix $(AUDIO), $(PSRC))
	$(CXX) $(CFLAGS) $(AUDIO)/Player.cpp $(OUT)

clean:
	rm -f $(APP) $(TARBALL) 
	rm -f .*~ *~ src/*~ src/*/*~ src/*/.*~ 
	rm -f obj/*.o*

tar: 
	tar -cvf $(TARBALL) $(SRCDIR)*

backup:
	tar -cvf $(BACKUP) $(SRCDIR)*

