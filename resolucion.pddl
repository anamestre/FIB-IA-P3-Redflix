(define (domain planificador)
    (:requirements :adl :typing)
    (:types contenido - item
            dia - item)
    (:predicates
        (predecesor ?x - contenido ?y - contenido)  ;;x precede a y
        (visto ?x - contenido)                 
        (ver ?x - contenido)
        (dia ?x - dia))                  

    (:action ver_predecesor :parameters (?x - contenido ?y - contenido)
        :precondition (and (predecesor ?x ?y) (not (ver ?x)) (ver ?y))
        :effect (ver ?x))

    (:action ver_contenido :parameters (?x - contenido)
        :precondition (and (ver ?x) (forall (?y - contenido) (or (not (predecesor ?y ?x)) (visto ?y))))
        :effect (and (not (ver ?x)) (visto ?x)))

    (:action ver_contenido_dia :parameters (?n - dia)
        :precondition (forall (?n - dia) (dia ?n))
        :effect (dia ?n))


)