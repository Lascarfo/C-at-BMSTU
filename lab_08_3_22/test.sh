clear
function pause(){
   read -p "$*"
}
echo '\n'
echo tests for flag a
echo '\n'
for i in 1 2 3 4 5;
do
./app.exe a ./func_tests_addition/in_${i}_0.txt ./func_tests_addition/in_${i}_1.txt out.txt
echo "check file out.txt and out_$i.txt"
echo ''
cmp -s out.txt ./func_tests_addition/out_$i.txt
echo "Test #$i complete with status $?"
echo
diff out.txt ./func_tests_addition/out_$i.txt
echo
pause
rm -f out.txt
done
echo '\n'
echo tests for flag m
echo '\n'
for i in 1 2 3;
do
./app.exe m ./func_tests_multiplication/in_${i}_0.txt ./func_tests_multiplication/in_${i}_1.txt out.txt
echo "check file out.txt and out_$i.txt"
echo ''
cmp -s out.txt ./func_tests_multiplication/out_$i.txt
echo "Test #$i complete with status $?"
echo
diff out.txt ./func_tests_multiplication/out_$i.txt
echo
pause
rm -f out.txt
done

