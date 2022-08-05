-- Tiago Oliveira Mendonça
-- 12121BSI238

import Data.Char
import Data.List

-- Exercício 1
addPares [] = []
addPares (x : xs) = (fst x + snd x) : addPares xs

-- Exercício 2
-- A)
retornaMaiuscula :: [Char] -> [Char]
retornaMaiuscula [] = []
retornaMaiuscula (x : xs) = toUpper x : retornaMaiuscula xs

-- B)
tupla :: String -> (String, String)
tupla x = (x, retornaMaiuscula x)

-- Exercicio 3
maiorElemento :: Ord x => [x] -> x
maiorElemento [y] = y
maiorElemento (y : y' : ys) = maiorElemento ((if y > y' then y else y'): ys)

indice x i =
  if x !! i == maiorElemento x
    then i + 1
    else indice x (i + 1)

retornaMaiorePosicao x = (maiorElemento x, indice x 0)

-- Exercício 4
remover i lista = filter (\e -> e/=lista !! (i - 1)) lista

-- Exercício 5
type NomeAluno = String
type MediaNota = Int
type Aluno = (NomeAluno, MediaNota)
-- A)
type Turma = [Aluno]

-- B)
aprovados [] nota = []
aprovados (a : as) nota =
  if snd a >= nota
    then fst a : aprovados as nota
    else aprovados as nota