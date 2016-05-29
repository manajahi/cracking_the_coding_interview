# Makefile for cracking_the_coding_interview/1-Data_Structures/2-LinkedLists
#
# Defines the build configuration targets and recipes thereof
#
# Copyright 2016 Edmund Highan
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

CCFLAGS=-std=c++11 $(INLINE_WARN) $(INLINE_LIMIT) -pthread -Wall
OPTIM = -O3 -march=native -DNDEBUG 
DEBUG = -O0 -g -Wall -Wextra -Wconversion
GPP=g++
BASEDIR=.
OBJDIR=$(BASEDIR)/obj
BIN=$(BASEDIR)
SRCDIR=src
RESDIR=$(SRCDIR)/resource
LIBCINC= -I.
LIBLINC= -L. 
LIBLINK= -lm #-lgsl -lgslcblas #-lgmp -lmpfr

CFLAGS=$(CCFLAGS)  -Wall  $(LIBCINC) 
LFLAGS=$(CCFLAGS)  -Wall  $(LIBLINC)

#############################################################################
#add non-executables .c files to OBJS 
#if .c file reside in a dir other than the current one, add .o rule below
OBJS=$(OBJDIR)/strings.o \
		 $(OBJDIR)/tuple.o \
		 $(OBJDIR)/var.o \
		 $(OBJDIR)/run.o 


##############################################################################
#EXECUTABLES: add executables rules here

.PHONY: release all test debug

release: CFLAGS +=$(OPTIM)
release: search
	@echo "release: build successful"

all: CFLAGS += $(OPTIM)
all: search
all: test
	@echo "all: build successful"

debug: CFLAGS += $(DEBUG)
debug: search
	@echo "debug: build successful"


test:
	make -f test/Makefile

search: $(OBJDIR)/search.oo
	ln -s $(OBJDIR)/search.oo $(BIN)/run

%.oo: %.o $(OBJS) $(LIBS)
	echo $<
	$(GPP) $(LFLAGS) -o $@ $(OBJS) $< $(LIBLINK)

$(OBJDIR)/search.o: $(SRCDIR)/main.c
	mkdir -p obj
	$(GPP) $(CFLAGS) -o $(OBJDIR)/search.o -c $(SRCDIR)/main.c


##############################################################################
# add non-executables .o rules here

$(OBJDIR)/strings.o: $(RESDIR)/strings.c
	$(GPP) $(CFLAGS) $ -c $ $^ $ $ -o $ $@

$(OBJDIR)/tuple.o: $(SRCDIR)/tuple.c
	$(GPP) $(CFLAGS) $ -c $ $^ $ $ -o $ $@

$(OBJDIR)/var.o: $(SRCDIR)/var.c
	$(GPP) $(CFLAGS) $ -c $ $^ $ $ -o $ $@


$(OBJDIR)/run.o: $(SRCDIR)/run.c
	$(GPP) $(CFLAGS) $ -c $ $^ $ $ -o $ $@

###############################################################################

clean:
	@rm -f $(OBJDIR)/*.o $(OBJDIR)/*.oo $(SRCDIR)/*~ 
