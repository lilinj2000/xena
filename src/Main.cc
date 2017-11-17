// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include <iostream>
#include "Server.hh"
#include "soil/json.hh"
#include "soil/Log.hh"
#include "args.hxx"

int main(int argc, char* argv[]) {
  args::ArgumentParser parser("The order test program.");
  args::HelpFlag help(
      parser,
      "help",
      "Display this help menu",
      {'h', "help"});
  args::ValueFlag<std::string> config(
      parser,
      "config",
      "config file",
      {'c', "config"});

  try {
    parser.ParseCLI(argc, argv);
  } catch (args::Help) {
    std::cout << parser;
    return 0;
  } catch (args::ParseError e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  std::string config_file = "xena.json";
  if (config) {
    config_file = args::get(config);
  }

  std::unique_ptr<xena::Server> server;

  rapidjson::Document doc;
  soil::json::load_from_file(&doc, config_file);
  soil::log::init(doc);

  server.reset(new xena::Server(doc));

  return 0;
}
