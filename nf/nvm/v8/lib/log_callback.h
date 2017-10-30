// Copyright (C) 2017 go-nebulas authors
//
// This file is part of the go-nebulas library.
//
// the go-nebulas library is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// the go-nebulas library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with the go-nebulas library.  If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef _NEBULAS_NF_NVM_V8_LIB_LOG_CALLBACK_H_
#define _NEBULAS_NF_NVM_V8_LIB_LOG_CALLBACK_H_

#include <v8.h>

using namespace v8;

typedef void (*LogFunc)(int level, const char *msg);

enum LogLevel {
  DEBUG = 1,
  WARN = 2,
  INFO = 3,
  ERROR = 4,
};

const char *getLogLevelText(int level);
void setLogFunc(LogFunc f);

void logCallback(const FunctionCallbackInfo<Value> &info);

#endif // _NEBULAS_NF_NVM_V8_LIB_LOG_CALLBACK_H_
