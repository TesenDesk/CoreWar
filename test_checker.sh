#!/bin/bash

cd gliperal-checker || exit 1

export TERM=xterm-256color

OUTPUT=$(./checker.sh)

echo "$OUTPUT"

IFFAIL="Failed tests"

if [[ "$OUTPUT" == *"$IFFAIL"* ]];
then
  echo "Some tests failed. :("
  exit 1
  else
  echo "All Tests passed. :)"
  exit 0
fi