#!/bin/bash

git pull origin
cd ruby
rm -f msgpack*.gem
sh makegem.sh
sudo gem install msgpack*.gem
