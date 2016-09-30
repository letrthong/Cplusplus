g++ example1.cpp  -o  example1

echo "Check memory"
echo  ""
valgrind --tool=memcheck ./example1

echo  ""
echo "Detect memory leak"
valgrind --tool=memcheck --leak-check=yes ./example1

echo  ""
echo "Report"
valgrind --tool=memcheck --leak-check=yes --xml=yes --xml-file=test.xml ./example1
