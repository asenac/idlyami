#!/bin/sh

if [ $# != 1 ]; then
	exit 1
fi

dirbase=`dirname $0`
dirtemplates=${dirbase}/../templates

filepath=`dirname $1`
filename=${filepath}/`basename $1 .pump`
filename="`echo ${filename} | sed -e 's/\.\///g'`"
define="IDLYAMI_`echo ${filename} | tr '[:lower:]' '[:upper:]' | sed -e 's/\//_/g' -e 's/\./_/g'`"

echo "{filename} = ${filename}"
echo "{define} = ${define}"

mkdir -p ${filepath}
cat ${dirtemplates}/header.hpp | sed -e 's/{filename}/'${filename}'/g'  -e 's/{define}/'${define}'/g' > $1

