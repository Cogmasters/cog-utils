#!/bin/bash
mypath=$(dirname $(readlink -f $0))
url="https://raw.githubusercontent.com/cee-studio/core-utils/master"

list="debug.h
jsmn.h
json-actor-boxed.c
json-actor-boxed.h
json-actor.c
json-actor.h
json-parser.c
json-printf.c
json-scanf.c
json-scanf.h
json-string.c
json-struct.c
log.c
logconf.c
logconf.h
log.h
ntl.c
ntl.h
orka-utils.c
orka-utils.h
utarray.h
uthash.h
utlist.h
utringbuffer.h
utstack.h
utstring.h"

mkdir -p $mypath/core-utils
pushd $mypath/core-utils
for i in $list; do
    echo "getting $i"
    echo "$url/$i"
    wget $url/$i -O $i
done
popd
