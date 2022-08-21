-- Tiago Oliveira Mendonça
-- 12121BSI238

--Exercício 1 - 6
module Main (main) where
import System.IO
main :: IO()
main = do
    hSetBuffering stdout NoBuffering
    putStrLn("Banco Tiago Oliveira Mendonca \n")
    putStrLn("Opcoes: \n")
    putStrLn("1. Saldo\n")
    putStrLn("2. Extrato\n")
    putStrLn("3. Deposito\n")
    putStrLn("4. Saque\n")
    putStrLn("5. Fim\n")
    putStrLn("Escolha uma opcao: \n")
    opcao <- readLn
    case opcao of
        1 -> do imprime "saldo.txt"
        2 -> do imprime "extrato.txt"
        3 -> do {putStr("Informe o valor a ser depositado:"); valor <- readLn; deposito valor;}
        4 -> do {putStr("Informe o valor a ser sacado:"); valor <- readLn; saque valor;}
        5 -> putStrLn("Volte sempre! Agradecemos por utilizar nosso banco!");
        _ -> putStrLn("Opcao invalida!");

    if opcao /= 5 then
        main
    else
        putStrLn("Fechando")

-- Exercício 8
imprime :: String -> IO()
imprime path = do
    conteudo <- readFile path
    putStr conteudo

-- Exercício 9
deposito :: Float -> IO()
deposito saldo = do
    saldo_ <- readFile "saldo.txt"
    putStr("Saldo atual: \n")
    putStr saldo_
    writeFile "saldo.txt" (show (read saldo_ + saldo))
    saldo_ <- readFile "saldo.txt"
    putStr("Saldo atualizado: \n")
    putStr saldo_
    appendFile "extrato.txt" ("+"++(show saldo)++"\n")

-- Exercício 10
saque :: Float -> IO()
saque saldo = do
    saldo_ <- readFile "saldo.txt"
    putStr("Saldo atual: \n")
    putStrLn saldo_
    writeFile "saldo.txt" (show (read saldo_ - saldo))
    saldo_ <- readFile "saldo.txt"
    putStr("Saldo atualizado: \n")
    putStr saldo_
    appendFile "extrato.txt" ("-"++(show saldo)++"\n")