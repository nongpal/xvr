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
**/

#ifndef XVR_LEXER_H
#define XVR_LEXER_H

#include "xvr_common.h"
#include "xvr_token_types.h"

typedef struct {
  int start;
  int current;
  int line;
  const char *source;
} Xvr_lexer;

typedef struct {
  Xvr_TokenType type;
  int lenght;
  int line;
  const char *lexeme;
} Xvr_Token;

XVR_API void Xvr_bindLexer(Xvr_lexer *lexer, const char *source);
XVR_API Xvr_Token Xvr_private_scanLexer(Xvr_lexer *lexer);
XVR_API void Xvr_private_printToken(Xvr_Token *token);

#endif // !XVR_LEXER_H
