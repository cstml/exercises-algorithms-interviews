module Erathostenes (
  erathostene
  ) where

erathostene :: Int -> [Int]
erathostene 0 = [1]
erathostene x = 1 : aux x [2..]
  where
    aux 0 y      =  []
    aux x (y:ys) = y : aux (x-1) filtered
      where
        filtered     = filter (\z -> z `mod` y /= 0) ys
