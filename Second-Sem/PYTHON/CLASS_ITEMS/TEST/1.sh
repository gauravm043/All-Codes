a=($@)
echo ${a[*]}
echo "SWAPPED"

let n=`expr $# - 1`
let temp=${a[0]}
a[0]=${a[$n]}
a[$n]=$temp

echo ${a[*]}
