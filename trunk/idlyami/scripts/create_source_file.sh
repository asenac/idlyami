#!/bin/sh

if [ $# != 1 ]; then
	exit 1
fi

dirbase=`dirname $0`
dirtemplates=${dirbase}/../templates

filename=`basename $1`

echo "{filename} = ${filename}"

mkdir -p `dirname $1`
cat ${dirtemplates}/header | sed -e 's/{filename}/'${filename}'/g' > $1

