flag=0


echo "ENTER A FILE NAME:  " 

read f

for file in `ls`
do
     if [ $f == $file ]
     then
	  echo "FILE FOUND"
	  let flag=1
	  break
     else
	  continue
     fi
done

if [ $flag != 1 ]
then
     echo " FILE NOT FOUND "
fi

if [ $flag == 1 ]
then
echo "PRESS 1 TO SEE THE CONTENTS OF THE FILE FOR EDIT PRESS 2"
read ans
if [ $ans == 1 ]
then
     cat $file
elif [ $ans == 2 ]
then
     vim $file
fi
fi
