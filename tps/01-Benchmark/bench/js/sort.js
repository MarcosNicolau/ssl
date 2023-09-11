import { measureExecutionTime, getArray } from "./bench.js";
import { BENCH_ARGS } from "./args.js";

measureExecutionTime(
	"array#sort",
	getArray,
	(array) => array.sort(),
	BENCH_ARGS.WM_ITERATIONS,
	BENCH_ARGS.ITERATIONS
);
