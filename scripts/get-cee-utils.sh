#!/bin/bash
set -e
set -o pipefail

mypath=$(dirname $(readlink -f $0))
url="https://raw.githubusercontent.com/cee-studio/cee-utils/master"

wget --no-cache $url/scripts/get-cee-utils.sh -O ${mypath}/get-cee-utils.sh
chmod +x ${mypath}/get-cee-utils.sh

list="README.md
debug.h
cee-sqlite3.h
cee-sqlite3.c
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
cJSON.c
cJSON.h
log.c
logconf.c
logconf.h
log.h
ntl.c
ntl.h
cee-utils.c
cee-utils.h
utarray.h
url-encode.h
hmac.h
hmac.c
teeny-sha1.c
cee-data-sizes.h
sha.h
sha1.c
greatest.h
utf8.h
uthash.h
utlist.h
utringbuffer.h
utstack.h
utstring.h
HttpStatusCodes_C.h
"

mkdir -p $mypath/../cee-utils
pushd $mypath/../cee-utils
for i in $list; do
    echo "getting $i"
    echo "$url/$i"
    wget --no-cache $url/$i -O $i
done
popd
