show_help(){
    echo "Usage: $ ./run.sh <PROGRAM_NUMBER> <ARGUMENT>\n"
    echo "EXAMPLE:"
    echo "Run the first program with the string 012$90$0x321:"
    echo "$ ./run.sh 1 012$90$0x321\n"
    echo "Or run the second program and solve 3*4+12/6:"
    echo "$ ./run.sh 2 3*4+12/6"
}

if [ -z $1 ] || [ $1 = "--help" ] || [ $1 = "-h" ]; then 
    show_help
    exit 0
fi

make $1 -s
./app.out $2