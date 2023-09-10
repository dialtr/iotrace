// Copyright (C) 2023 Thomas R. Dial. All Rights Reserved.

#include "iohooks.h"
#include <dlfcn.h>
#include <iostream>

using ::std::cerr;
using ::std::endl;

extern "C" {

static PFNLSEEK g_libc_lseek = nullptr;

void __attribute__((constructor))
iotrace_library_startup() {
  g_libc_lseek = reinterpret_cast<PFNLSEEK>(dlsym(RTLD_NEXT, "lseek"));
}

void __attribute__((destructor))
iotrace_library_shutdown() {
}

// Replacement lseek.
off_t lseek(int fd, off_t offset, int whence) {
  cerr << "fd: " << fd << ", offset: " << offset << ", whence: " << whence;
  const int status = (*g_libc_lseek)(fd, offset, whence);
  cerr << " | returned: " << status << endl;
  return status;
}

}  // extern "C"
