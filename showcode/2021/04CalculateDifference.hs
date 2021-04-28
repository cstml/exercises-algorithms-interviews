{-
Function that takes a list: [1,4,5,0]  and calculates the largest number - the smallest number
ex:
calculateDifference [1,4,5,0] = 5410 - 1045
                              = 4365
-}
calculateDifference :: [Int] -> Int
calculateDifference v = largest v - smallest v
  
largest  v = foldr1 f (sort v)
smallest v = foldl1 (flip f) (weird (sort v))

f = \x -> \y -> x  + y * 10

sort []     = []
sort (x:xs) = (sort smaller) ++ [x] ++ equal ++ (sort larger)
  where
    smaller = [y | y <- xs , y <  x]
    larger  = [y | y <- xs , y >  x]
    equal   = [y | y <- xs , y == x]

weird :: [Int] -> [Int]
weird x = first ++ before ++ rest
  where
    (first,rest) = firstNZ x
    firstNZ :: [Int] -> ([Int],[Int])
    firstNZ  (x:xs)
      | x /= 0    = ([x],xs)
      | otherwise = firstNZ xs
    before = take zeros $ repeat 0
    zeros = (length x) - (1 + (length rest)) 
