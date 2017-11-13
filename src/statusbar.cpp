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


#include "progressbar_cpp/statusbar.hpp"
#include <utility>


progressbar_cpp::statusbar::statusbar(const char * l) : label(l), inner(statusbar_new(label.c_str())) {}

progressbar_cpp::statusbar::statusbar(std::string l) : label(std::move(l)), inner(statusbar_new(label.c_str())) {}

progressbar_cpp::statusbar::statusbar(const char * l, const char * f) : label(l), format(f), inner(statusbar_new_with_format(label.c_str(), format.c_str())) {}

progressbar_cpp::statusbar::statusbar(std::string l, const char * f)
      : label(std::move(l)), format(f), inner(statusbar_new_with_format(label.c_str(), format.c_str())) {}

progressbar_cpp::statusbar::statusbar(const char * l, std::string f)
      : label(l), format(std::move(f)), inner(statusbar_new_with_format(label.c_str(), format.c_str())) {}

progressbar_cpp::statusbar::statusbar(std::string l, std::string f)
      : label(std::move(l)), format(std::move(f)), inner(statusbar_new_with_format(label.c_str(), format.c_str())) {}

void progressbar_cpp::statusbar::inc() {
	if(inner)
		statusbar_inc(inner.get());
}

void progressbar_cpp::statusbar::draw() {
	if(inner)
		statusbar_draw(inner.get());
}

void progressbar_cpp::statusbar::finish() {
	inner.reset();
}
