show_help(){
    echo "Usage: run_benchmarks <WARMUP_ITERATIONS> <ITERATIONS>\n"
    echo "EXAMPLE:"
    echo "Run a benchmarks with 10000 warmup iterations and 10000 iterations:"
    echo "$ run_benchmarks 10000 10000"

    echo "\nIf <WARMUP_ITERATIONS> or <ITERATIONS> are not provided then both default to 10000"
}


if [ ! -z $1 ] && ([ $1 = "--help" ] || [ $1 = "-h" ]); then 
    show_help
    exit 0
fi

WM_ITERATIONS=$1
ITERATIONS=$2

if [ -z $WM_ITERATIONS ]; then WM_ITERATIONS=10000
fi

if [ -z $ITERATIONS ]; then ITERATIONS=10000
fi

run_benchmarks() {
    BENCHMARK_TYPE=$1
    _WM_ITERATIONS=$2
    _ITERATIONS=$3
    cd haskell
    echo "Building... \n" 
    cabal build  --ghc-options=-W sort  
    cabal build  --ghc-options=-W find 
    echo ""
    echo "====================== $BENCHMARK_TYPE BENCHMARKS ======================" 
    echo "Haskell:" 
    cabal run sort $_WM_ITERATIONS $_ITERATIONS
    cabal run find $_WM_ITERATIONS $_ITERATIONS
    echo ""
    echo "Javascript:"
    cd ../js 
    npm run sort $_WM_ITERATIONS $_ITERATIONS
    npm run find $_WM_ITERATIONS $_ITERATIONS
    cd ..
}

DIR=$(dirname "$0")
cd $DIR/bench
run_benchmarks "SINGLE SNAPSHOT" 0 1 
run_benchmarks  "AVERAGE TIME" $WM_ITERATIONS $ITERATIONS


