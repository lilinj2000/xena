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


#include "src/server.h"
#include "soil/log.h"

namespace xena {

Server::Server(
    const rapidjson::Document& doc) {
  SOIL_FUNC_TRACE;

  options_.reset(new Options(doc));

  if (!options_->data_file.empty()) {
    data_file_.reset(
        new TimeStampDataFile(
            options_->data_file));
  }

  cond_.reset(soil::STimer::create());

  tservice_.reset(
      TService::create(doc,
                       this));

  run();
}

Server::~Server() {
  SOIL_FUNC_TRACE;
}

void Server::t1Update(int32_t local_id) {
  SOIL_FUNC_TRACE;

  updateT(local_id);
}

void Server::t2Update(int32_t local_id) {
  SOIL_FUNC_TRACE;

  updateT(local_id, false);
}

void Server::run() {
  SOIL_FUNC_TRACE;

  int count = 0;

  do {
    wait(options_->interval);

    int32_t local_id = tservice_->orderInsert(
        options_->instru,
        options_->price,
        options_->volume);

    records_[local_id]
        = std::shared_ptr<TimeStampData>(
            new TimeStampData(local_id));

    ++count;

    if (options_->count > 0
        && count >= options_->count) {
      break;
    }
  }while(true);

  // the last package just wait 2 seconds
  wait(2000);
}

void Server::updateT(
    int32_t local_id,
    bool is_t1) {
  auto it = records_.find(local_id);
  if (it != records_.end()) {
    if (is_t1) {
      it->second->updateT1();
    } else {
      it->second->updateT2();
    }

    if ((is_t1 && options_->ts_flag == Options::ONLY_T1)
        || (!is_t1 && options_->ts_flag == Options::ONLY_T2)
        || it->second->allUpdated()) {
      data_file_->putData(it->second);
      records_.erase(it);
    }
  }
}

}  // namespace xena
