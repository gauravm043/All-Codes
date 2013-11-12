let sum=0
echo $HOME
echo $TERM
for i in $@
do
     let sum=$sum+$i
done
echo $sum
