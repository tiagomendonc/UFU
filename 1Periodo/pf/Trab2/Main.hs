-- Tiago Oliveira Mendonça
-- 12121BSI238

type Cod = Int
type Nome = String 
type Valor = Float

type Prod = (Cod, Nome, Valor)

tabelaProdutos :: [Prod]
tabelaProdutos = [(001, "Chocolate", 5.25)
                 ,(002, "Biscoito", 10.10)
                 ,(003, "Laranja", 4.60)
                 ,(004, "Sabao", 2.10)
                 ,(005, "Batata Chips", 6.90)
                 ,(006, "Doritos", 8.90)]

isCodigo :: Cod -> Prod -> Bool
isCodigo n (num, nome, preco) = if n == num then True else False

getPreco :: Prod -> Valor
getPreco (num, nome, preco) = preco

getNome :: Prod -> Nome
getNome (num, nome, preco) = nome

buscaPrecoPorCodigo :: Cod -> Valor
buscaPrecoPorCodigo num = head (map getPreco (filter (isCodigo num) tabelaProdutos))

buscaNomePorCodigo :: Cod -> Nome
buscaNomePorCodigo num = head (map getNome (filter (isCodigo num) tabelaProdutos))

calculaPrecos :: [Cod] -> Valor
calculaPrecos ps = foldr (+) 0 (map buscaPrecoPorCodigo ps)

formatStrProduto :: Cod -> String
formatStrProduto num = do
     let nPts = length ((buscaNomePorCodigo num) ++ show (buscaPrecoPorCodigo num))
     (buscaNomePorCodigo num) ++ (replicate (30 - nPts) '.') ++ show (buscaPrecoPorCodigo num) ++ "\n"

geraNotaFiscal ns = do
      let nPts_ = length ("Total" ++ show (calculaPrecos ns))
      appendFile "nfce.txt" (foldr (++) [] (map (formatStrProduto) ns))
      appendFile "nfce.txt" ("Total" ++ (replicate (30 - nPts_) '.') ++ show (calculaPrecos ns))