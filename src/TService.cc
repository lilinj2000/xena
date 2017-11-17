// Copyright (c) 2010
// All rights reserved.

#include <stdexcept>

#include "FoalTService.hh"
#include "SeaTService.hh"
#include "XtraTService.hh"
#include "soil/Log.hh"

namespace xena {

TService* TService::create(
          const rapidjson::Document& doc,
          TServiceCallback* callback) {
  SOIL_FUNC_TRACE;

  if (doc.HasMember("foal_trader")) {
    return new FoalTService(doc, callback);
  } else if(doc.HasMember("sea_trader")) {
    return new SeaTService(doc, callback);
  } else if(doc.HasMember("xtra")) {
    return new XtraTService(doc, callback);
  } else {
    throw std::runtime_error("no supported TService!!!");
  }
}

};  // namespace xena
