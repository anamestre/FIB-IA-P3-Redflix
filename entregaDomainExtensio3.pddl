(define (domain planificador)
    (:requirements :adl :typing)
    (:types contenido - item
            dia - item)
    (:functions
        (capacidadDia ?d - dia)           ;; Cuantos contenidos tiene asignado un dia.
        (ordenDia ?d - dia)               ;; le damos un valor a cada dia, para ver cuál va antes.
        (ultimoDia ?c - contenido)        ;; el ultimo dia que se le ha asignado a un predecesor de este contenido.
        (predecesores ?c - contenido)     ;; el num de predecesores que tiene cada contenido.
        (predecesoresAsignados ?c - contenido)) ;; el num de predecesores de cada contenido que ya se ha asignado a un dia.
    (:predicates
        (predecesor ?x - contenido ?y - contenido)  ;;x precede a y             
        (ver ?x - contenido)
        (contenidoAsignado ?c - contenido))
     
    (:action ver_predecesor :parameters (?x - contenido ?y - contenido)
        :precondition (and (predecesor ?x ?y) (ver ?y))
        :effect  (ver ?x))
        
    (:action asignar_contenidos :parameters (?d - dia ?x - contenido)
        :precondition (and (ver ?x) (not (contenidoAsignado ?x)) (< (capacidadDia ?d) 3) (> (ordenDia ?d) (ultimoDia ?x)) 
                        (= (predecesores ?x) (predecesoresAsignados ?x)))
        :effect  (and (increase (capacidadDia ?d) 1) (contenidoAsignado ?x)
                (forall (?y - contenido) (when (predecesor ?x ?y) (and (assign (ultimoDia ?y) (ordenDia ?d)) 
                (increase (predecesoresAsignados ?y) 1) )))))
)