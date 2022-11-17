echo "ENTER YOUR NAME:"
read name
echo "ENTER YOUR REGISTRATION NUMBER:"
read rno 
echo "ENTER MARK-1:"
read m1
echo "ENTER MARK-2:"
read m2
echo "ENTER MARK-3:"
read m3
echo "ENTER MARK-4:"
read m4
echo "ENTER MARK-5:"
read m5
sum=$(($m1+$m2+$m3+$m4+$m5))
avg=$(($sum/5))
echo "----------------------"
echo "NAME:"$name
echo "REGISTRATION NUMBER:"$rno
echo "YOUR TOTAL:"$sum
echo "AVERAGE:"$avg
echo "----------------------"
if [ $m1 -lt 35 -o $m2 -lt 35 -o $m3 -lt 35 -o $m4 -lt 35 -o $m5 -lt 35 ]
then
    echo "YOU HAVE FAILED TO CLEAR ONE OR MORE SUBJECT"
elif [ $sum -lt 250 ]
then
    echo "YOUR GRADE IS:B"
elif [ $sum -ge 250 -a $sum -lt 300 ]
then
    echo "YOUR GRADE IS:A"
else
    echo "YOUR GRADE IS:S"
fi