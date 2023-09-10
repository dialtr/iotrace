# iotrace

## About

This is a quick hack that I threw together to demonstrate how to use
LD_PRELOAD to hook library functions.  I am trying to reverse engineer
and open source program that does some strange things with file I/O, and
so I thought it might be fun to learn how to implement LD_PRELOAD hooks
in the process. 

## Walkthrough

First, in the file **iohooks.cc**, I have two functions, **iotrace_library_startup**
and **io_trace_library_shutdown**, which run when this library is loaded and
unloaded, respectively.

The shutdown function is left with no implementation but is there simply
to show the way to do this if your library needs to deallocate memory or
other resources.

The startup functions obtains the address to the *real* **lseek** function
and stores it in a static variable so that our version can forward to it.

The implementation of **lseek** is simple: it just logs the parameters and
the return value, but otherwise forwards the call to the real seek
function.  

## Using

To use this while running **some_program**, just set the LD_PRELOAD accordingly:

```bash
# Assumes libiostrace.so is in the current directory.
LD_PRELOAD="./libiotrace.so" some_program
```

Assuming **some_program** does some kind of lseek operation, you should
see extra logging to standard error indicating what seeks were done.
