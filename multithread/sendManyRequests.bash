#!/bin/bash

for N in {1..500}
do
  ruby client.rb $((($N % 50) + 1)).txt &
done
wait