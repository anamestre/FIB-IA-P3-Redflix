(define (domain conros-domain)
	(:requirements :strips :typing :adl :equality)

	(:types conro - conro
			mes - mes)
	(:predicates
		(quiero_ver ?con - contenido)
		(visto ?con - contenido)
		(predecesor ?con - contenido ?cont - contenido)
		(ver ?con - contenido)
		(diaocupado ?d - dia)
		(paralelo ?con - contenido ?con2 - contenido)
		(siguiente ?d1 - dia ?d2 - dia)
		(auxiliar ?con - contenido ?d - dia)
	)
	
	(:action ver_Paralelo
		:parameters
			(?con - contenido ?d - dia ?dAnterior - dia)
		:precondition
			(and
				(siguiente ?dAnterior ?d)
				(not (visto ?con))	
				(not (planeado ?con))
				(forall (?pred - contenido) (or
											(not (predecesor ?con ?pred))
											(or
												(planeado ?pred)
												(visto ?pred)
											)
										)
				)
				(forall (?paral - contenido) (or
											(and
												(not (paralelo ?con ?paral))
												(not (paralelo ?paral ?con))
											)
											(and
												(or
													(auxiliar ?paral ?d)
													(auxiliar ?paral ?dAnterior)
												)
												(or
													(quiero_ver ?paral)
													(visto ?paral)
												)
											)
										)
				)
			)
		:effect
			(and 
				(diaocupado ?d)
				(quiero_ver ?con)
				(auxiliar ?con ?d)
			)
	)
)


;ficar (paralelo con2 con10) a l'altre arxiu
;    	(paralelo con10 con3)