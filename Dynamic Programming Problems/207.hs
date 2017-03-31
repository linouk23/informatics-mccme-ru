-- take 10 (iterate (\x -> (x+3)*2) 1)
-- [1,8,22,50,106,218,442,890,1786,3578]

-- map fst [(1, 2), (3, 4), (5, 6)]
-- [1,3,5]

fibs :: [Integer]
fibs = map fst $ iterate (\(x, y) -> (y, x + y)) (1, 1)

-- If fibs is the infinite list of Fibonacci numbers, one can define
fastfib n = fibs !! n

main = do
  num <- readLn :: IO Int
  print (fastfib (num + 1))