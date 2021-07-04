#!/bin/bash

SOURCE=
EXPECTED=
OUTPUTFORMAT=

while test $# -gt 0; do
  case "$1" in
    --markdown)
      OUTPUTFORMAT=$1
      shift
      ;;
    --source*)
      export SOURCE=`echo $1 | sed -e 's/^[^=]*=//g'`
      shift
      ;;
    --expected*)
      export EXPECTED=`echo $1 | sed -e 's/^[^=]*=//g'`
      shift
      ;;

  esac
done

./experiencetable $OUTPUTFORMAT $SOURCE | ./test/compareoutput $EXPECTED
