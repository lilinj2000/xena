// Copyright 2017 The Xena Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -----------------------------------------------------------------------------
// File: [file_name]
// -----------------------------------------------------------------------------
//
// [file_descrition]
//
// Example:
//
//   ... ...
//
//

#include "src/options.h"

namespace xena {

using soil::json::get_item_value;

Options::Options(const rapidjson::Document &doc): fok(true) {
  get_item_value(&instru, doc, "/xena/instru");
  get_item_value(&price, doc, "/xena/price");
  get_item_value(&volume, doc, "/xena/volume");
  get_item_value(&fok, doc, "/xena/fok", false);
  get_item_value(&interval, doc, "/xena/interval");
  get_item_value(&count, doc, "/xena/count");

  get_item_value(&ts_flag, doc, "/xena/ts_flag");

  get_item_value(&data_file, doc, "/xena/data_file");
}

}; // namespace xena
