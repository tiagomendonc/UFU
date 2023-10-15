-- 1) Obter a lista de clientes cujo telefone seja do Rio de Janeiro (isto é, com o código de área 21).
select c.* from cliente c where left(c.fonecel, 4) = '(21)' or left(c.foneres, 4) = '(21)'


-- 2) Obter os empréstimos feitos no primeiro semestre de 2013, exibidos do mais recente para o mais antigo.
select e.* from emprestimo e where e.dataret >= '2013-01-01' and e.dataret <= '2023-06-30' order by e.dataret desc;


-- 2 Diferente)
select e.* from emprestimo e where e.dataret between '2013-01-01' and '2023-06-30' order by e.dataret desc;


-- 3) Listar clientes cujo nome (incluindo espaços) tenha mais de 15 caracteres.
select c.* from cliente c where LENGTH(c.nome) > 15; 


-- 4) Listar todos os nomes de pessoas no banco de dados incluindo atores, diretores de filmes e clientes.
select c.nome from cliente c 
union
select a.nomereal from ator a 
union
select distinct f.direcao from filme f
order by nome asc


-- 5) Listar empréstimos cuja data de devolução está, pelo menos, 7 dias posterior em relação à data de retirada.
select e.* from emprestimo e where cast(to_char(age(e.datedev, e.dataret), 'DD') as integer) >= 7;


-- 6) Obter a lista de empréstimos feitos no ano de 2012 cujo valor pago seja estritamente inferior a 10.
select e.* from emprestimo e where (e.dataret between '2012-01-01' and '2012-12-31') and valor_pg < 10.00 


-- 7) Obter uma listagem com filmes de aventura ou drama com duração superior a duas horas (note que filmes podem ter mais de uma categoria).
select f.* from filme f where (f.categoria like '%Aventura%' or f.categoria like '%Drama%') and f.duracao > 120;


-- 8) Obter uma listagem com filmes que estejam, simultaneamente, nas categorias de crime e drama,
--    com duração superior a duas horas, que tenham sido gravados a mais de 10 anos e cujo título original tenha mais de 5 caracteres.
select f.* from filme f where (f.categoria like '%Crime%' and f.categoria like '%Drama%') 
							and f.duracao > 120 
							and  cast(to_char(age(current_date, f.data_lancamento), 'YY') as integer) > 10
							and LENGTH(f.titulo_original) > 5;
							
-- 9) Listar os 5 filmes mais antigos do acervo.
select f.* from filme f order by f.data_lancamento asc limit 5