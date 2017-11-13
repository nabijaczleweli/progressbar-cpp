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


#pragma once


#include "statusbar_deleter.hpp"
#include <memory>
#include <progressbar/statusbar.h>
#include <string>


namespace progressbar_cpp {
	/// statusbar -- a class for displaying indefinite progress on the command line (to stderr).
	class statusbar {
	private:
		std::string label;
		std::string format;
		std::unique_ptr<::statusbar, statusbar_deleter> inner;

	public:
		/// Create a new statusbar with the specified label
		statusbar(const char * label);
		statusbar(std::string label);

		/// Create a new statusbar with the specified label and format string
		statusbar(const char * label, const char * format);
		statusbar(std::string label, const char * format);
		statusbar(const char * label, std::string format);
		statusbar(std::string label, std::string format);


		/// Increment statusbar. Don't increment past the initialized # of steps, though.
		void inc();

		/// Draw statusbar to the screen. Don't call this directly,
		/// as it's called internally by *inc*.
		void draw();

		/// Finalize (and free!) statusbar. Call this if you break out partway through.
		void finish();
	};
}
