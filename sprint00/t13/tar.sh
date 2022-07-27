#!/bin/bash
case $1 in 
-c)
tar -cf $2 ${@:3}
;;
-e)
tar -xf $2
;;
esac
