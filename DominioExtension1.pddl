
(define (domain contenido)
	(:requirements :strips :typing :adl :equality)
	(:types contenido dia)

	(:predicates
		(quiero_ver ?lib - contenido)
		(visto ?lib - contenido)
		(predecesor ?lib - contenido ?pred - contenido)
		(ver ?lib - contenido)
		(diaocupado ?m - dia)
	)
	(:action planear
		:parameters (?lib - contenido ?m - dia)	
		:precondition
			(and
				(not (diaocupado ?m)) 
				(not (quiero_ver ?lib))	
				(not (quiero_ver ?lib))
				(forall (?l - contenido)(or
										(and       
											(predecesor ?lib ?l)
											(or
											(quiero_ver ?l)
											(quiero_ver ?l)))
										(and 
											(predecesor ?l ?lib)
											(ver ?l)
										)
									  	(not (predecesor ?lib ?l)) 
									  )
				) 
			)
		:effect
		(and  (diaocupado ?m)
			  (quiero_ver ?lib)	
		)
	)
)