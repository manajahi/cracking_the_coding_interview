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

CFLAGS=-std=c11 $(INLINE_WARN) $(INLINE_LIMIT) -Wall -fpic
OPTIM = -O3 -march=native -DNDEBUG 
DEBUG = -O0 -g -Wconversion
CC=gcc
AR=ar
ARFLAGS=rcs
BASEDIR=.
INCLUDE=$(BASEDIR)/include:$(BASEDIR)/include/vector_impl
OBJDIR=$(BASEDIR)/obj
LIBDIR=$(BASEDIR)/lib
SRCDIR=$(BASEDIR)/src
TESTDIR=$(BASEDIR)/test
LIBCINC= -I.
LIBLINC= -L. 
LIBLINK=

CFLAGS += $(LIBCINC) 
LFLAGS = $(CFLAGS) -Wall $(LIBLINC)

############################################################################
SOMAJVER=0
SOVER=$(SOMAJVER).0.1

#############################################################################
#add non-executables .c files to OBJS 
#if .c file reside in a dir other than the current one, add .o rule below

LIBS=$(LIBDIR)/common.o		\
	 $(LIBDIR)/vector_i8.o  \
	 $(LIBDIR)/vector_i16.o \
	 $(LIBDIR)/vector_i32.o \
	 $(LIBDIR)/vector_i64.o \
	 $(LIBDIR)/vector_u8.o  \
	 $(LIBDIR)/vector_u16.o \
	 $(LIBDIR)/vector_u32.o \
	 $(LIBDIR)/vector_u64.o

##############################################################################
#EXECUTABLES: add executables rules here

.PHONY: release dirs vector all test debug clean

release: CFLAGS +=$(OPTIM)
release: dirs
release: vector
	@echo "release: build successful"

all: CFLAGS += $(OPTIM)
all: vector
all: test
	@echo "all: build successful"

debug: CFLAGS += $(DEBUG)
debug: dirs
debug: vector
	@echo "debug: build successful"

dirs:
	mkdir -p $(LIBDIR)

test:
	make -f $(TEST)/Makefile

vector: $(LIBDIR)/libvector.so $(LIBDIR)/libvector.a

%.so: %.o $(OBJS) $(LIBS)
	echo $<
	$(CC) $(LFLAGS) -o $@ $(OBJS) $< $(LIBLINK)

%.a: %.o $(OBJS) $(LIBS)
	echo $<
	$(CC) $(LFLAGS) -o $@ $(OBJS) $< $(LIBLINK)

$(LIBDIR)/libvector.so: $(LIBS)
	$(CC) -shared -Wl,-soname,libvector.so.$(SOMAJVER) -o $@.$(SOVER) $^ 

$(LIBDIR)/libvector.a: $(LIBS)
	$(AR) $(ARFLAGS) $@ $^

##############################################################################
# add non-executables .o rules here

$(LIBDIR)/common.o: $(SRCDIR)/common.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_i8.o: $(SRCDIR)/vector_i8.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_i16.o: $(SRCDIR)/vector_i16.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_i32.o: $(SRCDIR)/vector_i32.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_i64.o: $(SRCDIR)/vector_i64.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_u8.o: $(SRCDIR)/vector_u8.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_u16.o: $(SRCDIR)/vector_u16.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_u32.o: $(SRCDIR)/vector_u32.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBDIR)/vector_u64.o: $(SRCDIR)/vector_u64.c
	$(CC) $(CFLAGS) -c $^ -o $@


###############################################################################

clean:
	@rm -f $(OBJDIR)/*.o $(OBJDIR)/*.oo \
	$(LIBDIR)/*.o $(LIBDIR)/*.so $(LIBDIR)/*.so.* $(LIBDIR)/*.a \
	$(SRCDIR)/*~ 
