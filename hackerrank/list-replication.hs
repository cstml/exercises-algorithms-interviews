f :: Int -> [Int] -> [Int]
f n [] = []
f n  l = take n (repeat (head l)) ++ (f n (tail l))

-- This part handles the Input and Output and can be used as it is. Do not modify this part.
main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words
