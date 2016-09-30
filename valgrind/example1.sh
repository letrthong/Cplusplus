g++ example1.cpp  -o  example1

echo "Detect memory leak"
echo  ""
valgrind --tool=memcheck ./example1