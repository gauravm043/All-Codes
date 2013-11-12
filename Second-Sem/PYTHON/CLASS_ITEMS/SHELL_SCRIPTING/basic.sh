#!/bin/bash
echo " HELLO MR. $USER HOW ARE U .TODAY'S DATE IS  `date` "

# SWAPPING THE COMMAND LINE ARFUMENTS
echo $@
export a=($@)
export n=`expr $# - 1`

export temp=${a[0]}
a[0]=${a[$n]}
a[$n]=$temp
echo ${a[*]}
