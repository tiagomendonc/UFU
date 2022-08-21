-- Tiago Oliveira Mendonça - 12121BSI238

-- Exercício 1
imprimeNvezes :: Int -> IO()
imprimeNvezes n = do
                  putStrLn "Frase"
                  if n > 1 then imprimeNvezes (n - 1)
                  else putStrLn "Encerrado"

-- Exercício 2
eLogico :: Bool -> Bool -> Bool
eLogico a b |a == True && b == True = True
            |otherwise = False

-- Exercício 3
eLogico_ :: Bool -> Bool -> Bool
eLogico_ a b |a == True = b
             |b == False = False

-- Exercício 4
comb :: Int -> Int -> Int
comb n k |k == 1 = n
         |k == n = 1
         |1 < k && k < n = comb (n - 1) (k - 1) + comb (n - 1) k