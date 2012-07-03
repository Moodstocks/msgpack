#!/bin/bash

git pull origin
pushd cpp
  ./bootstrap || exit 1
  ./configure || exit 1
  make || exit 1
  sudo make install || exit 1
popd
pushd ruby
  rm -f msgpack*.gem
  sh makegem.sh || exit 1
  rvmsudo gem install msgpack*.gem || exit 1
popd
