(define (domain planificador)
    (:requirements :adl :typing)
    (:types contenido - item)
    (:predicates
        (predecesor ?x - contenido ?y - contenido)  ;;x precede a y
        (ver ?x - contenido))

    (:action ver_predecesor :parameters (?x - contenido ?y - contenido)
        :precondition (and (predecesor ?x ?y) (ver ?y))
        :effect (ver ?x))
)
     