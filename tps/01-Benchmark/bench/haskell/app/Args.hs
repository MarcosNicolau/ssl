module Args where
import System.Environment (getArgs)

getCLIArgs :: IO [Int]
getCLIArgs = do
  args <- getArgs
  -- we expect two value from the console, the first for the wmIterations and the second for the iterations
  let wmIterations | null args = 10000
                   | not (null (head args)) =  read (head args) :: Int
                   | otherwise = 10000
  let iterations | null args = 10000 
                 |  not (null (last args)) =  read (last args) :: Int
                 | otherwise = 10000
  return [wmIterations, iterations]