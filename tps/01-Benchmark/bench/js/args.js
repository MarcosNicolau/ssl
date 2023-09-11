//argv[0] and argv[1] are the process execution path and the path for the js file respectively.
//So argv[2] is the first arg that you pass and so on...

// we expect two value from the console, the first for the warmup iterations and the second for the iterations
export const BENCH_ARGS = {
	WM_ITERATIONS: process.argv[2] || 10000,
	ITERATIONS: process.argv[3] || 10000,
};
