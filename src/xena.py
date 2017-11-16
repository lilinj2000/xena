#!/usr/bin/env python

import json


sink1 = {
    "sink": {
        "type": "stdout_sink_mt",
        "level": "trace"
        }
    }

sink2 = {
    "sink": {
        "type": "rotating_file_sink_mt",
        "level": "info",
        "file_name": "xena.log",
        "max_file_size": 5000000,
        "max_files": 10
        }
    }

log = {
    "level": "trace",
    "sinks": [sink1, sink2]
    }

xena = {
    "instru": "IF1712",
    "price": 3790,
    "volume": 1,
    "interval": 2000,
    "count": 1,
    "ts_flag": 1,
    "data_file": "xena_data.txt"
    }

# fema json
foal_trader = { 
    "flow_path": "./",

    "front_address": "tcp://180.169.101.189:7001",
    "broker_id": "0158",
    "user_id": "04452",
    "password": "111111",
    "investor_id": "04452"
    }

config = {
    "foal_trader": foal_trader,
    "log": log,
    "xena": xena
    } 

with open('fema.json', 'w') as f:
    json.dump(config, f, sort_keys=True, indent=4)

# rem json
sea_trader = { 
    "svr_address": "172.31.0.26",
    "svr_port": 20000,
    "qry_address": "172.31.0.27",
    "qry_port": 20001,
    "user_id": "88991042d",
    "password": "1",
    "prod_info": "tester",
    "mac_addr": "00:0F:53:35:BA:10",
    "account_id": "88991042",
    # 100-sh     101-sz
    # 102-cffex  103-shfe
    # 104-dce    105-zcze
    "exchange_id": 103
    }

config = {
    "sea_trader": sea_trader,
    "log": log,
    "xena": xena
    } 

with open('rem.json', 'w') as f:
    json.dump(config, f, sort_keys=True, indent=4)

# xele json
xtra = { 
    "exchange_id": 1,
    "participant_id": "0148",
    "user_id": "88991042d",
    "password": "1",
    "client_id": "88991042d",
    "account_id": "88991042",
    "front_address": "tcp://127.0.0.1:122"
    }

config = {
    "xtra": xtra,
    "log": log,
    "xena": xena
    } 

with open('xele.json', 'w') as f:
    json.dump(config, f, sort_keys=True, indent=4)
