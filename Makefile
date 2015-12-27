# Application Name-- Still TBA!
APP = Hatchet

# Object files 
OBJS = Player.o Hatchet.o

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
SOUND = $(SRCDIR)sound/

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
	$(CXX) $(LFLAGS) -o $@ $(addprefix $(OBJDIR), $(OBJS))

obj/Hatchet.o: src/Hatchet.cpp
	$(CXX) $(CFLAGS) src/Hatchet.cpp $(OUT)

obj/Player.o: $(addprefix $(SOUND), $(PSRC))
	$(CXX) $(CFLAGS) $(SOUND)Player.cpp $(OUT)

clean:
	rm -f $(APP) $(TARBALL) 
	rm -f .*~ *~ src/*~ src/*/*~ src/*/.*~ 
	rm -f obj/*.o*

tar: 
	tar -cvf $(TARBALL) $(SRCDIR)*

backup:
	tar -cvf $(BACKUP) $(SRCDIR)*

