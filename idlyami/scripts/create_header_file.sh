#!/bin/sh

if [ $# != 1 ]; then
	exit 1
fi

dirbase=`dirname $0`
dirtemplates=${dirbase}/../templates

filename=$1
define="IDLYAMI_`echo ${filename} | tr '[:lower:]' '[:upper:]' | sed -e 's/\./_/g' -e 's/\//_/g'`"
filename=`basename ${filename}`

echo "{filename} = ${filename}"
echo "{define} = ${define}"

mkdir -p `dirname $1`
cat ${dirtemplates}/header.hpp | sed -e 's/{filename}/'${filename}'/g'  -e 's/{define}/'${define}'/g' > $1

