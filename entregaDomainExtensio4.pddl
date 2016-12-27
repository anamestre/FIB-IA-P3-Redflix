(define (domain planificador)
    (:requirements :adl :typing :fluents)
    (:types contenido - item
            dia - item)
    (:functions
        (ordenDia ?d - dia)               ;; le damos un valor a cada dia, para ver cuál va antes.
        (ultimoDia ?c - contenido)        ;; el ultimo dia que se le ha asignado a un predecesor de este contenido.
        (predecesores ?c - contenido)     ;; el num de predecesores que tiene cada contenido.
        (predecesoresAsignados ?c - contenido) ;; el num de predecesores de cada contenido que ya se ha asignado a un dia.
        (minutosContenido ?c - contenido)
        (minutosDia ?d - dia))
    (:predicates
        (predecesor ?x - contenido ?y - contenido)  ;;x precede a y           
        (ver ?x - contenido)
        (contenidoAsignado ?c - contenido))
     
    (:action asignar_contenidos :parameters (?d - dia ?x - contenido)
        :precondition (and (ver ?x) (not (contenidoAsignado ?x)) (> (ordenDia ?d) (ultimoDia ?x)) 
                        (= (predecesores ?x) (predecesoresAsignados ?x)) 
                        (<= (+ (minutosDia ?d) (minutosContenido ?x)) 200))
        :effect  (and (contenidoAsignado ?x) (increase (minutosDia ?d) (minutosContenido ?x))
                (forall (?y - contenido) (when (predecesor ?x ?y) (and (assign (ultimoDia ?y) (ordenDia ?d)) 
                (increase (predecesoresAsignados ?y) 1) )))))
)