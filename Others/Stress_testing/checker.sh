for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in.txt
    diff -w <(./a < in.txt) <(./b < in.txt) || break
done

// Note :
gen is the file name of test generator
in.txt where the test case written on file
a is actual sollution
b is brute force sollution

