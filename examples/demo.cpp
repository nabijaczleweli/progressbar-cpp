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
#include "progressbar_cpp/statusbar.hpp"
#include <chrono>
#include <thread>


using namespace std::literals;


int main(void) {
	// Progress bar
	const auto max = 60;

	progressbar_cpp::progressbar smooth("Smooth", max);
	for(auto i = 0u; i < max; ++i) {
		std::this_thread::sleep_for(100ms);
		smooth.inc();
	}
	smooth.finish();

	{
		progressbar_cpp::progressbar longlabel("Three Second Task with a long label", 3);
		for(auto i = 0u; i < 3; ++i) {
			longlabel.inc();
			std::this_thread::sleep_for(1s);
		}
	}

	{
		progressbar_cpp::progressbar fast("Fast", 20);
		for(auto i = 0u; i < 20; ++i) {
			std::this_thread::sleep_for(100ms);
			fast.inc();
		}
		fast.finish();
	}

	{
		progressbar_cpp::progressbar custom("Custom", max, "<.>");
		for(auto i = 0u; i < max; ++i) {
			std::this_thread::sleep_for(100ms);
			custom.inc();
		}
		custom.finish();
	}
	smooth.finish();


	// Status bar
	progressbar_cpp::statusbar status("Indeterminate");
	for(auto i = 0u; i < 30; ++i) {
		std::this_thread::sleep_for(100ms);
		status.inc();
	}
	status.finish();

	{
		progressbar_cpp::statusbar longStatus("Status bar with a really long label");
		for(auto i = 0u; i < 10; ++i) {
			std::this_thread::sleep_for(100ms);
			longStatus.inc();
		}
	}

	{
		progressbar_cpp::statusbar customStatus("Custom", "(|)|");
		for(auto i = 0u; i < 30; ++i) {
			std::this_thread::sleep_for(100ms);
			customStatus.inc();
		}
		customStatus.finish();
	}
}
