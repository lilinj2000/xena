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

#include <iostream>
#include <memory>
#include "args.hxx"
#include "soil/json.h"
#include "soil/log.h"
#include "src/server.h"

int main(int argc, char *argv[]) {
  args::ArgumentParser parser("The order test program.");
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
  args::ValueFlag<std::string> config(parser, "config", "config file",
                                      {'c', "config"});

  try {
    parser.ParseCLI(argc, argv);
  } catch (args::Help &h) {
    std::cout << parser;
    return 0;
  } catch (args::ParseError &e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  std::string config_file = "xena.json";
  if (config) {
    config_file = args::get(config);
  }

  std::unique_ptr<xena::Server> server;

  try {
    rapidjson::Document doc;
    soil::json::load_from_file(&doc, config_file);
    soil::log::init(doc);

    server.reset(new xena::Server(doc));
  } catch (std::exception& e) {
    SOIL_ERROR("exception: {}", e.what());
    return 1;
  } catch (...) {
    SOIL_ERROR("caught unknow exception!!!");
    return 1;
  }

  return 0;
}
