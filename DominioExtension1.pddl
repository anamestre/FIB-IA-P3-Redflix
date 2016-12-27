
(define (domain contenido)
	(:requirements :strips :typing :adl :equality)
	(:types contenido dia)

	(:predicates
		(quiero_ver ?con - contenido)
		(visto ?con - contenido)
		(predecesor ?con - contenido ?cont - contenido)
		(ver ?con - contenido)
		(diaocupado ?d - dia)
	)
	(:action ver_Contenidos
		:parameters (?con - contenido ?d - dia)	
		:precondition
			(and
				(not (diaocupado ?d)) 
				(not (visto ?con))	
				(not (quiero_ver ?con))
				(forall (?c - contenido) (or
										(and       
											(predecesor ?con ?c)
											(or
											(visto ?c)
											(quiero_ver ?c)))
										(and 
											(predecesor ?c ?con)
											(ver ?c)
										)
									  	(not (predecesor ?con ?c)) 
									  )
				) 
			)
		:effect
		(and  (diaocupado ?d)
			  (quiero_ver ?con)	
		)
	)
)