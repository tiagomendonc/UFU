-- Tiago Oliveira Mendonça
-- 12121BSI238

import Data.Char

-- Exercício 1
-- A
numof :: Char -> [Char] -> Int
numof x y = length(filter (== x) y)
-- B
ellen :: [[Char]] -> [Int]
ellen cs = map length cs
-- C
ssp :: [Int] -> Int
ssp cs = foldr (+) 0 (map (^2) (filter (>0) cs ))

-- Exercício 2
separa :: [Char] -> (String, String)
separa s = (filter isAlpha s, filter isDigit s)

-- Exercício 3
-- A
const :: x -> y -> x
const x y = x
-- Recebe dois valores como parâmetro e retorna o primeiro
-- B
swap :: (x, y) -> (y, x)
swap (x,y) = (y, x)
-- Recebe um 2-tupla como parâmetro e retorna outra tupla com os valores invertidos na ordem
-- C
apply :: (x -> y) -> x -> y
apply f x = f x
-- Recebe uma função e um valor como parâmetro e retorna a mesma função com o valor x como parâmetro
-- D
flip :: (x -> y -> z) -> y -> x -> z
flip f x y = f y x
-- Recebe uma função e dois valores como parâmetro e retorna a mesma função com x e y invertidos como parâmetro

-- Exercício 4
data ShopItem = Product {nome :: String,
                         quantidade :: Float,
                         precoUnitario :: Float} deriving (Show)
p1 :: ShopItem
p2 :: ShopItem
p3 :: ShopItem
p1 = Product "Leite" 3 2.7
p2 = Product "Melancia" 1 5.5
p3 = Product "Pao" 15 0.5

valorCompra :: ShopItem -> Float
valorCompra (Product _ quant preco) = quant * preco

valorTotal :: [ShopItem] -> Float
valorTotal cs = foldr (+) 0 (map valorCompra cs)
