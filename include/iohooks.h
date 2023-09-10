// Copyright (C) 2023 Thomas R. Dial. All Rights Reserved.
#ifndef INCLUDE_IOHOOKS_H_
#define INCLUDE_IOHOOKS_H_

#include <unistd.h>

extern "C" {

// The lseek function type.
typedef off_t (*PFNLSEEK)(
    int, // fd
    off_t, // offset
    int  // whence
);

}  // extern "C"

#endif // INCLUDE_IOHOOKS_H_
