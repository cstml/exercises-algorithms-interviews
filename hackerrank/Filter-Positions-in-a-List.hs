f :: [Int] -> [Int]
f = \ list -> map fst . filter (not. odd . snd) $ zip list [1..] 
            
main = do
	inputdata <- getContents
	mapM_ (putStrLn. show). f. map read. lines $ inputdata
