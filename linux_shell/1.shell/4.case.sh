#!/bin/bash
read a
case $a in
    1)
        echo 1
        ;;
    2)
        echo 2
        ;;
    *)
        echo "Not Found"
        ;;
esac
