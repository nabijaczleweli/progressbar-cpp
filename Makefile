# The MIT License (MIT)

# Copyright (c) 2017 nabijaczleweli

# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
# the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


include configMakefile


LDAR := $(PIC)
VERAR := $(foreach l,PROGRESSBAR_CPP PROGRESSBAR,-D$(l)_VERSION='$($(l)_VERSION)')
INCAR := -Iinclude -isystemext/progressbar/include
SOURCES := $(sort $(wildcard src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp))
PROGRESSBAR_SOURCES := $(sort $(wildcard ext/progressbar/lib/*.c ext/progressbar/lib/**/*.c ext/progressbar/lib/**/**/*.c ext/progressbar/lib/**/**/**/*.c))

.PHONY : all clean static

all : static

clean :
	rm -rf $(OUTDIR)

static : $(OUTDIR)libprogressbar-cpp$(ARCH)


$(OUTDIR)libprogressbar-cpp$(ARCH) : $(subst $(SRCDIR),$(OBJDIR),$(subst .cpp,$(OBJ),$(SOURCES))) $(subst ext/progressbar/lib,$(BLDDIR)progressbar,$(subst .c,$(OBJ),$(PROGRESSBAR_SOURCES)))
	$(AR) crs $@ $^


$(OBJDIR)%$(OBJ) : $(SRCDIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXAR) $(INCAR) $(VERAR) -c -o$@ $^

$(BLDDIR)progressbar/%$(OBJ) : ext/progressbar/lib/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCAR) -Iext/progressbar/include/progressbar -c -o$@ $^
