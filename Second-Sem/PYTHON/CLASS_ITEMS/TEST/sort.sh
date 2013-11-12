#! /bin/bash 

a=($@)
let size=$#

let i=0

while [ $i != $size ]
do
     let j=`expr $i + 1`
     while [ $j != $size ]
     do
	  if [ ${a[$i]} -gt ${a[$j]} ]
	  then
	       let temp=${a[$j]}
	       a[$j]=${a[$i]}
	       a[$i]=$temp
	  fi
	  let j=`expr $j + 1`
     done
     let i=`expr $i + 1`
done

echo "The Sorted Array Is:"
echo ${a[*]}
