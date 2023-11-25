-- 1) A lista de empresas (código e nome) em ordem alfabética de nome.
select e.* from empresa e order by e.Nome

-- 2)  A lista dos vôos juntamente com os nomes das respectivas empresas, em ordem deempresa.
select v.*, e.nome from voo v join empresa e on e.codemp = v.codemp order by e.nome

-- 3) Os vôos da Gol com seus respectivos trechos (origem/destino) na ordem em que ocorrem.
select r.* from voo v join rota r on v.codvoo = r.codvoo where v.codemp = 'GLO' order by r.h_saida

-- 4) A lista de viagens, saindo do aeroporto GIG na data 07/11/2022, em ordem crescente dehorário previsto, com respectivos destinos imediatos.
select v.*, r.destino from viagem v join rota r on v.codrota = r.codrota where r.origem = 'GIG' and v.data = '2022-11-07' order by v.h_saida_real;

-- 5) Número de viagens realizadas com atraso, na saída, superior a 10 minutos, por empresa.
select 
	a.codemp, e.nome, count(v.codrota)  
from viagem v 
join rota r on v.codrota = r.codrota 
join aviao a on v.codaviao = a.codaviao 
join empresa e on a.codemp = e.codemp  
where (extract(EPOCH from v.h_saida_real) - extract(EPOCH from r.h_saida)) / 60 > 10 
group by a.codemp, e.nome 
order by count;

-- 6) A lista de cidades atendidas pela Azul (as atendidas como origem e também as atendidascomo destino), em ordem alfabética.
select 
	r.origem as cidade
from rota r
join voo v2 on r.codvoo = v2.codvoo
join empresa e on v2.codemp = e.codemp
where e.codemp = 'AZU'

UNION

select 
	r.destino as cidade
from rota r
join voo v2 on r.codrota = v2.codvoo
join empresa e on v2.codemp = e.codemp
where e.codemp = 'AZU'
order by cidade;

-- 7) Para cada vôo, a distância total (somatório da distância de cada trecho) em ordemdecrescente.
select 
	v.codvoo, SUM(t.distancia)
from voo v 
join rota r on v.codvoo = r.codvoo 
join trecho t on (r.destino = t.destino and r.origem = t.origem)
group by 1
order by sum(t.distancia) desc

-- 8) Viagens  que atrasaram, na saída, mais  que a média de atrasos  (também na saída),mostrando empresa, vôo, origem, destino e data.
select 
	e.codemp,
	e.nome,
	r.origem,
	r.destino,
	v."data",
	v.h_saida_real
from viagem v 
join rota r on v.codrota = r.codrota 
join voo v2 on r.codvoo = v2.codvoo 
join empresa e on v2.codemp = e.codemp 
where (extract(EPOCH from v.h_saida_real) - extract(EPOCH from r.h_saida)) > 0 
	and (extract(EPOCH from v.h_saida_real) - extract(EPOCH from r.h_saida)) > 
		(select avg(extract(EPOCH from v.h_saida_real) - extract(EPOCH from r.h_saida)) from viagem v join rota r on v.codrota = r.codrota)
order by v.h_saida_real 

-- 9) O voo da Gol que tem a maior duração total, somando-se a duração de cada trecho massem computar os tempos de escala. O tempo de voo pode ser exibido no formato hh:mm:ss ou apenasem minutos.
with DuracaoTrecho as (
    select
        vo.codvoo,
        SUM(extract(EPOCH from (r.H_Chegada - r.H_Saida))) / 60 as DuracaoMinutos
    from
        rota r
        join voo vo on r.codvoo = vo.codvoo
        join empresa e on vo.codemp = e.codemp
    group by
        vo.codvoo
)
select
    vo.codvoo,
    COALESCE(TO_CHAR(MAX(dt.DuracaoMinutos) * interval '1 minute', 'HH24:MI:SS'), '') as sum
from
    DuracaoTrecho dt
    join voo vo on dt.codvoo = vo.codvoo
    join empresa e on vo.codemp = e.codemp
where
    e.nome = 'Gol Linhas Aéreas'
group by
    vo.codvoo, e.nome
order by
    MAX(dt.DuracaoMinutos) desc
limit 1;

-- 10) Uma lista de pontos de cada trecho, que servirão a um sistema de bonificação para seususuários que a Gol deseja implantar. 
-- 		Considerando que o maior de seus trechos (em distância) receberá 1.000 pontos, os pontos dos demais trechos devem ser proporcionais em relação à distância do maiortrecho. 
-- 		Se um trecho A→B for listado então seu inverso (B→A) não deve aparecer no resultado. Noteque, na base de dados, pode haver trechos que não possuam trechos inversos.
 select distinct
    least(origem, destino) AS least,
    greatest(origem, destino) AS greatest,
    distancia,
    case
        when distancia = max_distancia then 1000
        else round(1000.0 * distancia / max_distancia)
    end as pontos
from trecho
cross join (select max(distancia) as max_distancia from trecho) as max_distancia
order by distancia








