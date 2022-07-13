--Exercício 1 - A
ordena2 :: Int -> Int -> (Int, Int)
ordena2 x y =
  if x > y
    then (y, x)
    else (x, y)


--Exercício 1 - B
ordena2_b :: Int -> Int -> (Int, Int)
ordena2_b x y
  | x > y = (y, x)
  | otherwise = (x, y)

--Exercício 2 - A
mes :: Int -> String
mes m
  | m == 1 = "Janeiro"
  | m == 2 = "Fevereiro"
  | m == 3 = "Marco"
  | m == 4 = "Abril"
  | m == 5 = "Maio"
  | m == 6 = "Junho"
  | m == 7 = "Julho"
  | m == 8 = "Agosto"
  | m == 9 = "Setembro"
  | m == 10 = "Outubro"
  | m == 11 = "Novembro"
  | m == 12 = "Dezembro"
  | otherwise = "Erro!"

--Exercício 2 - B
mes_b :: Int -> String
mes_b m =
  case m of
  1 -> "Janeiro"
  2 -> "Fevereiro"
  3 -> "Marco"
  4 -> "Abril"
  5 -> "Maio"
  6 -> "Junho"
  7 -> "Julho"
  8 -> "Agosto"
  9 -> "Setembro"
  10 -> "Outubro"
  11 -> "Novembro"
  12 -> "Dezembro"
  _ -> "Erro!"
-- Sim, é possível usar if then else, entretanto não é tão funcional quando se ter muitas opções. No caso de se ter várias opções, é mais recomendando usar o case.

--Exercício 3
triangulo :: Int -> Int -> Int -> String
triangulo x y z
  | x <= 0 || y <= 0 || z <= 0 || x + y < z || x + z < y || y + z < x = "Nao eh um triangulo"
  | x == y && x == z = "Eh um triangulo equilatero"
  | x == y || x == z || y == z = "Eh um triangulo isosceles"
  | otherwise = "Eh um triangulo escaleno"

--Exercício 4
maior_s :: Int -> Int -> Int
maior_s x y =
  let somaQ = x ^ 2 + y ^ 2; quadS = (x + y) ^ 2
    in if somaQ > quadS
          then somaQ
          else quadS

--Exercício 5
menu :: IO()
menu = do
  putStrLn "Nome do aluno: "
  aluno <- getLine
  putStrLn "Numero de matricula: "
  matricula <- getLine
  putStrLn "Nota: "
  nota <- getLine
  putStr "Aluno: "
  putStr aluno
  putStr ", matricula: "
  putStr matricula
  putStr ", nota: "
  putStrLn nota