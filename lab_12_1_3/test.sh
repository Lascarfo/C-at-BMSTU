clear
function pause(){
   read -p "$*"
}
for i in 1 2 3 4 5;
do
./app.exe ./tests/in_$i.txt out.txt f
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

