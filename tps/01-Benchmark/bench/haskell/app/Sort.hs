module Main where
import Data.List(sort)
import Bench (bench, list) 
import Args (getCLIArgs)


main :: IO ()
main = do 
  [wmIterations, iterations] <- getCLIArgs
  bench "list#sort" sort list  wmIterations iterations
 