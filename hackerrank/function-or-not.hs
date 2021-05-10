main :: IO ()
main = do 
    t <- (readLn :: IO Int )
    loop t

loop :: Int -> IO ()
loop 0 = return ()
loop t = do
    n <- (readLn :: IO Int)
    auxLoop n []
    loop (t-1)
    
auxLoop :: Int -> [[Int]] -> IO ()
auxLoop 0 s 
  | coherent s = putStrLn "YES"
  | otherwise  = putStrLn "NO"
  
auxLoop n s = do
    p <-  readInts 
    auxLoop (n-1) (p : s)
  where
    readInts :: IO [Int]
    readInts = fmap (map read.words) getLine

coherent :: [[Int]] -> Bool
coherent s = testCoherent s s
  where
    testCoherent []     _ = True
    testCoherent (x:xs) [] = testCoherent xs xs 
    testCoherent xx@(x:xs) (l:ls) 
      | (head x) /= (head l)                                       = testCoherent xx ls
      | (head x) == (head l) && (head (tail x)) == (head (tail l)) = testCoherent xx ls
      | otherwise                                                  = False
                                 
