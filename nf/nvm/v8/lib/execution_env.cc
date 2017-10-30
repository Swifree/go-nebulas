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

#include "execution_env.h"

int SetupExecutionEnv(Isolate *isolate, Local<Context> &context) {
  char data[] = "const console = require('console.js');"
                "const Storage = require('storage.js');"
                "const LCS = Storage.LocalContractStorage;"
                "const GCS = Storage.GlobalContractStorage;";

  Local<String> source =
      String::NewFromUtf8(isolate, data, NewStringType::kNormal)
          .ToLocalChecked();

  // Compile the source code.
  MaybeLocal<Script> script = Script::Compile(context, source);

  if (script.IsEmpty()) {
    fprintf(stderr, "execution-env.js: compile error.\n");
    return 1;
  }

  // Run the script to get the result.
  MaybeLocal<Value> ret = script.ToLocalChecked()->Run(context);
  return 0;
}
