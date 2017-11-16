// Copyright (c) 2010
// All rights reserved.

#include "Options.hh"

namespace xena {

using soil::json::get_item_value;

Options::Options(
      const rapidjson::Document& doc) {
  get_item_value(&instru, doc, "/xena/instru");
  get_item_value(&price, doc, "/xena/price");
  get_item_value(&volume, doc, "/xena/volume");
  get_item_value(&interval, doc, "/xena/interval");
  get_item_value(&count, doc, "/xena/count");

  get_item_value(&ts_flag, doc, "/xena/ts_flag");

  get_item_value(&data_file, doc, "/xena/data_file");
}

};  // namespace xena
