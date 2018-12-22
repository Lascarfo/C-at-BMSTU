clear
function pause(){
   read -p "$*"
}
for i in 1 2 3;
do
./app.exe ./tests/in_$i.txt s > out.txt
echo "check file out.txt and out_$i.txt"
echo ''
cmp -s out.txt ./tests/out_$i.txt
echo "Test #$i complete with status $?"
echo
diff out.txt ./tests/out_$i.txt
echo
pause
rm -f out.txt
done

for i in 4 5;
do
./app.exe ./tests/in_$i.txt e > out.txt
echo "check file out.txt and out_$i.txt"
echo ''
cmp -s out.txt ./tests/out_$i.txt
echo "Test #$i complete with status $?"
echo
diff out.txt ./tests/out_$i.txt
echo
pause
rm -f out.txt
done


