// The MIT License (MIT)

// Copyright (c) 2017 nabijaczleweli

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.


#include "progressbar_cpp/progressbar.hpp"
#include <utility>


progressbar_cpp::progressbar::progressbar(const char * l, unsigned long max) : label(l), inner(progressbar_new(label.c_str(), max)) {}

progressbar_cpp::progressbar::progressbar(std::string l, unsigned long max) : label(std::move(l)), inner(progressbar_new(label.c_str(), max)) {}

progressbar_cpp::progressbar::progressbar(const char * l, unsigned long max, const char * f)
      : label(l), format(f), inner(progressbar_new_with_format(label.c_str(), max, format.c_str())) {}

progressbar_cpp::progressbar::progressbar(std::string l, unsigned long max, const char * f)
      : label(std::move(l)), format(f), inner(progressbar_new_with_format(label.c_str(), max, format.c_str())) {}

progressbar_cpp::progressbar::progressbar(const char * l, unsigned long max, std::string f)
      : label(l), format(std::move(f)), inner(progressbar_new_with_format(label.c_str(), max, format.c_str())) {}

progressbar_cpp::progressbar::progressbar(std::string l, unsigned long max, std::string f)
      : label(std::move(l)), format(std::move(f)), inner(progressbar_new_with_format(label.c_str(), max, format.c_str())) {}

void progressbar_cpp::progressbar::inc() {
	if(inner)
		progressbar_inc(inner.get());
}

void progressbar_cpp::progressbar::update(unsigned long value) {
	if(inner)
		progressbar_update(inner.get(), value);
}

void progressbar_cpp::progressbar::update_label(const char * l) {
	if(inner) {
		label = l;
		progressbar_update_label(inner.get(), label.c_str());
	}
}

void progressbar_cpp::progressbar::update_label(std::string l) {
	if(inner) {
		label = std::move(l);
		progressbar_update_label(inner.get(), label.c_str());
	}
}

void progressbar_cpp::progressbar::finish() {
	inner.reset();
}
