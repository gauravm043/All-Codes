let t=`date | cut -d ":" -f1 | cut -d " " -f5`
if [ $t -lt 12 ]
then 
     echo "GOOD MORNING $USER"
else
     echo "GOOD AFTERNOON $USER"
fi
echo "PRESS 1 TO SEE ALL DIRECTORIES IN A FOLDER " 
read ans
echo "ENTER PATH NAME"
read path


if [ $ans == 1 ]
then
     cd ~
     cd $path
     for files in `ls`
     do
	  if [ -d $files ]
	  then
	       echo $files " IS  A DIRECTORY"
	  fi
     done
fi
