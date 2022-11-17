
echo "ENTER A NUMBER:"
read n
if [ $n -lt 0 ]
then
    echo $n "is negative"
elif [ $n == 0 ]
then    
    echo $n "is neither postiver nor negative"
else
    echo $n "is positive"
fi

