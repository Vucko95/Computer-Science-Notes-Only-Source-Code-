#!/bin/bash

echo "We need root permissions to install libdnet"
sudo echo "OK"
curl -O "https://bootstrap.pypa.io/get-pip.py"
python get-pip.py --user
PIP_BIN=$HOME/Library/Python/2.7/bin/pip
$PIP_BIN install scapy --user
$PIP_BIN install pypcap --user
curl -L https://github.com/dugsong/libdnet/archive/libdnet-1.12.zip -o libdnet-1.12.zip
unzip libdnet-1.12.zip
cd libdnet-libdnet-1.12
./configure
make
sudo make install
cd python
python setup.py install --user