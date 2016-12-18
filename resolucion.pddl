(define (domain planificador)
   (:requeriments :adl :typing)
   (:types  capitulo - item
            pelicula - item)
   (:predicates
       (capitulo ?cap)
       (pelicula ?pel)
       (pertenece ?cap - capitulo ?ser - serie)
       (pertenece ?pel - pelicula ?ser - serie)
       (predecesor ?cap - capitulo ?ser -serie)
       (predecesor ?pel - pelicula ?ser -serie)
       (visto ?cap - capitulo ?ser - serie)
       (visto ?pel - pelicula ?ser - serie)
       (quiere ?cap - capitulo ?ser - serie)
       (quiere ?pel - pelicula ?ser - serie)
    )

    (:action ver_predecesor
            :parameters (?cap ?cap1 - capitulo ?pel ?pel1 - pelicula ?serie - serie)
            :precondition (or (and(pertenece ?cap ?serie) 
                              (pertenece ?cap1 ?serie)
                              (predecesor ?cap ?cap1) 
                              (not (quiere cap ?serie) (quiere ?cap1 ?serie))
                              )
                              (and(pertenece ?cap ?serie) 
                              (pertenece ?pel ?serie)
                              (predecesor ?cap ?pel) 
                              (not (quiere cap ?serie) (quiere ?pel ?serie))
                              )
                              (and(pertenece ?pel ?serie)
                              (pertenece ?pel1 ?serie)
                              (predecesor ?pel ?pel1) 
                              (not (quiere cap ?pel) (quiere ?pel1 ?serie))
                              )
                          )
            :effect (or(visto ?cap) (visto ?pel))
    )

    (:action ver_capitulo 
              :parameters (?cap - capitulo)
              :precondition (and (quiere ?cap) (forall (?cap1 - capitulo) (or (not (predecesor ?cap ?cap1)) (visto ?cap1))))
              :effect (and (not (quiere ?cap)) (visto ?cap))
    )

    (:action ver_pelicula
              :parameters (?cap - capitulo ?pel - pelicula)
              :precondition (and (quiere ?pel) (forall (?pel1 - pelicula) (or (not (predecesor ?cap ?pel1)) (visto ?pel1))))
              :effect (and (not (quiere ?pel)) (visto ?pel))
    )

    (:action ver_peliculas
              :parameters (?pel - pelicula)
              :precondition (and (quiere ?pel) (forall (?pel1 - pelicula) (or (not (predecesor ?pel ?pel1)) (visto ?pel1))))
              :effect (and (not (quiere ?pel)) (visto ?pel))
    )
)







