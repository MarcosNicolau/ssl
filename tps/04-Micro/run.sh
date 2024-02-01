make
echo "================ Compiling first program which is correct ================"
./micro.out programs/correct.m
echo "" 

echo "================ Compiling second program which is lexically incorrect ================"
./micro.out programs/err_1.m
echo ""

echo "================ Compiling third program which is syntactically and semantically incorrect ================"
./micro.out programs/err_2.m