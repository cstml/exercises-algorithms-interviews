fn :: Int -> [Int]
fn n = case n of
            0 -> []
            n -> n : (fn(n-1))

main = do
n <- readLn :: IO Int
print (fn(n))
