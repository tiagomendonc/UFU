-- 5) As empresas que têm algum vôo que não passe pelo aeroporto POA.
select distinct 
  	e.codemp,
	e.nome
from empresa e
join voo v on e.codemp = v.codemp
where not exists (
    select 
    	1
    from rota r
    where v.codvoo = r.codvoo and (r.Origem = 'POA' or r.Destino = 'POA')
  )
order by e.nome desc;

-- 6) As empresas que têm todos os seus vôos passando pelo aeroporto GIG.
select 
  e.codemp,
  e.nome
from empresa e
where not exists (
    select 
      v.codvoo
    from voo v
    where v.codemp = e.codemp and not exists (
        select 
          r.codrota
        from rota r
        where r.codvoo = v.codvoo and (r.origem = 'GIG' OR r.destino = 'GIG')
      )
  );
 
 -- 7) As empresas que cobrem todos os aeroportos. Cobrir um aeroporto significa passar por eleem algum vôo, seja como origem ou como destino.
 with aeroportos as (
  select distinct 
  	origem AS aeroporto
  from rota
  union
  select distinct destino as aeroporto
  from rota
)
select
  e.codemp,
  e.nome
from empresa e
where not exists (
    select 
      ac.aeroporto
    from aeroportos ac
    where not exists (
        select 
          vo.codvoo
        from voo vo
          join rota r on vo.codvoo = r.codvoo
        where vo.codemp = e.codemp and (r.origem = ac.aeroporto or r.destino = ac.aeroporto)
      )
  );
 
 -- 9) Para cada empresa, o destino e horário de saída da primeira viagem saindo do aeroporto GIG na data 2022-11-07.
with viagensNumeradas as (
  select 
    e.codemp,
    e.nome,
    vo.codvoo,
    r.destino,
    v.h_saida_real,
    row_number() over (partition by e.codemp order by v.h_saida_real) as numeroViagem
from viagem v
join rota r on v.codrota = r.codrota
join voo vo on r.codvoo = vo.codvoo
join empresa e on vo.codemp = e.codemp
 where r.origem = 'GIG' and v.data = '2022-11-07'
)
select
  codemp,
  nome,
  codvoo,
  destino,
  h_saida_real
from viagensNumeradas
where numeroViagem = 1;

-- 10) A relação de viagens da Azul, em 2022-11-07, em ordem de horário de saída, listando origem e destino, e com a observação Pontual ou Atrasado, 
--    ocorrendo o segundo caso quando adiferença entre o horário real de saída e o horário de saída for maior do que 10 minutos.
select
    r.codrota,
    vi.data,
    vi.h_saida_real,
    vi.h_chegada_real,
    vi.codaviao,
    case
        when extract(EPOCH from (vi.h_saida_real - r.h_Saida)::INTERVAL) > 600 then 'Atrasado'
        else 'Pontual'
    end as case
from empresa e
join voo v on e.codemp = v.codemp
join rota r on v.codvoo = r.codvoo
left join viagem vi on r.codrota = vi.codrota and vi.data = '2022-11-07'
where e.nome = 'Azul Linhas Aéreas Brasileiras'
order by vi.h_saida_real;














	
	


    
