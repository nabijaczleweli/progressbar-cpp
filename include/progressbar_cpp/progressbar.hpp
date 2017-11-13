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


#include "progressbar_deleter.hpp"
#include <memory>
#include <progressbar/progressbar.h>
#include <string>


namespace progressbar_cpp {
	/// progressbar -- a class for displaying progress on the command line (to stderr).
	class progressbar {
	private:
		std::string label;
		std::string format;
		std::unique_ptr<::progressbar, progressbar_deleter> inner;

	public:
		/// Create a new progressbar with the specified label and number of steps.
		///
		/// @param label The label that will prefix the progressbar.
		/// @param max The number of times the progressbar must be incremented before it is considered complete,
		///            or, in other words, the number of tasks that this progressbar is tracking.
		progressbar(const char * label, unsigned long max);
		progressbar(std::string label, unsigned long max);

		/// Create a new progressbar with the specified label, number of steps, and format string.
		///
		/// @param label The label that will prefix the progressbar.
		/// @param max The number of times the progressbar must be incremented before it is considered complete,
		///            or, in other words, the number of tasks that this progressbar is tracking.
		/// @param format The format of the progressbar. The string provided must be three characters, and it will
		///               be interpretted with the first character as the left border of the bar, the second
		///               character of the bar and the third character as the right border of the bar. For example,
		///               "<->" would result in a bar formatted like "<------     >".
		progressbar(const char * label, unsigned long max, const char * format);
		progressbar(std::string label, unsigned long max, const char * format);
		progressbar(const char * label, unsigned long max, std::string format);
		progressbar(std::string label, unsigned long max, std::string format);


		/// Increment progressbar. Don't increment past the initialized # of steps, though.
		void inc();

		/// Set the current status on the progressbar.
		void update(unsigned long value);

		/// Set the label of the progressbar. Note that no rendering is done. The label is simply set so that the next
		/// rendering will use the new label. To immediately see the new label, call draw.
		void update_label(const char * label);
		void update_label(std::string label);

		/// Finalize (and free!) progressbar. Call this if you break out partway through.
		void finish();
	};
}
