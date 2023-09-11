module Main where
import Data.List(find)
import Bench (bench, list) 
import Args (getCLIArgs)

findEl :: Int -> Maybe Int
findEl el = find (==el) list

main :: IO ()
main = do
  [wmIterations, iterations] <- getCLIArgs
  bench "list#find" findEl 569 wmIterations iterations
 
