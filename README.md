# progressbar-cpp [![TravisCI Build Status](https://travis-ci.org/nabijaczleweli/progressbar-cpp.svg?branch=master)](https://travis-ci.org/nabijaczleweli/progressbar-cpp) [![AppVeyorCI Build Status](https://ci.appveyor.com/api/projects/status/4nk36a7c38da5cby/branch/master?svg=true)](https://ci.appveyor.com/project/nabijaczleweli/progressbar-cpp/branch/master) [![Licence](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)
A C++ wrapper for [an easy-to-use C library for displaying text progress bars](https://github.com/doches/progressbar).

## How?

```cpp
#include <progressbar_cpp/progressbar.hpp>

progressbar_cpp::progressbar progress("Loading", 100);
for(int i = 0; i < 100; ++i) {
  // Do some stuff
  progressbar.inc();
}
// Progress bar is RAIId away. Alternatively, you can call
progress.finish();
```
