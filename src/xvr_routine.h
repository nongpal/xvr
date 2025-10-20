/**
MIT License

Copyright (c) 2025 arfy slowy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef XVR_ROUTINE_H
#define XVR_ROUTINE_H

#include "xvr_ast.h"
#include "xvr_common.h"

typedef struct Xvr_Routine {
  unsigned char *param; // c-string params in sequence (could be moved below the
                        // jump table?)
  unsigned int paramCapacity;
  unsigned int paramCount;

  unsigned char *code; // the instruction set
  unsigned int codeCapacity;
  unsigned int codeCount;

  unsigned char
      *jumps; // each 'jump' is the starting address of an element within 'data'
  unsigned int jumpsCapacity;
  unsigned int jumpsCount;

  unsigned char *data; //{type,val} tuples of data
  unsigned int dataCapacity;
  unsigned int dataCount;

  unsigned char *subs; // subroutines, recursively
  unsigned int subsCapacity;
  unsigned int subsCount;

  bool panic;
} Xvr_Routine;

XVR_API void *Xvr_compileRoutine(Xvr_Ast *ast);

#endif // !XVR_ROUTINE_H
