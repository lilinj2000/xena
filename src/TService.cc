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

#include <stdexcept>

#include "src/tservice.h"

#include "soil/log.h"
#include "src/cata_tservice.h"
#include "src/foal_tservice.h"
#include "src/sea_tservice.h"
#include "src/ufo_tservice.h"
#include "src/xmas_tservice.h"
#include "src/xtra_tservice.h"
#include "src/esau_tservice.h"
#include "src/yet_tservice.h"

namespace xena {

TService *TService::create(const rapidjson::Document &doc,
                           TServiceCallback *callback) {
  SOIL_FUNC_TRACE;

  if (doc.HasMember("foal_trader")) {
    return new FoalTService(doc, callback);
  } else if (doc.HasMember("sea_trader")) {
    return new SeaTService(doc, callback);
  } else if (doc.HasMember("xmas_trader")) {
    return new XmasTService(doc, callback);
  } else if (doc.HasMember("ufo")) {
    return new UfoTService(doc, callback);
  } else if (doc.HasMember("yet")) {
    return new YetTService(doc, callback);
  } else if (doc.HasMember("cata_trader")) {
    return new CataTService(doc, callback);
  } else if (doc.HasMember("esau")) {
    return new EsauTService(doc, callback);
  } else {
    throw std::runtime_error("no supported TService!!!");
  }
}

}; // namespace xena
