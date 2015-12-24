# Application Name-- Still TBA!
APP = app

# Object files 
OBJS = test.o

# g++ options and flags
CXX = g++
DEBUG = -g
CHECKS = -Wall -Werror 
INCLUDES = -lvlc 
CFLAGS = $(CHECKS) $(INCLUDES) -c
LFLAGS = $(CHECKS) $(INCLUDES)
OUT = -o $@

# Relevant directories
SRCDIR = src/
OBJDIR = obj/
AUDIO = $(SRCDIR)audio/

# Relevant source files, by object
PSRC = test.cpp

# Extras 
TARBALL = $(APP)_src.tar
BACKUP = build_$$(date +%Y%m%d_%H%M%S).tar


#############################################
############## BUILD TARGETS ################
#############################################


all: $(APP)

$(APP): $(addprefix $(OBJDIR), $(OBJS))
	$(CXX) -o $@ $< $(LFLAGS)

obj/test.o: $(addprefix $(AUDIO), $(PSRC))
	$(CXX) $(CFLAGS) $(AUDIO)/test.cpp $(OUT)


clean:
	rm -f $(APP) $(TARBALL) *~ obj/*.o src/*/*~ src/*/.*~


tar: 
	tar -cvf $(TARBALL) $(SRCDIR)*

backup:
	tar -cvf $(BACKUP) $(SRCDIR)*

