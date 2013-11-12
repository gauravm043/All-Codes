#! /bin/bash -x  
#! /bin/python 


# $@ PRINTS ALL THE COMMAND LINE ARGUMENTS AND $# PRINTS THEIR NUMBER







for parm		# ALSO DISPLAYS ALL COMMAND LINE ARGUEMENTS
do
     echo $parm
done


cd ~/classwork/				# ALLCOMMANDS ARE WORKING PROPERLY

ls

echo $USER
echo $PWD
echo $OSTYPE

echo HELLO MR. $USER TODAY IS `date | cut -d ' ' -f2,3`
echo HOW ARE YOU DOING THIS


if [ `date | cut -d ' ' -f4 | cut -d ':' -f1` -ge 12 ]	# ITS VERY IMPORTANT SINCE THE SIGNS <= ETC WON'T WORK HERE     
then
     echo AFTERNOON 
else
     echo MORNING
fi

let sum=`expr 38 + 19`
echo $sum
let pro=`expr 38 \* 19`
echo $pro
let div=`expr 38 / 19`
echo $div
let sub=`expr 38 - 19`
echo $sub

let pro=1
for i in $@
do
     let pro=`expr $pro \* $i`
done

echo $pro


#  PROGRAM TO WRITE SUM OF FIRST N NATURAL NUMBERS

echo ENTER VALUE OF N:
read n

let sum=0

while [ $n -ge 0 ]
do
     let sum=`expr $sum + $n `
     let n=`expr $n - 1`
done

echo THE SUM OF FIRST N NATURAL NUMBERS IS : $sum
